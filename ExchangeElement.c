/*Exchange elements of a 8x8 integer array
1.Vertically (Row 1  Row 8, Row 2  Row 7…)
2.Horizontally (Column 1  Column 4 … 5  8 …)
3.Randomly (without repetition & involving all)
Using a Menu-driven program and allowing repetition until a stop option occurs.
Note: Use function pointers to facilitate loop.*/
#include<stdio.h>
# define row 8
# define column 8
void display(int arr[row][column]){
    for(int l=0;l<row;l++){
        for(int m=0;m<column;m++){
            printf("%d ",arr[l][m]);
        }
        printf("\n");
    }
}
//case 1
 void Vertical_Change( int arr[row][column],int i,int j){
    int temp[column];
    for( int n=0;n<column;n++){
        temp[n]=arr[i][n];
        arr[i][n]=arr[j][n];
        arr[j][n]=temp[n];
    }
 }
 //case 2
 void  Horizontal_Change( int arr[row][column],int i,int j){
     int temp[row];
    for( int n=0;n<row;n++){
        temp[n]=arr[n][i];
        arr[n][i]=arr[n][j];
        arr[n][j]=temp[n];
    }
 }

//case 3
void  Ramdomly_Change(){

}
int main(){
    int ch;
    int student[row][column] ={
        {1,2,3,4,5,6,7,8},
        {9,10,11,12,13,14,15,16},
        {17,18,19,20,21,22,23,24},
        {25,26,27,28,29,30,31,32},
        {33,34,35,36,37,38,39,40},
        {41,42,43,44,45,46,47,48},
        {49,50,51,52,53,54,55,56},
        {57,58,59,60,61,62,63,64}
        };
        printf("1.To Exchange vertically press 1:\n 2.To Exchange Horizontally press 2:\n 3.To Exchange Randomly press 3:\n");
        scanf("%d",&ch);
        //int student1=student;
        if(ch==1){
            int i=0,j=7;
            for(int k=0;k<row/2;k++){
                Vertical_Change(student,i,j);
                i++;
                j--;
            }
            display(student);
        }else if(ch==2){
             int i=0,j=7;
            for(int k=0;k<column/2;k++){
                Horizontal_Change(student,i,j);
                i++;
                j--;
            }
            display(student);
            
        }else if(ch==3){
            Ramdomly_Change();
        }else{
            printf("Invalid");
        }
    return 0;
}
