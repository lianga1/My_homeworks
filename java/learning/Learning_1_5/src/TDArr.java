public class TDArr {
    public static void main(String[] args){
        String[][] s =new String[2][];
        s[0] = new String[2];
        s[1] = new String[3];
        s[0][0] = "Hello";
        s[0][1] = "World";
        s[1][0] = "Java";
        s[1][1] = "C#";
        s[1][2] = "C++";
        for(String[] x:s){
            for(String y:x){
                System.out.print(y+" ");
            }
            System.out.println();
        }
    }
}
