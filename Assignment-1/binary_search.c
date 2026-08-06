#include <stdio.h>
 int binarySearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return 1;   

        else if (arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return 0;   
}

int main()
{
    int productIds[] = {2, 8, 9, 16, 18, 26, 38, 48, 51, 90};
    int size = sizeof(productIds) / sizeof(productIds[0]);

    int key;

    printf("Enter Product ID to search: ");
    scanf("%d", &key);

    if (binarySearch(productIds, size, key))
        printf("True - Product ID %d found in catalog.\n", key);
    else
        printf("False - Product ID %d not found in catalog.\n", key);

    return 0;
}