#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int count=0;
struct Node *start=NULL;
struct Node
{
int data;struct Node *next;
};
void insert_at_end(int x)
{
	struct Node *t,*temp;
    t=(struct Node*)malloc(sizeof(struct Node));count++;
    if(start==NULL)
	{
		start=t;
		start->data=x;
		start->next=NULL;
		return;
	}
	temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	
	}
	temp->next=t;
	t->data=x;
	t->next=NULL;
}
void display()
{
	struct Node *t;
	if(start==NULL)
	{
		printf("Linked List is empty!!!\n\n");
		return;
	}

    printf("No of elements: %d\n",count);
    printf("Elements are: ");
    printf("\n");
    t=start;
    while(t->next!=NULL)
    {
    	printf("%d ",t->data);
	    t=t->next;
    }
    printf("%d ",t->data);
    t=t->next;
}
int main()
{
	int ch,data;
	while(1)
	{
		printf("\n----------CREATE LIST----------\n");
		printf("1. INSERT AT END\n");
		printf("2. diplay\n");
		printf("3. exit\n\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter the insert value: ");
			scanf("%d",&data);
			printf("\n");
			insert_at_end(data);
		}
		else if(ch==2)
		{
		    display();
			
		}
		else if(ch==3)
		{
		    break;
		}
		else
		{
		    printf("Wrong choice!!!\n");
		}
	}
}
