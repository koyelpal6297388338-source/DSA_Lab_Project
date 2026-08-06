/*write a program to take input in array 10 unordered number and apply
quicksort to order the array in ascending order .
Input: array size=10
Array items= [8,2,10,6,5,12,18,9,4,11]
*/
#include <stdio.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j, temp;

    for(j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    int arr[10] = {8, 2, 10, 6, 5, 12, 18, 9, 4, 11};
    int i;

    printf("Original Array:\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, 9);

    printf("\n\nSorted Array in Ascending Order:\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}