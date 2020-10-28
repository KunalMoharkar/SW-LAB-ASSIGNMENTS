import java.util.Scanner;

public class SortArray {  // Save as HelloJNI.java
   static {
      System.loadLibrary("sortarray"); // Load native library sortarray.dll (Windows) or libsortarray.so (Unixes)
                                   //  at runtime
                                   // This library contains a native method called sortArray()
   }
 
   // Declare an instance native method sortArray() which receives no parameter and returns void
   private native int[] sortArray(int[] arr);
 
   // Test Driver
   public static void main(String[] args) {
       try {
           // int arr[]={3,2,1};
            Scanner s=new Scanner(System.in);

            System.out.println("enter number of elements");

            int n=s.nextInt();

            int arr[]=new int[n];

            System.out.println("enter elements");

            for(int i=0;i<n;i++){//for reading array
                arr[i]=s.nextInt();

            }

            int sortedarr[]=new SortArray().sortArray(arr);  // Create an instance and invoke the native method
            //int len=arr.length;
            System.out.println("In SortArray.java, after caling native method result:");
            for(int ele:sortedarr)
            {
                System.out.print(ele+" ");
            }
            s.close();
            
       } catch (ArithmeticException | NullPointerException e) {
           //TODO: handle exception
           System.out.println("Exception!! "+e.getMessage());
       }
       
      
   }
}