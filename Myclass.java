import java.util.*;

public class Myclass {
    static {
        System.loadLibrary("hello"); // Load library
     }
     // Declare an instance native method 
     private native void sayHello();
     private native boolean isPalindrome(String str);
     public static void main(String[] args) {

        Myclass m = new Myclass();
        m.sayHello();  // Create an instance and invoke the native method

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
