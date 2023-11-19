#include<iostream>
using namespace std;

#define EXIT_SUCCESS 0

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

class LinkedList
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

class DoublyCircularLL : public LinkedList
{
	private:
		PNODE Last;						
	public:

		DoublyCircularLL();	
//		~DoublyCircularLL();	
		
/*----------------------------- Function declaration for insertion operations -----------------------------*/
		void InsertFirst(int iNo);
		void InsertLast(int iNo);	
		void InsertAtPos(int iNo,int iPos);

		
/*----------------------------- Function declaration for deletion operations -----------------------------*/
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int iPos);

};

void DoublyCircularLL :: InsertFirst(int iNo)
{
	PNODE newNode = new NODE(iNo);
	
	if ( (First == NULL) && (Last == NULL) )
	{
		First = newNode;
		Last = newNode;
	}
	else
	{
		newNode->nextPtr = First;
		First->prevPtr = newNode;
		
		First = newNode;
	}
	Last -> nextPtr = First;
	First -> prevPtr = Last;
	
	iCount = iCount + 1;
}

void DoublyCircularLL :: InsertLast(int iNo)
{
	PNODE newNode = new NODE(iNo);
	
	if ( (First == NULL) && (Last == NULL) )
	{
		First = newNode;
		Last = newNode;
	}
	else
	{
		Last->nextPtr =  newNode;
		newNode->prevPtr = Last;
		
		Last = newNode;
	}
	Last -> nextPtr = First;
	First -> prevPtr = Last;
	
	iCount = iCount + 1;
}

void DoublyCircularLL :: DeleteFirst()
{
	
	if(iCount == 0)		/* If linked list is empty */
	{
		return;
	}
	else if(iCount == 1)	/* If linked list contains one node */
	{
		delete First;
		
		First = NULL;
		Last = NULL;
	}
	else			/* If linked list contains more than one code */
	{
		First = First->nextPtr;
		delete Last->nextPtr;
		
		First->prevPtr = Last;	
		Last->nextPtr = First;
	}
	iCount = iCount - 1;
}

void DoublyCircularLL :: DeleteLast()
{	
	if(iCount == 0)		/* If linked list is empty */
	{
		return;
	}
	else if(iCount == 1)	/* If linked list contains one node */
	{
		delete First;
		
		First = NULL;
		Last = NULL;
	}
	else			/* If linked list contains more than one code */
	{	
		Last = Last->prevPtr;
		delete Last->nextPtr;	
		
		First->prevPtr = Last;	
		Last->nextPtr = First;
	}
		iCount = iCount - 1;
}

void DoublyCircularLL :: InsertAtPos(int iNo,int iPos)
{
	if( (iPos < 1) || (iPos > iCount + 1) )
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
		PNODE iTemp = First;
		int iCnt = 0;
		
		for (iCnt = 1; iCnt < iPos -1; iCnt++)
		{
			iTemp = iTemp->nextPtr;
		}
		
		PNODE newNode = new NODE(iNo);
		
		newNode->nextPtr = iTemp->nextPtr;
		iTemp->nextPtr->prevPtr = newNode;
		
		iTemp->nextPtr = newNode;
		newNode->prevPtr = iTemp;
		
		iCount = iCount + 1;
	}
}

void DoublyCircularLL :: DeleteAtPos(int iPos)
{
	if( (iPos < 1) || (iPos > iCount) )
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
		PNODE iTemp = First;
		int iCnt = 0;
		for (iCnt = 1; iCnt < iPos -1; iCnt++)
		{
			iTemp = iTemp->nextPtr;
		}
		
		iTemp->nextPtr = iTemp->nextPtr->nextPtr;
		delete iTemp->nextPtr->prevPtr;
		
		iTemp->nextPtr->prevPtr =iTemp;
		
		iCount = iCount - 1;
		
	}
}

DoublyCircularLL :: DoublyCircularLL()
{
	Last = NULL;
}

int main(int argc,char *argv[])
{
		
	DoublyCircularLL dObj;
	
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
