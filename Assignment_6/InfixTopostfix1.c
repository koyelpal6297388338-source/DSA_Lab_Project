/*A simple calculator receives an infix expression. It must :
1. Convert infix expression to postfix
2. Evaluate the postfix expression. 
Sample input : 3+4*5*/
 #include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int precedence(char x)
{
    if(x == '+' || x == '-')
        return 1;

    if(x == '*' || x == '/')
        return 2;

    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char x;

    for(i = 0; infix[i] != '\0'; i++)
    {
        if(isdigit(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else
        {
            while(top != -1 &&
                  precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j++] = pop();
            }

            push(infix[i]);
        }
    }

    while(top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[])
{
    int s[MAX];
    int t = -1;
    int i, a, b;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        if(isdigit(postfix[i]))
        {
            s[++t] = postfix[i] - '0';
        }
        else
        {
            b = s[t--];
            a = s[t--];

            switch(postfix[i])
            {
                case '+':
                    s[++t] = a + b;
                    break;

                case '-':
                    s[++t] = a - b;
                    break;

                case '*':
                    s[++t] = a * b;
                    break;

                case '/':
                    s[++t] = a / b;
                    break;
            }
        }
    }

    return s[t];
}

int main()
{
    char infix[MAX], postfix[MAX];
    int result;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}



