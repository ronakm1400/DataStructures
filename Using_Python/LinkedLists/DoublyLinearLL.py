class NodeD:
	
	def __init__(self,element):
		
		self.prevPtr = None
		self.nextPtr = None
		self.Data = element

class DoublyLinearLL:
	
	def __init__(self):	
		
		self.iCount = 0;
		self.First = None;				
	
	def CountNodes(self):
		
		return self.iCount
		
	def DisplayNodes(self):
		
		print("Elements in linked lists are : ")
		
		tempPtr = self.First
		
		for iCnt in range(0,self.iCount,1):
			print("|",tempPtr.Data,"|<=>",end = ' ')
		
		print("None")
		
	def InsertFirst(self,Value):	
		
		newNode = None
		
		newNode = NodeD(Value)
		
		if(self.iCount == 0):
			
			First = newNode
		else:
			newNode.nextPtr = self.First
			self.First = newNode
		
		self.iCount = self.iCount + 1
		
	def InsertLast(self,Value):	
		
		newNode = None
		
		newNode = NodeD(Value)
		
		if(self.iCount == 0):
			
			First = newNode
		
		else:
			tempPtr = self.First
			
			while(tempPtr.nextPtr != None):	
				tempPtr = tempPtr.nextPtr
				
			newNode.prevPtr = tempPtr
			tempPtr.nextPtr = newNode
			self.First = newNode
		
		self.iCount = self.iCount + 1
		
	
	def DeleteFirst(self):
		
		if(self.iCount == 0):
			print("Linked list is empty\n")
			return
		
		elif(self.iCount == 1):
			self.First = None
			
		else:
			self.First = self.First.nextPtr
			self.prevPtr = None
			
			self.iCount = self.iCount + 1
		
	
		def DeleteLast(self):
		
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
				
				self.iCount = self.iCount + 1
		
		def InsertAtPos(self,Value,Pos):

			if((Pos < 1) or (Pos > self.iCount + 1)):
				print("Invalid number of position\n")
				return

			if(Pos == 1):
				InsertFirst(Value)

			elif(Pos == self.iCount + 1):
				InsertLast(Value)

			else:
				tempPtr = self.First

				for iCnt in range(0,Pos - 1,1):

					tempPtr = tempPtr.nextPtr

				newNode = NodeD(Value)

				newNode.nextPtr = tempPtr.nextPtr
				tempPtr.nextPtr.prevPtr = newNode

				tempPtr.nextPtr = newNode
				newNode.prevPtr = tempPtr

				self.iCount = self.iCount + 1	
						

		def DeleteAtPos(Pos):
			
			if((Pos < 1) or (Pos > self.iCount)):
				print("Invalid number of position\n")
				return

			if(Pos == 1):
					DeleteFirst()

			elif(Pos == self.iCount):
					DeleteLast()

			else:
				tempPtr = self.First

				for iCnt in range(0,Pos - 1,1):

					tempPtr = tempPtr.nextPtr

				tempPtr.nextPtr = tempPtr.nextPtr.nextPtr
				tempPtr.nextPtr.prevPtr = tempPtr

				self.iCount = self.iCount + 1	
						
def main():
	
	line = "-"*50
	
	print("-"*20,"Implementation Of Doubly Linear Linked Lists","-"*20)
	
	dObj = DoublyLinearLL()
	
	dObj.InsertFirst(51)
	dObj.InsertFirst(21)
	dObj.InsertFirst(11) 	
	print("\n")
	print(line)
	print("Linked list after inserting nodes at first position")	
	print(line)
	dObj.DisplayNodes()
	print("Number of nodes in linked lists are : ",dObj.CountNodes())
	
	dObj.InsertLast(101)
	dObj.InsertLast(111)	
	print("\n")
	print(line)
	print("Linked list after inserting nodes at last position")
	print(line)
	dObj.DisplayNodes()
	print("Number of nodes in linked lists are : ",dObj.CountNodes())
	
	dObj.InsertAtPos(55,4)
	print("\n")
	print(line)
	print("Linked list after inserting node at 4 position")
	print(line)
	dObj.DisplayNodes()
	print("Number of nodes in linked lists are : ",dObj.CountNodes())
	
	dObj.DeleteAtPos(4)
	print("\n")
	print(line)
	print("Linked list after deleting node at 4 position")
	print(line)
	dObj.DisplayNodes()
	print("Number of nodes in linked lists are : ",dObj.CountNodes())

	dObj.DeleteFirst()
	print("\n")
	print(line)
	print("Linked list after deleting node from first position")
	print(line)
	dObj.DisplayNodes()
	print("Number of nodes in linked lists are : ",dObj.CountNodes())
	
	dObj.DeleteLast()
	print("\n")
	print(line)
	print("Linked list after deleting node from last position")
	print(line)
	dObj.DisplayNodes()
	print("Number of nodes in linked lists are : ",dObj.CountNodes())


if __name__ == "__main__":
	main()
