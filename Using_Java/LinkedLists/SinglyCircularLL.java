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

class SinglyCircular implements LinkedList
{
	private int iCount;	
	
	private NodeS first;
	private NodeS last;
	
	public SinglyCircular()
	{
		iCount	= 0;
		first 	= null;
		last	= null;
	} 
	
	public void displayNodes()
	{
		int iCnt = 0;
		NodeS tempPtr = first;
		
		for(iCnt = 0; iCnt < iCount; iCnt++)
		{
			System.out.print("|"+ tempPtr.iData+"|<->");
			tempPtr = tempPtr.nextPtr;
		}
		
	}
	
	public int countNodes()
	{
		return iCount;
	}
	
	public void insertFirst(int iNo)
	{
		NodeS newNode = null;
		
		newNode = new NodeS(iNo);
		
		if((first == null) && (last == null))
		{
			first = newNode;
			last  = newNode;
		}
		else
		{
			newNode.nextPtr = first;
			first = newNode;
		}
		
		last.nextPtr = first;
		
		iCount++;
	
	}
	
	public void insertLast(int iNo)
	{
		NodeS newNode = null;
		
		newNode = new NodeS(iNo);
		
		if((first == null) && (last == null))
		{
			first = newNode;
			last  = newNode;
		}
		else
		{
			last.nextPtr = newNode;
			last = last.nextPtr;
		}
		
		last.nextPtr = first;
		
		iCount++;
	}
	
	public void deleteFirst()
	{
		if((first == null) && (last == null))
		{
			System.out.println("\nLinked list is empty");
			return;
		}
		
		if(first == last)
		{
			first = null;
			last  = null;
		}
		else
		{
			first = first.nextPtr;
			last.nextPtr = first;
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
		
		if(first == last)
		{
			first = null;
			last  = null;
		}
		else
		{
			NodeS tempPtr = first;
			
			while(tempPtr.nextPtr != last)
			{
				tempPtr = tempPtr.nextPtr;
			}
			
			last = tempPtr;
			last.nextPtr = first;
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
			NodeS tempPtr  = first;
			NodeS tempPtrX = null; 
			
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

class SinglyCircularLL
{
	public static void main(java.lang.String Arg[])
	{
		SinglyCircular sObj = new SinglyCircular();
		
	System.out.println("============================================================================");
	
	
	System.out.println("\n----------------------------------------------------------------------------");
		System.out.println("Linked list after inserting nodes at first position : ");
		System.out.println("----------------------------------------------------------------------------");
	
		sObj.insertFirst(101);
		sObj.insertFirst(51);
		sObj.insertFirst(21);
		sObj.insertFirst(11);
		sObj.displayNodes();
		System.out.println("\nNumber of elements in linked lists are : "+sObj.countNodes());


	System.out.println("\n----------------------------------------------------------------------------");	
		sObj.insertLast(111);
		sObj.insertLast(151);

		System.out.println("Linked list after inserting nodes at last position : ");
		System.out.println("----------------------------------------------------------------------------");		
		sObj.displayNodes();
		System.out.println("\nNumber of elements in linked lists are : "+sObj.countNodes());

	System.out.println("\n----------------------------------------------------------------------------");	
		sObj.insertAtPos(55,4);

		System.out.println("Linked list after inserting node at given position : ");
		System.out.println("----------------------------------------------------------------------------");		
		sObj.displayNodes();
		System.out.println("\nNumber of elements in linked lists are : "+sObj.countNodes());

	System.out.println("\n----------------------------------------------------------------------------");	
		sObj.deleteAtPos(4);

		System.out.println("Linked list after deleting node at given position : ");
		System.out.println("----------------------------------------------------------------------------");		
		sObj.displayNodes();
		System.out.println("\nNumber of elements in linked lists are : "+sObj.countNodes());


	System.out.println("\n----------------------------------------------------------------------------");	
		
		sObj.deleteFirst();		
		
		System.out.println("Linked list after deleting node from first position : ");
		System.out.println("----------------------------------------------------------------------------");

		sObj.displayNodes();
		System.out.println("\nNumber of elements in linked lists are : "+sObj.countNodes());

System.out.println("\n----------------------------------------------------------------------------");	
		
		sObj.deleteLast();
		System.out.println("Linked list after deleting node from last position : ");
		System.out.println("----------------------------------------------------------------------------");

		sObj.displayNodes();
		System.out.println("\nNumber of elements in linked lists are : "+sObj.countNodes());


	System.out.println("\n============================================================================");
			
	}
	
}
