import java.util.*;
public class ScannerDemo {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("next方式接收：");
        nextDemo(scan);
        //clear the buffer
        scan.nextLine();
        System.out.println("nextLine方式接收：");
        nextLineDemo(scan);
    }
    public static void nextDemo(Scanner scan){
        //判断是否还有输入
        if(scan.hasNext()){
            String str1 = scan.next();
            System.out.println("输入的数据为："+str1);
        }
    }
    public static void nextLineDemo(Scanner scan){
        //判断是否还有输入
        if(scan.hasNextLine()){
            String str2 = scan.nextLine();
            System.out.println("输入的数据为："+str2);
        }
    }
}