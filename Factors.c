/*Write a c program to display the factors of all composite numbers below 20 in a tabular form*/
#include<stdio.h>
//Function to check if a number is composite
int isComposite(int num){
    if(num<=1)return 0;
    for(int i=2;i*i<=num;i++){
        if(num%i==0) return 1;
    }
    return 0;
}

//Function to print factors of a number 
void printFactors(int num){
    printf("    | ");
    for(int i=1;i<=num;i++){
        if(num%i==0) printf("%d ",i);
    }
    printf("\n");
}
int main(){
    printf("Composite numbers below 20:\n");
    printf("--------------------------\n");
    printf("Number | Factors\n");
    printf("----------------------\n");
    for(int i=2;i<20;i++){
        if(isComposite(i)){
            printf(" %5d | ",i);
            printFactors(i);
            printf("-----------------\n");
        }
    }
    return 0;
}