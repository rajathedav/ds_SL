#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int BOOL;

#define TRUE 1
#define FALSE 0

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE,int);
void Display(PNODE);
int Count(PNODE);
void InsertLast(PPNODE,int);
void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void InsetAtPos(PPNODE,int,int);
void DeleteAtPos(PPNODE,int);




int main()
{
	PNODE First=NULL;
	int iret=0;
	InsertFirst(&First,101);
	InsertFirst(&First,51);
	InsertFirst(&First,21);
	InsertFirst(&First,11);
	Display(First);
	iret=Count(First);
	printf("Number of Element are %d\n",iret);

	InsertLast(&First,111);
	InsertLast(&First,121);

	Display(First);
	DeleteLast(&First);
	Display(First); 
	DeleteFirst(&First);
	Display(First);
	InsetAtPos(&First,151,3);
	Display(First);
	DeleteAtPos(&First,3);
	Display(First);



	return 0;
}
void InsertFirst(PPNODE Head,int value)
{
	PNODE newn=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=value;
	newn->next=NULL;

	if(*Head==NULL)         // Linked List is empty.   
	{
		*Head=newn;
	}
	else				   // Linked List contain atleast one node.
	{
		newn->next=*Head; // sequence is compalsary same if we change the seq. the it loop infinite time.......
		*Head=newn;
	}
}

void Display(PNODE Head)
{
	printf("Element from linked list are\n");

	while(Head!=NULL)
	{
		printf("| %d |->",Head->data);
		Head=Head->next;
	}
	printf("NULL\n");
}

int Count(PNODE Head)
{
	int icnt=0;

	while(Head!=NULL)
	{
		icnt++;
		Head=Head->next;
	}

	return icnt;
}
void InsertLast(PPNODE Head,int value)
{
	PNODE newn=NULL;
	PNODE Temp=*Head;

	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->data=value;
	newn->next=NULL;

	if(*Head==NULL)         // Linked List is empty.   
	{
		*Head=newn;
	}
	else				   // Linked List contain atleast one node.
	{
		while(Temp->next!=NULL)
		{
			Temp=Temp->next;
		}

		Temp->next=newn;
	}
}
void DeleteLast(PPNODE Head)
{
	PNODE temp=*Head;

	if(*Head==NULL)
	{
		return;
	}
	else if((*Head)->next==NULL)
	{
		free (temp);
		*Head=NULL;
	}
	else
	{
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}

		free(temp->next);
		temp->next=NULL;
	}
}

void DeleteFirst(PPNODE Head)
{
	PNODE temp=*Head;

	if((*H==NULL)
	{
		return;
	}
	else
	{
		(*Head)=(*Head)->next;
		free(temp);
	}
}

void InsetAtPos(PPNODE Head,int value,int ipos)
{
	PNODE temp=*Head;
	PNODE newn=NULL;
	int size=Count(*Head);
	int i=0;
	if((ipos<1)||(ipos>size+1))
	{
		return;
	}
	if(ipos==1)
	{
		InsertFirst(Head,value);	
	}
	else if(ipos==(size+1))
	{
		InsertLast(Head,value);
	}
	else
	{
		newn=(PNODE)malloc(sizeof(NODE));

		newn->data=value;
		newn->next=NULL;

		for(i=1;i<=(ipos-2);i++)
		{
			temp=temp->next;
		}

		newn->next=temp->next;
		temp->next=newn;
	}
	printf("Insert at pos\n");
}
	

void DeleteAtPos(PPNODE Head,int ipos)
{
	PNODE temp1=*Head;
	PNODE temp2=NULL;
	int i=0;
	int size=Count(*Head);

	if((ipos<1)||(ipos>size))
	{
		return;
	}

	if(ipos==1)
	{
		DeleteFirst(Head);
	}
	else if(ipos==size)
	{
		DeleteLast(Head);
	}
	else
	{
		for(i=1;i<=(ipos-2);i++)
		{
			temp1=temp1->next;
		}

		temp2=temp1->next;

		temp1->next=temp2->next;
		free(temp2);
	}
}