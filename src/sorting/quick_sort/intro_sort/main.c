#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    
}

void lazy_quicksort(int *arr, int low, int high)
{

    //return base case - lazy sorting, if array size is less than
    //16 items we do nothing
    if ((high - low) < 16)
    {
        return;
    }

    //Median of three calculation
    int middle = (low+high)/2;

    
    if(arr[low] > arr[middle])
    {
        swap(&arr[low], &arr[middle]);
    }

    if (arr[low] > arr[high])
    {
        swap(&arr[low], &arr[high]);
    }

    if(arr[middle] > arr[high])
    {
        swap(&arr[middle], &arr[high]);
    }

    swap(&arr[high], &arr[middle]);

    int left_pointer = low;
    int right_pointer = high - 1;
    int pivot = arr[high];

    while(left_pointer <= right_pointer)
    {
        while(left_pointer <= right_pointer && arr[left_pointer] < pivot)
        {
            left_pointer++;
        }

        while(left_pointer <= right_pointer && arr[right_pointer] > pivot)
        {
            right_pointer--;
        }

        if(left_pointer <= right_pointer)
        {
            swap(&arr[left_pointer], &arr[right_pointer]);
            left_pointer++; right_pointer--;
        }
    }

    swap(&arr[high], &arr[left_pointer]);

    lazy_quicksort(arr, low, left_pointer-1);
    lazy_quicksort(arr, left_pointer+1, high);

}

void introsort(int *arr, int length)
{

    lazy_quicksort(arr, 0, length-1 );
    insertion_sort(arr, length);
}





int main()
{

    size_t length = 300000000;
    int *array = malloc(length * sizeof(int));

    if (array == NULL)
    {
        return 1;
    }

    for (size_t i = 0; i < length; i++) 
    { 
        array[i] = length - i; 
    }

    introsort(array, length);

    printf("First element: %d\n", array[0]);
    printf("Second element: %d\n", array[1]);
    printf("Last element: %d\n", array[length - 1]);


    free(array);

    return 0; 
    
}