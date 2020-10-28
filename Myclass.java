public class Myclass {
    static {
        System.loadLibrary("hello"); // Load library
     }
     // Declare an instance native method 
     private native void sayHello();
   
     public static void main(String[] args) {
        new Myclass().sayHello();  // Create an instance and invoke the native method
     }
}
