/*A basic calculator needs to evaluate expression already written in postfix form requirements:
evaluate given postfix expression.
input 62+3* */
  #include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    top++;
    stack[top] = value;
}

int pop()
{
    int value;

    value = stack[top];
    top--;

    return value;
}

int evaluatePostfix(char exp[])
{
    int i;
    int a, b;

    for(i = 0; exp[i] != '\0'; i++)
    {
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            if(exp[i] == '+')
                push(a + b);

            else if(exp[i] == '-')
                push(a - b);

            else if(exp[i] == '*')
                push(a * b);

            else if(exp[i] == '/')
                push(a / b);
        }
    }

    return pop();
}

int main()
{
    char exp[MAX];
    int result;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}