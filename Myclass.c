#include <jni.h>        // JNI header provided by JDK
#include <stdio.h>      // C Standard IO Header
#include "Myclass.h"   // Generated header 

// Implementation of the native method sayHello()
extern JNIEXPORT void JNICALL Java_Myclass_sayHello(JNIEnv *env, jobject thisObj) {
   printf("Hello World!\n");
   return;
}