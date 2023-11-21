class NodeD
{
	public int 	iData;
	public NodeD nextPtr;
	public NodeD prevPtr;
	
	public NodeD()
	{
		iData 	= 0;
		nextPtr = null;
		prevPtr = null;
	}
	
	public NodeD(int iValue)
	{
		iData 	= iValue;
		nextPtr = null;
		prevPtr = null;
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

class DoublyCircular implements LinkedList
{
	private int	iCount;
	private NodeD 	first;
	private NodeD 	last;
	
	public DoublyCircular()
	{
		iCount = 0;
		first  = null;
		last   = null;
	}
	
	public void displayNodes()
	{
		int iCnt = 0;
		
		NodeD tempPtr = first;
		
		for(iCnt = 0; iCnt < iCount; iCnt++)
		{
			System.out.print("|"+tempPtr.iData+"|<=>");
			tempPtr = tempPtr.nextPtr;
		}
		
	}
	
	public int countNodes()
	{
		return iCount;
	}

	public void insertFirst(int iNo)
	{
	
		NodeD newNode = null;
		
		newNode = new NodeD(iNo);
		
		if((first == null) && (last == null))
		{
			first = newNode;
			last  = newNode;
		}
		else
		{
			newNode.nextPtr = first;
			first.prevPtr = newNode;
			
			first = newNode;
		}
		
		last.nextPtr = first;
		first.prevPtr = last;
		
		iCount++;
	
	}
	
	public void insertLast(int iNo)
	{
		NodeD newNode = null;
		
		newNode = new NodeD(iNo);
		
		if((first == null) && (last == null))
		{
			first = newNode;
			last  = newNode;
		}
		else
		{
			last.nextPtr = newNode;
			newNode.prevPtr = last;
			
			last = newNode;
		}
		
		last.nextPtr = first;
		first.prevPtr = last;
		
		iCount++;
	
	
	}
	
	public void deleteFirst()
	{
		if((first == null) && (last == null))
		{
			System.out.println("\nLinked list is empty");
			return;
		}
		else if(first == last)
		{
			first = null;
			last  = null;
		}
		else
		{
			first = first.nextPtr;
			
			first.prevPtr = last;
			last.nextPtr  = first;
		}
		iCount--;	
	}
	
	public void deleteLast()
	{
		if((first == null) && (last == null))
		{
			System.out.println("\nLinked list is empty");
			return;
		}
		else if(first == last)
		{
			first = null;
			last  = null;
		}
		else
		{
			last = last.prevPtr;
			
			first.prevPtr = last;
			last.nextPtr  = first;
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
			NodeD tempPtr  = first;
			NodeD tempPtrX = null; 
			
			for(iCnt = 1; iCnt < iPos - 1; iCnt++)
			{
				tempPtr = tempPtr.nextPtr;
			}
			
			tempPtrX = tempPtr.nextPtr;
			tempPtr.nextPtr = tempPtr.nextPtr.nextPtr;
			
			iCount--;
		}
	}
	

}

class DoublyCircularLL
{

	public static void main(java.lang.String Arg[])
	{
		DoublyCircular dObj = new DoublyCircular();
		
		dObj.insertFirst(101);
		dObj.insertFirst(51);
		dObj.insertFirst(21);
		dObj.insertFirst(11);

	System.out.println("============================================================================");
	
	
	System.out.println("\n----------------------------------------------------------------------------");
		System.out.println("Linked list after inserting nodes at first position : ");
		System.out.println("----------------------------------------------------------------------------");

		dObj.displayNodes();
		System.out.println("\nNumber of elements in linked lists are : "+dObj.countNodes());
	
	System.out.println("\n----------------------------------------------------------------------------");	
		dObj.insertLast(111);
		dObj.insertLast(151);

		System.out.println("Linked list after inserting nodes at last position : ");
		System.out.println("----------------------------------------------------------------------------");		
		dObj.displayNodes();
		System.out.println("\nNumber of elements in linked lists are : "+dObj.countNodes());

	System.out.println("\n----------------------------------------------------------------------------");	
		dObj.insertAtPos(55,4);

		System.out.println("Linked list after inserting node at given position : ");
		System.out.println("----------------------------------------------------------------------------");		
		dObj.displayNodes();
		System.out.println("\nNumber of elements in linked lists are : "+dObj.countNodes());

	System.out.println("\n----------------------------------------------------------------------------");	
		dObj.deleteAtPos(4);

		System.out.println("Linked list after deleting node at given position : ");
		System.out.println("----------------------------------------------------------------------------");		
		dObj.displayNodes();
		System.out.println("\nNumber of elements in linked lists are : "+dObj.countNodes());
	
	System.out.println("\n----------------------------------------------------------------------------");	
		
		dObj.deleteFirst();		
		
		System.out.println("Linked list after deleting node from first position : ");
		System.out.println("----------------------------------------------------------------------------");

		dObj.displayNodes();
		System.out.println("\nNumber of elements in linked lists are : "+dObj.countNodes());

	System.out.println("\n----------------------------------------------------------------------------");	
		
		dObj.deleteLast();
		System.out.println("Linked list after deleting node from last position : ");
		System.out.println("----------------------------------------------------------------------------");

		dObj.displayNodes();
		System.out.println("\nNumber of elements in linked lists are : "+dObj.countNodes());

	System.out.println("\n============================================================================");

	}

}
