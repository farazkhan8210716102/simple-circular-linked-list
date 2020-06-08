#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
 struct node *temp,*newnode,*head;
void insert();
void delete();
void delete_middle();
void display();
void exit();
main()
{
    int ch;
    while(1)
    {
        printf("enter the choice \n");
        printf("1.insert\n2.delete\n3.delete_middle\n4.display\n5.exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
           case 1:insert();break;
           case 2:delete();break;
           case 3:delete_middle();break;
           case 4: display();break;
           case 5: exit(0);
        }
    }
}
void insert()
{
    if(head==NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data \n");
        scanf("%d",&newnode->data);
        newnode->next=head;
        head=newnode;
        temp=newnode;
    }
    else

        {
            newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data \n");
        scanf("%d",&newnode->data);
        newnode->next=head;
        temp->next=newnode;
        temp=newnode;
        }
}
void delete()
{
       temp=head;
       head=temp->next;
           printf("%d is the number deleted \n",temp->data);

       free(temp);
}
void delete_middle()
{
    struct node *p,*q;
    int pos;
    p=head;
    printf("enter the position \n");
    scanf("%d",&pos);
    while(p<pos-1)
    {
        p=p->next;
    }
    q=p->next;
    p->next=q->next;
    printf("%d is the number deleted \n",q->data);
    free(q);

}
void display()
{

   temp=head;        // temp is assigned to the start list so that the values could be printed from the root position
    if(temp!=NULL)
    {
        printf("\n the contents in the linked list are \n");
        while(temp->next!=head)
        {
            printf("%d\n",temp->data);
            temp=temp->next;         // after printing the data of the temp , address is being forwarded to the next node
        }
    }
    else
        printf("linked list is empty \n");
}
