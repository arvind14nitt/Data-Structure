/*
Given an array, find the largest element in it. 
Example: 
 

Input : arr[] = {10, 20, 4}
Output : 20

Input : arr[] = {20, 10, 20, 4, 100}
Output : 100
*/

#include "stdio.h"
#define ARRAY_SIZE 10
typedef int int32_t;
int32_t arr_max(int * a, int size)
{
    int32_t i, max = a[0];
    for(i=0; i< size; i++)
    {
       if(max < a[i] )
          max = a[i];
    }
    return max;
}

int32_t main()
{
    int32_t arr[ARRAY_SIZE], i, max; // taken 100 element array
    printf("Enter Array Elements:\n");
    for(i=0; i< ARRAY_SIZE; i++)
    {
      scanf("%d", &arr[i]);
    }
    max = arr_max(arr,ARRAY_SIZE);
    printf("Max of Array is %d\n", max);
    return 0;
}

