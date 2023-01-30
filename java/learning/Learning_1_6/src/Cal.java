import java.util.*;
public class Cal {
    public static void main(String[] args) {
        Calendar c = Calendar.getInstance();
        c.set(2022, Calendar.JANUARY, 2);
        System.out.println(c.getTime());
    }
}
