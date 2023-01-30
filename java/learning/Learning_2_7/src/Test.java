enum Color{
    RED {
        public String getColor(){
            return "R";
        }
    },
    GREEN {
        public String getColor(){
            return "G";
        }
    },
    BLUE {
        public String getColor(){//枚举对象实现抽象方法
            return "B";
        }
    };
    public abstract String getColor();
}
public class Test{
    public static void main(String[] args) {
        for (Color c:Color.values()){
            System.out.print(c.getColor() + "、");
        }
    }
}