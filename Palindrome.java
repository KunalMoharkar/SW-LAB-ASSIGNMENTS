import java.util.*;


public class Palindrome {
    
    static{
        System.loadLibrary("hello"); // Load library
    }

    private native boolean isPalindrome(String str); //native method

    public static void main(String[] args) {

        Palindrome m = new Palindrome();


        //Question 1
    
        Scanner sc = new Scanner(System.in);  
        System.out.print("Enter String: ");  
        String str= sc.nextLine();  
        sc.close();

        if(m.isPalindrome(str))
        {
            System.out.println("Yes it is a Palindrome");
        }
        else
        {
            System.out.println("Not a Palindrome");
        }

    }

}
