#include <stdio.h>
#include <stdlib.h>
struct Node {
    int studentID;
    struct Node*next;
};
struct Node*HEAD =NULL;
void createList(){
    int n,i,id;
    struct Node*newNode,*temp;
    printf("Enter number of students:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter student id:");
        scanf("%d",&id);
        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->studentID=id;
        newNode->next=NULL;
        if(HEAD==NULL)
        HEAD=newNode;
        else{
            temp=HEAD;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
}
void display()
{
    struct Node *temp;

    if(HEAD == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = HEAD;

    printf("\nStudent Records:\n");

    while(temp != NULL)
    {
        printf("Student ID: %d\n", temp->studentID);
        temp = temp->next;
    }
}

int main()
{
    createList();
    display();

    return 0;
}
