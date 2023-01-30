public class Test {
    public static void main(String[] args){
        show(new Cat());
        show(new Dog());

        Animal a = new Cat();
        a.eat();
        Cat c = (Cat)a;
        c.work();
    }
    public static void show(Animal a){
        a.eat();
        if(a instanceof Cat c){
            c.work();
        }else if(a instanceof Dog d){
            d.work();
        }
    }
}

abstract class Animal{
    abstract void eat();
}
class Cat extends Animal{
    public void eat(){
        System.out.println("Cat eat fish");
    }
    public void work(){
        System.out.println("Cat catch mouse");
    }
}
class Dog extends Animal{
    public void eat(){
        System.out.println("Dog eat bone");
    }
    public void work(){
        System.out.println("Dog guard house");
    }
}