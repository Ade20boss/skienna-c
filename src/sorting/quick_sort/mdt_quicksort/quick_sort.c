#include "quick_sort.h"
#include <stdio.h>


/* Swaps the values at two pointer addresses */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void quick_sort(int *arr, int low, int high)
{
    //return base case
    if (low >= high)
    {
        return;
    }
    //find the index of the median element
    int middle = (low + high)/2;
    //Arranging the three chosen element begin
    //First check ensures that arr[low] is smaller than arr[middle]
    if (arr[low] > arr[middle])
    {
        swap(&arr[low], &arr[middle]);
    }
    //Second check - Ensures that arr[low] is less than arr[high]
    //This locks arr[low] as the smallest
    if (arr[low] > arr[high])
    {
        swap(&arr[low], &arr[high]);
    }
    //Last check is to ensure that arr[middle] and arr[high] are correctly ordered
    if (arr[middle] > arr[high])
    {
        swap(&arr[middle], &arr[high]);
    }

    swap(&arr[middle], &arr[high]);

    //Instantiate our pointers and pivot
    int left_pointer = low; //starts at the beginning of current array
    int right_pointer = high - 1; //starts at the index to the left of pivot
    int pivot = arr[high]; //pivot becomes last element(shh, dont tell anyone; its actually the median of three)

    //Overaching manager - manages the search operation, makes sure the search operations continue if the pointers haven't crossed paths
    while(left_pointer <= right_pointer)
    {

        //left pointer search - halts immediately the left pointer crosses over; continues as
        //long as numbers don't meet criteria and it hasn't crossed over
        while (left_pointer <= right_pointer && arr[left_pointer] < pivot)
        {
            left_pointer++;
        }

        //right pointer search - halts immediately the left pointer crosses over; continues as
        //long as numbers don't meet criteria and it hasn't crossed over
        while (left_pointer <= right_pointer && arr[right_pointer] > pivot)
        {
            right_pointer--;
        }

        //immediately search operations pause, we need to swap and move pointers
        // but only if pointers haven't crossed paths
        if (left_pointer <= right_pointer)
        {
            swap(&arr[left_pointer], &arr[right_pointer]);
            right_pointer--;
            left_pointer++;
        }

    }

    //immediately search operations comes to an end, we need to lock the pivot in its place
    //Swap pivot with left_pointer
    swap(&arr[high], &arr[left_pointer]);

    //RECURSION - FUNCTION CALL FOR RIGHT AND LEFT HALVES OF ARRAY
    quick_sort(arr, low, left_pointer - 1);
    quick_sort(arr, left_pointer + 1, high);
}

int main() {
    int length = 40000;
    int array[length];
    
    // THE MALICIOUS PAYLOAD: A perfectly sorted array
    for(int i = 0; i < length; i++) {
        array[i] = i; 
    }

    quick_sort(array, 0, length - 1);
    
    printf("Standard Engine: Sorted %d items.\n", length);
    return 0;
}