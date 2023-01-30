import java.util.Arrays;
public class Arr {
    public static void main(String[] args){
        int[] arr = {1,2,9,4,5,6,7,8,9,10};
        int sum = 0;
        for(int x:arr){
            sum += x;
        }

        Arrays.sort(arr);
        System.out.println(Arrays.toString(arr));
    }
}