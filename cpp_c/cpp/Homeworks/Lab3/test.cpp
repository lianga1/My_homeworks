
#include <cstring>
#include "util.h"
#include "grams.h"

#include <iostream>
#include <regex>
#include <set>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "util.h"
// You can include any std header file here.
#include <regex>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief split a string by the delimiter space aka ` ` and append the result to the back of the vector `ret`.
 * 
 * @param s the string to be splitted
 * @param ret result vector. In this lab, argument `ret` is a global variable 
 *            and is used to store the words according to the appearance order.
 */
void split_string(const string& s, vector<string>& ret) {
    // hint: you can use function `substr` to get a substring of the string `s`
    //       if you know what regular expression is, you can use `regex` to easily split the string `s`
    //       stringstream may be useful, too
    /* Your code here */

        string::size_type i=0,j=0;
    while(i!=s.size())
    {
        while(i!=s.size()&&isspace(s[i]))
            i++;
        j=i;
        while(j!=s.size()&&!isspace(s[j]))
            j++;
        if(i!=j)
            ret.push_back(s.substr(i,j-i));
        i=j;
    }
    return;
}

using namespace std;

// define some global variables
vector<string> words;                       // all words, sort by appearance order
vector<pair<string, int>> freq;             // frequency of coocurrence of each word
// for simplicity, each row of the co-occurrence matrix represents the word by lexicographical order
// thus, we'd use a map to store the index of the word which is `word_index`
map<string, int> word_index;                // mapping the word to the index in the co-occurrence matrix
map<int, string> index_word;                // mapping the index to the word in the co-occurrence matrix
vector<vector<int>> coocur_matrix;          // co-ocurrence martix, each row is a n-gram
vector<vector<double>> normalized_matrix;   // normalized co-ocurrence martix
// You can add more global variables here if you need.
// Notice that if you add more global variables, you should declare them in the `grams.h` using `extern`

/**
 * @brief read the input file and record all words in the file. 
 *  Store the words in the vector `words` according to the appearance order.
 * 
 * @param filename  file name of the input file
 * @param words     vector to store the words
 * @return size_t   the size of the `words` vector
 */
size_t record_words(const string& filename, vector<string>& words) {
    ifstream file(filename);
    if (!file.good()) {
        cerr << "Error: cannot open file " << filename << endl;
        exit(1);
    }
    string line;
    while (getline(file, line)) {
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        split_string(line, words);
    }
    file.close();
    return words.size();
}

/**
 * @brief go through the vector `words` and record the frequency of each word.
 * e.g.:
 *  words = ["a", "a", "b", "c", "d", "e", "e"]
 *  freq = [("a", 2), ("b", 1), ("c", 1), ("d", 1), ("e", 2)]
 * 
 * @param words     vector of words
 * @param freq      vector to store the frequency of each word
 * @return size_t   the size of the `freq` vector
 */
size_t record_freq(const vector<string>& words, vector<pair<string, int>>& freq) {
    map<string,int> w_fmap;// declare a map which stores the frequence of each word
    vector<string>::const_iterator iter=words.begin();

    while(iter!=words.end())//record each word's frequence
    {
        ++w_fmap[(*iter)];
        //cout<<*iter<<endl;

        iter++;
        
    }
    cout<<"map.size "<<w_fmap.size()<<endl;
    map<string,int>::iterator it;

    it=w_fmap.begin();
    while(it!=w_fmap.end())//make the frequence into the vector freq
        {freq.push_back(*it);it++;
      //  cout<<it->second<<endl;
        }

   
   
    // hint: you may find the `map` data structure useful
    /* Your code here */
    cout<<"freq.size "<<freq.size()<<endl;

    auto itera=freq.begin();
    int i=0;
    while(itera!=freq.end())
    {
        if(itera->first=="cbs")
                cout<<"the number of cbs "<<itera->second<<endl;
        itera++;
    }

    return freq.size();
}

/**
 * @brief Filter out the 3000 most frequent words.
 * !!Notice that if a word is not in the 3000 most frequent words, it should be replaced by `<unk>`.
 * 
 * @param freq      vector of words and their frequency
 * @param words     original vector of words. You should change the vector `words` to keep the 3000 most frequent words.
 */
void filter_words(vector<pair<string, int>>& freq, vector<string>& words) {
   
    vector<string>::iterator iter=words.begin();
    //put the words into the vector of pair 
    //sort the vector


    sort(freq.begin(),freq.end(),[](pair<string,int> x , pair<string,int>y)-> bool {return (x.second>y.second)||(x.second==y.second&&x.first<y.first);});
    //put the 3000 most_occured words into the set
    cout<<"the smallest is "<<freq[3000].second<<endl;
    set<string> fre;
    int i=0;
    for(i=0;i<3000;i++)
        {fre.insert(freq[i].first);
        if(freq[i].first=="cbs")
             cout<<freq[i].second<<endl;
        }

    //check whether the word in words is in the set or not, if not, replace it with <unk>
    while(iter!=words.end())
    {
        if(fre.find(*iter)==fre.end())
            *iter="<unk>";


        iter++;
    }



   
    // hint: you can use function `sort` to sort the vector `freq` by modify the compare function.
    // if you want to write a compare function more gracefully, you can try to use `lambda expression`(It's a new feature in C++11.).
    /* Your code here */
    return;
}

/**
 * @brief Use `words` vector to construct a word index map. 
 * The key is the word and the value is the position of the word in the alphabetical order.
 * e.g. :
 * words: ["I", "like", "to", "eat", "apple"]
 * word_index: {"I": 0, "apple": 1, "eat": 2, "like": 3, "to": 4}
 * 
 * @param words         vector of words
 * @param word_index    map to store the word index
 * @return size_t       the size of the `word_index` map
 */
size_t set_word_index(const vector<string>& words, map<string, int>& word_index) {
    int i=0;
    vector<string>::const_iterator iter=words.begin();
    for(;iter!=words.end();iter++)
    {
        if(*iter=="cbs")
            cout<<"there is cbs"<<endl;
        break;
    }
    iter=words.begin();
    while(iter!=words.end())
    {
        if(word_index.count(*iter)==1)
            {iter++;continue;}
        word_index[(*iter)]=i;
        i++;
        iter++;
         //cout<<"i "<<i<<endl;   
    }  

    //for(auto f = word_index.begin();f!=word_index.end();f++)
    //    cout<<f->second<<endl;
    //cout<<"i "<<i<<endl;    
    //cout<<"<unk> num "<<word_index.at("<unk>")<<endl; 
    //cout<<"word_index.size() "<<word_index.size()<<endl;

    /* Your code here */
    return word_index.size();
}

/**
 * @brief Set up the coocur matrix object. 
 * Each row of the coocur matrix represents the word by lexicographical order. 
 * The value of each element in the co-occurrence matrix is the number of times that two words appear together.
 * e.g. :
 * consider n as 3,
 * words: ["<unk>", "I", "like", "to", "eat", "apple", "<unk>"]
 * coocur_matrix:   (sorted by lexicographical order. Thus, these rows represent the words ["<unk>", "I", "apple", "eat", "like", "to"])
 * coocur_matrix[1][4] == 1 represents that if consider "I" as center word, the number of times that "I" and "like" appear together is 1.
 * [0, 1, 1, 0, 0, 0]
 * [1, 0, 0, 0, 1, 0]
 * [1, 0, 0, 1, 0, 0]
 * [0, 0, 1, 0, 0, 1]
 * [0, 1, 0, 0, 0, 1]
 * [0, 0, 0, 1, 1, 0]
 * 
 * @param words             vector of words
 * @param word_index        map of word index
 * @param coocur_matrix     vector of vector to store the co-occurrence matrix
 * @param n                 hyper-parameter of n-gram
 */
void set_coocur_matrix( vector<string>& words,  const map<string, int>& word_index, vector<vector<int>>& coocur_matrix, int n) {
    size_t siz = words.size();
    int size=siz;
    int m=0;
  //  for(m=0;m<n-1;m++)
  //  {
  //  words.insert(words.begin(),"<unk>");
  //  words.push_back("<unk>");

  //  }

    coocur_matrix = vector<vector<int>>(word_index.size(), vector<int>(word_index.size(), 0));
    cout<<"coocur_matrix.size "<<coocur_matrix.size()<<endl;
    for (int left = 0, right = n, center = (n + 1) / 2; right <= size; left++, right++, center++) {
        if (center % 100 == 0) {
            cout << setprecision(5) << (double)center/size << '\r';     // This is to show the progress of building the co-occurrence matrix.
        }
    int i;
    for(i=left;i<right;i++)
    {
        if(i==center)continue;
        coocur_matrix.at(word_index.at(words[center])).at(word_index.at(words[i]))++;//add the left 
    }

    //coocur_matrix.at(word_index.at(words[center])).at(word_index.at(words[left]))++;//add the left 
   // coocur_matrix.at(word_index.at(words[center])).at(word_index.at(words[right])) ++;//add the right
   //

        // If you want, you can do the similar thing to print the progress of other parts.
        /* Your code here */
    }

    return;
}

/**
 * @brief normalize the co-occurrence matrix by column.
 * e.g.:
 * co-occurrence matrix:
 * [0, 2, 1, 0, 0, 0]
 * [2, 0, 0, 0, 1, 0]
 * [1, 0, 0, 1, 0, 0]
 * [0, 0, 1, 0, 0, 1]
 * [0, 1, 0, 0, 0, 1]
 * [0, 0, 0, 1, 1, 0]
 * normalized matrix:
 * [0, 2/3, 0.5, 0, 0, 0]
 * [2/3, 0, 0, 0, 0.5, 0]
 * [1/3, 0, 0, 0.5, 0, 0]
 * [0, 0, 0.5, 0, 0, 0.5]
 * [0, 1/3, 0, 0, 0, 0.5]
 * [0, 0, 0, 0.5, 0.5, 0]
 * 
 * @param coocur_matrix         co-occurrence martix
 * @param normalized_matrix     normalized co-occurrence martix
 */
void normalize_matrix(const vector<vector<int>>& coocur_matrix, vector<vector<double>>& normalized_matrix) {
    size_t i,j;

    normalized_matrix = vector<vector<double>>(coocur_matrix.size(), vector<double>(coocur_matrix .size(), 0.0));
    //summarize the normalized matrix

    vector<int> col_sum(coocur_matrix.size(),0);
    
    for( i=0;i<coocur_matrix.size();i++)
{
        for(j=0;j<coocur_matrix.size();j++)
            col_sum[j]+=coocur_matrix[i][j];
}
    for(i=0;i<coocur_matrix.size();i++)
        for(j=0;j<coocur_matrix.size();j++)
            normalized_matrix[i][j]=(double)coocur_matrix[i][j]/col_sum[j];

cout<<normalized_matrix[0][0]<<endl;

int sum;
for(size_t i=0;i<coocur_matrix.size();i++)
    sum+=coocur_matrix[i][0];
cout<<(double)coocur_matrix[0][0]/sum<<endl;

    /* Your code here */
}

/**
 * @brief save the normalized co-occurrence matrix to a file. The first line should be the words which each row represents.
 * each number is separated by a space.
 * e.g.:
 * a b c d
 * 0.2 0 0.6 0.2
 * 0 0.5 0.5 0
 * 0.6666666666666666 0.3333333333333333 0 0
 * 0 0 0 1
 * 
 * @param filename      file name of the output file
 * @param matrix        normalized co-occurrence martix
 * @param word_index    map of word to index
 */
void save_matrix(const string& filename, const vector<vector<int>>& matrix, const map<string, int>& word_index) {

    
    ofstream file;
    file.open(filename);
    map<string,int >::const_iterator iter=word_index.begin();
    while(iter!=word_index.end())
        {
            file<<iter->first<<' ';
        iter++;
        }//output the words
    file<<endl;

    size_t size=matrix.size();
    size_t i=0,j=0;
    for(i=0;i<size;i++)//out put the matrix
       { 
           for(j=0;j<matrix[i].size();j++)
            file<<matrix[i][j]<<" ";
        file<<endl;
       }
       file.close();

    // TODO: save the normalized_matrix to file `result.txt`. Notice that the first row should be the words.
    /* Your code here */
}

/**
 * @brief restore the normalized co-occurrence matrix from file `filename`.
 * Assume that the file is in the same format as the one in `save_matrix` function.
 * e.g.:
 * 0.2 0 0.6 0.2
 * 0 0.5 0.5 0
 * 0.6666666666666666 0.3333333333333333 0 0
 * 0 0 0 1
 * 
 * @param filename    file name of the input file
 * @param matrix      normalized co-occurrence martix
 * @param index_word  map of index to word
 */
void restore_matrix(const string& filename, vector<vector<double>>& matrix, map<int, string>& index_word) {
    ifstream file;
    file.open(filename);//open the file
    file.seekg(0,ios::beg);

    int i=0;
    string word;
    getline(file,word);//get the first line
    vector<string> words;
    split_string(word,words);//split the first line into the words
    vector<string>::iterator it_w=words.begin();
    while(it_w!=words.end())//make the index_word map
    {
        index_word[i]=*it_w;
        it_w++;
        i++;
    }
    matrix.clear();
    matrix = vector<vector<double>>(index_word.size(), vector<double>(index_word.size(), 0.0));//summarize the matrix
    size_t size=matrix.size();
    size_t i1=0,j=0;
    string doub;//store the input string

    for(i1=0;i1<size;i1++)//input the matrix
    { 
        for(j=0;j<size;j++)
            {  file>>doub;
                matrix[i1][j]=stod(doub);
            }
    }

    // hint: you can refer to the `set_word_index` function and `split_string` function.
    /* Your code here */
    return;
}

/**
 * @brief calculate the cosine similarity of word i and word j
 * you can calculate the cosine similarity by using the formula:
 * cosine_similarity = sum(matrix[i][k]*matrix[j][k]) / (sqrt(sum(matrix[i][k]^2)) * sqrt(sum(matrix[j][k]^2)))
 * if you can not understand the formula, please refer to the lab notes.
 * 
 * @param matrix    normalized co-occurrence martix
 * @param i         index of word i
 * @param j         index of word j
 * @return double   cosine similarity of word i and word j
 */
double similarity(const vector<vector<double>>& matrix, size_t i, size_t j) {
    

    /* Your code here */
    double res;

    size_t size=matrix.size();
    size_t k=0;
    double sum=0.0;
    for(k=0;k<size;k++)//calculate the inner product
        sum+=matrix[i][k]*matrix[j][k];
    
    double modi=0.0,modj=0.0;
    for(k=0;k<size;k++)//calculate the mod
    {
        modi+=(matrix[i][k]*matrix[i][k]);
        modj+=(matrix[j][k]*matrix[j][k]);
    }
    modi=sqrt(modi);
    modj=sqrt(modj);
    res=(double)sum/(modi*modj);
    
    return res == 0 ? 0 : res;
}

/**
 * @brief find the 5 most similar words to the given word. If there are less than 5 words, then simply return all of them.
 * You should sort them by the similarity score in descending order.
 * If they have the same similarity score, then sort them by the alphabetical order.
 * 
 * @param word                  given word
 * @param matrix                normalized co-occurrence martix
 * @param index_word            map of index to word
 * @return vector<string>       vector of 5 most similar words
 */
vector<string> most_similar(const string& word, const vector<vector<double>>& matrix, const map<int, string>& index_word) {
    int count=0;
    map<int,string>::size_type size,k,j;
        double ss=0.0;
    size_t in;
    for(in=0;in<index_word.size();in++)
    {
        ss+=matrix [in][1500];
    }
    cout<<"ss is "<<ss<<endl;

    size=index_word.size();
    int wordnum=-1;
    for(k=0;k<size;k++)//find the number which reflects the word
    {
        if(index_word.find(k)->second==word)
            wordnum=k;
    }
    //cout<<"word num"<<wordnum<<endl;
    
    // TODO: implement this function. 
    /* Your code here */

    if(wordnum==-1)//return if the word is not found
   { cerr << "Error: cannot find word " << word << endl;
    return vector<string>();
   }
    size_t i;
    vector<pair<int,double>> m_sim;
    double sim;
    for(i=0;i<size;i++)//store the similarities
    {
        if(i!=wordnum)
        {sim=similarity(matrix,wordnum,i);
        
        m_sim.push_back(make_pair(i,sim));}

    }

    sort(m_sim.begin(),m_sim.end(),[](pair<int ,double> x , pair<int,double>y)-> bool {return x.second>y.second;});//sort the similarities
   auto a=m_sim.begin();
   a++;
   cout<<a->second<<" "<<a->first<<endl;

    vector<string> result;

    vector<pair<int,double>>::iterator iter=m_sim.begin();
    while(count<5)//store the words
    {
        result.push_back(index_word.find(iter->first)->second);
        iter++;
        count++;
    }
    return result;
}

/**
 * @brief train the model.
 * 
 * @param n             hyperparameter `n`
 * @param filename      file name of the dataset file
 */
void train(const int& n, const string& filename) {
    record_words(filename, words);          // record all words
    cout << "done with record_words" << endl;
    // padding the words vector with word `<unk>`
    for (auto i = 0; i < n - 1; i++) {
        words.insert(words.begin(), "<unk>");
    }
    record_freq(words, freq);                               // record the frequency of each word
    cout << "done with record_freq" << endl;
    for (auto i = 0; i < n - 1; i++) {
        words.insert(words.end(), "<unk>");
    }
    filter_words(freq, words);                              // filter the less frequent words by replacing them by `<unk>`
    cout << "done with filter_words" << endl;
    set_word_index(words, word_index);                      // store the index of the word in the matrix
    cout << "done with set_word_index" << endl;
    set_coocur_matrix(words, word_index, coocur_matrix, n); // store the co-occurrence matrix
    cout << "done with set_coocur_matrix" << endl;
    normalize_matrix(coocur_matrix, normalized_matrix);     // normalize the matrix

    // Now we have the 	normalized co-occurrence matrix, we can use it to do some cool stuff.
    // We want to save the normalized matrix to a file, so that we can use it later.
    save_matrix("matrix.txt", coocur_matrix, word_index);
    cout<<"success"<<endl;
    return;
}

void test(const string& testfile, const string& matrix_file) {
    restore_matrix(matrix_file, normalized_matrix, index_word);
    // Now you should try to use the normalized matrix to find the most similar words.
    // We believe that the more similar the words are, the more likely they have the same context.
    // In this case, you can use this method to find the most similar words.
    ifstream file(testfile);                             // open the test file
    if (!file.good()) {
        cerr << "Error: cannot open file " << testfile << endl;
        exit(1);
    }
    string word;
    // first, we read the words from the test file. Each row of the test file is a word.
    vector<string> test_words;
    while (getline(file, word)) {
        test_words.emplace_back(word);
    }
    file.close();
    // Now, we shall find the 5 most similar words for each word in the test file.
    ofstream outfile("output.txt");
    if (!outfile.good()) {
        cerr << "Error: cannot open file output.txt" << endl;
        exit(1);
    }
    for (auto w : test_words) {
        auto vec = most_similar(w, normalized_matrix, index_word);
        for (auto item : vec) {
            outfile << item << " ";
        }
        outfile << endl;
    }
    outfile.close();
    
    return;
}

int main(int argc, const char** argv) {
    argc=4;
    argv[1]="--train";
    argv[2]="5";
    argv[3]="wikitext.txt";
    

    if (strcmp(argv[1], "--train") != 0 && strcmp(argv[1], "--test") != 0) {
        cout << "Invalid input" << endl;
        cout << "Usage: ./n_gram --train <n> <input file>" << endl;
        cout << "       ./n_gram --test <test file> <matrix file>" << endl;
        return 1;
    }
    if (strcmp(argv[1], "--train") == 0) {
        if (argc != 4) {
            cout << "Invalid input" << endl;
            cout << "Usage: .n_/gram --train <n> <input file>" << endl;
            return 1;
        }
        int n = stoi(argv[2]);                  // hyperparameter `n`
        string filename = argv[3];              // the input file name
        train(n, filename);
    }
    else {
        if (argc != 4) {
            cout << "Invalid input" << endl;
            cout << "Usage: ./n_gram --test <test file> <matrix file>" << endl;
            return 1;
        }
        string test_file = argv[2];
        string matrix_file = argv[3];
        test(test_file, matrix_file);
    }
    string str;
    return 0;
}