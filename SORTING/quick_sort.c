#include<stdio.h>
void swap( int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int p,int r){
    int x,i,j;
    x=arr[r];
    i=p-1;
    for(j=p;j<=r-1;j++){
        if(arr[j]<=x){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}

void quick_Sort(int arr[],int p,int r){
    int q;
    if(p<r){
        q=partition(arr,p,r);
        quick_Sort(arr,p,q-1);
        quick_Sort(arr,q+1,r);
    }

}

int main(){
    int n,i,p,r;
    printf("Enter the toal number of elements:");
    scanf("%d",&n);
    int arr[n];
    for (i=0; i<n; i++) {
        printf("arr[%d]:",i);
        scanf("%d",&arr[i]);
    
    }

    p=0;
    r=(sizeof(arr)/sizeof(int))-1;
    quick_Sort(arr,p,r);
    for(i=0;i<=r;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}