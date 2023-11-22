class NodeS:
	
	def __init__(self,iElement):
		
		self.iData 	= iElement
		self.nextPtr 	= None

class SinglyLinearLL:
	
	def __init__(self):
		
		self.iCount = 0
		self.First  = None
	
	def displayNodes(self):
		
		tempPtr = self.First
			
		for iCnt in range(0,self.iCount,1):
			
			print("|",tempPtr.iData,"|->",end = ' ')
			tempPtr = tempPtr.nextPtr
			
		print("None")
		
	def countNodes(self):
		
		return self.iCount
	
	def insertFirst(self,Value):
		
		newNode = None	
		
		newNode = NodeS(Value)
		
		if(self.First == None):
			
			self.First = newNode
		
		else:
			newNode.nextPtr = self.First
			self.First = newNode
	
		self.iCount = self.iCount + 1		
	
	def insertLast(self,Value):
		
		newNode = None
		
		newNode = NodeS(Value)
		
		if(self.First == None):
			self.First = newNode
			
		else:
			tempPtr = self.First
			
			while(tempPtr.nextPtr != None):
					tempPtr = tempPtr.nextPtr			
			
			tempPtr.nextPtr = newNode	
					
		self.iCount = self.iCount + 1	
		
	
	def deleteFirst(self):
		
		if(self.iCount == 0):
			
			print("Linked list is empty\n")
			return	
			
		elif(self.iCount == 1):
			
			self.First = None
		
		else:
			self.First = self.First.nextPtr 
		
		self.iCount = self.iCount - 1		
		
	def deleteLast(self):

		if(self.iCount == 0):
			
			print("Linked list is empty\n")
			return	
			
		elif(self.iCount == 1):
			
			self.First = None
		
		else:
			tempPtr = self.First
			
			while(tempPtr.nextPtr.nextPtr != None):
				
				tempPtr = tempPtr.nextPtr
			
			tempPtr.nextPtr = None 
			
		self.iCount = self.iCount - 1		
		
	def insertAtPos(self,Value,Pos):
		
		if((Pos < 1) or (Pos > self.iCount + 1)):
			print("Invalid position\n")
			return 
		
		if(Pos == 1):
			self.insertFirst(Value)
				
		elif(Pos == self.iCount + 1):
			self.insertLast(Value)					
		
		else:	
			
			tempPtr = self.First
			
			for iCnt in range(1,Pos-1,1):
				tempPtr = tempPtr.nextPtr
			
			newNode = None
			
			newNode = NodeS(Value)
			
			newNode.nextPtr = tempPtr.nextPtr
			tempPtr.nextPtr = newNode	
			
			self.iCount = self.iCount + 1
		
	def deleteAtPos(self,Pos):
		
		if((Pos < 1) or (Pos > self.iCount + 1)):
			print("Invalid position\n")
			return 
		
		if(Pos == 1):
			self.deleteFirst()
			
		elif(Pos == self.iCount):
			self.deleteLast()
							
		else:
			
			tempPtr = self.First
			tempPtrX = None
			
			for iCnt in range(1,Pos-1,1):
				tempPtr = tempPtr.nextPtr
				
			tempPtrX = tempPtr.nextPtr  	
			tempPtr.nextPtr	 = tempPtr.nextPtr.nextPtr
			
			self.iCount = self.iCount - 1						

def main():

	line = "-"*50
	
	print("-"*20,"Implementation Of Singly Linear Linked Lists","-"*20)
	
	sObj = SinglyLinearLL()


	sObj.insertFirst(101)
	sObj.insertFirst(51)
	sObj.insertFirst(21)
	sObj.insertFirst(11) 	
	print("\n")
	print(line)
	print("Linked list after inserting nodes at first position")	
	print(line)
	sObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(sObj.countNodes()))
	
	sObj.insertLast(111)
	sObj.insertLast(151)	
	print("\n")
	print(line)
	print("Linked list after inserting nodes at last position")
	print(line)
	sObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(sObj.countNodes()))
	
	sObj.insertAtPos(55,4)
	print("\n")
	print(line)
	print("Linked list after inserting node at position")	
	print(line)
	sObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(sObj.countNodes()))
	
	sObj.deleteAtPos(4)
	print("\n")
	print(line)
	print("Linked list after deleting node from position")	
	print(line)
	sObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(sObj.countNodes()))

	sObj.deleteFirst()
	
	print("\n")
	print(line)
	print("Linked list after deleting node from first position")
	print(line)
	sObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(sObj.countNodes()))
	
	sObj.deleteLast()
	print("\n")
	print(line)
	print("Linked list after deleting node from last position")
	print(line)
	sObj.displayNodes()
	print("Number of nodes in linked lists are : {}".format(sObj.countNodes()))
	
if __name__ == "__main__":
	main()
