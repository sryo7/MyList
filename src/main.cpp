#include<iostream>
#include"MyList.h"

int main(int argc, const char * argv[])
{
	MyList myList;
	myList.pushBackNode(0);
	myList.display();
	myList.pushBackNode(5);
	myList.display();
	myList.replaceNode(4, 1);
	myList.display();
	myList.insertNode(2, 1);
	myList.display();
	myList.insertNode(3, 2);
	myList.display();
	myList.insertNode(7, 5);
	myList.display();
	myList.insertNode(8, -1);
	myList.display();
	myList.insertNode(6, -3);
	myList.display();
	myList.insertNode(1, -8);
	myList.display();
	//myList.popBackNode();
	//myList.display();
	//myList.deleteNode(2);
	//myList.display();
	//myList.deleteNode(6);
	//myList.display();
	//myList.deleteNode(-1);
	//myList.display();
	//myList.deleteNode(-2);
	//myList.display();
	//myList.deleteNode(-3);
	//myList.display();
	//myList.popBackNode();
	//myList.popBackNode();
	//myList.pushBackNode(2);
	//myList.display();
	//myList.insertNode(8, -1);
	//myList.display();
	
	MyList myList2 = myList;
	myList2.popBackNode();
	myList2.popBackNode();
	myList2.display();
	myList.display();



	

	//MyList myList3;
	//for (int i = 0; i < 1; i++) {
	//	myList = myList3;
	//	myList3 = myList;
	//}
	//myList.display();

	system("pause");
	return 0;
}