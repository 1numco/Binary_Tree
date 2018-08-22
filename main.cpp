#include "Header.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
const int max = 20;
using namespace std;
int main()
{
	Tree *tree = new Tree; //create root
	srand(time(NULL));
	for (int i = 10; i > 0; i--)
	{
		tree->add(rand() % max);   //add node with random data
	}
	int key = rand() % max;  //select the key to find and delete
	int f = 0;
	tree->show();  //here output, of course, not very vivid(more details can be found in debug)
	cout << endl;
	tree->find(key, f);
	if (f == 1)
	{
		cout << "Node with key =" << key << " was found." << endl << "After removing this node: ";
		tree->del_node(key, f);
		tree->show();
	}
	if (f == 2)
		cout << "Node with key =" << key << " wasn't found." << endl;
	
	tree->del();
	
	cout << endl;
	
	system("pause");
	return 0;
}