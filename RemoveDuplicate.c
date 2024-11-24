#include<stdio.h>
#define MAX_SIZE 100
int countDuplicates(int arr[],int n){
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
                break;
            }
        }
    }
    return count;
}

void copyUniqueElements(int arr[],int uniqueArr[],int n,int *uniqueCount){
    int j=0;
    for(int i=0;i<n;i++){
        int isUnique=1;
        for(int k=0;k<i;k++){
            if(arr[i]==arr[k]){
                isUnique=0;
                break;
            }
        }
        if(isUnique){
            uniqueArr[j++]=arr[i];
        }
    }
    *uniqueCount=j;
}

void printReverse(int arr[],int n){
    printf("Reverse array:");
    for(int i=n-1;i>=0;i--){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    if(n>MAX_SIZE){
        printf("Error: Array size exceeds maximum limit.");
        return 1;
    }
    int arr[n];
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int duplicateCount=countDuplicates(arr,n);
    printf("Total Duplicate Elements:%d\n",duplicateCount);
    int uniqueArray[n];
    int uniqueCount;
    copyUniqueElements(arr,uniqueArray,n,&uniqueCount);
    printf("unique elements array:");
    for(int i=0;i<uniqueCount;i++){
        printf("%d ",uniqueArray[i]);
    }
    printf("\n");
    printReverse(uniqueArray,uniqueCount);
    return 0;
}