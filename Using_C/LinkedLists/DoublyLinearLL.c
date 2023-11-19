/* Implementation of Doubly Linear Linked List */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/* Declaration of structure */
struct Node
{	
	int iData;
	struct Node* nextPtr;	/* Self referential structure */	
	struct Node* prevPtr;	
};

/*
-------------------------------------------------------------
	Old Name			New Name
-------------------------------------------------------------
	
	Node				 NODE	
	Node*				 PNODE
	Node**				 PPNODE	
-------------------------------------------------------------
*/

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: InsertFirst		
//		Return Type			: void
//		Description			: This function accepts the address of the a pointer named as 'First' 
//					  		  declared inside main function and one integer value.This function 
//					  		  is used to insert node at the first position
//		Author Name			: Ronak Sunil Mutha
//		Date				: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE Head,int iNo)
{

	/* Creation of newnode */
	auto PNODE newNode = NULL;
	
	/* Dynamic memory allocation for newnode */
	newNode = (PNODE)malloc(sizeof(NODE));
	
	/* Initialization of data into newnode */
	newNode->iData = iNo;
	newNode-> nextPtr = NULL;
	newNode-> prevPtr = NULL;	
	
	if (*Head == NULL)		/* If linked list is empty */
	{
		*Head = newNode; 
	}
	
	else				/* If linked list contains atleast one node */
	{
		newNode ->nextPtr = *Head;
		(*Head)->prevPtr = newNode;		
		*Head = newNode;
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: InsertLast		
//		Return Type			: void
//		Description			: This function accepts the address of the a pointer named as 'First' 
//					  		  declared inside main function.This function is used to insert node 
//					  		  at the last position
//		Author Name			: Ronak Sunil Mutha
//		Date				: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head,int iNo)
{	
	/* Creation of newnode */
	auto PNODE newNode = NULL;
	auto PNODE tempPtr = *Head;

	/* Dynamic memory allocation for newnode */	
	newNode = (PNODE)malloc(sizeof(NODE));
	
	/* Initialization of data into newnode */
	newNode->iData = iNo;
	newNode-> nextPtr = NULL;
	newNode-> prevPtr = NULL;	
	
	if (*Head == NULL)		/* If linked list is empty */
	{
		*Head = newNode; 
	}
	else				/* If linked list contains atleast one node */
	{
		while (tempPtr -> nextPtr != NULL)
		{
			tempPtr = tempPtr -> nextPtr;
		}	
		newNode -> prevPtr = tempPtr;	
		tempPtr -> nextPtr = newNode;
	
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: DeleteFirst		
//		Return Type			: void
//		Description			: This function accepts the address of the a pointer named as 'First' 
//					  		  declared inside main function.This function is used to delete node 
//			  	 	  		  at the first position
//		Author Name			: Ronak Sunil Mutha
//		Date				: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head)
{	
	if (*Head == NULL)		/* If linked list is empty */
	{
		fprintf(stderr,"Linked List is empty\n");
		_exit(EXIT_FAILURE);
	}
	else if ((*Head)->nextPtr == NULL)	/* If linked list contains atleast one node */
	{
		if(*Head)
		{
			free(*Head);
		}
		
		*Head = NULL;
	}
	else					/* If linked list contains more than one node */
	{
		(*Head) = (*Head)-> nextPtr;
		
		if((*Head)->prevPtr)
		{
			free((*Head)->prevPtr);		
		}
		
		(*Head)->prevPtr = NULL;	
	}


}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: DeleteLast		
//		Return Type			: void
//		Description			: This function accepts the address of the a pointer named as 'First' 
//					 	 	  declared inside main function.This function is used to delete node 
//			  	 			  at the last position
//		Author Name			: Ronak Sunil Mutha
//		Date				: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head)
{
	auto PNODE tempPtr = *Head;
	
	if (*Head == NULL)		/* If linked list is empty */
	{
		fprintf(stderr,"\nLinked list is empty\n");
		_exit(EXIT_FAILURE);
	}
	
	else if ((*Head)->nextPtr == NULL)	/* If linked list contains atleast one node */
	{
		free(*Head);
		*Head = NULL;
	}
	
	else					/* If linked list contains more than one node */
	{
		while (tempPtr->nextPtr->nextPtr != NULL)
		{
			tempPtr = tempPtr -> nextPtr;	
		}
		free(tempPtr->nextPtr);
		tempPtr -> nextPtr = NULL;		
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: DisplayNode		
//		Return Type			: void
//		Description			: This function accepts a pointer named as 'First' declared 
//					  		  inside main function.This function is used display elements 
//					  	      stored in linked list		
//		Author Name			: Ronak Sunil Mutha
//		Date				: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DisplayNodes(PNODE Head)
{
	printf("\nElements in doubly linear linked-lists are : ");
	printf("\n\nNULL<=>");	
	while (Head != NULL)
	{
		printf("|%d |<=>",Head->iData);
		Head = Head -> nextPtr;
	}
	printf("NULL \n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: CountNode		
//		Return Type			: int
//		Description			: This function accepts a pointer named as 'First' which is 
//							  declared inside main function. This function counts the 
//							  number of nodes in linked list. 
//		Author Name			: Ronak Sunil Mutha
//		Date				: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


int CountNodes(PNODE Head)
{
	int iCount = 0;
	while (Head != NULL)
	{
		iCount = iCount + 1;
		Head = Head -> nextPtr;
	}
	return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: InsertAtPos		
//		Return Type			: void
//		Description			: This function accepts the address of the a pointer named as 'First' 
//							  declared inside main function an integer value and a position from 
//							  user.This function is used to insert node at user defined position 
//		Author Name			: Ronak Sunil Mutha
//		Date				: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE Head,int iNo,int iPos)
{
	int iLength = 0;
	PNODE newNode = NULL;

	iLength = CountNodes(*Head);
	
	register int iCnt = 0;
	auto PNODE tempPtr = *Head;	
	
	if ((iPos < 1) || (iPos > iLength + 1) )
	{
		fprintf(stderr,"Invalid position\n");
		_exit(EXIT_FAILURE);
	}	
	
	if (iPos == 1)
	{
		InsertFirst(Head,iNo);
	}
	else if (iPos == iLength + 1)
	{
		InsertLast(Head,iNo);
	}
	else
	{
		for (iCnt = 1; iCnt<iPos - 1; iCnt++)
		{
			tempPtr = tempPtr -> nextPtr;
		}
		
		newNode = (PNODE)malloc(sizeof(NODE));
		
		newNode ->iData = iNo;
		newNode -> nextPtr = NULL;
		newNode -> prevPtr = NULL;	// #
		
		newNode->nextPtr = tempPtr->nextPtr;
		tempPtr->nextPtr->prevPtr = newNode;	// #
		
		tempPtr->nextPtr = newNode;
		newNode->prevPtr = tempPtr;	// #
	}
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: DeleteAtPos		
//		Return Type			: void
//		Description			: This function accepts a pointer named as 'First' declared inside main function 
//							  and a position from user.This function is used to delete node at user defined position 
//		Author Name			: Ronak Sunil Mutha
//		Date				: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE Head,int iPos)
{

	auto int iLength = 0;
	PNODE newNode = NULL;
	iLength = CountNodes(*Head);
	
	register int iCnt = 0;
	auto PNODE tempPtr = *Head;
	
	if ( (iPos < 1) || (iPos > iLength) )
	{
		printf("Invalid input!\n");
		return;
	}	
	
	if (iPos == 1)
	{
		DeleteFirst(Head);
	}
	else if (iPos == iLength + 1)
	{
		DeleteLast(Head);
	}
	else
	{
		for (iCnt = 1; iCnt<iPos - 1; iCnt++)
		{
			tempPtr = tempPtr -> nextPtr;
		}
		tempPtr -> nextPtr = tempPtr->nextPtr->nextPtr;
		
		if(tempPtr->nextPtr->prevPtr)
		{
			free(tempPtr->nextPtr->prevPtr);	
		}
		
		tempPtr->nextPtr->prevPtr = tempPtr;	
	} 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		Entry point function main
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc,char * argv[])
{
	printf("\n-*-*-*-*-*-*-*-*-*-*- Data structures and algorithms using c programming -*-*-*-*-*-*-*-*-*-*-*\n");

	printf("\n\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("\t\t\tImplementation of doubly linear linked list\n");	
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");

	auto PNODE First = NULL;
	auto signed int iChoice = 0,iValue = 0,iPosition = 0,iRet = 0;
		
	while (1)
	{
		printf("\n----------------------------------------------------------------\n");
		printf("1 : Insert Node at First position \n");
		printf("2 : Insert Node at Last position\n");
		printf("3 : Insert Node at the given position\n");
		printf("4 : Delete Node at the First position\n");
		printf("5 : Delete Node at the Last position\n");
		printf("6 : Delete Node at the given position\n");
		printf("7 : Display the elements in linked lists\n");
		printf("8 : Count the elements in linked lists\n");
		printf("9 : Terminate the application\n");
		printf("----------------------------------------------------------------\n");	
		
		printf("\nPlease enter choice : \n");
		printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
		scanf("%d",&iChoice);
		printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");	
	
		switch(iChoice)
		{
			case 1:
				printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
				printf("Enter the value that you want to insert : \n");
				scanf("%d",&iValue);
				printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
				
				InsertFirst(&First,iValue);
				break;
			
			case 2:			
				printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
				printf("Enter the value that you want to insert : \n");
				scanf("%d",&iValue);
				printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
				
				InsertLast(&First,iValue);
				break;
			
			case 3:
				printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
				printf("Enter the value that you want to insert : \n");
				scanf("%d",&iValue);
				
				printf("\nEnter the position : \n");
				scanf("%d",&iPosition);
				printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
				InsertAtPos(&First,iValue,iPosition);
			
				break;
			
			case 4:
				DeleteFirst(&First);
				break;
			
			case 5:
				DeleteLast(&First);
				break;
			
			case 6:
				printf("Enter the position : \n");
				scanf("%d",&iPosition);
				DeleteAtPos(&First,iPosition);
				break;
				
			case 7:
				DisplayNodes(First);
				break;
			
			case 8:
				iRet = CountNodes(First);	
				printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
				printf("Number of nodes in linked list are : %d\n",iRet);
				printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
				
				break;
			
			case 9:
				printf("\n-*-*-*-*-*-*-*-*-*-*-*-*- Thankyou for using application -*-*-*-*-*-*-*-*-*-*-*-*-\n");
				return 0;
							
		}/* end of switch case */
	
	}/* end of while */
							
	exit(EXIT_SUCCESS);
}
