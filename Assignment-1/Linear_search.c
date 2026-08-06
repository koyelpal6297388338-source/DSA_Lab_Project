#include<stdio.h>
int main(){
int arr[]={101,20,49,385,210,620,85,921,12,206};
int n=10;
int search,i,flag=0;

printf("Enter the acc no to be search:");
scanf("%d",&search);

for(i=0;i<n;i++){
if(arr[i]==search){
    printf("Acces no found in position %d\n",i+1);
    flag=1;
    break;

}
}
if(flag==0){
    printf("Access no not found\n");
}
return 0;


}