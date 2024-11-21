//Calculator program version 3
#include<stdio.h>
int main(){
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
    
    return 0;
}