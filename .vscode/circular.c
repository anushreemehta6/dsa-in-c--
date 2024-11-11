#include<stdio.h>
#include<stdlib.h>
#define Size 5
int front=-1,rear=-1,Que[Size];
void push(){
   int s;
   printf("enter the number to add: ");
   scanf("%d",&s);
   if((rear+1)%Size==front){
    printf("overflow");
   }
   else if((front==-1&&rear==-1)||(rear = front-1)){
    front=0;
    rear=0;
   }
   else{
    rear = rear+1;
   }
   Que[rear]=s;
   printf("insertion done ");
}
void pop(){
    if(front==-1&&rear==-1){
        printf("underflow");
    }
    if(front=rear){
        front=-1;
        rear=-1;
    }
    else{
        front=front+1;
    }
}
void show(){
    printf("the following queue is : ");
    for(int i=front;i<=rear;i++){
        printf("%d\n",Que[i]);
    }
}
int main(){
  int choice;
  while(1){
    printf("enter the choices");
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
        printf("invalide");
    }
  }
  return 0;

}