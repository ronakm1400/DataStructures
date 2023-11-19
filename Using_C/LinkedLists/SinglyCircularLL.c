/*	SINGLY CIRCULAR LINKED LIST	*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

// Declaration of structure 
//-------------------------------------------------------------
//	Old Name			New Name
//-------------------------------------------------------------
//	
//	Node				 NODE	
//	Node*				 PNODE
//	Node**				 PPNODE	
//-------------------------------------------------------------

typedef struct Node
{
	int iData;
	struct Node *nextPtr;

}NODE,*PNODE,**PPNODE;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: InsertFirst		
//		Return Type			: void
//		Description			: This function accepts the address of the a pointer named as 'First' and 'Last'
//					  		  declared inside main function and one integer value.This function 
//					  		  is used to insert node at the first position
//		Author Name			: Ronak Sunil Mutha
//		Date				: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE Head,PPNODE Tail,int iNo)
{
	auto PNODE newNode = NULL;
	
	/* Memory allocation to new node*/
	newNode = (PNODE)malloc(sizeof(NODE));
	
	/*Initializing the newnode */
	newNode->iData = iNo;
	newNode->nextPtr = NULL;
	
	if ( (*Head == NULL) && (*Tail == NULL) )	// LL is empty
	{
		*Head = newNode;
		*Tail = newNode;
	}
	else		// LL contains atleast one node	
	{
		newNode->nextPtr = *Head;
		*Head = newNode;
			
	}
	(*Tail)->nextPtr = *Head;	// To maintain the circular nature of LL
	
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: InsertLast		
//		Return Type			: void
//		Description			: This function accepts the address of the a pointer named as 'First' and 'Last'
//					  		  declared inside main function.This function is used to insert node 
//					  		  at the last position
//		Author Name			: Ronak Sunil Mutha
//		Date				: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head,PPNODE Tail,int iNo)
{
	auto PNODE newNode = NULL;
	
	/* Memory allocation to new node*/
	newNode = (PNODE)malloc(sizeof(NODE));
	
	/*Initializing the newnode */
	newNode->iData = iNo;
	newNode->nextPtr = NULL;
	
	if ( (*Head == NULL) && (*Tail == NULL) )	// LL is empty
	{
		*Head = newNode;
		*Tail = newNode;	
	}
	else
	{	
		(*Tail)->nextPtr = newNode;
		*Tail = (*Tail)->nextPtr;	// *Tail = newNode
	}
	(*Tail)->nextPtr = *Head;	
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: DeleteFirst		
//		Return Type			: void
//		Description			: This function accepts a pointer named as 'First' and 'Last'
//					  		  declared inside main function.This function is used to delete node 
//			  	 	  		  at the first position
//		Author Name			: Ronak Sunil Mutha
//		Date				: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	
	if ( (*Head == NULL) && (*Tail == NULL) )	// 1st condition
	{
		return;
	}
	else if (*Head == *Tail)	// 2nd Condition
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else				// 3rd Condition
	{
		*Head = (*Head)->nextPtr;
		
		if((*Tail)->nextPtr)
		{
			free((*Tail)->nextPtr);	
		}
		
		(*Tail)->nextPtr = *Head;	
	}
	
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: DeleteLast		
//		Return Type			: void
//		Description			: This function accepts a pointer named as 'First' and 'Last'
//					 	 	  declared inside main function.This function is used to delete node 
//			  	 			  at the last position
//		Author Name			: Ronak Sunil Mutha
//		Date				: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head,PPNODE Tail)
{
	auto PNODE tempPtr = *Head;
	
	if ( (*Head == NULL) && (*Tail == NULL) )
	{
		return;
	}
	else if (*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		while (tempPtr->nextPtr != *Tail)
		{
			tempPtr = tempPtr->nextPtr;
		}
		
		if(*Tail)
		{
			free(*Tail);
		}
		
		*Tail = tempPtr;
		
		(*Tail)->nextPtr = *Head;	
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

void DisplayNodes(PNODE Head,PNODE Tail)
{
	printf("\nElements in linked list are : ");
	
	printf("->");
	if ((Head != NULL) && (Tail != NULL))
	{
		do
		{
			printf("|%d|->",Head->iData);
			Head = Head->nextPtr;
		}while (Head != Tail->nextPtr);
	}
	else
	{
		printf("Linked list is empty\n");
	}
	printf("\n");
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

int CountNodes(PNODE Head,PNODE Tail)
{
	auto int iCount = 0;
		
	if ((Head != NULL) && (Tail != NULL))
	{
		do
		{
			iCount = iCount + 1;
			Head = Head->nextPtr;
		}while (Head != Tail->nextPtr);		
		return iCount;
	}
	else
	{
		return 0;
	}
	printf("\n");

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: InsertAtPos		
//		Return Type			: void
//		Description			: This function accepts the address of the a pointer named as 'First' and 'Last'
//							  declared inside main function an integer value and a position from 
//							  user.This function is used to insert node at user defined position 
//		Author Name			: Ronak Sunil Mutha
//		Date				: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE Head,PPNODE Tail,int iNo,int iPos)
{
	auto PNODE newNode = NULL;
	auto PNODE tempPtr = *Head;
	auto int iLength = 0;
	register int iCnt = 0;
	
	iLength = CountNodes(*Head,*Tail);
	
	if ( (iPos < 1) || (iPos > iLength + 1) )
	{
		fprintf(stderr,"Invalid position\n");
		_exit(EXIT_FAILURE);
	}
	
	if (iPos == 1)
	{
		InsertFirst(Head,Tail,iNo);
	}
	else if (iPos == iLength + 1)
	{
		InsertLast(Head,Tail,iNo);
	}
	else
	{
		for (iCnt = 1;iCnt < iPos - 1; iCnt++)
		{
			tempPtr = tempPtr -> nextPtr;
		}
		
		/* Memory allocation of new node */
		newNode = (PNODE)malloc(sizeof(NODE));
		
		/* Initialization of data into newnode*/
		newNode->iData = iNo;
		newNode->nextPtr = NULL;
		
		newNode->nextPtr = tempPtr->nextPtr;
		tempPtr->nextPtr = newNode;
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Function Name		: DeleteAtPos		
//		Return Type			: void
//		Description			: This function accepts a pointer named as 'First' and 'Last'
//					  		  declared inside main function and a position from user.
//					 		  This function is used to delete node at user defined position 
//		Author Name			: Ronak Sunil Mutha
//		Date				: 15/06/2023
//		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE Head,PPNODE Tail,int iPos)
{

	auto PNODE tempPtr = *Head;
	auto PNODE tempPtrX = NULL;
	auto int iLength = 0;
	register int iCnt = 0;
	
	iLength = CountNodes(*Head,*Tail);
	
	if ( (iPos < 1) || (iPos > iLength) )
	{
		fprintf(stderr,"Invalid position\n");
		_exit(EXIT_FAILURE);
	}
	
	if (iPos == 1)
	{
		DeleteFirst(Head,Tail);
	}
	else if (iPos == iLength)
	{
		DeleteLast(Head,Tail);
	}
	else
	{
		for (iCnt = 1;iCnt < iPos - 1; iCnt++)
		{
			tempPtr = tempPtr -> nextPtr;
		}
		tempPtrX = tempPtr -> nextPtr;
				
		tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
		if(tempPtrX)
		{
			free(tempPtrX);
		}
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		Entry point function main
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc,char *argv[])
{
	printf("\n-*-*-*-*-*-*-*-*-*-*- Data structures and algorithms using c programming -*-*-*-*-*-*-*-*-*-*-*\n");

	printf("\n\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("\t\t\tImplementation of singly circular linked list\n");	
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");

	auto PNODE First = NULL;
	auto PNODE Last = NULL;
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
				
				InsertFirst(&First,&Last,iValue);
				break;
			
			case 2:			
				printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
				printf("Enter the value that you want to insert : \n");
				scanf("%d",&iValue);
				printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
				
				InsertLast(&First,&Last,iValue);
				break;
			
			case 3:
				printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
				printf("Enter the value that you want to insert : \n");
				scanf("%d",&iValue);
				
				printf("\nEnter the position : \n");
				scanf("%d",&iPosition);
				printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
				InsertAtPos(&First,&Last,iValue,iPosition);
			
				break;
			
			case 4:
				DeleteFirst(&First,&Last);
				break;
			
			case 5:
				DeleteLast(&First,&Last);
				break;
			
			case 6:
				printf("Enter the position : \n");
				scanf("%d",&iPosition);
				DeleteAtPos(&First,&Last,iPosition);
				break;
				
			case 7:
				DisplayNodes(First,Last);
				break;
			
			case 8:
				iRet = CountNodes(First,Last);	
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
