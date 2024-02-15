#include <stdio.h>
#include <stdlib.h>
void transfer(int n, char from , char to, char temp){
    if(n==0){
        return; 
    }else {
    
    transfer(n-1,  from,  temp,  to);
    printf("\nMove disk %d from %c to %c via %c",n,from,to,temp);
    transfer(n-1,temp,to,from);
    }
}
int main(){
    int n;
    system("clear");
    printf("\nEnter No. of dics \n");
    scanf("%d",&n);
    transfer(n,'S','T', 'A');
    
    return 0;
}