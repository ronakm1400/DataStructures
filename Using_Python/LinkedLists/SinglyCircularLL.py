from abc import ABC,abstractmethod

class NodeS:
	
	def __init__(self,iElement):
		
		self.iData 	= iElement
		self.nextPtr 	= None

class LinkedLists(ABC):
	
	@abstractmethod
	def insertFirst(self,iNo):
		pass
			
	@abstractmethod
	def insertLast(self,iNo):
		pass
	
	@abstractmethod
	def deleteFirst(self):
		pass

	@abstractmethod		
	def deleteLast(self):
		pass
	
	@abstractmethod
	def insertAtPos(self,iNo,iPos):
		pass
	
	@abstractmethod	
	def deleteAtPos(self,iPos):
		pass
	

class SinglyCircularLL(LinkedLists):
	
	def __init__(self):
		self.iCount	= 0
		self.first	= None
		self.last	= None	 		
	
	def displayNodes(self):
		
		tempPtr = self.first	
		
		for iCnt in range(0,self.iCount,1):
			
			print("|",tempPtr.iData,"|<->",end = ' ')
			tempPtr = tempPtr.nextPtr
		print()
			
	def countNodes(self):
		
		return self.iCount
	
	def insertFirst(self,iValue):	
		
		newNode = None
		
		newNode = NodeS(iValue)
		
		if((self.first == None) and (self.last == None)):
			
			self.first = newNode
			self.last  = newNode
		
		else:
			
			newNode.nextPtr = self.first
			self.first = newNode
			
		
		self.last.nextPtr = self.first
		
		self.iCount = self.iCount + 1	
				
	
	def insertLast(self,iValue):
	
		newNode = None
		
		newNode = NodeS(iValue)
		
		if((self.first == None) and (self.last == None)):
			
			self.first = newNode
			self.last  = newNode
		
		else:
			self.last.nextPtr = newNode
			self.last = self.last.nextPtr		
		
		self.last.nextPtr = self.first
		
		self.iCount = self.iCount + 1	
				
		
	def deleteFirst(self):
		
		if(self.iCount == 0):
			
			print("Linked list is empty")
			return
		
		elif(self.iCount == 1):
			
			self.first = None
			self.last  = None
		
		else:
			
			self.first = self.first.nextPtr
			
			self.last.nextPtr = self.first
		
		self.iCount = self.iCount - 1			
			
	def deleteLast(self):

		if(self.iCount == 0):
			
			print("Linked list is empty")
			return
		
		elif(self.iCount == 1):
			
			self.first = None
			self.last  = None
		
		else:
			
			tempPtr = self.first
			
			while(tempPtr.nextPtr != self.last):
				
				tempPtr = tempPtr.nextPtr
				
			self.last = tempPtr
			
			self.nextPtr = self.first		
					
		self.iCount = self.iCount - 1			
	
	def insertAtPos(self,iValue,iPos):
		
		if((iPos < 1) or (iPos > self.iCount + 1)):	
			
			print("Invalid position")
			
		if(iPos == 1):
			
			insertFirst(iValue)
			
		elif(iPos == self.iCount + 1):
			
			insertLast(iValue)
			
		else:
			
			tempPtr = self.first
			
			for iCnt in range(1,iPos - 1,1):
				
				tempPtr = tempPtr.nextPtr
			
			newNode = None
			
			newNode = NodeS(iValue)	
			
			newNode.nextPtr = tempPtr.nextPtr
			tempPtr.nextPtr = newNode
			
			self.iCount = self.iCount + 1
			
	
	def deleteAtPos(self,iPos):
	
		if((iPos < 1) or (iPos > self.iCount)):	
			
			print("Invalid position")
			
		if(iPos == 1):
			
			deleteFirst()
			
		elif(iPos == self.iCount):
			
			deleteLast()
			
		else:
			
			tempPtr = self.first
			tempPtrX = None
			
			for iCnt in range(1,iPos - 1,1):
				
				tempPtr = tempPtr.nextPtr
			
			tempPtrX = tempPtr.nextPtr
				
			tempPtr.nextPtr = tempPtr.nextPtr.nextPtr
			
			self.iCount = self.iCount - 1
			
 	
def main():
	
	line = "-"*70
	
	print()
	print(line)
	print("Implementation of singly circular linked list using python")
	print(line)
	
	sObj = SinglyCircularLL()
	
	print("\nInserting elements at first position :")
	sObj.insertFirst(111)
	sObj.insertFirst(101)
	sObj.insertFirst(51)
	sObj.insertFirst(21)
	sObj.insertFirst(11)
	
	sObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(sObj.countNodes()))
	
	print("\nInserting node at given position : ")
	sObj.insertAtPos(55,4)
	
	sObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(sObj.countNodes()))
	
	print("\nDeleting node from given position : ")
	sObj.deleteAtPos(4)

	sObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(sObj.countNodes()))
	
	print("\nInserting elements at last position : ")
	sObj.insertLast(151)
	sObj.insertLast(201)
	sObj.insertLast(251)
	
	sObj.displayNodes()	
	print("Number of nodes in linked lists are : {}".format(sObj.countNodes()))
	
	print("\nDeleting node from first position : ")
	sObj.deleteFirst()
	
	sObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(sObj.countNodes()))
	
	print("\nDeleting node from last position : ")
	sObj.deleteLast()
	
	sObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(sObj.countNodes()))
	
	
if __name__ == "__main__":
	main()
