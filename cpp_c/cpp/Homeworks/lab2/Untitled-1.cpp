#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <sstream>

#include "util.h"
#include "editor.h"
using namespace std;

/**
 * @brief Read lines from filename
 *        If something goes wrong, also output_error(cerr, "Runtime error\n")
 * @param filename file to be opened
 * @param lines store each line of file
 * @return true if success
 * @return false if something goes wrong, e.g. can't open file
 */
bool read_lines(const string& filename, list<string> &lines) {

    fstream file;

    file.open(filename);

    if(!file.is_open())
       {output_error(cerr, "Runtime error\n"); return false;}
    while(!file.eof())
    {
        string line;
        getline(file,line);
        lines.push_back(line);

    }

    return true;
}

/**
 * @brief Output lines to os.
 *        If something goes wrong, also output_error(cerr, "Runtime error\n")
 *
 * @param os output stream, usually cout or ofstream
 * @param lines lines to be output
 * @param show_line_num if true, output line number before each line
 * @return true if success
 * @return false if something goes wrong, e.g. os is not open
 */
bool output_lines(ostream &os, const list<string> &lines, bool show_line_num) {
    list<string>::const_iterator iter;
    iter=lines.begin();
    int line_num=1;
    if(!os)
    {
       output_error(cerr, "Runtime error\n");
       return false;
    }
    
    while(iter!=lines.end())
    {
        if(show_line_num==true)
            os<<line_num<<' '<<(*iter)<<endl;
        if(show_line_num==false)
            os<<(*iter)<<endl;
        line_num++;
        iter++;
    }

    return true;
}

/**
 * @brief Delete line at line_num from lines.
 *        If something goes wrong, also output_error(cerr, "Runtime error\n")
 *
 * @param lines The list of lines to be deleted from
 * @param line_num The index of the line to be delete.
 * @return true if the line is deleted successfully.
 * @return false something goes wrong, e.g. line_num is out of range.
 */
bool delete_line(list<string> &lines, int line_num) {
    cout<<"in"<<endl;
    list<string>::iterator iter,iter_begin,iter_end;
    iter=iter_begin=lines.begin();
    iter_end=lines.end();

    if(distance(iter_begin,iter_end)+1<line_num)
       {
           output_error(cerr, "Runtime error\n");
        return false;
       } 

    for(;distance(iter_begin,iter)+1!=line_num;iter++);
    iter=lines.erase(iter);

    
    return true;
}

/**
 * @brief Insert a line into the list of lines.
 *        If something goes wrong, also output_error(cerr, "Runtime error\n")
 *
 * @param lines The list of lines to be inserted into.
 * @param line_num The index of the line to be inserted.
 * @param line The line to be inserted.
 * @return true if the line is inserted successfully.
 * @return false something goes wrong, e.g. line_num is out of range.
 */
bool insert_line(list<string> &lines, int line_num, const string &line) {

    list<string>::iterator iter,iter_begin,iter_end;
    iter=iter_begin=lines.begin();
    iter_end=lines.end();

    if(distance(iter_begin,iter_end)+1<line_num)
        {output_error(cerr, "Runtime error\n");
            return false;}    
    for(;distance(iter_begin,iter)+1!=line_num;iter++);
    iter=lines.insert(iter,line);


    
    return true;
}

/**
 * @brief Replace the line at line_num with line.
 *        If something goes wrong, also output_error(cerr, "Runtime error\n")
 *
 * @param lines The list of lines to be replaced.
 * @param line_num The index of the line to be replaced.
 * @param line The line to be replaced.
 * @return true if the line is replaced successfully.
 * @return false something goes wrong, e.g. line_num is out of range.
 */
bool replace_line(list<string> &lines, int line_num, const string &line) {
    
    list<string>::iterator iter,iter_begin,iter_end;
    iter=iter_begin=lines.begin();
    iter_end=lines.end();

    if(distance(iter_begin,iter_end)+1<line_num)
    {output_error(cerr, "Runtime error\n");
        return false;}    
    for(;distance(iter_begin,iter)+1!=line_num;iter++);
    *iter=line;

    return true;
}

/**
 * @brief Check whether given argc is in expect_count
 *        E.g. check_argc(1, {1, 2, 3}) => true
 *             check_argc(2, {1, 3}) => false
 *        If in, return true, else output_error(cerr, "Invalid command\n") and return false
 *
 * @param argc the number of arguments
 * @param expect_count the expected number of arguments
 * @return true when argc is in expect_count otherwise false
 */
inline bool check_argc(vector<string>::size_type argc, vector<int> expect_count) {
    
    vector<int>::iterator iter=expect_count.begin();
    bool check = false;
    while(iter<=expect_count.end())
    {
        if((*iter)==argc)
        {
            check=true;
            return true;
        }
        iter++;
    }
    if(check==false)
        output_error(cerr, "Invalid command\n");
  
    
    return false;
}
/**
 * @brief If result is true, output_info(cout, "OK\n")
 *
 * @param result
 */
inline void check_result(bool result) {
    if (result) {
        output_info(cout, "OK\n");
    }
}

/**
 * @brief This is the main_loop function of the editor.
 *        It will parse the input from user and call the corresponding function.
 *        Valid commands are:
 *        1. i/insert [line_num] [line] // Insert [line] at [line_num], the
 * original line at [line_num] will be the next line.
 *        2. d/delete [line_num] // Delete [line_num]
 *        3. e/edit [line_num] [line] // Replace [line_num] with [line]
 *        4. l/list // List all lines with line number
 *        5. w/write [filename] // Write the file to [filename],
 *        if [filename] is not specified, we will use the original file name
 *        6. r/reload [filename] // Reload the file from [filename]
 *        if [filename] is not specified, we will use the original file name
 *        7. q/quit // Quit
 *
 *        Note:
 *        1. [line_num] is the line number, starting from 1.
 *        2. Both short and long command are supported.
 *           E.g. "i 1 hello" are equivalent to "insert 1 hello".
 *        3. If command is invalid including the number of the argument is
 *           invalid, it will call output_error(cerr, "Invalid command\n")
 *        4. If the command is executed successfully, it will call output_info(cout, "OK\n")
 *           Otherwise, it will call output_error(cerr, "Runtime error\n")
 *
 * @param is
 * @param filename
 */
void main_loop(const string &filename) {
    list<string> lines;
    read_lines(filename, lines);
    while (true) {
        cout << "> ";
        string cmd;
        getline(cin, cmd);
        cin.sync();
        vector<string> cmds = split(cmd, ' ', 3);
        if (cmds[0] == "i" || cmds[0] == "insert") {
            if (!check_argc(cmds.size(), {3})) continue;
            check_result(insert_line(lines, stoi(cmds[1]), cmds[2]));
        } 
        else if (cmds[0] == "d" || cmds[0] == "delete")
        {
            if(!check_argc(cmds.size(),{2})) continue;
            check_result(delete_line(lines,stoi(cmds[1])));
        }
        else if (cmds[0] == "e" || cmds[0] == "edit")
        {
            if (!check_argc(cmds.size(), {3})) continue;
            check_result(replace_line(lines, stoi(cmds[1]), cmds[2]));
        }
        else if (cmds[0] == "l" || cmds[0] == "list")
        {
            if (!check_argc(cmds.size(), {1})) continue;
            check_result(output_lines(cout,lines,true));
        }
        else if (cmds[0] == "w" || cmds[0] == "write")
        {
            if (!check_argc(cmds.size(), {1,2})) continue;
            ofstream write_f;
            if(cmds.size()==2)
                write_f.open(cmds[1]);
            else
                write_f.open(filename);
        
            check_result(output_lines(write_f,lines));
        }
        else if (cmds[0] == "r" || cmds[0] == "reload")
        {
            if (!check_argc(cmds.size(), {1,2})) continue;
            ifstream read_f;
            if(cmds.size()==2)
                check_result(read_lines(cmds[1],lines));
            else
                check_result(read_lines(filename,lines));
        }
        else if (cmds[0] == "q" || cmds[0] == "quit")
        {
            return ;
        }
        else
        {
            output_error(cerr, "Invalid command\n");
        }
        

        //else if ...
        // TODO: complete this function
        /* Your Code Here */

    }
}

// Code style (for anyone interested): {BasedOnStyle: Google, IndentWidth: 4,
// ColumnLimit: 120}

/**
 * @brief This is the main function of the editor.
 *        When execute the editor program, we can expect 0 or 1 argument(argc be
 * 1 or 2). If there is no argument, we will first ask user to input a filename.
 *        If there is one argument, we will open the file and start to edit.
 *        Otherwise, we will print the usage and exit.
 *        Usage: ./editor.exe [filename] (windows)
 *               ./editor [filename] (*nix)
 *        Please note that if the file do not exist, we will create it with specified filename.
 * @param argc
 * @param argv
 * @return int 0 if success, -1 if any unexpected error
 */

/**
 * @brief split single line string (Do not contain "\n") by delimiter to at most max_part
 * e.g "1,2,3,4" by "," at most 4 part => ["1","2","3","4"]
 *     "1,2,3,4" by "," at most 5 part => ["1","2","3","4"]
 *     "1,2,3,4" by "," at most 3 part => ["1","2","3,4"]
 * @param str any string
 * @param delim any char delimiter
 * @param max_part
 * @return vector<string> containing splitted string
 */
vector<string> split(const string& str, char delim, int max_part) {
    vector<string> res;
    typedef string::size_type strsz;
    strsz i,j;
    i=j=0;
    int part=1;
    
    while(i!=str.size()&&part<max_part)
    {
        while(i!=str.size()&&str[i]==delim)
            i++;
        j=i;
        while(j!=str.size()&&str[j]!=delim)
            j++;
        if(i!=j)
        {
            res.push_back(str.substr(i,j-i));
            i=j;
            
        }
        part++;

    }
    if(i!=str.size())
        res.push_back(str.substr(i+1,str.size()-i));

 
    return res;
}

/**
 * @brief output info string to os and mark it green
 *
 * @param os any output stream, usually cout
 * @param str any string
 * @return ostream& the original output stream
 */
ostream& output_info(ostream& os, const string& str) {
    os << "\033[32m" << str << "\033[0m";
    return os.flush();
}

/**
 * @brief output error string to os and mark it red
 *
 * @param os any output stream, usually cerr
 * @param str any string
 * @return ostream& the original output stream
 */
ostream& output_error(ostream& os, const string& str) {
    
    os<<"\033[31m"<<str<< "\033[0m";

    
    return os.flush();
}


int main(int argc, char *argv[]) {
    string filename;
    if (argc <= 2) {
        if (argc == 1) {
            cout << "Please input a file name: ";
            getline(cin, filename);
        } else if (argc == 2) {
            filename = argv[1];
        }
        fstream file;
        file.open(filename,ios::out);

        // If the file do not exist, create it first
        // TODO: complete this function
        /* Your Code Here */
        


        // Run the main loop
        main_loop(filename);
    } else {
#ifdef __WIN32__
        cerr << "Usage: ./editor.exe [filename]" << endl;
#else
        cerr << "Usage: ./editor [filename]" << endl;
#endif
        return -1;
    }
    return 0;
}
