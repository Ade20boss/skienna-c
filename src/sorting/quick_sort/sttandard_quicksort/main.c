#include <stdio.h>


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void standard_quicksort(int *arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int left = low;
    int right = high - 1;
    int pivot = arr[high];

    while (left <= right)
    {
        while (left <= right && arr[left] < pivot)
        {
            left++;
        }

        while (left <= right && arr[right] > pivot)
        {
            right--;
        }

        if (left <= right)
        {
            swap(&arr[left], &arr[right]);
            left++; right--;
        }
    }

    swap(&arr[high], &arr[left]);

    standard_quicksort(arr, low, left -1);
    standard_quicksort(arr, left+1, high);


}




int main() {
    int length = 40000;
    int array[length];
    
    // THE MALICIOUS PAYLOAD: A perfectly sorted array
    for(int i = 0; i < length; i++) {
        array[i] = i; 
    }

    standard_quicksort(array, 0, length - 1);
    
    printf("Standard Engine: Sorted %d items.\n", length);
    return 0;
}