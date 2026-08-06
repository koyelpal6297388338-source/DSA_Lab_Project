/*Write a program to take input marks of ten students randomly in an array,sort the array using mergesort and show the highest and lowest marks. Input size=10. Array items=[80,73,59,92,86,47,92,58,91,48]*/
#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
    int temp[10];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int marks[10] = {80, 73, 59, 92, 86, 47, 92, 58, 91, 48};
    int i;

    mergeSort(marks, 0, 9);

    printf("Sorted Marks:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", marks[i]);
    }

    printf("\n\nLowest Marks = %d", marks[0]);
    printf("\nHighest Marks = %d", marks[9]);

    return 0;
}