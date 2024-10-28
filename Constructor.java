public class Constructor {
    int id;
    String name;

   public  Constructor() {
        id = 4;
        name = "Alex";
    }

    public Constructor(int i ,String n ) {
        id = i;
        name = n;
    }

    void display() {
        System.out.println(id + " " + name);
    }

    public static void main(String[] args) {
        Constructor ob1 = new Constructor();
        Constructor ob2 = new Constructor(2, "Alex");
        ob1.display();
        ob2.display();
    }

}