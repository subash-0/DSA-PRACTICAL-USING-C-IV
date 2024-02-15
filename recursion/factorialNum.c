#include <stdint.h>
#include <stdio.h>
int fact(int n){
    if(n>=1){
        return n*fact(n-1);
    }else {
    return 1;
    }
}

int main(){
    int n;
    printf("Enter number:");
    scanf("%d",&n);
    printf("Your factorial is:%d",fact(n));

    return 0;
}