

#include <iostream>
#include "Nodes.h"
#include "Slinkedlist.h"
#include "Dlinkedlist.h"

int main()
{
	SL_list<int> sList;
	sList.addB(25);
	sList.addE(56);
	std::cout << sList;
	sList.addI(2, 33);
	sList.rmB();
	std::cout << sList;

	DL_list<double> dList;
	dList.addB(22);
	dList.addE(55);
	std::cout << dList;
	sList.addI(2, 37);
	dList.rmB();
	std::cout << dList;
}

