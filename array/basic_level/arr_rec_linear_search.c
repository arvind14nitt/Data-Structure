/*
Given an unsorted array and an element x, search x in given array. 
Write recursive C code for this. If element is not present, return -1
*/
#include "stdio.h"
typedef int int32_t;
#define ARR_SIZE 10
int32_t rec_search(int *a, int i, int key)
{
   if(i < 0 )
      return -1;
   if(a[i-1] == key)
      return i-1; // index of key
   return rec_search(a, i-1, key);
} 


int32_t main()
{
    int32_t index , arr[ ARR_SIZE ], i, key;
    printf("Enter the Array Elements:\n"); 
    for(i=0; i<ARR_SIZE; i++)
    {
      scanf("%d\n",&arr[i]);
    }  
    printf("Enter the Key to be searched in the Array\n");
    scanf("%d\n",&key);

    index = rec_search(arr,ARR_SIZE, key);
    if(index == -1)
    { 
      printf("Key not found in array\n");
    }
    else{

      printf("Key %d found at %d in array\n", key, index);
    }
    return 0;
}
