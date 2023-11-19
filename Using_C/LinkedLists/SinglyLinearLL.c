/* Implementation of Singly Linear Linked List using c programming*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

// Declaration of structure 
//
//-------------------------------------------------------------
//	Old Name			New Name
//-------------------------------------------------------------
//	
//	NodeS				 NODE	
//	NodeS*				 PNODE
//	NodeS**				 PPNODE	
//-------------------------------------------------------------
//

typedef struct Node		
{
	int iData;
	struct Node *nextPtr;		/* Self referential structure */

}NODE,*PNODE,**PPNODE;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: InsertFirst		
//		Return Type		: void
//		Description		: This function accepts the address of the a pointer named as 'First' 
//					  declared inside main function and one integer value.This function 
//					  is used to insert node at the first position
//		Author Name		: Ronak Sunil Mutha
//		Date			: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE Head,int iNo)
{
	/* Creation of newnode */
	auto PNODE newNode = NULL;
	
	/* Dynamic memory allocation for newnode */
	newNode = (PNODE)malloc(sizeof(NODE));
	
	/* Initialization of data into newnode */
	newNode -> iData = iNo;
	newNode -> nextPtr = NULL;
	
	if (*Head == NULL)			/* If linked list is empty */
	{
		*Head = newNode;	
	}
	else					/* If linked list contains at least one node */
	{
		newNode -> nextPtr = *Head;
		*Head = newNode;
	}
	
}/* end of InsertFirst */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: InsertLast		
//		Return Type		: void
//		Description		: This function accepts the address of the a pointer named as 'First' 
//					  declared inside main function.This function is used to insert node 
//					  at the last position
//		Author Name		: Ronak Sunil Mutha
//		Date			: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head,int iNo)
{
	auto PNODE newNode = NULL;
	auto PNODE iTemp = *Head;

	/* Dynamic memory allocation for newnode */	
	newNode = (PNODE)malloc(sizeof(NODE));

	/* Initialization of data into newnode */
	newNode -> iData = iNo;
	newNode -> nextPtr = NULL;
	
	if (*Head == NULL)			/* If linked list is empty */
	{
		*Head = newNode;	
	}
	else					/* If linked list contains at least one node */
	{
		while (iTemp->nextPtr != NULL)
		{
			iTemp = iTemp->nextPtr;
		}
		iTemp->nextPtr = newNode;
	}

}/* end of InsertLast */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: DeleteFirst		
//		Return Type		: void
//		Description		: This function accepts address of a pointer named as 'First' declared
//					  inside main function.This function is used to delete node at the first
//					  position
//		Author Name		: Ronak Sunil Mutha
//		Date			: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head)
{
	auto PNODE iTemp = *Head; 
	
	if (*Head == NULL)				/* If linked list is empty */
	{
		return;
	}	
	else if( (*Head)->nextPtr == NULL)			/* If linked list contains atleast one node */
	{		
		free(*Head);
		*Head = NULL;
	}
	else						/* If linked list contains more than one node */
	{
		*Head = (*Head) -> nextPtr;
		free(iTemp);		
	}

}/* end of DeleteFirst */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: DeleteLast		
//		Return Type		: void
//		Description		: This function accepts address of a pointer named as 'First' declared
//					  inside main function.This function is used to delete node at the last 
//					  position
//		Author Name		: Ronak Sunil Mutha
//		Date			: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head)
{	
	auto PNODE iTemp = *Head;
	
	if (*Head == NULL)					/* If linked list is empty */
	{
		return;
	}	
	else if( (*Head)->nextPtr == NULL)			/* If linked list contains atleast one node */
	{		
		free(*Head);
		*Head = NULL;
	}
	else							/* If linked list contains more than one node */
	{
		while (iTemp->nextPtr->nextPtr != NULL)
		{
			iTemp = iTemp->nextPtr;
		}
		
		if(iTemp->nextPtr)
		{
			free(iTemp->nextPtr);
		}
		
		iTemp->nextPtr = NULL;		
	}
	
}/* end of DeleteLast */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: DisplayNode		
//		Return Type		: void
//		Description		: This function accepts a pointer named as 'First' declared 
//					  inside main function.This function is used display elements stored in 
//					  linked list		
//		Author Name		: Ronak Sunil Mutha
//		Date			: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DisplayNode(PNODE Head)
{
	
	printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");	
	printf("Elements of linked-list are : ");

	while (Head != NULL)
	{
		printf("|%d|->",Head->iData);
		Head = Head -> nextPtr;
	}
	printf("NULL\n");
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
		
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: CountNode		
//		Return Type		: int
//		Description		: This function accepts a pointer named as 'First' which is 
//					  declared inside main function. This function counts the number of 
//				          nodes in linked list. 
//		Author Name		: Ronak Sunil Mutha
//		Date			: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CountNode(PNODE Head)
{
	auto signed int iCount = 0;
	
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
//		Return Type		: void
//		Description		: This function accepts the address of the a pointer named as 'First' 
//					  declared inside main function an integer value and a position from 
//					  user.This function is used to insert node at user defined position 
//		Author Name		: Ronak Sunil Mutha
//		Date		 	: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE Head,int iNum,int iPos)
{
	auto int iLength = 0;
	register int iCnt = 0;
	auto PNODE iTemp = *Head;
	auto PNODE newNode = NULL;
	
	/* call to CountNode function to calculate number of nodes in linked list */
	iLength = CountNode(*Head);	
	
	/* Filter if user enters invalid positions */
	if ( (iPos < 1) || (iPos > (iLength + 1)) )	
	{
		fprintf(stderr,"Invalid position\n");
		_exit(EXIT_FAILURE);
	}	
	
	if (iPos == 1)						/* If user enters position 1 */
	{
		InsertFirst(Head,iNum);
	}
	else if (iPos == iLength + 1)				/* If user enters position number of nodes + 1 */
	{
		InsertLast(Head,iNum);
	}
	else					/* If user enters any position in between number of nodes */
	{
		newNode = (PNODE)malloc(sizeof(NODE));
		newNode->iData = iNum;
		newNode->nextPtr = NULL;
		
		for (iCnt = 1; iCnt < iPos - 1; iCnt++)
		{
			iTemp = iTemp ->nextPtr;
		}
		newNode->nextPtr = iTemp->nextPtr;
		iTemp->nextPtr = newNode;
	}


}/* end of InsertAtPos */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: DeleteAtPos		
//		Return Type		: void
//		Description		: This function accepts a pointer named as 'First' declared inside main 
//					  function and a position from user.This function is used to delete node 
//					  at user defined position 
//		Author Name		: Ronak Sunil Mutha
//		Date			: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE Head,int iPos)
{
	auto PNODE iTemp = *Head;
	auto PNODE iTempX = NULL;
	register int iCnt = 0;	
	auto int iLength = 0;
	iLength = CountNode(*Head);	
	
	/* Filter if user enters invalid positions */
	if ( (iPos < 1) || (iPos > iLength ) )	
	{
		fprintf(stderr,"Invalid position\n");
		_exit(EXIT_FAILURE);
	}	
	
	if (iPos == 1)						/* If user enters position 1 */
	{
		DeleteFirst(Head);
	}
	else if (iPos == iLength)				/* If user enters the last position of node */
	{
		DeleteLast(Head);
	}
	else					/* If user enters any position in between number of nodes */
	{
		for (iCnt = 1; iCnt < iPos - 1; iCnt++)
		{
			iTemp = iTemp ->nextPtr;
		}
		iTempX = iTemp->nextPtr;
	
		iTemp->nextPtr = iTemp->nextPtr->nextPtr;
		
		if(iTempX)
		{	
			free(iTempX);
		}
	}

}/* end of DeleteAtPos */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		Entry point function main
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc,char * argv[])
{
	printf("\n-*-*-*-*-*-*-*-*-*-*- Data structures and algorithms using c programming -*-*-*-*-*-*-*-*-*-*-*\n");

	printf("\n\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("\t\t\tImplementation of singly linear linked list\n");	
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
				DisplayNode(First);
				break;
			
			case 8:
				iRet = CountNode(First);	
				printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
				printf("Number of nodes in linked list are : %d\n",iRet);
				printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
				
				break;
			
			case 9:
				printf("\n-*-*-*-*-*-*-*-*-*-*-*-*- Thankyou for using application -*-*-*-*-*-*-*-*-*-*-*-*-\n");
				return EXIT_SUCCESS;
							
		}/* end of switch case */
	
	}/* end of while */
							
	exit(EXIT_SUCCESS);

}
