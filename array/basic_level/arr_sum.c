/********************************************************/
/* Given an array of integers, find sum of its elements.*/
/* Examples :                                           */
/* Input : arr[] = {1, 2, 3}                            */
/* Output : 6                                           */
/* 1 + 2 + 3 = 6                                        */
/* Input : arr[] = {15, 12, 13, 10}                     */
/* Output : 50                                          */
/********************************************************/

#include "stdio.h"
#define ARRAY_SIZE 10
typedef int int32_t;
int arr_sum(int * a, int size)
{
    int32_t i, sum = 0;
    for(i=0; i< size; i++)
    {
       sum = sum + a[i];
    }
    return sum;
}

int main()
{
    int32_t arr[ARRAY_SIZE], i, sum; // taken 100 element array
    printf("Enter Array Elements:\n");
    for(i=0; i< ARRAY_SIZE; i++)
    {
      scanf("%d", &arr[i]);
    }
    sum = arr_sum(arr,ARRAY_SIZE);
    printf("Sum of Array is %d\n", sum);
    return 0;
}
