#include <stdio.h>
#include <stdlib.h>
#include "types.h"
/********************** Function Delaration ********************/
int8_t binarySearch(uint32_t* arr, uint8_t size, uint32_t num);
void swap(uint32_t* num1, uint32_t* num2);
void print_array(uint32_t* arr);
/***************************************************************/
/********************** Global Variables ***********************/
uint8_t sortingflag = 0;
/***************************************************************/
int main()
{
    uint32_t arr[6], num;
    printf("Enter array elements:\n");
    for(int i=0; i<6; i++) // get array element from user
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the desired number:\n"); // get the number from user
    scanf("%d",&num);
    int8_t result = binarySearch(arr, 6, num);
    printf("Sorted array: ");
    print_array(arr);
    if(result == -1)                   // check the result of the binary search function
    {
        printf("\nNOT FOUND\n");
    }
    else
    {
        printf("\nFound and the index is (sorted array): %d\n", result);
    }

    return 0;
}
int8_t binarySearch(uint32_t* arr, uint8_t size, uint32_t num)
{
    uint32_t min_idx, start =0, end =size-1, mid = (start+end)/2 ;
    for(uint32_t c=0; c<size-1; c++) // to check if array is sorted in ascending
    {
        if(arr[c+1] > arr[c])
        {
            sortingflag = 0;
        }
        else
        {
            sortingflag = 1;
            break;
        }
    }
    if(sortingflag == 1)
    {
        for(uint32_t i=0; i<size-1; i++) // sort array using selection sort algorithm
        {
            min_idx=i;
            for(uint32_t j = i+1; j<size; j++)
            {
                if(arr[j] < arr[min_idx])
                {
                    min_idx = j;         // save the index of the smallest number in array
                }
            }
            if(i != min_idx)
            {
                swap(&arr[min_idx], &arr[i]);
            }
        }
        sortingflag =0;
    }
    //find number using binary search
    while(start <= end)
    {
        mid = start+(end - start)/2;
        if(arr[mid] == num)
        {
            return mid;
        }
        else if(arr[mid] < num) // if numbed is greater than mid-number then move the start to mid + 1 position
        {
            start = mid + 1;
        }
        else if(arr[mid] > num) // if numbed is smaller than mid-number then move the end to mid - 1 position
        {
            end = mid -1;
        }
    }
    return -1;
}
void swap(uint32_t* num1, uint32_t* num2) // function to swap two numbers
{
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}
void print_array(uint32_t* arr) // to print elements of array
{
    for(uint32_t i=0; i<6; i++)
    {
        printf("%d ",arr[i]);
    }
}
