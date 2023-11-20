class NodeS
{
	public int iData;
	public NodeS nextPtr;
	
	public NodeS()
	{
		this.iData 	= 0;
		this.nextPtr 	= null;
	}
	
	public NodeS(int iValue)
	{
		this.iData   	= iValue;
		this.nextPtr 	= null;
	}
	
}

interface LinkedList
{
	public void insertFirst(int iNo);
	public void insertLast(int iNo);
	
	public void deleteFirst();
	public void deleteLast();
	
	public void insertAtPos(int iNo,int iPos);
	public void deleteAtPos(int iPos);
}

class SinglyLinear implements LinkedLists 
{
	public NodeS first;
	public int iCount;
				
	public SinglyLinear()
	{
		this.first 	= null;
		this.iCount	= 0;
	}
	
	public void displayNodes()
	{
		int iCnt = 0;
		
		NodeS tempPtr = first;
		
		for(iCnt = 0; iCnt < iCount; iCnt++)
		{
			System.out.print("|"+ tempPtr.iData+"|->");
			tempPtr = tempPtr.nextPtr;
		}
		System.out.println("null");	
	}
	
	public int countNodes()
	{
		return this.iCount;
	}				
	
	public void insertFirst(int iNo)
	{
		NodeS newNode = null;
		
		newNode = new NodeS(iNo);
	
		if(first == null)
		{
			first = newNode;
		}
		else
		{
			newNode.nextPtr = first;
			first = newNode;
		}
		iCount++;
	}
	
	public void insertLast(int iNo)
	{
		NodeS newNode = null;
		
		newNode = new NodeS(iNo);
		
		if(first == null)
		{
			first = newNode;
		}
		else
		{
			NodeS tempPtr = first;
			
			while(tempPtr.nextPtr != null)
			{
				tempPtr = tempPtr.nextPtr;
			}
			
			tempPtr.nextPtr = newNode;
			newNode.nextPtr = null;
		}
		iCount++;
	}
	
	public void deleteFirst()
	{
		if(first == null)
		{
			System.out.println("Linked list is empty\n");		
			return;
		}
		else if(first.nextPtr == null)
		{
			first = null;
		}
		else
		{
			first = first.nextPtr;
		}
		iCount--;
	}
	
	public void deleteLast()
	{
		if(first == null)
		{
			System.out.println("Linked list is empty\n");		
			return;
		}
		else if(first.nextPtr == null)
		{
			first = null;
		}
		else
		{
			NodeS tempPtr = first;
			while(tempPtr.nextPtr != null)
			{
				tempPtr = tempPtr.nextPtr;
			}	
			
			tempPtr.nextPtr = null;
		}
		iCount--;
	}
	
	public void insertAtPos(int iNo,int iPos)
	{
		if((iPos < 0) || (iPos > iCount + 1))
		{
			System.out.println("Invalid position\n");
			return;
		}
		
		if(iPos == 1)
		{
			insertFirst(iNo);
		}
		else if(iPos == iCount + 1)
		{
			insertLast(iNo);
		}
		else
		{
			int iCnt = 0;
			NodeS tempPtr = first;
			
			for(iCnt = 1; iCnt < iPos - 1; iCnt++)
			{
				tempPtr = tempPtr.nextPtr;
			}
			
			NodeS newNode = null;			
			newNode = new NodeS(iNo);
			
			newNode.nextPtr = tempPtr.nextPtr;
			tempPtr.nextPtr = newNode;
			
			iCount++;
		}
		
	}
	
	public void deleteAtPos(int iPos)
	{
			if((iPos < 0) || (iPos > iCount + 1))
		{
			System.out.println("Invalid position\n");
			return;
		}
		
		if(iPos == 1)
		{
			deleteFirst();
		}
		else if(iPos == iCount)
		{
			deleteLast();
		}
		else
		{
			int iCnt = 1;
			NodeS tempPtr = first;
			
			for(iCnt = 1; iCnt < iPos - 1; iCnt++)
			{
				tempPtr = tempPtr.nextPtr;
			}
			
			tempPtr.nextPtr = tempPtr.nextPtr.nextPtr;
			
			iCount--;
		}
		
	}
	
}

class SinglyLinearLL
{
	public static void main(java.lang.String Arg[])
	{
		SinglyLinear sObj = new SinglyLinear();
		
		sObj.insertFirst(101);
		sObj.insertFirst(51);
		sObj.insertFirst(21);
		sObj.insertFirst(11);

	System.out.println("============================================================================");
	
	
	System.out.println("\n----------------------------------------------------------------------------");
		System.out.println("Linked list after inserting nodes at first position : ");
		System.out.println("----------------------------------------------------------------------------");

		sObj.displayNodes();
		System.out.println("Number of elements in linked lists are : "+sObj.countNodes());
	
	System.out.println("\n----------------------------------------------------------------------------");	
		sObj.insertLast(111);
		sObj.insertLast(151);

		System.out.println("Linked list after inserting nodes at last position : ");
		System.out.println("----------------------------------------------------------------------------");		
		sObj.displayNodes();
		System.out.println("Number of elements in linked lists are : "+sObj.countNodes());

	System.out.println("\n----------------------------------------------------------------------------");	
		sObj.insertAtPos(55,4);

		System.out.println("Linked list after inserting node at given position : ");
		System.out.println("----------------------------------------------------------------------------");		
		sObj.displayNodes();
		System.out.println("Number of elements in linked lists are : "+sObj.countNodes());

	System.out.println("\n----------------------------------------------------------------------------");	
		sObj.deleteAtPos(4);

		System.out.println("Linked list after deleting node at given position : ");
		System.out.println("----------------------------------------------------------------------------");		
		sObj.displayNodes();
		System.out.println("Number of elements in linked lists are : "+sObj.countNodes());
	
	System.out.println("\n----------------------------------------------------------------------------");	
		
		sObj.deleteFirst();		
		
		System.out.println("Linked list after deleting node from first position : ");
		System.out.println("----------------------------------------------------------------------------");

		sObj.displayNodes();
		System.out.println("Number of elements in linked lists are : "+sObj.countNodes());

	System.out.println("\n----------------------------------------------------------------------------");	
		
		sObj.deleteLast();
		System.out.println("Linked list after deleting node from last position : ");
		System.out.println("----------------------------------------------------------------------------");

		sObj.displayNodes();
		System.out.println("Number of elements in linked lists are : "+sObj.countNodes());

	System.out.println("\n============================================================================");

	}	
}
