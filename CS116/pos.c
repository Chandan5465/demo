#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void performOperation(char operation,int a,int b)
{
    int result=0;
    switch(operation)
    {
        case '+':
        result=a+b;
        printf("result:%d\n",result);
        exit(result);
        case '-':
        result=a-b;
        printf("result:%d\n",result);
        exit(result);
        case '*':
        result=a*b;
        printf("result:%d\n",result);
        exit(result);
        case '/':
        if(b!=0)
        {
            result=a/b;
            printf("result:%d\n",result);
            exit(result);
        
        }
        else{
            printf("error division by zero\n");
            exit(EXIT_FAILURE);

        }
        default:printf("invalid operation\n");
        
        
    }
}
int main()
{
    char operation;
    int operand1,operand2,status;
    printf("enter a operation(+,-,*,/):");
    scanf("%c",&operation);
    printf("enter the first number");
    scanf("%d",&operand1);
    printf("enter the second number");
    scanf("%d",&operand2);
    pid_t pid=fork();
    if (pid<0)
    {
        perror('fork');
        return EXIT_FAILURE;
    }
    else if(pid==0)
    {
        performOperation(operation,operand1,operand2);

    }
    else{
        waitpid(pid,&status,0);
        if(WIFEXITED(status))
        {
            printf("child process exited with result=%d\n",WEXITEDSTATUS(status));
        }
        else{
            printf("child process did not terminated successfully \n");
        }
    }
    return EXIT_SUCCESS;
    
}
