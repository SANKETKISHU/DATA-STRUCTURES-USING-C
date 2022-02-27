#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct abc
{
	int data;
	struct abc *next;
	struct abc *prior;
}*start=NULL,*last=NULL;
void insert_beginning();
void insert_end();
void insert_specific();
void remove_beginning();
void remove_end();
void remove_specific();
void count_element();
void sum_of_element();
void display();
 main()
{
	int choice;
	while(1)
	{
	printf("\n-------------------------------DOUBLE LINK LIST--------------------------------");
	printf("\n");
	printf("\n A MENU-DRIVEND PROGRAM TO DO THE FOLLOWING OPERATIONS ON A DOUBLE LINKED LIST\n.");
	printf("\n*******************************************************************************\n");
	printf("\n[1] INSERT ELEMENT AT THE BEGINNING\n");
	printf("\n[2] INSERT ELEMENT AT THE END\n");
	printf("\n[3] INSERT ELEMENT AFTER A SPECIFIC ELEMENT\n");
	printf("\n[4] REMOVE ELEMENT FROM THE BEGINNING\n");
	printf("\n[5] REMOVE ELEMENT FROM THE END\n");
	printf("\n[6] REMOVE A SPECIFIC ELEMENT\n");
	printf("\n[7] COUNT THE NUMBER OF ELEMENTS\n");
	printf("\n[8] FIND THE SUM OF ELEMENTS\n");
	printf("\n[9] DISPLAY THE ELEMENT\n");
	printf("\n[10]EXIT\n");
	printf("\n");
	printf("\n-------------------------------------------------------------------------------\n");
	printf("\n*******************************************************************************\n");
	printf("\n ENTER YOUR CHOICE:");
	scanf("%d",&choice);
	if(choice==1)
	{
		insert_beginning();
    }
    else if(choice==2)
	{
		insert_end();
	}
	else if(choice==3)
	{
		insert_specific();
	}
	else if(choice==4)
	{
		remove_beginning();
	}
	else if(choice==5)
	{
		remove_end();
	}
	else if(choice==6)
	{
		remove_specific();
	}
	else if(choice==7)
	{
		count_element();
	}
	else if(choice==8)
	{
		sum_of_element();
	}
	else if(choice==9)
	{
		display();
	}
	else if(choice==10)
	{
		break;
	}
	else
	{
		printf("WRONG CHOICE");
	}
}
	getch();
}
void insert_beginning()
{
	struct abc *temp=start;
	if(start==NULL)
	{
		printf("EMPTY DATA");
	}
	else
	{
		start=(struct abc*)malloc(sizeof(struct abc));
		printf("ENTER THE DATA YOU WANT IN BIGINNING:");
		scanf("%d",&start->data);
		start->next=temp;
	}
}
void insert_end()
{
	struct abc *temp=start;
	if(start==NULL)
	{
		start=(struct abc *)malloc(sizeof(struct abc));
		printf("\nENTER NEW DATA\t");
		scanf("%d",&start->data);
		start->prior=NULL;
		start->next=NULL;
		last=start;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=(struct abc*)malloc(sizeof(struct abc));
		printf("\nENTER DATA\t");
		scanf("%d",&temp->next->data);
		temp->next->next=NULL;
		temp->next->prior=temp;
		last=temp->next;
	}
}
void insert_specific()
{
	int a;
	struct abc *temp=start,*copy;
	if(start==NULL)
	{
		printf("NO DATA FOUND");
	}
	else
	{
		printf("\nENTER THE ELEMENT YOU WANT TO INSERT AFTER THAT ELEMENT\t");
		scanf("%d",&a);
		while(temp->data!=a)
		{
			temp=temp->next;
		}
		copy=temp->next;
		temp->next=(struct abc*)malloc(sizeof(struct abc));
		printf("ENTER NEW DATA TO INSERT AFERT A SPECFIC DATA THAT YOU SELECTED");
		scanf("%d",&temp->next->data);
		temp->next->next=copy;
		temp->next->prior=temp;
	}
}
void remove_beginning()
{
	struct abc *temp=start;
	if(start==NULL)
	{
		printf("NO DATA FOUND");
	}
	else
	{
		start=start->next;
	    start->prior=NULL;
		free(temp);	
	}
}
void remove_end()
{
	struct abc *temp=start,*p;
	if(start==NULL)
	{
		printf("NO DATA FOUND");
	}
	else
	{
		while(temp->next!=NULL)
		{
			p=temp;
			temp=temp->next;
		}
		p->next=NULL;
		free(temp);
	}
}
void remove_specific()
{
	struct abc *temp=start,*p;
	int num;
	printf("\nENTER THE DATA THAT YOU WANT TO REMOVE\t");
	scanf("%d",&num);
	if(start==NULL)
	{
		printf("NO DATA FOUND");
	}
	else
	{
		while(temp->data!=num)
		{
			p=temp;
			temp=temp->next;
		}
		printf("\nNUMBER REMOVED\n");
		p->next=temp->next;
		free(temp);
	}
}
void count_element()
{
	struct abc *temp=start;
	int c;
	if(start==NULL)
	{
		printf("NO DATA FOUND");
	}
	else
	{
		while(temp!=NULL)
		{
			c=c+1;
			temp=temp->next;
		}
		printf("TOTAL NUMBER OF ELEMENT IS %d\t",c);
	}
}
void sum_of_element()
{
	struct abc *temp=start;
	int s;
	if(start==NULL)
	{
		printf("NO DATA FOUND");
	}
	else
	{
		while(temp!=NULL)
		{
			s=s+temp->data;
			temp=temp->next;
		}
		printf("TOTAL SUM OF ELEMENT IS\t %d",s);
	}
}
void display()
{
	struct abc *temp=start;
	if (start==NULL)
	printf("List  is empty");
	else
	{
		while(temp!=NULL)
		{
			printf("\nELEMENTNT IN NODE\t %d",temp->data);
			temp=temp->next;
		}
	}
}

	

