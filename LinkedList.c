#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node **PPNODE;

void Display(PNODE head)
{
	printf("NUmbers in list are : ");
	while(head != NULL)
	{
		printf("| %d |->",head -> data);
		head = head -> next;
	}
	printf("NULL\n");
}

int Count(PNODE head)
{
	int iCnt = 0;
	
	while(head != NULL)
	{
		iCnt++;
		head = head -> next;
	}
	
	return iCnt;
}

void Insertfirst(PPNODE head, int no)
{
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn -> data = no;
	newn -> next = NULL;
	
	if(*head != NULL)
	{
		newn -> next = *head;
	}
	*head = newn;
}

void InsertLast(PPNODE head, int no)
{
	PNODE newn = NULL;
	PNODE temp = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn -> data = no;
	newn -> next = NULL;
	
	if(*head == NULL)
	{
		*head = newn;
	}
	else
	{
		temp = *head;
		
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		
		temp -> next = newn;
		
	}
	
}

void DeleteFirst(PPNODE head)
{
	PNODE temp = NULL;
	
	if(*head == NULL)
	{
		return;
	}
	else
	{
		temp = *head;
		*head = (*head) -> next;
		free(temp);
	}
}

void DeleteLast(PPNODE head)
{
	PNODE temp = NULL;
	
	if(*head == NULL)
	{
		return;
	}
	else if((*head) -> next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		temp = *head;
		while(temp -> next -> next != NULL)
		{
			temp = temp -> next;
		}
		
		free(temp -> next);
		temp -> next = NULL;
	}
}

void InsertAtPos(PPNODE head, int no, int pos)
{
	int size = 0, iCnt = 0;
	
	PNODE temp = NULL;
	PNODE newn = NULL;
	
	size = Count(*head);
	
	if(pos < 1 || pos > (size + 1))
	{
		printf("----------INVALID INPUT----------\n");
		return;
	}
	
	if(pos == 1)
	{
		Insertfirst(head,no);
	}
	else if(pos == (size + 1))
	{
		InsertLast(head, no);
	}
	else
	{
		temp = *head;
		
		newn = (PNODE)malloc(sizeof(NODE));
		
		newn -> data = no;
		newn -> next = NULL;
	
		for(iCnt = 1; iCnt < (pos - 1); iCnt++)
		{
			temp = temp -> next;
		}
		
		newn -> next = temp -> next;
		temp -> next = newn;
	}
	
}

void DeleteAtPos(PPNODE head, int pos)
{
	int size = 0, iCnt = 0;
	
	PNODE temp = NULL;
	PNODE tempdelete = NULL;
	
	size = Count(*head);
	
	if(pos < 1 || pos > size)
	{
		printf("----------INVALID INPUT----------\n");
		return;
	}
	
	if(pos == 1)
	{
		DeleteFirst(head);
	}
	else if(pos == (size + 1))
	{
		DeleteLast(head);
	}
	else
	{
		temp = *head;
			
		for(iCnt = 1; iCnt < (pos - 1); iCnt++)
		{
			temp = temp -> next;
		}
		
		tempdelete = temp -> next;
		
		temp -> next = temp -> next -> next;
		free(tempdelete);
	}
}

int main()
{
	int iRet = 0,x = 0,Value = 0,pos = 0;
	
	PNODE first = NULL;
	
	while(1)
	{	
		printf("\n\n\n***************************Welcome***************************");
		printf("Enter \n1 : Insert at first position\t2 : Insert at Last\n3 : Delete at first \t\t4 : Delete at Last\n5 : Insert at position\t\t6 : Delete at postion\n7 : Display and Count\t \t8 : Exit\n\n\n");

		scanf("%d",&x);
		
		switch(x)
		{
			case 1:
				printf("Enter Number :");
				scanf("%d",&Value);
				
				Insertfirst(&first,Value);
				
				Display(first);
				
				iRet = Count(first);
				printf("Number of Elements in List are : %d",iRet);
				
				break;
				
			case 2:
				printf("Enter Number :");
				scanf("%d",&Value);
				
				InsertLast(&first,Value);
				
				Display(first);
				
				iRet = Count(first);
				printf("Number of Elements in List are : %d",iRet);

				Display(first);
				
				iRet = Count(first);
				printf("Number of Elements in List are : %d",iRet);
				
				break;
				
			case 3:
				DeleteFirst(&first);

				Display(first);
				
				iRet = Count(first);
				printf("Number of Elements in List are : %d",iRet);
				
				break;
				
			case 4:
				DeleteLast(&first);

				Display(first);
				
				iRet = Count(first);
				printf("Number of Elements in List are : %d",iRet);
				
				break;
				
			case 5:
				printf("Enter Number : ");
				scanf("%d",&Value);
				
				printf("Enter Position : ");
				scanf("%d",&pos);
				
				InsertAtPos(&first,Value,pos);

				Display(first);
				
				iRet = Count(first);
				printf("Number of Elements in List are : %d",iRet);
				
				break;
				
			case 6:
				printf("Enter Position : ");
				scanf("%d",&pos);
				
				DeleteAtPos(&first,pos);

				Display(first);
				
				iRet = Count(first);
				printf("Number of Elements in List are : %d",iRet);
				
				break;
				
			case 7:
				Display(first);
				
				iRet = Count(first);
				printf("Number of Elements in List are : %d",iRet);
				
				break;
			
			case 8:
				exit(1);
				
				break;
				
			default:
				printf("Invalid Input");
				
		}
	}
	
	printf("Thanku\n");
	
	return 0;
}
