#include<iostream>
#include "MyList.h"



MyList::MyList()
{
	headNode = nullptr;
	tailNode = nullptr;
}

MyList::~MyList() {
	ListNode *nodePtr;
	nodePtr = headNode;

	while (nodePtr->next){
		nodePtr = nodePtr->next;
		delete nodePtr->prev;
	}

}

MyList::MyList(const MyList &myList) {

	this->headNode = nullptr;
	this->tailNode = nullptr;

	ListNode *nodePtr;
	nodePtr = myList.headNode;

	while (nodePtr) {
		this->pushBackNode(nodePtr->data);
		nodePtr = nodePtr->next;
	}




};


void MyList::pushBackNode(int newData)
{
	ListNode *newNode;

	newNode = new ListNode;
	newNode->prev = tailNode;
	newNode->data = newData;
	newNode->next = nullptr;


  	if (!headNode){
		headNode = newNode;
		newNode->next = tailNode;
	}
	else if(!tailNode){
		tailNode = newNode;
		headNode->next = newNode;
		tailNode->prev = headNode;
	}
	else{
		tailNode->next = newNode;
		tailNode = newNode;
	}
	componentCount++;

}

void MyList::replaceNode(int newData, int index){

	ListNode *nodePtr;

	if (index == 0 || index * index>componentCount*componentCount) {
		std::cout << "it doesn't meet the conditions." << std::endl <<
			"please type in another valid integral number" << std::endl;
	}

	else {
		if (index > 0) {
			nodePtr = headNode;
			for (int i = 1; i < index; i++) {
				nodePtr = nodePtr->next;
			}
		}
		
		else{
			nodePtr = tailNode;
			for (int i = -1; i > index; i--) {
				nodePtr = nodePtr->prev;
			}
		}

		nodePtr->data = newData;
	}

}

void MyList::insertNode(int newData, int index) {

	ListNode *newNode;

	newNode = new ListNode;

	if (!tailNode&&index == -1) {
		pushBackNode(newData);
		return;
	}

	if (index == componentCount + 1) {
		pushBackNode(newData);
		componentCount--;
	}
	else if (index == -componentCount - 1) {
		newNode->next = headNode;
		newNode->data = newData;
		newNode->prev = nullptr;
		headNode = newNode;
		newNode->next->prev = newNode;
	}

	else if (index == 0 || index * index > componentCount*componentCount) {
		std::cout << "it doesn't meet the conditions." << std::endl <<
			"please type in another valid integral number" << std::endl;
	}

	else {
		ListNode *nodePtr;


		if (index > 0) {
			nodePtr = headNode;
			for (int i = 1; i < index; i++) {
				nodePtr = nodePtr->next;
			}

			newNode->prev = nodePtr->prev;
			newNode->data = newData;
			newNode->next = nodePtr;
			nodePtr->prev = newNode; 
			newNode = nodePtr->prev;
		}

		else {
			nodePtr = tailNode;
			for (int i = -1; i > index; i--) {
				nodePtr = nodePtr->prev;
			}
			newNode->prev = nodePtr;
			newNode->data = newData;
			newNode->next = nodePtr->next;
			nodePtr->next = newNode;
			newNode = nodePtr->next;
		}


		if (newNode->prev == nullptr){ 	headNode = newNode; }
		else{ newNode->prev->next = newNode;}

		if (newNode->next == nullptr) { tailNode = newNode; }
		else{ newNode->next->prev = newNode; }

	}
	componentCount++;
}

void MyList::popBackNode() {
	if (componentCount > 2) {
		tailNode = tailNode->prev;
		delete tailNode->next;		
		tailNode->next = nullptr;
	}
	if (componentCount == 2) {
		tailNode = nullptr;
		headNode->next = tailNode;
	}
	if (componentCount == 1) {
		headNode = nullptr;
	}
	componentCount--;
}

void MyList::deleteNode(int index) 
{
	if (index == 0 || index * index > componentCount*componentCount) {
		std::cout << "please type in another valid integral number" <<
			         "which indicates the location that you want delete " << std::endl;
	}
	else{
		ListNode *nodePtr;
		if (index > 0) {
			nodePtr = headNode;
			for (int i = 1; i < index; i++) {
				nodePtr = nodePtr->next;
			}
		}
		else {
			nodePtr = tailNode;
			for (int i = -1; i > index; i--) {
				nodePtr = nodePtr->prev;
			}
		}
		if (nodePtr == headNode) {
			headNode = nodePtr->next;
			headNode->prev = nullptr;
		}
		else if (nodePtr == tailNode) {
			tailNode = nodePtr->prev;
			tailNode->next = nullptr;
		}
		else {
			nodePtr->prev->next = nodePtr->next;
			nodePtr->next->prev = nodePtr->prev;
		}
		delete nodePtr;

	}

	componentCount--;
}

int MyList::getData(int index){
	ListNode *nodePtr;
	nodePtr = headNode;

	if (index == 0 || index * index > componentCount*componentCount) {
			std::cout << "it doesn't meet the conditions." << std::endl <<
				"please type in another valid integral number" << std::endl;
	}
	else if (index > 0) {
		for (int i = 1; i < index; i++) {
			nodePtr = nodePtr->next;
		}
	}
	else {
		for (int i = 1; i < componentCount + 1 + index; i++) {
			nodePtr = nodePtr->next;
		}
	}

	return nodePtr->data;
}

int MyList::getLengh() {
	return componentCount;
}

void MyList::display(){
	ListNode *nodePtr;
	nodePtr = headNode;
	std::cout << nodePtr->data;

	while (nodePtr->next){
		nodePtr = nodePtr->next;
		std::cout <<","<< nodePtr->data;
	}
	
	std::cout << std::endl;
}

