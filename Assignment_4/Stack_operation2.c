/*
bank account keeping the transaction amount as it is processd  by customer.
The transtion amount of last customer is stored at top possition .After completition 
of all transaction the manager pull teh amount one by one and display the amount and find 
total _transaction amount to print
Define the following function:
push():to insert amount in
pop():to remove amount
dosum():find sum of all tramsaction amount

amount to be inserted in following order:1050,2090,3000,6000,5500,8900
*/
#include <stdio.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int amount)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = amount;
    }
}

int pop()
{
    int amount;

    if(top == -1)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    else
    {
        amount = stack[top];
        top--;
        return amount;
    }
}

int dosum()
{
    int sum = 0;

    while(top != -1)
    {
        sum = sum + pop();
    }

    return sum;
}

int main()
{
    int total;

    push(1050);
    push(2090);
    push(3000);
    push(6000);
    push(5500);
    push(8900);

    printf("Transaction amounts:\n");

    while(top != -1)
    {
        printf("%d\n", pop());
    }

    push(1050);
    push(2090);
    push(3000);
    push(6000);
    push(5500);
    push(8900);

    total = dosum();

    printf("\nTotal Transaction Amount = %d\n", total);

    return 0;
}