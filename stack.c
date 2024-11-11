#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
int top = -1, Stk[SIZE];
void push()
{
    if (top == SIZE)
    {
        printf("overflow");
    }
    printf("enter the element: ");
    int item;
    scanf("%d",&item);
    top=top+1;
    Stk[top]=item;
}
void pop(){
    if(top==-1){
        printf("underflow, no items to delete");
    }
    top=top-1;
    printf("delteion complete");
}
void show(){
    printf("the following stack is :");
    for(int i=top;i<SIZE;i--){
        printf( "%d",Stk[i]);
    }
}
int main(){
    int choice;
     while(1){
    printf("enter the choice");
    scanf("%d",&choice);
   

   
    switch(choice){
        case 1:
          push();
          break;
        case 2:
          pop();
          break;
        case 3:
          show();
          break;
        default:
        printf("wrong value input");

    }
     }
    
}
