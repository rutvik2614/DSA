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


void enqueue(int val)
{
    struct node *hptr,*newnode;
    hptr=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(hptr==NULL)
    {
        newnode->next=hptr;
        head=newnode;
        return;
    }
    while(hptr->next!=NULL)
    {
        hptr=hptr->next;
    }
    hptr->next=newnode;
    newnode->next=NULL;   
}

int dequeue()
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
        hptr=node2del->next;
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
    int val,choice;
    do
    {
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.PEEP\n5.EXIT\nENTER YOUR CHOICE : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the number to be enqueued : ");
            scanf("%d",&val);
            enqueue(val);
            break;

            case 2:
            val=dequeue();
            if(val==-1)
            {
                printf("queue is empty.\n");
            }
            else
            {
                printf("Eelement dequeued = %d",val);
            }
            break;
            
            case 3:
            printf("Elements in Queue are :\n");
            display();
            break;
			
            case 4:
            val = peep();
			if(val==-1) 
            printf("Queue is empty\n");
			else
			printf("Element at front is: %d\n",val);
			break;
			
            case 5:
			exit(0);
			default:printf("Invalid choice\n");
        }
    }while(choice!=5);
}