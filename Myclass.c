#include <jni.h>        // JNI header provided by JDK
#include <stdio.h>      // C Standard IO Header
#include "Myclass.h"   // Generated header 

// Implementation of the native method sayHello()
JNIEXPORT void JNICALL Java_Myclass_sayHello(JNIEnv *env, jobject thisObj)
{
   printf("Hello World!\n");
   return;
}

//question 1 check palindrome function
JNIEXPORT jboolean JNICALL Java_Myclass_isPalindrome(JNIEnv *env,  jobject obj, jstring prompt)
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

//question 4 -- calling static and member methods
JNIEXPORT void JNICALL Java_Myclass_accessDetails(JNIEnv *env, jobject obj)
{   
   //get the class
   jclass thisClass = (*env)->GetObjectClass(env, obj);
 
   // Get the Method ID for method "accessDetails", which takes no arg and return void
   jmethodID printDetails = (*env)->GetMethodID(env, thisClass, "printDetails", "()V");

   if (printDetails == NULL) //handle errors
   {
      return;
   }
   //call method
   (*env)->CallVoidMethod(env, obj,  printDetails);

   //get id of static method "printDetails" that takes no arg and return void
   jmethodID printAddress = (*env)->GetStaticMethodID(env, thisClass,"printAddress", "()V");

   if (NULL == printAddress) 
   {    
     return;
   }
   //call static method
   (*env)->CallStaticObjectMethod(env, thisClass, printAddress);
}

//Question 5 --- modify member methods
JNIEXPORT void JNICALL Java_Myclass_modifyDetails(JNIEnv *env, jobject obj)
{   
    //get the class
    jclass thisClass = (*env)->GetObjectClass(env, obj);
    
    //get id of data members (String variable)
    jfieldID fidName = (*env)->GetFieldID(env, thisClass, "name", "Ljava/lang/String;");
    jfieldID fidUniversity = (*env)->GetFieldID(env, thisClass, "university", "Ljava/lang/String;");
    jfieldID fidBranch = (*env)->GetFieldID(env, thisClass, "branch", "Ljava/lang/String;");
    
    if((fidName==NULL)||(fidUniversity==NULL)||(fidBranch==NULL))//handle errors
    {
        return;
    }
 
    // Get the data members using the Field ID
    jstring name = (*env)->GetObjectField(env, obj, fidName);
    jstring university = (*env)->GetObjectField(env, obj, fidUniversity);
    jstring branch = (*env)->GetObjectField(env, obj, fidBranch);
 
    // Create a C-string with the JNI String
    const char *strName = (*env)->GetStringUTFChars(env, name, NULL);
    const char *strUniversity = (*env)->GetStringUTFChars(env, university, NULL);
    const char *strBranch = (*env)->GetStringUTFChars(env, branch, NULL);

    if ((strName==NULL)||(strUniversity==NULL)||(strBranch==NULL))//handle errors
    { 
        return;
    }
    
    //free the memory of the old strings
    (*env)->ReleaseStringUTFChars(env, name, strName);
    (*env)->ReleaseStringUTFChars(env, university, strUniversity);
    (*env)->ReleaseStringUTFChars(env, branch, strBranch);

    // Create a new C-string and assign to the JNI string
    name = (*env)->NewStringUTF(env, "Suruchi");
    university = (*env)->NewStringUTF(env, "VNIT NAGPUR");
    branch = (*env)->NewStringUTF(env, "COMPUTER SCIENCE");

    if ((name==NULL)||(university==NULL)||(branch==NULL))//handle errors
    {
        return;
    }
 
    // modify the data members
    (*env)->SetObjectField(env, obj, fidName, name);
    (*env)->SetObjectField(env, obj, fidUniversity, university);
    (*env)->SetObjectField(env, obj, fidBranch, branch);

    //STATIC MEMEBERS
    //get static members
    jfieldID fidPinCode = (*env)->GetStaticFieldID(env, thisClass, "pinCode", "I");
    jfieldID fidCity = (*env)->GetStaticFieldID(env, thisClass, "city", "Ljava/lang/String;");

    if ((fidPinCode==NULL)||(fidCity==NULL)) //handle errors
    {
        return;
    }
    //get sataic members form field id
    jint pinCode = (*env)->GetStaticIntField(env, thisClass, fidPinCode);
    jstring city = (*env)->GetStaticObjectField(env, thisClass, fidCity);

    //get string
    const char *strCity = (*env)->GetStringUTFChars(env, city, NULL);
   
     //free the memory of the old strings
    (*env)->ReleaseStringUTFChars(env, city, strCity);

    //modify pincode
    pinCode = 100045;
    // Create a new C-string and assign to the JNI string
    city = (*env)->NewStringUTF(env, "Kanker");

    //set new value for static members
    (*env)->SetStaticIntField(env, thisClass, fidPinCode, pinCode);
    (*env)->SetStaticObjectField(env, thisClass, fidCity, city);
}