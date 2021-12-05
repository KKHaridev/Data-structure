#include <stdio.h>
#include <stdlib.h>
#define N 10
int a[20],top=-1;

void push(int x){
  if(top==N-1){
    printf("Stack overflow\n");
  }
  else{
    top++;
    a[top]=x;
    for(int i=0;i<=top;i++)
      printf("%d ",a[i]);
  }
}
void pop(){
  if(top==-1){
    printf("\nStack underflow\n");
  }
  else{
    int item=a[top];
    printf("%d is popped",item);
    top--;
  }
}

void display(){
  for(int i=0;i<=top;i++){
    printf("%d ",a[i]);
  }
}

void status(){
  if(top==-1){
    printf("\nNo elements\n");
  }
  else if(top==N-1){
    printf("\nFull\n");
  }
  else{
    printf("\nSize:%d\nNumber of elements in stack %d\n",N,top+1);
  }
}
int main() {
  int option,numpush;
  char ch='y';
  
  do{
    printf("\n1.Push\n2.Pop\n3.Display\n4.Status\nEnter any option : ");
    scanf("%d",&option);
    switch (option){
    case 1:
      printf("\nEnter the element to be added : ");
      scanf("%d",&numpush);
      push(numpush);
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      getchar();
      break;
    case 4:
      status();
      getchar();
      printf("\nPress enter to continue\n");
      getchar();
      break;
    default : 
      printf("\nEnter valid option\n");
    }
    system("clear");
  }while(ch=='y');
  return 0;
}