import java.io.File;

public class dir {
    public static void main(String[] args){
        String dirname="C:\\Users\\18381\\Desktop\\dev_env\\java\\Learning_1_9\\newdir";
        File d = new File(dirname);
        d.mkdirs();//create a directory

        String dn="C:\\Users\\18381\\Desktop\\dev_env\\java\\Learning_1_9";
        File f1=new File(dn);
        if(f1.isDirectory()){
            System.out.println("目录 " + dirname);
            String[] s = f1.list();
            assert s != null;
            for (String value : s) {
                File f = new File(dirname + "/" + value);
                if (f.isDirectory()) {
                    System.out.println(value + " 是一个目录");
                } else {
                    System.out.println(value + " 是一个文件");
                }
            }
        } else {
            System.out.println(dirname + " 不是一个目录");
        }//read the subdirectories

        //list for String[],listfile for File[]
        //File.delete can delete a file
        //File.deleteOnExit can delete a file when the program exits
    }
}
