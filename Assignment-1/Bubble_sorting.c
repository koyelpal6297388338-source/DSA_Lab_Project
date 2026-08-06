#include <stdio.h>

int main() {
    int marks[10] = {99, 85, 58, 71, 46, 80, 78, 65, 49, 55};
    int i, j, temp;

    
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (marks[j] > marks[j + 1]) {
                temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }


    printf("Marks in ascending order:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", marks[i]);
    }

    return 0;
}