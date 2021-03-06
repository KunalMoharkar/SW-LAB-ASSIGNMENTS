#include <jni.h>        // JNI header provided by JDK
#include <stdio.h>      // C Standard IO Header
#include "Myclass.h"   // Generated header 

JNIEXPORT jboolean JNICALL Java_Palindrome_isPalindrome(JNIEnv *env,  jobject obj, jstring prompt)
{
    int i,j;
    const char *str = (*env)->GetStringUTFChars(env, prompt, 0); //get string

    i = 0;

    while(str[i]!='\0') //reach the end of string
    {
        i++;
    }

    j = 0;
    i--;

    while(j<i) //check palindrome
    {
        if(str[j]!=str[i])
        {
            return 0; //not a plaindrome
        }
        j++;
        i--;
    }

    return 1;  //palindrome 
}