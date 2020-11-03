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
     private native void accessDetails();
     private native void modifyDetails();
     public static void main(String[] args) {

        Myclass m = new Myclass("Kunal","VNIT","CSE");
    
    
        //Question 4

        System.out.println("accesing details from native method :\n");
        m.accessDetails();

        //Question 5

        System.out.println("calling native method which modifies details:\n");
        m.modifyDetails();

        System.out.println("modified details :\n");
        m.accessDetails();

     }
}
