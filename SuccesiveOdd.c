#include<Stdio.h>
void sum_of_succesive(int num,int squ){
    int sum=0;
    int oddNumber=1;
    for(int i=1;i<=num;i++){
        sum+=oddNumber;
        oddNumber+=2;
    }
    if(sum==squ){
        oddNumber=1;
        printf("%d = ",squ);
        for(int i=1;i<=num;i++){
        printf("%d + ",oddNumber);
        oddNumber+=2;
    }
    printf("\n");
    }
}
int main(){
    int limit;
    printf("Enter the limit:" );
    scanf("%d",&limit);
    for(int i=1;i<=limit;i++){
        int squ=i*i;
        sum_of_succesive(i,squ);
    }
    return 0;
}