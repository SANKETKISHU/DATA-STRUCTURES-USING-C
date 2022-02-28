#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int count=0;
struct Node *start=NULL;
struct Node
{
int data;struct Node *next;
};
void insert_at_begin(int x)
{
	struct Node *t;
	t=(struct Node*)malloc(sizeof(struct Node));
	count++;
	if(start==NULL)
	{
		start=t;
		start->data=x;
		start->next=NULL;
		return;
	}
	t->data=x;
	t->next=start;
	start=t;
}
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
void delete_from_begin()
{
	struct Node *t;
	int n;
	if(start==NULL)
	{
		printf("Linked List is empty!!!\n\n");
	    return;
	}
	n=start->data;t=start->next;
	free(start);
	start=t;
	count--;
	printf("Deleted element is %d\n\n",n);
	return;
}
void delete_from_end()
{
struct Node *t,*u;
int n;
if(start==NULL)
{
	printf("Linked List is empty!!!\n\n");return;
}
count--;
if(start->next==NULL)
{
	n=start->data;
	free(start);
	start=NULL;
	printf("Deleted element is %d\n\n",n);
	return;	
}
t=start;
while(t->next!=NULL)
{
	u=t;
	t=t->next;
}
n=t->data;
u->next=NULL;
free(t);
printf("Deleted element is %d\n\n",n);
return;
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
    t=start;
    while(t->next!=NULL)
    {
    	printf("%d ",t->data);
	    t=t->next;
    }
    printf("%d ",t->data);
    t=t->next;
}
void sumofdata()
{
	struct Node *p=start;
	int s=0;
	if(start==NULL)
	{
		printf("Linked List is empty!!!\n\n");
	}
	else
	{
		while(p!=NULL)
		{
			s=s+p->data;
			p=p->next;
		}
		printf("%d\n\n",s);
	}
}
void no_delete()
{
	struct Node *del,*p=start;
	int num,x;
	printf("enter number you want to delete\n");
	scanf("%d",&num);
	if(start==NULL)
	{
		printf("\nlist is empty\n");
	}
	else
	{
		p=start;
		while(p->next->data!=num && p->next!='\0')
		{
			p=p->next;
		}
		if(p->next==NULL)
		{
			printf("\n number is not found\n"); 
		}
		else
		{
		    del=p->next;
		    p->next=p->next->next;
		    x=del->data;
		    free(del);
		    printf("%d",x);
	    }
    }
}
void no_count()
{
	struct Node *t;
	int c=0;
	if(start==NULL)
	{
		printf("Linked List is empty!!!\n\n");
		return;
	}
	printf("Elements are: ");
	t=start;
	while(t->next!=NULL)
	{
		c=c+1;
		t=t->next;
	}
	printf("%d ",c);
	printf("\n\n");
}
void insert_at_pos(int x)
{	
    struct Node *t,*q,*r;
	int p,c=1;
	t=(struct Node*)malloc(sizeof(struct Node));
	count++;printf("Enter position");
	scanf("%d",&p);
	if(start==NULL)
	{	
	    printf("Linked List is empty!!!\n\n");
		return;
	}
	else
	{
		q=start;
		while(c!=p)
		{
			c=c+1;
			r=q;
			q=q->next;
		}
		t->data=x;
		t->next=q;
		r->next=t;
	}
}
int main()
{
	int ch,data;
	while(1)
	{
		printf("----------CREATE LIST----------\n");
		printf("1. INSERT AT BEGINING\n");
		printf("2. INSERT AT END\n");
		printf("3. Insert element after a specific element\n");
		printf("4.Remove element from the beginning\n");
		printf("5. Remove element from the end\n");
		printf("6. Remove a specific element\n");
		printf("7. Count the number of elements\n");
		printf("8. Find the sum of the elements\n");
                printf("9. diplay\n");
		printf("10. exit\n\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		if(ch==1)
		{
				
		printf("Enter the insert value: ");
		scanf("%d",&data);
		printf("\n");
		insert_at_begin(data);
		}
		else if(ch==2)
		{
			printf("Enter the insert value: ");
			scanf("%d",&data);
			printf("\n");
			insert_at_end(data);
		}
		else if(ch==3)
        {
        	 	
		printf("Enter the insert value: ");
		scanf("%d",&data);
		insert_at_pos(data);
		}
		else if(ch==4)
		{
			delete_from_begin();
		}
		else if(ch==5)
		{
			delete_from_end();
		}
		else if(ch==6)
		{
			no_delete();
		}
		else if(ch==7)
		{
			no_count();
		}
		else if(ch==8)
		{
		    sumofdata();
		}
		else if(ch==9)
		{
		    display();
			
		}
		else if(ch==10)
		{
		    break;
		}
		else
		{
		    printf("Wrong choice!!!\n");
		}
	}
}
		
			

		
	

