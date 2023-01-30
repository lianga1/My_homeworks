public class AbstractDemo {
    public static void main(String[] args){
        Salary s = new Salary("Mohd Mohtashim", "Ambehta, UP", 3, 3600.00);
        Employee e = new Salary("George W.", "Houston, TX", 2,2400);
        System.out.println("\n Call mailcheck using Salary reference");
        s.mailCheck();
        System.out.println("\n Call mailcheck using Employee reference");
        e.mailCheck();
    }
}
