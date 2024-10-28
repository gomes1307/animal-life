import java.util.Scanner;
public class VC {
    public static void main(String[] args) {

        // Scanner object to read input
        Scanner sc = new Scanner(System.in);

        // Counter variables for vowels and consonants
        int v = 0, c = 0;

        // Prompt user for input and read the string
        System.out.print("Enter a string: ");
        String str = sc.nextLine();

        // Convert the string to lowercase for case-insensitive counting
        str = str.toLowerCase();

        // Loop through each character in the string
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            // Check if the character is a vowel
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                v++;
            } else if(ch >= 'a' && ch <= 'z') { // Check if it's a letter (consonant)
                c++;
            }
        }

        // Print the results
        System.out.println("Number of vowels: " + v);
        System.out.println("Number of consonants: " + c);
        sc.close();
    }
}
