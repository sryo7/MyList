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

	int componentCount=0;

public:
	MyList();
	~MyList();
	void pushBackNode(int newData); 

	void replaceNode(int newdata, int index);

	void insertNode(int newData, int index);

	void popBackNode();

	void deleteNode(int index);

	void getData(int index);

	void getLengh();

	void display();
};

