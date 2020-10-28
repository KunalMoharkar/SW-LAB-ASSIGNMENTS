#include <jni.h>
#include "ThrowCatch.h"

JNIEXPORT void JNICALL Java_ThrowCatch_catchThrow(JNIEnv *env, jobject obj)
{
    /* We don't clear the exception here, we free the resource and throw
       that exception to the caller */
    jclass newExcCls;
    jboolean ifExceptionPending;

    newExcCls = (*env)->FindClass(env, "java/lang/NullPointerException");
    if (newExcCls == 0) { // Unable to find the new exception class, give up. 
      return;
    }
    jint st =(*env)->ThrowNew(env, newExcCls, "null pointer exception thrown from C code");
    if (st == 0) {
        printf("\nCheckDemo:1 null pointer exception thrown using ThrowNew\n");
        fflush(stdout);
        (*env)->DeleteLocalRef(env, newExcCls);
        //do not clear the exception, let the caller handle it
    }

}

JNIEXPORT void JNICALL Java_ThrowCatch_catchThrow1(JNIEnv * env, jobject obj)
{
    /*We clear the exception here and further check if anymore exceptions are pending or not*/
    jclass newExcCls;
    jboolean ifExceptionPending;
    jclass cls = (*env)->GetObjectClass(env, obj);

    /*Because CallVoidMethod throws a NullPointerException,
     the native code can detect this exception after CallVoidMethod returns by calling the method ExceptionCheck*/
     
    jmethodID mid = (*env)->GetMethodID(env, cls, "callback", "()V");       
    jthrowable exc;
    if (mid == 0) {
        return;
    }
    (*env)->CallVoidMethod(env, obj, mid);
    
    //use ExceptionCheck to check
    jboolean ifException =(*env)->ExceptionCheck(env);
    printf("\nExceptionCheck (suppose some jni method threw Arithmetic exception(such as divide by zero)): %d\n", ifException);
    fflush(stdout);

    (*env)->ExceptionClear(env);  //clear the exception, so we can proceed
    ifException =(*env)->ExceptionCheck(env);
    printf("\nExceptionCheck after clear: %d\n",ifException);
    fflush(stdout);

    //use ExceptionOccurred to check if any exception is still pending
    jthrowable exObj = (*env)->ExceptionOccurred(env);
    if (exObj == NULL) {
        printf("\nExceptionCheckDemo : no exception\n");
        fflush(stdout);
    } else {
        printf("\nExceptionCheckDemo : there's pending exception, call ExceptionDescribe\n");
        fflush(stdout);
        (*env)->ExceptionDescribe(env);   //this does not clear the exception

        ifExceptionPending =(*env)->ExceptionCheck(env);
        printf("\nExceptionCheckDemo : ExceptionCheck after ExceptionDescribe: %d\n",ifExceptionPending);
        fflush(stdout);

        (*env)->ExceptionClear(env);      //clear the exception, so we can proceed
        ifExceptionPending =(*env)->ExceptionCheck(env);
        printf("\nExceptionCheckDemo : ExceptionCheck after clear: %d\n",ifExceptionPending);
        fflush(stdout);
        (*env)->DeleteLocalRef(env, exObj);
    }
}