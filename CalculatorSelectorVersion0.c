//Calculator Selector Program Version 0
#include<stdio.h>
void simple_calc(){
    int valid_op=1;
    char key=' ';
    char op='+';
    int i,Numval;
    double result=0.0;
    printf("Accept calculator (version 3)Input [Press = and <Enter> to End]:");
    do
    {
        Numval=0;
        key=getchar();
        while (key>='0'&& key<='9'){
            Numval=Numval*10+key-'0';
            key=getchar();
        }
        switch (op){
            case '+': result+=Numval;break;
            case '-':result-=Numval;break;
            case '*':result*=Numval;break;
            case '/':result/=Numval;break;
            case '=':printf("\n Result = %lf",result);
                        valid_op=0;break;
            default: printf("\nError in Input");
                        valid_op=0;break;
        }
        op=key;
        
    } while (valid_op);
}
int main(){
    int i,opt;
    char c;
    char Promt[100]="Accept an option between 1/2/3:";
    char Menu[][100]={
        "1.Ordinary Calculator",
        "2.Calcultor with brackets",
        "3.Exit from Program"
    };
    do{
        for(i=0;i<3;i++)printf("\n%s",Menu[i]);
        printf("\n%s",Promt);
        c=getchar();
        printf("%c\n",c);
        fflush(stdin);
        opt=c-'0';
        if(opt==1){simple_calc();continue;}
        if(opt==2){printf("\nNot Yet Ready!!!");continue;}
        if(opt!=3){printf("\nInvalid Option!!!\n");}
    }while(opt!=3);
    return 0;
}