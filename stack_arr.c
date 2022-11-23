#include<stdio.h>
#include<stdlib.h>
#define size 4
struct stack
{
    int a[size];
    int top;
}s;
void push(int val)
{
    if(s.top==size-1)
    {
        printf("STACK IS FULL\n");
    }
    else
    {
        (s.top)++;
        s.a[s.top]=val;
    }
}
int pop()
{
    int val;
    if(s.top==-1)
    {
        printf("STACK IS EMPTY.\n");
    }
    else
    {
        val=s.a[s.top];
        (s.top)--;
        return val;
    }
}
void display()
{
    if(s.top==-1)
    {
        printf("STACK IS EMPTY\n");
    }
    printf("\n");
    for(int i=s.top;i>=0;i--)
    {
        printf("%d\t",s.a[i]);
    }
}
int peep()
{
    int val;
    if(s.top==-1)
    printf("STACK IS EMPTY");
    else
    {
        val=s.a[s.top];
        return val;
    }
}
void main()
{
    int val;
    s.top=-1;
    int choice;
    do
    {
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.PEEP\n5.EXIT\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("ENTER THE VALUE TO BE PUSHED: ");
            scanf("%d",&val);
            push(val);
            break;
            case 2:
            val=pop();
            printf("Element popped=%d",val);
            break;
            case 3:
            printf("Elements is stack are as follows:\n");
            display();
            break;
            case 4:
            val=peep();
            printf("Element at top= %d\n",val);
            break;
            case 5:
            exit(0);
            default:
            printf("ENTER A VALID CHOICE(1 TO 4)");
        }
    }while(choice!=5);
}