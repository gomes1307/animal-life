import java.util.Scanner;

public class palindrome{ // Improved class name

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.println("Enter an integer to check if it's a palindrome: ");
    int num = sc.nextInt();

    int originalNum = num; // Store original number for comparison
    int reversedNum = 0;

    // Efficiently reverse using while loop and modulo operator
    while (num != 0) {
      int digit = num % 10;
      reversedNum = reversedNum * 10 + digit;
      num /= 10;
    }

    if (originalNum == reversedNum) {
      System.out.println(originalNum + " is a palindrome.");
    } else {
      System.out.println(originalNum + " is not a palindrome.");
    }
    sc.close();
  }
}
