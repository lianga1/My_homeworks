import java.io.*;

public class fstream {
    public static void main(String args[]) throws IOException {
        InputStream f = new FileInputStream("C:\\Users\\18381\\Desktop\\dev_env\\java\\Learning_1_9\\src\\hello.txt");
        int c=0;
        while(c!=-1){
            c=f.read();
            if(c==-1)
                break;
            System.out.print((char)c);
        }
        OutputStream w = new FileOutputStream("C:\\Users\\18381\\Desktop\\dev_env\\java\\Learning_1_9\\src\\bye.txt");
        char[] str= "welcome".toCharArray();
        for(char ch:str){
            w.write((char)ch);
        }

    }
}
