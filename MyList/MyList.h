#pragma once

#include<iostream>
#include "MyList.h"

class MyList
{
private:
	struct ListNode
	{
		int data;
		ListNode *next;
		ListNode *prev;
		
	};
	ListNode *headNode;
	ListNode *tailNode;

	int componentCount = 0;

public:
	MyList();
	~MyList();
	MyList(const MyList &myList);
	void pushBackNode(int newData); 

	void replaceNode(int newdata, int index);

	void insertNode(int newData, int index);

	void popBackNode();

	void deleteNode(int index);

	int getData(int index);

	int getLengh();

	void display();
};

