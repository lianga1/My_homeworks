import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class stream {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("please input a character");
        char c= (char)br.read();
        System.out.println(c);

    }

}