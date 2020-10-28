// Save as "HelloJNI.c"
//#include <jni.h>        // JNI header provided by JDK
#include <stdio.h>      // C Standard IO Header
#include<stdlib.h>
#include "SortArray.h"   // Generated

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

JNIEXPORT jintArray JNICALL Java_SortArray_sortArray(JNIEnv *env, jobject obj, jintArray arr)
{
    jsize len = (*env)->GetArrayLength(env, arr);   // JNI function to get the length of the array
    int i, sum = 0;
    //int* temp=(int*)malloc(len*sizeof(int));
    int temp[len];
    jintArray result;
    result = (*env)->NewIntArray(env, len);
    //int a=3/0;
    jint *body = (*env)->GetIntArrayElements(env, arr, 0);      //JNI function to obtain a pointer to the individual elements of the array
    for (i=0; i<len; i++) {
        temp[i]=body[i];
    }
    printf("In Native function, Before sort(): ");
    printArray(temp,len);
    bubbleSort(temp,len);
    printf("In Native function, After sort(): ");
    printArray(temp,len);
    for(i=0;i<len;++i)
    {
        body[i]=temp[i];
    }
    (*env)->ReleaseIntArrayElements(env, arr, body, 0);     // JNI function to release the array memory

    // move from the temp structure to the java structure
    (*env)->SetIntArrayRegion(env, result, 0, len, temp);
    return result;
}