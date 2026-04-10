#include <stdio.h>

void insertion_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main()
{
    int array[] = {1, 2, 4, 6, 7, 9, 8, 5, 3};
    int length = sizeof(array)/sizeof(array[0]);
    insertion_sort(array, length);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}