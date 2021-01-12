#include "DoublyLinkedList.h"
#include <cstddef>
#include <iostream>

DoublyLinkedList::DoublyLinkedList()
{
	length = 0;
	head = NULL;
	tail = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
	NodeType* eraser = head;
	int index = 0;
	while(index < length)
	{
		eraser = eraser->next;
		index++;
	}
	index = length;
	while(index > 1)
	{
		deleteItem(eraser->data);
		eraser = eraser->next;
		index--;
	}
	delete head;
}

void DoublyLinkedList::insertItem(DataType &item)
{
	NodeType* location;
	bool moreToSearch;
	bool isEqual;

	NodeType* newNode = new NodeType;
	newNode->data = item;

	if(lengthIs() == 0)//list is empty
	{
		newNode->next = NULL;
		newNode->back = NULL;
		head = newNode;
		length++;
	}
	else if(lengthIs() == 1)//one item in list
	{
		switch(item.compareTo(head->data))
		{
		case EQUAL:
			break;
		case GREATER:
			head->next = newNode;
			head->back = NULL;
			newNode->back = head;
			newNode->next = NULL;
			length++;
			break;
		case LESS:
			head->back = newNode;
			newNode->next = head;
			head = newNode;
			length++;
			break;
		}//switch
	}//length is 1

	else//2 or more elements
	{
		location = head;
		moreToSearch = location->next != NULL;
		bool isFirst = false;
		bool isLast= false;

		while(moreToSearch)
		{
			//std::cout<<"searching location "<<(location->data).getValue()<<std::endl;
			switch(item.compareTo(location->data))
			{
			case GREATER:
				moreToSearch = (location->next != NULL);
				//std::cout<<moreToSearch<<std::endl;
				//std::cout<<"current location: "<<location->data.getValue()<<std::endl;
				if(moreToSearch)
				{
					location = location ->next;
					//std::cout<<"iterated to location: "<<location->data.getValue()<<std::endl;
				}
				else
				{
					isLast = true;
				}
				break;
			case LESS:
				moreToSearch = false;
				//std::cout<<moreToSearch<<std::endl;
				//std::cout<<"current location: "<<location->data.getValue()<<std::endl;
				break;
			case EQUAL:
				moreToSearch = false;
				isEqual = true;
				break;
			}//switch
		}//while searching for position
		if(!isEqual)//element not already in list
		{
			isFirst = (location->back == NULL);

			if(isLast)
			{
				//std::cout<<"in is last "<<std::endl;
				location->next = newNode;
				newNode->back = location;
				//std::cout<<"back points to: "<<(location->back)->data.getValue()<<std::endl;
				//std::cout<<"next points to: "<<(location->data).getValue()<<std::endl;
				//newNode->back = location->back;
				//location = newNode;
			}
			else if(isFirst)
			{
				//std::cout<<"in is first "<<std::endl;
				//std::cout<<"location points to: "<<(location->data).getValue()<<std::endl;
				location->back = newNode;
				newNode->next = location;
				head = newNode;
			}
			else
			{
				//std::cout<<"in normal insertion "<<std::endl;
				newNode->back = location->back;
				std::cout<<"back points to: "<<(location->back)->data.getValue()<<std::endl;
				newNode->next = location;
				//std::cout<<"next points to: "<<(location->data).getValue()<<std::endl;
				(location->back)->next = newNode;
				location->back = newNode;
			}
			length++;
		}
	}
}

void DoublyLinkedList::deleteItem(DataType &item)
{
	if(lengthIs() != 0)//list not empty
	{
		if(lengthIs() == 1 && item.compareTo(head->data) == EQUAL)//one item in list
		{
			head == NULL;
			length--;
		}
		else// 2 or more items in list
		{
			if(item.compareTo(head->data) == EQUAL)//first item
			{
				(head->next)->back = NULL;
				head = head->next;
				length--;
			}
			else
			{
				NodeType* location = head;
				bool moreToSearch = (location->next != NULL);
				bool isLast = false;
				while(moreToSearch)
				{
				switch(item.compareTo(location->data))
					{
						case EQUAL:
							moreToSearch = false;
							isLast = (location->next ==NULL);
							if(!isLast)
							{
								(location->back)->next = location->next;
								(location->next)->back = location->back;
								length--;
							}
							else
							{
								(location->back)->next = NULL;
								length--;
							}

							break;
						case LESS:
							moreToSearch = false;
							std::cout<<"item not in list"<<std::endl;
							break;
						case GREATER:
							moreToSearch = (location->next != NULL);
							if(moreToSearch)
								location = location->next;
							else
								isLast = true;
							break;
					}//switch
				}//while

			}
		}
	}
	else
	std::cout<<"list is empty"<<std::endl;
}

int DoublyLinkedList::lengthIs() const
{
	return length;
}

void DoublyLinkedList::print()
{
	NodeType* printPointer = head;
	int index = 0;

	if(printPointer == NULL || lengthIs() == 0)
	{
		std::cout<<"LIST IS EMPTY";
	}
	else
	{
		//std::cout<<"in print statement"<<std::endl;

		while(printPointer != NULL && index < lengthIs())
		{
			std::cout<<printPointer->data.getValue()<<" ";
			printPointer = printPointer->next;
			index++;
		}
	}
	std::cout<<std::endl;
}
