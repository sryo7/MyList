#include<iostream>
#include"MyList.h"

int main(int argc, const char * argv[])
{
	MyList myList;
	myList.pushBackNode(1);
	myList.pushBackNode(3);

	MyList myList2 = myList;
	myList.insertNode(2, -2);
	myList.display();
	myList2.display();



	system("pause");
	return 0;
}