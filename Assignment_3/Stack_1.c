/*Consider a bookrack where the books one placed in stack. Each book have acc_no (1, 2,3...) If you are asked to place book in stack using acc_no and take the back from stack using acc_no. How you perform these two operations on stack of books. The sequence of operation is given here PUSH(1), PUSH(2), POP(3), PUSH(4), PUSH(5), POP(5). Display the final position of the stack. */
#include <stdio.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int acc_no)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = acc_no;
        printf("PUSH(%d)\n", acc_no);
    }
}

void pop(int acc_no)
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else if(stack[top] != acc_no)
    {
        printf("POP(%d) not possible - %d is at the top\n",
               acc_no, stack[top]);
    }
    else
    {
        printf("POP(%d)\n", acc_no);
        top--;
    }
}

void display()
{
    int i;

    printf("\nFinal Stack:\n");

    for(i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    push(1);
    push(2);
    pop(3);
    push(4);
    push(5);
    pop(5);

    display();

    return 0;
}