#pragma once

class Tree
{
protected:
	int data;
	Tree *left, *right;
	bool indic;
public:
	Tree();
	~Tree();
	void add(int);
	void show();
	void del();
	void find(int,int&);
	void del_node(int,int&);
};