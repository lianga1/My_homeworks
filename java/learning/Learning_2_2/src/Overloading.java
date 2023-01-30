public class Overloading {
    public int test(){
        System.out.println("test1");
        return 1;
    }
    public void test(int a){
        System.out.println("test2");

    }
    // Overloaded test
    public String test(int a, String b){
        System.out.println("test3");
        return "return test3";
    }
    public String test(String a, int b){
        System.out.println("test4");
        return "return test4";
    }
    public static void main(String[] args){
        Overloading o= new Overloading();
        System.out.println(o.test());
        o.test(1);
        System.out.println(o.test(1, "test3"));
        System.out.println(o.test("test4", 1));
    }
}
