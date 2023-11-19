/* Implementation of singly circular linked list using c++ */

#include<iostream>
using namespace std;

#define EXIT_SUCCESS 0

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Class Name				: Node
//	Public Characteristics	: integer ,integer pointer	
//	Constructor				: Default Constructor,Parameterized Costructor	
//	
//////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef class Node
{

	private:	
		int iData;
		Node *nextPtr;
		
	public:
		Node()
		{
			iData = 0;
			nextPtr = NULL;
		}
		
		Node(int iValue)
		{
			iData = iValue;
			nextPtr = NULL;
		}
		
		/* To access the private characteristics of class Node */
		friend class LinkedList;
		friend class SinglyCircularLL;

}NODE,*PNODE;
/*
----------------------------------------------------------
	Old Name			New Name
----------------------------------------------------------
	Node				 NODE
	*Node				 PNODE
----------------------------------------------------------
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Class Name				: LinkedList
//	Private Characteristics	: integer ,integer pointer to first node,integer pointer to last node	
//	Public Methods			: 6 pure virtual methods, 2 discrete methods		
//	Constructor				: Default Constructor
//	
//////////////////////////////////////////////////////////////////////////////////////////////////////////

class LinkedList
{
	
	private:
		int iCount;
		PNODE First;
		PNODE Last;

	public:
		LinkedList()
		{
			First = NULL;
			Last = NULL;
			iCount = 0;
		}
		
/*----------------------------- Pure virtual functions for insertion operations -----------------------------*/

		virtual void InsertFirst(int iNo) = 0;
		virtual void InsertLast(int iNo) = 0;
		virtual void InsertAtPos(int iNo, int iPos) = 0;
		
/*----------------------------- Pure virtual functions for insertion operations -----------------------------*/

		virtual void DeleteFirst() = 0;
		virtual void DeleteLast() = 0;
		virtual void DeleteAtPos(int iPos) = 0;

/*----------------------------- Function to display elements in linked list-----------------------------*/
		
		void DisplayNodes()
		{
			int iCnt = 0;
			PNODE iTemp = First;
					
			cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
			cout<<"Elements in linked list are : \n";
			cout<<"->";
			for(iCnt = 1; iCnt <= iCount; iCnt++)
			{
				cout<<"|"<<iTemp->iData<<"|->";
				iTemp = iTemp->nextPtr;
			}
			cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
		}

/*----------------------------- Function to count number of elements in linked list-----------------------------*/
				
		int CountNodes()
		{
			return iCount;
		}
		
		/* To access the private characteristics of class LinkedList */
		friend class SinglyCircularLL;
		
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Class Name					: SinglyCircularLL
//	Inherited class				: LinkedList	
//	Public Methods				: InsertFirst,InsertLast,InsertAtPos,DeleteFirst,DeleteLast
//						  		  DeleteAtPos	
//			
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SinglyCircularLL : public LinkedList
{
	public:
/*----------------------------- Function declaration for insertion operations -----------------------------*/
		~SinglyCircularLL();
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

void SinglyCircularLL :: InsertFirst(int iNo)
{
	PNODE newNode = NULL;

	/* Dynamic memory allocation */
	newNode = new NODE(iNo);
	
	if ( (First == NULL) && (Last == NULL) )	/* If linked list is empty */	
	{
		First = newNode;
		Last = newNode;
	}
	else						/* If linked list contains more than 1 node */
	{
		newNode->nextPtr = First;
		First = newNode;
	}
	Last->nextPtr = First;
	iCount = iCount + 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Class Function Name 	: InsertLast	
//		Parameters				: integer
//		Description				: This function inserts node at the last position
//		Return Type				: void
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCircularLL :: InsertLast(int iNo)
{
	PNODE newNode = NULL;
	
	/* Dynamic memory allocation */
	newNode = new NODE(iNo);
	
	if ( (First == NULL) && (Last == NULL) )	/* If linked list is empty */	
	{
		First = newNode;
		Last = newNode;
	}
	else						/* If linked list contains more than 1 node */
	{
		Last->nextPtr = newNode;
		Last = newNode;
	}
	Last->nextPtr = First;
	iCount = iCount + 1;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Class Function Name 	: DeleteFirst	
//		Parameters				: nothing
//		Description				: This function deletes node at the first position
//		Return Type				: void
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCircularLL :: DeleteFirst()
{
	
	if(iCount == 0)		/* If linked list is empty */
	{
		return;
	}
	else if (iCount == 1)	/* If linked contain only 1 node */
	{
		delete First;
		
		First = NULL;
		Last = NULL;
	}
	else			/* If linked contains more than 1 node */
	{
		First = First->nextPtr;
		delete Last->nextPtr;
		
		Last->nextPtr = First;
	}
	iCount = iCount - 1;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Class Function Name 	: DeleteLast	
//		Parameters				: nothing
//		Description				: This function deletes node at the last position
//		Return Type				: void
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCircularLL :: DeleteLast()
{	
	if(iCount == 0)		/* If linked list is empty */
	{
		return;
	}
	else if (iCount == 1)	/* If linked contain only 1 node */
	{
		delete First;
		
		First = NULL;
		Last = NULL;
	}
	else			/* If linked contains more than 1 node */
	{
		PNODE iTemp = First;
		
		while(iTemp->nextPtr != Last)
		{
			iTemp = iTemp->nextPtr;
		}
		delete Last;
		Last = iTemp;
	
		Last->nextPtr = First;		
	}
	iCount = iCount - 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Class Function Name 	: InsertAtPos	
//		Parameters				: integer,integer
//		Description				: This function inserts node at the user defined position
//		Return Type				: void
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCircularLL :: InsertAtPos(int iNo,int iPos)
{
	
	if( (iPos < 1) || (iPos > iCount + 1))
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
		int iCnt = 0;
		PNODE newNode = NULL;
		PNODE iTemp = First;
		
		for(iCnt = 1; iCnt < iPos - 1; iCnt++)
		{
			iTemp = iTemp->nextPtr;
		}
		
		newNode = new NODE(iNo);
		
		newNode->nextPtr = iTemp->nextPtr;
		iTemp->nextPtr = newNode;
		
		iCount = iCount + 1;
			
	}	
}	

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Class Function Name 	: DeleteAtPos	
//		Parameters				: integer
//		Description				: This function deletes node from the user defined position
//		Return Type				: void
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyCircularLL :: DeleteAtPos(int iPos)
{	
	if( (iPos < 1) || (iPos > iCount))
	{
		return;
	}
	
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iCount)
	{
		DeleteLast();
	}
	else
	{
		int iCnt = 0;
		PNODE iTemp = First;
		PNODE iTempX = NULL;
		
		for(iCnt = 1; iCnt < iPos - 1; iCnt++)
		{
			iTemp = iTemp->nextPtr;
		}
		iTempX = iTemp->nextPtr;
		iTemp->nextPtr = iTemp->nextPtr->nextPtr;
		
		delete iTempX;
		
		iCount = iCount - 1;
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		Destructor	: deallocates the allocated resources
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SinglyCircularLL :: ~SinglyCircularLL()
{
	PNODE iTemp = First;
	
	for (int iCnt = 1; iCnt <= iCount; iCnt++)
	{
		iTemp = First;
		First = First->nextPtr;
		delete iTemp;
	}
	cout<<"\nDestructor called\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		Entry point function main
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc,char *argv[])
{
	cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
	cout<<"\t\tImplementation of singly circular linked list using c++ \n";
	cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
	
	SinglyCircularLL sObj;
	
	unsigned int iChoice = 0,iValue = 0,iPosition = 0,iRet = 0;
		
	while (1)
	{
		cout<<"\n----------------------------------------------------------------\n";
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
		
		cout<<"\nPlease enter choice : \n";
		cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
		cin>>iChoice;
		cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";	
	
		switch(iChoice)
		{
			case 1:
				cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				cout<<"Enter the value that you want to insert : \n";
				cin>>iValue;
				cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				
				sObj.InsertFirst(iValue);
				break;
			
			case 2:			
				cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				cout<<"Enter the value that you want to insert : \n";
				cin>>iValue;
				cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				
				sObj.InsertLast(iValue);
				break;
			
			case 3:
				cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				cout<<"Enter the value that you want to insert : \n";
				cin>>iValue;
				
				cout<<"\nEnter the position : \n";
				cin>>iPosition;
				cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				sObj.InsertAtPos(iValue,iPosition);
				break;
			
			case 4:
				sObj.DeleteFirst();
				break;
			
			case 5:
				sObj.DeleteLast();
				break;
			
			case 6:
				cout<<"Enter the position : \n";
				cin>>iPosition;
				sObj.DeleteAtPos(iPosition);
				break;
				
			case 7:
				sObj.DisplayNodes();
				break;
			
			case 8:
				iRet = sObj.CountNodes();
				
				cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				cout<<"Number of nodes in linked list are : "<<iRet<<"\n";
				cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				
				break;
			
			case 9:
				cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";		
				cout<<"Thankyou for using application\n";
				cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				return 0;
							
		}/* end of switch case */
	
	}/* end of while */
			
	return EXIT_SUCCESS;
	
}/* end of main */
