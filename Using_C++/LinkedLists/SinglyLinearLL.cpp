#include<iostream>
using namespace std;

/* Declaration of structure */
typedef struct Node
{
	int iData;
	struct Node *nextPtr;
}NODE,*PNODE;
/*
----------------------------------------------------------
	Old Name			New Name
----------------------------------------------------------
	Node				 NODE
	*Node				 PNODE
----------------------------------------------------------
*/

class SinglyLinearLL
{
	private:
		/* Characteristics */
		int iCount;
		PNODE First;
	
	public:
		/* Default Constructor */
		SinglyLinearLL();
		~SinglyLinearLL();
		
		/* Function declaration for insertion operations */
		void InsertFirst(int iNo);
		void InsertLast(int iNo);
		void InsertAtPos(int iNo,int iPos);
		
		/* Function declaration for deletion operations */
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int iPos);
		
		/* Function declaration to display nodes of linked lists */
		void DisplayNodes();
		int CountNodes();

};

void SinglyLinearLL :: InsertFirst(int iNo)
{
	
	PNODE newNode = NULL;
		
	newNode = new NODE();
	
	newNode->iData = iNo;
	newNode->nextPtr = NULL;
	
	if (First == NULL)
	{
		First = newNode;
	}
	
	else
	{
		newNode->nextPtr = First;
		First = newNode;
	}
	iCount = iCount + 1;
	
}

void SinglyLinearLL :: InsertLast(int iNo)
{
	PNODE newNode = NULL;
	
	newNode = new NODE();
	
	newNode->iData = iNo;
	newNode->nextPtr = NULL;
	
	if (First == NULL)
	{
		First = newNode;
	}
	else
	{
		PNODE iTemp = First;
		while (iTemp->nextPtr != NULL)
		{
			iTemp = iTemp->nextPtr;
		}	
		iTemp->nextPtr = newNode;
	}

	iCount = iCount + 1;

}

void SinglyLinearLL :: DeleteFirst()
{		
	if(First == NULL)
	{
		return;
	}
	else if (First->nextPtr == NULL)
	{
		delete First;
		First = NULL;
	}	
	else 
	{
		PNODE iTemp = First;
		
		First = First -> nextPtr;
		delete iTemp;
	}
	iCount = iCount - 1;
}

void SinglyLinearLL :: DeleteLast()
{
	PNODE iTemp = NULL;
	
	if(First == NULL)
	{
		return;
	}
	else if (First->nextPtr == NULL)
	{
		delete First;
		First = NULL;
	}	
	else
	{
		PNODE iTemp = First;
		while(iTemp->nextPtr->nextPtr != NULL)
		{
			iTemp = iTemp->nextPtr;
		}
		delete iTemp->nextPtr;
		iTemp->nextPtr = NULL;
	}
	
	iCount = iCount - 1;
}

void SinglyLinearLL :: DisplayNodes()
{
	PNODE iTemp = First;
	
	while(iTemp != NULL)
	{
		cout<<"|"<<iTemp->iData<<"|->";
		iTemp = iTemp->nextPtr;
	}
	cout<<"NULL\n";
}

int SinglyLinearLL :: CountNodes()
{
	return iCount;
}

/* Default Constructor */
SinglyLinearLL :: SinglyLinearLL()
{
	First = NULL;
	iCount = 0;
}

/* Destructor */
SinglyLinearLL :: ~SinglyLinearLL()
{
	PNODE iTemp = First;
	
	for (int iCnt = 1; iCnt <= iCount; iCnt++)
	{
		iTemp = First;
		First = First->nextPtr;
		delete iTemp;
	}

}

void SinglyLinearLL :: InsertAtPos(int iNo,int iPos)
{	
	if( (iPos < 1) || (iPos > (iCount + 1)) )
	{
		return;
	}
	
	if (iPos == 1)
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
		
		for (iCnt = 1; iCnt < iPos-1; iCnt++)
		{
			iTemp = iTemp->nextPtr;
		}
		
		PNODE newNode = NULL;	
		newNode = new NODE;
		
		newNode->iData = iNo;
		newNode->nextPtr = NULL;
	
		newNode->nextPtr = iTemp->nextPtr;		
		iTemp->nextPtr = newNode;

		iCount = iCount + 1;

	}
}

void SinglyLinearLL :: DeleteAtPos(int iPos)
{
	
	if( (iPos < 1) || (iPos > iCount) ) 
	{
		return;
	}
	
	if (iPos == 1)
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
		PNODE iTempX = NULL;
		
		signed int iCnt = 0;
		for(iCnt = 1; iCnt<iPos-1; iCnt++)
		{
			iTemp = iTemp->nextPtr;
		}
		iTempX = iTemp->nextPtr;
		iTemp->nextPtr = iTemp->nextPtr->nextPtr;
		
		delete iTempX;
		
		iCount = iCount - 1;	
	}
	
}
int main(int argc,char *argv[])
{
	
	SinglyLinearLL sObj;
	
	int iChoice = 0,iValue = 0,iPosition = 0,iRet = 0;
		
	cout<<"Marvellous LinkedList Application\n";
	
	while (1)
	{
		cout<<"Please enter choice : \n";
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
				cout<<"Enter the value that you want to insert : \n";
				cin>>iValue;
				sObj.InsertFirst(iValue);
				break;
			
			
			case 2:
				cout<<"Enter the value that you want to insert : \n";
				cin>>iValue;
				sObj.InsertLast(iValue);
				break;
			
			case 3:
				cout<<"Enter the value that you want to insert : \n";
				cin>>iValue;
				
				cout<<"Enter the position : \n";
				cin>>iPosition;
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
				cout<<"Number of nodes in linked list are : "<<iRet<<"\n";
				break;
			
			case 9:
				return 0;
							
		}
			
	}
	
	return 0;

}
