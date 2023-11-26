from abc import ABC,abstractmethod

class NodeD:
	
	def __init__(self,iElement):
		
		self.iData = iElement
		self.nextPtr = None
		self.prevPtr = None
		
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


class DoublyCircularLL(LinkedLists):
	
	def __init__(self):
		
		self.iCount = 0
		self.first  = None
		self.last   = None
	
	def displayNodes(self):
		
		tempPtr = self.first
		
		print("<=>",end = ' ')
		for iCnt in range(0,self.iCount,1):
			
			print("|",tempPtr.iData,"|<=>",end = ' ')
			tempPtr = tempPtr.nextPtr
			
		print()
		
	def countNodes(self):
		
		return self.iCount	
	
	def insertFirst(self,iValue):
		
		newNode = None
		
		newNode = NodeD(iValue)
		
		if((self.first == None) and (self.last == None)):
			
			self.first = newNode
			self.last  = newNode
			
		else:
			
			newNode.nextPtr = self.first
			self.first = newNode
			
		self.first.prevPtr = self.last		
		self.last.nextPtr  = self.first
		
		self.iCount = self.iCount + 1
			
	def insertLast(self,iValue):
			
		newNode = None
		
		newNode = NodeD(iValue)
		
		if((self.first == None) and (self.last == None)):
			
			self.first = newNode
			self.last  = newNode
			
		else:
			self.last.nextPtr = newNode
			newNode.prevPtr = self.last
			
			self.last = newNode
			
		self.first.prevPtr = self.last		
		self.last.nextPtr  = self.first
		
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
			
			self.first.prevPtr = self.last		
			self.last.nextPtr  = self.first
			
		self.iCount = self.iCount - 1					
			
		
	def deleteLast(self):
		if(self.iCount == 0):
			
			print("Linked list is empty")
			return
		
		elif(self.iCount == 1):
			
			self.first = None
			self.last  = None
	
		else:
			self.last = self.last.prevPtr
			
			self.first.prevPtr = self.last		
			self.last.nextPtr  = self.first
			
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
			
			newNode = NodeD(iValue)	
			
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
	print("Implementation of doubly circular linked list using python")
	print(line)

	dObj = DoublyCircularLL()		
	
	print("\nInserting elements at first position :")
	dObj.insertFirst(111)
	dObj.insertFirst(101)
	dObj.insertFirst(51)
	dObj.insertFirst(21)
	dObj.insertFirst(11)
	
	dObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(dObj.countNodes()))

	print("\nInserting elements at last position :")
	dObj.insertLast(151)
	dObj.insertLast(201)
	dObj.insertLast(211)

	dObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(dObj.countNodes()))
	
	print("\nInserting element at given position : ")
	dObj.insertAtPos(55,4)

	dObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(dObj.countNodes()))
	
	print("\nDeleting element from given position : ")
	dObj.deleteAtPos(4)

	dObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(dObj.countNodes()))
	
	print("\nDeleting element from first position : ")
	dObj.deleteFirst()

	dObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(dObj.countNodes()))
	
	print("\nDeleting element from last position : ")
	dObj.deleteLast()

	dObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(dObj.countNodes()))
	

if __name__ == "__main__":
	main()
