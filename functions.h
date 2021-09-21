#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define size 6
#define number_not_found -1
#define sorted 0
#define not_sorted 1

/************************************************ Global Variables ************************************************/
uint8_t sortingflag = 0;
/******************************************************************************************************************/

/************************************************* Function Delaration *****************************************/
/*******
	Function Description: this function sort the array in ascending way first then search for the desired number
	parameter: arr: the array entered by the user
               arr_size: size of the array
               num: the desired number user search for
	return: the number index in the array
*/
int8_t binarySearch(uint32_t* arr, uint8_t arr_size, uint32_t num);

/*******
	Function Description: this function swaps the position of two integer numbers in the memory
	parameter: num1: the first number
               num2: the second number
	return: none
*/
void swap(uint32_t* num1, uint32_t* num2);

/*******
	Function Description: this function prints all array element
	parameter: arr: the array we want to print its elements
               arr_size: size of the array
	return: none
*/
void print_array(uint32_t* arr, uint8_t arr_size);

/******************************************************************************************************************/

#endif // FUNCTIONS_H_INCLUDED
