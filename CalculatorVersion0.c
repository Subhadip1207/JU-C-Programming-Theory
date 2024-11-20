//Calculator program version 0
//(1)if input is 1234abhbs=, the output will be 1234
//(2)if input is 12+34=, the output will be 46

#include<stdio.h>
int main(){
    char key=' ';
    char op='+';
    int i,result=0,NumVal;
    Check_Key:
    {
        NumVal=0;
        Accept_Key:
        key=getchar();
        if(key>='0'&&key<='9'){
            NumVal=NumVal*10+key-'0';
            goto Accept_Key;
        }
        if(op=='+')result+=NumVal;
        if(op=='-')result-=NumVal;
        if(op=='*')result*=NumVal;
        if(op=='/')result/=NumVal;
        if(key!='='){op=key;goto Check_Key;}
    }
     printf("\nResult=%d\nPress.and Enter to exit",result);
     while (op=getchar()!='.');
     
    return 0;
}