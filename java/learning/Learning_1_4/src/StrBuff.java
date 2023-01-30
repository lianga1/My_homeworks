public class StrBuff {
    public static void main(String[] args){
        StringBuilder sb = new StringBuilder("Hello");
        sb.append(" World");// sb = "Hello World"
        System.out.println(sb);
        sb.insert(5, " Java");// sb = "Hello Java World"
        System.out.println(sb);
        sb.delete(5, 10);// sb = "Hello World"
        System.out.println(sb);
        sb.reverse();// sb = "dlroW olleH"
        System.out.println(sb);
        sb.replace(0, 5, "Hello");// sb = "Hello olleH"
        System.out.println(sb);
        sb.setCharAt(0, 'h');// sb = "hello olleH"
        System.out.println(sb);
        sb.setLength(5);// sb = "hello"
        System.out.println(sb);
        sb.ensureCapacity(100);// sb = "hello"
        System.out.println(sb.capacity());// 100
        sb.trimToSize();// sb = "hello"
        System.out.println(sb.capacity());// 5
    }
}//in a word, string buffer can do everything string can do, but it is mutable.
//and stringbuilder is the same as stringbuffer, but it is not thread safe. but faster.