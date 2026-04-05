#include <stdio.h>

int *insertion_sort(int *arr, int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    return arr;
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