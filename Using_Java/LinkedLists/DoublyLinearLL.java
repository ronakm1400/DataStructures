class NodeD
{
	public int iData;
	public NodeD nextPtr;
	public NodeD prevPtr;
	
	public NodeD()
	{
		this.iData 	= 0;
		this.nextPtr 	= null;
		this.prevPtr  	= null;	
	}
	
	public NodeD(int iValue)
	{
		this.iData   	= iValue;
		this.nextPtr 	= null;
		this.prevPtr	= null;
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

class DoublyLinear implements LinkedList 
{
	public NodeD first;
	public int iCount;
				
	public DoublyLinear()
	{
		this.first 	= null;
		this.iCount	= 0;
	}
	
	public void displayNodes()
	{
		int iCnt = 0;
		
		NodeD tempPtr = first;
		
		for(iCnt = 0; iCnt < iCount; iCnt++)
		{
			System.out.print("|"+ tempPtr.iData+"|<=>");
			tempPtr = tempPtr.nextPtr;
		}
		System.out.println("null");	
	}
	
	public void displayNodesInReverse()
	{
		int iCnt = 0;
		
		NodeD tempPtr = first;
	
		for(iCnt = 0; iCnt < iCount; iCnt++)
		{
			System.out.print("|"+ tempPtr.iData+"|<=>");
			tempPtr = tempPtr.prevPtr;
		}
		System.out.println("null");	
	}
	
	public int countNodes()
	{
		return this.iCount;
	}				
	
	public void insertFirst(int iNo)
	{
		NodeD newNode = null;
		
		newNode = new NodeD(iNo);
	
		if(first == null)
		{
			first = newNode;
		}
		else
		{
			newNode.nextPtr = first;
			first.prevPtr = newNode;
			first = newNode;
		}
		iCount++;
	}
	
	public void insertLast(int iNo)
	{
		NodeD newNode = null;
		
		newNode = new NodeD(iNo);
		
		if(first == null)
		{
			first = newNode;
		}
		else
		{
			NodeD tempPtr = first;
			
			while(tempPtr.nextPtr != null)
			{
				tempPtr = tempPtr.nextPtr;
			}
			
			newNode.prevPtr = tempPtr;
			tempPtr.nextPtr = newNode;
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
		else if(iCount == 1)
		{
			first = null;
		}
		else
		{
			first = first.nextPtr;
			first.prevPtr = null;
			iCount--;	
		}
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
			NodeD tempPtr = first;
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
			NodeD tempPtr = first;
			
			for(iCnt = 1; iCnt < iPos - 1; iCnt++)
			{
				tempPtr = tempPtr.nextPtr;
			}
			
			NodeD newNode = null;			
			newNode = new NodeD(iNo);
			
			newNode.nextPtr = tempPtr.nextPtr;
			tempPtr.nextPtr = newNode;
			
			tempPtr.nextPtr = newNode;
			newNode.prevPtr = tempPtr;		
					
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
			NodeD tempPtr = first;
			
			for(iCnt = 1; iCnt < iPos - 1; iCnt++)
			{
				tempPtr = tempPtr.nextPtr;
			}
			
			tempPtr.nextPtr = tempPtr.nextPtr.nextPtr;
			tempPtr.nextPtr.nextPtr = tempPtr;
			
			iCount--;
		}
		
	}
	
}

class DoublyLinearLL
{
	public static void main(java.lang.String Arg[])
	{
		DoublyLinear dObj = new DoublyLinear();
		
		dObj.insertFirst(101);
		dObj.insertFirst(51);
		dObj.insertFirst(21);
		dObj.insertFirst(11);

	System.out.println("============================================================================");
	
	
	System.out.println("\n----------------------------------------------------------------------------");
		System.out.println("Linked list after inserting nodes at first position : ");
		System.out.println("----------------------------------------------------------------------------");

		dObj.displayNodes();
		System.out.println("Number of elements in linked lists are : "+dObj.countNodes());
	
	System.out.println("\n----------------------------------------------------------------------------");	
		dObj.insertLast(111);
		dObj.insertLast(151);

		System.out.println("Linked list after inserting nodes at last position : ");
		System.out.println("----------------------------------------------------------------------------");		
		dObj.displayNodes();
		System.out.println("Number of elements in linked lists are : "+dObj.countNodes());

	System.out.println("\n----------------------------------------------------------------------------");	
		dObj.insertAtPos(55,4);

		System.out.println("Linked list after inserting node at given position : ");
		System.out.println("----------------------------------------------------------------------------");		
		dObj.displayNodes();
		System.out.println("Number of elements in linked lists are : "+dObj.countNodes());

	System.out.println("\n----------------------------------------------------------------------------");	
		dObj.deleteAtPos(4);

		System.out.println("Linked list after deleting node at given position : ");
		System.out.println("----------------------------------------------------------------------------");		
		dObj.displayNodes();
		System.out.println("Number of elements in linked lists are : "+dObj.countNodes());
	
	System.out.println("\n----------------------------------------------------------------------------");	
		
		dObj.deleteFirst();		
		
		System.out.println("Linked list after deleting node from first position : ");
		System.out.println("----------------------------------------------------------------------------");

		dObj.displayNodes();
		System.out.println("Number of elements in linked lists are : "+dObj.countNodes());

	System.out.println("\n----------------------------------------------------------------------------");	
		
		dObj.deleteLast();
		System.out.println("Linked list after deleting node from last position : ");
		System.out.println("----------------------------------------------------------------------------");

		dObj.displayNodes();
		System.out.println("Number of elements in linked lists are : "+dObj.countNodes());

	System.out.println("\n============================================================================");

	}	
}
