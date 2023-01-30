public class Str {
    public static void main(String[] args){
        String s1 = "Hello";
        String s2 = "Hello";
        String s3 = s1;
        String s4 = new String("Hello");
        String s5 = new String("Hello");
        System.out.println(s1 == s2);
        System.out.println(s1 == s3);
        System.out.println(s1 == s4);
        System.out.println(s1 == s5);
        System.out.println(s4 == s5);
        System.out.printf("s1 = %s\n", s1);
        String fs = String.format("s1 = %s", s1);
        System.out.println(fs);
    }
}
/*
* result:
* true
* true
* false
* false
* */