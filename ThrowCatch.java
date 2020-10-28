/*There are generally two ways to handle an exception in JNI side.

    The first approach is to free the resources allocated at JNI and return. This will leave the 
    responsibility of handling the exception to the caller of the native method.
    catchThrow() handles NullPointerException from any jni function by using the first approach.

    The second practice is to clear the exception and continue executing. This is done through the 
    following JNI function call: void ExceptionClear(JNIEnv *env);
    catchThrow1() handles ArithmeticException from any jni function by using the second approach.
*/


public class ThrowCatch {
    private native void catchThrow() throws NullPointerException;
    private native void catchThrow1();
    private void callback() throws ArithmeticException {            //demo method to help show jni arithmetic exception handling
        throw new ArithmeticException("thrown in CatchThrow.callback");
      }
    public static void main(String args[]) {
        ThrowCatch c = new ThrowCatch();
        try {
          c.catchThrow();
        } catch (Exception e) {
          System.out.println("In Java:\n  " + e);
        }
        c.catchThrow1();
      }
      static {
        System.loadLibrary("throwcatch");
      }
}