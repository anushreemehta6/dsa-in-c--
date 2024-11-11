#include<stdio.h>
#include<stdlib.h>
int main(){
    // creation || initialization 
    int a[5]={1,2,6};
    //insertion
    int item , pos;
    printf("Enter the element you wan to add: ");
    scanf("%d",&item);
    printf("Enter the position: ");
    scanf("%d",&pos);
    for(int i=4;i>=pos;i--){
        a[i+1]=a[i];
    }
    a[pos]=item;
    printf("The element after insertion: ");
    for(int i=0;i<=4;i++){
        printf("%d \n",a[i]);
    }
    //deletion
    int loc;
    printf("enter the pos which you want to delete :");
    scanf("%d",&loc);
    for(int i=loc;i<=4;i++){
        a[i]=a[i+1];
    }
     printf("The element after deletion : ");
    for(int i=0;i<=4;i++){
        printf("%d \n",a[i]);
    }
    //seaching 
    int se;
    printf("enter the element you want to search: ");
    scanf("%d",&se);
    for(int i=0;i<=4;i++){
        if(se==a[i]){
            printf("element found at position %d",i);
        }
       
    }
}