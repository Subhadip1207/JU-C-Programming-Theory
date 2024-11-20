// Calculator version 1
#include<stdio.h>
int main(){
    char key=' ';
    char op='+';
    int i,result=0,NumVal;
    printf("\nAccept Calculator(Version 1) Input[press = and <Enter> to End]:");
    char valid[]={'+','-','*','/','='};
    Check_Key:
{
    for( i=0;i<=4;i++){
        if(op==valid[i]) break;
    }
    if(i>4){printf("\nError in Input"); goto stop ;}
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
        if(key!='='){op=key;goto Check_Key;
}
    printf("\nResult=%d",result);
    stop:
    printf("\npress.to exit");
     while (op=getchar()!='.');
    return 0;
}
}