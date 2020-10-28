import java.util.*;

public class Myclass {

    private static String city = "Nagpur";
    private static int pinCode = 440034;
    private String name;
    private String university;
    private String branch;

    static{
        System.loadLibrary("hello"); // Load library
    }

    //construtor
    Myclass(String name,String university,String branch)
    {
        this.name = name;
        this.university = university;
        this.branch = branch;
    }

    //static method to print pincode and city

    public static void printAddress() {
        System.out.println("\nAddress Details:\n");
        System.out.println("City Name:"+city+"\n");
        System.out.println("Pin Code:"+pinCode+"\n");
    }

    //object method to print data members

    public void printDetails() {
        System.out.println("\nPerson Details:\n");
        System.out.println("Name:"+this.name+"\n");
        System.out.println("University:"+this.university+"\n");
        System.out.println("Branch:"+this.branch+"\n");
    }

     // Declare an instance native method 
     private native void sayHello();
     private native boolean isPalindrome(String str);
     private native void accessDetails();
     private native void modifyDetails();
     public static void main(String[] args) {

        Myclass m = new Myclass("Kunal","VNIT","CSE");
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

        //Question 4

        m.accessDetails();

        //Question 5

        m.modifyDetails();
        m.accessDetails();

     }
}
