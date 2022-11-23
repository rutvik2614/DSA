#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

void display()
{
    struct node *hptr;
    hptr=head;
    if(hptr==NULL)
    {
        printf("\nlist is empty.\n");
    }
    while(hptr!=NULL)
    {
        printf("%d\t",hptr->data);
        hptr=hptr->next;
    }
}

void push(int val)
{
    struct node *hptr,*newnode;
    hptr=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}

int pop()
{
    int del;
    struct node *hptr,*node2del;
    hptr=head;
    if(hptr==NULL)
    {
        
        return -1;
    }
    if(hptr->next==NULL)
    {
        node2del=hptr;
        del=node2del->data;
        hptr->next=NULL;
        free(node2del);
        return del;
    }
    node2del=hptr;
    del=node2del->data;
    hptr=node2del->next;
    head=hptr;
    free(node2del);
    return del;
}
int peep()
{
    int val;
    if(head==NULL)
    {
        return -1;
    }
    val=head->data;
    return val;
}
void main()
{
    int choice,val;
    struct node* head=NULL;
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
            if(val==-1)
            {
                printf("LIST IS EMPTY");
            }
            else
            {
                printf("Element popped=%d",val);
            }
            break;
            case 3:
            printf("Elements is stack are as follows:\n");
            display();
            break;
            case 4:
            val=peep();
            if(val==-1)
            {
                printf("LIST IS EMPTY");
            }
            else
            {
                printf("Element at top= %d\n",val);
            }
            break;
            case 5:
            exit(0);
            default:
            printf("ENTER A VALID CHOICE(1 TO 4)");
        }
    }while(choice!=5);
}