
///////////////////////////////////////////////////////////////////////////
//	DOUBLY LINKED LIST	
///////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
 
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Input : Pointer , Integer
//  Output: void
//  Description : Accepts pointer to head node as first parameter and Integer as second pameter  
//		  Inserts node in DOUBLY LINKED LIST at 1st position
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE head, int no)
{
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if(*head == NULL)
	{
		*head = newn;
	}
	else
	{
		newn -> next = (*head);
		(*head) -> prev = newn;
		(*head) = newn;
	}
}

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Input : Pointer , Integer
//  Output: void 
//  Description : Accepts pointer to head node as first parameter and Integer as second pameter  
//		  Inserts node in DOUBLY LINKED LIST at LAST position
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE head, int no)
{
	PNODE temp = NULL ,newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	
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
		newn -> prev = temp;
	}
}

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
// 	Input : Pointer
//  Output: void
//  Description : Accepts pointer to head node as parameter  
//		  Deletes node in DOUBLY LINKED LIST at first position
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE head)
{
	if(*head == NULL)
	{
		return;
	}
	else
	{
		*head = (*head) -> next;
		free((*head) -> prev);
		(*head) -> prev = NULL;
	}
}

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
// 	Input : Pointer
//  Output: void
//  Description : Accepts pointer to head node as parameter  
//		  Deletes node in DOUBLY LINKED LIST at last position
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE head)
{
	PNODE temp = NULL;
	
	if(*head == NULL)
	{
		return;
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

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
// 	Input : Pointer
//  Output: void
//  Description : Accepts first parameter as Address of head node
//		  Displays all node in DOUBLY LINKED LIST 
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

void Display(PNODE head)
{
	while(head != NULL)
	{
		printf("| %d |->",head -> data);
		head = head -> next;
	}
	printf("NULL\n");
}

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//	Input : Pointer
//  Output: Integer
//  Description : Accepts first parameter as Address of head node
//		  Counts no of nodes in DOUBLY LINKED LIST
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Input : Pointer , Integer , Integer
//  Output: void
//  Description :  Accepts first parameter as pointer to head node second as  data in no and third as position in iPos
//		   Inserts node in DOUBLY LINKED LIST at iPos position
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE head, int no, int iPos)
{
	int iCnt = 0, iCount = 0;
	PNODE temp = NULL, newn = NULL;
	
	iCount = Count(*head);
	
	if((iPos < 0) || (iPos > (iCount + 1)))
	{
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(head,no);
	}
	else if(iPos == (iCount + 1))
	{
		InsertLast(head,no);
	}
	else
	{
		temp = *head;
		
		newn = (PNODE)malloc(sizeof(NODE));
		
		newn -> data = no;
		newn -> next = NULL;
		newn -> prev = NULL;
		
		for(iCnt = 1; iCnt < (iPos - 1) ;iCnt++)
		{
			temp = temp -> next;
		}
		
		newn -> next = temp -> next;
		newn -> prev = temp;
		temp -> next -> prev = newn; 
		temp -> next = newn;
	}
	
}

///////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Input : Pointer, Integer 
//  Output: void
//  Description : Accepts first parameter as pointer to head node and Second parameter as position in iPos
//		  Deletes node in DOUBLY LINKED LIST at iPos position
//
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE head, int iPos)
{
	int iCnt = 0, iCount = 0;
	PNODE temp = NULL;
	
	iCount = Count(*head);
	
	if((iPos < 0) || (iPos > iCount))
	{
		return;
	}
	
	if(iPos == 1)
	{
		DeleteFirst(head);
	}
	else if(iPos == iCount)
	{
		DeleteLast(head);
	}
	else
	{
		temp = *head;
		
		for(iCnt = 1; iCnt < (iPos - 1) ;iCnt++)
		{
			temp = temp -> next;
		}
		
		temp -> next = temp -> next -> next;
		free(temp -> next -> prev);
		temp -> next -> prev = temp;
	}
}
	
///////////////////////////////////////////////////////////////////////////
//
//  Function Name : main
//  Output: Integer
//  Description : Can create and manipulate DOUBLY CIRCULAR LINKED LIST
//  Author : Kaushal Sachin Kapadnis
//	Date : 26-6-2022
//
///////////////////////////////////////////////////////////////////////////

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
				
				InsertFirst(&first,Value);
				
				break;
				
			case 2:
				printf("Enter Number :");
				scanf("%d",&Value);
				
				InsertLast(&first,Value);
								
				break;
				
			case 3:
				DeleteFirst(&first);

				break;
				
			case 4:
				DeleteLast(&first);
				
				break;
				
			case 5:
				printf("Enter Number : ");
				scanf("%d",&Value);
				
				printf("Enter Position : ");
				scanf("%d",&pos);
				
				InsertAtPos(&first,Value,pos);

				break;
				
			case 6:
				printf("Enter Position : ");
				scanf("%d",&pos);
				
				DeleteAtPos(&first,pos);
				
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
