import java.util.Scanner;
public class hello{
public static void main (String[] Args)
{
    Scanner Sc= new Scanner(System.in);

    int a;
    a =Sc.nextInt();
    double area = 3.1416*a*a;
    System.out.println(area);
    Sc.close();

}
}