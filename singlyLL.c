#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* insert(struct node *head,int num)
{
    struct node *hptr;
    hptr=head;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    if(hptr==NULL||head->data>num)        //list is empty or the no. to be inserted is smaller than the first no.
    {
        newnode->next=head;
        head=newnode;
        return head;
    }
    else
    {
        while(hptr->next!=NULL && hptr->next->data<num)  //insert at last or before a no.
        {
            hptr=hptr->next;
        }
        newnode->next=hptr->next;
        hptr->next=newnode;
        return head;
    }
}
struct node* del(struct node *head,int num)
{
    struct node *hptr,*node2del;
    hptr=head;
    if(hptr==NULL)
    {
        printf("LINKED LIST IS EMPTY.\n");
        return head;
    }
    if(hptr->data==num)           //when element to be deleted is first in the list.
    {                                
        head=hptr->next;
        printf("node deleted = %d",hptr->data);
        free(hptr);
        return head;
    }
    else
    {
        while(hptr->next!=NULL)
        {
            if(hptr->next->data==num)
            {
                node2del=hptr->next;             //when element to be deleted is in middle or last in the list 
                hptr->next=node2del->next;
                printf("node deleted = %d",node2del->data);
                free(node2del);
                return head;
            }
            hptr=hptr->next;
        }
        if(hptr->next==NULL)
        {
            printf("Element is not present in the list.\n");
            return head;
        }
    }
   
}

void display(struct node *head,int num)
{
    struct node *hptr;
    if(head==NULL)
    printf("linked list is empty.\n");
    for(hptr=head;hptr!=NULL;hptr=hptr->next)
    {
        printf("%d\t",hptr->data);
    }
}
int main()
{
    int num=0,choice=0;
    struct node *head;
    head=NULL;
    do
    {
        printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter data for the node: ");
                scanf("%d",&num);
                head=insert(head,num);
                break;
            case 2:
                printf("enter the data to be deleted: ");
                scanf("%d",&num);
                head=del(head,num);
                break;
            case 3:
                display(head,num);
                break;
            case 4:
                exit(0);
            default :
                printf("ENTER VALID CHOICE (1 TO 4)");
        }
    }while(choice!=4);
}
