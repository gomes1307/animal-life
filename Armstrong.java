import java.util.Scanner;
public class Armstrong {
    public static void main(String[] args) {
        Scanner k = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int num = k.nextInt();

        int originalNumber = num; 

        int result = 0;
        int n = String.valueOf(num).length();

        while (num != 0) {
            int remainder = num % 10;
            result += Math.pow(remainder, n);
            num /= 10;
        }

        if (originalNumber == result) {
            System.out.println(originalNumber  + " is an Armstrong number.");
        } else {
            System.out.println(originalNumber + " is not an Armstrong number.");
        }
        k.close();
    }
}
