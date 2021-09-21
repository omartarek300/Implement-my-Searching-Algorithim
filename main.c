#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "functions.h"
int main()
{
    uint32_t arr[size], num;
    printf("Enter array elements:\n");
    for(uint8_t num_index=0; num_index < size; num_index++) // get array element from user
    {
        scanf("%d",&arr[num_index]);
    }
    printf("Enter the desired number:\n"); // get the number from user
    scanf("%d",&num);
    uint32_t result = binarySearch(arr, size, num);
    printf("Sorted array: ");
    print_array(arr, size);
    if(result == number_not_found)                   // check the result of the binary search function
    {
        printf("\nNOT FOUND\n");
    }
    else
    {
        printf("\nFound and the index is (sorted array): %d\n", result);
    }

    return 0;
}
int8_t binarySearch(uint32_t* arr, uint8_t arr_size, uint32_t num)
{
    uint8_t min_index, start = 0, end =arr_size-1, mid = (start+end)/2 ;
    for(uint8_t num_index =0; num_index < arr_size-1; num_index ++) // to check if array is sorted in ascending
    {
        if(arr[num_index+1] > arr[num_index])
        {
            sortingflag = sorted;
        }
        else
        {
            sortingflag = not_sorted;
            break;
        }
    }
    if(sortingflag == not_sorted)
    {
        for(uint8_t num_index=0; num_index < arr_size-1; num_index++) // sort array using selection sort algorithm
        {
            min_index = num_index;
            for(uint8_t sub_num_index = num_index+1; sub_num_index < arr_size; sub_num_index++)
            {
                if(arr[sub_num_index] < arr[min_index])
                {
                    min_index = sub_num_index;         // save the index of the smallest number in array
                }
            }
            if(num_index != min_index)
            {
                swap(&arr[min_index], &arr[num_index]);
            }
        }
        sortingflag = sorted;
    }
    //find number using binary search
    while(start <= end)
    {
        mid = start+(end - start)/2;
        if(arr[mid] == num)
        {
            return mid; // number is found
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
    // if the number doesn't exist return not found
    return number_not_found;
}
void swap(uint32_t* num1, uint32_t* num2) // function to swap two numbers
{
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}
void print_array(uint32_t* arr, uint8_t arr_size) // to print elements of array
{
    for(uint32_t num_index=0; num_index < arr_size; num_index++)
    {
        printf("%d ",arr[num_index]);
    }
}
