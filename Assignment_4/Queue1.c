/* A single screen cinema hall has one ticket counter.One customer arrives at a time.Simulate the ticket counter using queue.
The requirements are:
1.Add customers.
2.Serve customers. 
3.Show "housefull" if the sets are full.
4.Display all the customers.

Customer ids:
100
115
095
086*/
#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void addCustomer(int customer)
{
    if(rear == MAX - 1)
    {
        printf("Housefull! No more customers can be added.\n");
    }
    else
    {
        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = customer;

        printf("Customer %d added.\n", customer);
    }
}

void serveCustomer()
{
    if(front == -1 || front > rear)
    {
        printf("No customer to serve.\n");
    }
    else
    {
        printf("Customer %d served.\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;

    if(front == -1 || front > rear)
    {
        printf("No customers in queue.\n");
    }
    else
    {
        printf("\nCustomers in Queue:\n");

        for(i = front; i <= rear; i++)
        {
            printf("Customer %d\n", queue[i]);
        }
    }
}

int main()
{
    addCustomer(1);
    addCustomer(2);
    addCustomer(3);
    addCustomer(4);
    addCustomer(5);

    addCustomer(6);

    display();

    serveCustomer();
    serveCustomer();

    display();

    return 0;
}