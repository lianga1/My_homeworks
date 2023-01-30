import java.lang.Exception;
import java.io.*;
public class ExcepTest {
    public static void main(String[] args) {
        try {
            int a = 0;
            int b = 5 / a;
        } catch (ArithmeticException e) {
            System.out.println("Exception caught:"+e);
        }finally {
            System.out.println("Finally block executed");
        }
    }
}