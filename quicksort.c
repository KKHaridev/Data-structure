#include<stdio.h>

int j;
void swap(int *p,int *aj){
    int t=*p;
    *p=*aj;
    *aj=t;
}
int partition(int a[20],int l,int u){
    int pivot,i;
    pivot=l,i=l,j=u;
    while(i<j){
        while(a[i]<a[pivot])
            i++;
        while(a[j]>a[pivot])
            j--;
        if(i<j)
            swap(&a[i],&a[j]);
    }
    swap(&a[pivot],&a[j]);
    return j;
}
int quick_sort(int a[20],int l,int u){
    if(l<u){
        partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}
void main(){
    int a[20],n,low=0;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quick_sort(a,low,n-1);
    printf("Sorted array : ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}