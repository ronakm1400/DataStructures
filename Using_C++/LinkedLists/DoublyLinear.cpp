/* Implementation of doubly linear linked list using c++ */

#include<iostream>
using namespace std;

#define EXIT_SUCCESS 0

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Class Name				: Node
//	Public Characteristics	: integer ,integer pointer,integer pointer	
//	Constructor				: Default Constructor,Parameterized Costructor	
//	
//////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef class Node
{
	public:
		int iData;
		Node *nextPtr;			
		Node *prevPtr;
		
		Node()
		{
			iData = 0;
			nextPtr = NULL;
			prevPtr = NULL;
		}
		
		Node(int iValue)
		{
			iData = iValue;
			nextPtr = NULL;
			prevPtr = NULL;
		}
						
}NODE,*PNODE;
/*
----------------------------------------------------------
	Old Name			New Name
----------------------------------------------------------
	Node				 NODE
	*Node				 PNODE
----------------------------------------------------------
*/

class LinkedList : public Node
{
	public:
		PNODE First;
		int iCount;
	
	public:	
		LinkedList()
		{
			First = NULL;
			iCount = 0;
		}
				
		virtual void InsertFirst(int iNo) = 0;
		virtual void InsertLast(int iNo) = 0;	
		virtual void InsertAtPos(int iNo,int iPos) = 0;

		virtual void DeleteFirst() = 0;
		virtual void DeleteLast() = 0;
		virtual void DeleteAtPos(int iPos) = 0;

		void DisplayNodes()
		{
			int iCnt = 0;
			PNODE iTemp = First;
			
			for(iCnt = 1; iCnt <= iCount; iCnt++)
			{
				cout<<"|"<<iTemp->iData<<"|<=>";
				iTemp = iTemp->nextPtr;
			}
			cout<<"\n";
		}
		
		int CountNodes()
		{
			return iCount;
		}
		
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Class Name		: Doubly
//	Private Characteristics	: integer ,integer pointer	
//	Public Behaviours	: InsertFirst,InsertLast,InsertAtPos,DeleteFirst,DeleteLast,DeleteAtPos,	
//				  DisplayNodes,CountNodes
//	Constructor		: Default Constructor	
//	
//////////////////////////////////////////////////////////////////////////////////////////////////////////

class DoublyLinearLL : public LinkedList
{			
	public:

//		~DoublyLinearLL();		/* Destructor*/
		
/*----------------------------- Function declaration for insertion operations -----------------------------*/
		void InsertFirst(int iNo);
		void InsertLast(int iNo);	
		void InsertAtPos(int iNo,int iPos);

		
/*----------------------------- Function declaration for deletion operations -----------------------------*/
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int iPos);

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Class Function Name 	: InsertFirst	
//		Parameters				: integer
//		Description				: This function inserts node at the first position
//		Return Type				: void
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLinearLL :: InsertFirst(int iNo)		/* Function Definition */
{
	PNODE newNode = NULL;
	
	/* Dynamic memory allocation */
	newNode = new NODE(iNo);
	
	if (First == NULL)				/* If Linked List is empty */
	{
		First = newNode; 
	}
	else						/* If Linked List contains atleast one node */
	{
		newNode->nextPtr = First;
		First->prevPtr = newNode;		
		First = newNode;
	}
	iCount = iCount + 1;
} 

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Class Function Name 	: InsertLast	
//		Parameters		: integer
//		Description		: This function inserts node at the last position
//		Return Type		: void
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLinearLL :: InsertLast(int iNo)
{
	
	PNODE newNode = NULL;
	
	/* Dynamic memory allocation */
	newNode = new NODE(iNo);
	
	if (First == NULL)				/* If Linked List is empty */
	{
		First = newNode; 
	}
	else						/* If Linked List contains atleast one node */
	{
		PNODE iTemp = First;
		
		while(iTemp->nextPtr != NULL)
		{
			iTemp = iTemp->nextPtr;
		}
		newNode->prevPtr = iTemp;
		iTemp->nextPtr = newNode;
	}
	iCount = iCount + 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Class Function Name 	: DeleteFirst	
//		Parameters		: nothing
//		Description		: This function deletes the first node in the linked list
//		Return Type		: void
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLinearLL :: DeleteFirst()
{

	if (First == NULL)		// LL is empty
	{
		return;
	}
	
	else if (First->nextPtr == NULL)	/* If linked list contains only 1 node */
	{
		delete First;
		First = NULL;
	}
	else					/* If linked list contains more than 1 node */
	{
		First = First->nextPtr;
		delete First->prevPtr;		
		First->prevPtr = NULL;	
	}
	iCount = iCount - 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Class Function Name 	: DeleteLast	
//		Parameters		: nothing
//		Description		: This function deletes the last node of the linked list
//		Return Type		: void
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLinearLL :: DeleteLast()
{
	
	if (First == NULL)		/* If linked list is empty */
	{
		return;
	}
	
	else if (First->nextPtr == NULL)	/* If linked list contains 1 node */
	{
		delete First;
		First = NULL;
	}
	
	else					/* If linked list contains more than 1 node */
	{
		PNODE iTemp = First;
		while (iTemp->nextPtr->nextPtr != NULL)
		{
			iTemp = iTemp->nextPtr;	
		}
		delete iTemp->nextPtr;
		iTemp->nextPtr = NULL;		
	}
	iCount = iCount - 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Class Function Name 	: InsertAtPos	
//		Parameters		: integer,integer
//		Description		: This function inserts the node at the user defined position 
//					  of the linked list
//		Return Type		: void
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLinearLL :: InsertAtPos(int iNo,int iPos)
{
	
	if ( (iPos < 1) || (iPos > iCount + 1) )
	{
		return;
	}	
	
	if(iPos == 1)
	{
		InsertFirst(iNo);
	}
	else if(iPos == iCount + 1)
	{
		InsertLast(iNo);
	}
	else
	{
		signed int iCnt = 0;
		PNODE iTemp = First;
		
		for (iCnt = 1; iCnt<iPos - 1; iCnt++)
		{
			iTemp = iTemp->nextPtr;
		}
		
		PNODE newNode = NULL;
	
		newNode = new NODE(iNo);
		
		newNode->nextPtr = iTemp->nextPtr;	
		iTemp->nextPtr->prevPtr = newNode;	
		
		iTemp->nextPtr = newNode;
		newNode->prevPtr = iTemp;
			
		iCount = iCount + 1;	
	}
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Class Function Name 	: DeleteAtPos	
//		Parameters		: integer
//		Description		: This function delete the node at the user defined position 
//					  of the linked list
//		Return Type		: void
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void DoublyLinearLL :: DeleteAtPos(int iPos)
{	
	
	if ( (iPos < 1) || (iPos > iCount) )
	{
		return;
	}	
	
	if (iPos == 1)
	{
		DeleteFirst();
	}
	else if (iPos == iCount)
	{
		DeleteLast();
	}
	else
	{
		signed int iCnt = 0;
		PNODE iTemp = First;
		
		for (iCnt = 1; iCnt < iPos - 1; iCnt++)
		{
			iTemp = iTemp->nextPtr;
		}
		iTemp->nextPtr = iTemp->nextPtr->nextPtr;
		
		delete iTemp->nextPtr->prevPtr;	
		
		iTemp->nextPtr->prevPtr = iTemp;
		
		iCount = iCount - 1;
	} 

}
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		Entry point function main
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc,char *argv[])
{
		
	DoublyLinearLL dObj;
	
	unsigned int iChoice = 0,iValue = 0,iPosition = 0,iRet = 0;
		
	cout<<"\n-*-*-*-*-*-* Data structures and algorithm using object oriented approach -*-*-*-*-*-*\n";
	
	while (1)
	{
		cout<<"\nPlease enter choice : \n";
		cout<<"----------------------------------------------------------------\n";
		cout<<"1 : Insert Node at First position \n";
		cout<<"2 : Insert Node at Last position\n";
		cout<<"3 : Insert Node at the given position\n";
		cout<<"4 : Delete Node at the First position\n";
		cout<<"5 : Delete Node at the Last position\n";
		cout<<"6 : Delete Node at the given position\n";
		cout<<"7 : Display the elements in linked lists\n";
		cout<<"8 : Count the elements in linked lists\n";
		cout<<"9 : Terminate the application\n";
		cout<<"----------------------------------------------------------------\n";	
	
		cin>>iChoice;
		
	
		switch(iChoice)
		{
			case 1:
				
				cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				cout<<"Enter the value that you want to insert : \n";
				cin>>iValue;
				cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				
				dObj.InsertFirst(iValue);
				break;
			
			
			case 2:
				
				cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				cout<<"Enter the value that you want to insert : \n";
				cin>>iValue;
				cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				
				dObj.InsertLast(iValue);
				break;
			
			case 3:
				cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				cout<<"Enter the value that you want to insert : \n";
				cin>>iValue;
				
				cout<<"\nEnter the position : \n";
				cin>>iPosition;
				cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				dObj.InsertAtPos(iValue,iPosition);
				break;
			
			case 4:
				dObj.DeleteFirst();
				break;
			
			case 5:
				dObj.DeleteLast();
				break;
			
			case 6:
				cout<<"Enter the position : \n";
				cin>>iPosition;
				dObj.DeleteAtPos(iPosition);
				break;
				
			case 7:
				dObj.DisplayNodes();
				break;
			
			case 8:
				iRet = dObj.CountNodes();
				
				cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				cout<<"Number of nodes in linked list are : "<<iRet<<"\n";
				cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				
				break;
			
			case 9:
				return 0;
							
		}
			
	}
	return EXIT_SUCCESS;

}
