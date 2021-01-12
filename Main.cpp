#include <iostream>
#include <fstream>
#include "DataType.h"
#include "DoublyLinkedList.h"

using namespace std;

int main(int argc, char* argv[]) {

	DoublyLinkedList DLL;
	DataType item;
	int input;
	fstream fs;

	fs.open(argv[1], fstream::in);
	if(fs.is_open())
	{
		fs >> input;
		while (!fs.eof())
		{
			item.initialize(input);
			DLL.insertItem(item);
			fs >> input;
		}
	}
	else {
		cout << "Failed to open the input file" << endl;
		exit(1);
	}

	cout<<"COMMANDS: insert(i), delete (d), length(l), print (p), quit(q)/n/n Enter a command:";
}
