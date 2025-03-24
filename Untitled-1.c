#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wai.h>
void performoperation(char operation,int a,int b)
{
    int result=0;
    switch(operation){
        case'+':
        result=a+b;
        printf("result:%d\n",result);
        exit(result);
        case'-':
        result=a-b;
        printf("result:%d\n",result);
        exit(result);
        case'*':
        result=a*b;
        printf("result:%d\n",result);
        exit(result);
        case'/':
        if(b!=0)}
        result=a/b;
        printf("result:%d\n",result);
        exit(result);
    }else{
        printf("error: division by zero\n");
        exit[EXIT ]
    }
}