/*
K K Haridev
CSE B
*/
#include <stdio.h>
#include <stdlib.h>
int Max;

void selection(int b[]){
  for(int i=0;i<Max;i++){
    int min_index=i;
    for(int j=i+1;j<Max;j++){
      if(b[j]<b[min_index]){
        min_index=j;
      }
    }
    if(min_index!=i){
      int temp;
      temp=b[i];
      b[i]=b[min_index];
      b[min_index]=temp;
      
    }
  }
  printf("After selection sort\n");
  for(int i=0;i<Max;i++){
    printf("%d ",b[i]);
  }
  printf("\n");
}

void insertion(int c[]) {
  int i, j, current_val;
  for(i = 1 ; i < Max; i++){
    current_val = c[i];
    j = i-1;
    while(j>=0 && current_val < c[j]){
      c[j+1]=c[j];
      j--;
    }
    c[j+1]=current_val;
  }
  printf("After insertion sort\n");
  for(int i=0;i<Max;i++){
    printf("%d ",c[i]);
  }
  printf("\n");
  
}

int main(void) {
  char ch ='y';
  int a[20],b[20],c[20];
  int option;
  printf("Enter the number of elements : ");
  scanf("%d",&Max);
  printf("Enter the elements\n");
  for(int i=0;i<Max;i++){
    scanf("%d",&a[i]);
    b[i]=a[i];
    c[i]=a[i];
  }
  do{
    printf("\nChoose any of the options to continue:\n1.Selection Sort\n2.Insertion Sort\n3.Display Entered Array\n0 to exit\noption : ");
    scanf("%d",&option);
    printf("\n");
    switch(option){
      case 1:
        selection(b);
        break;
      case 2:
        insertion(c);
        break;
      case 3: 
        for(int i=0; i<Max; i++)
          printf("%d \t", a[i]);
        printf("\n\n");
        break;
      case 0:
        exit(0);
        break;
      default:
        printf("invalid option");
    }
  }while(ch=='y');
  return 0;
}
