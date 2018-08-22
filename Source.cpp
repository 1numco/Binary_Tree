#include "Header.h"
#include <iostream>
#include <Windows.h>
using namespace std;



Tree::Tree()
{
	this->data = 0;
	this->indic = false;
	this->left = NULL;
	this->right = NULL;
}

void Tree::add(int n)
{
	
	if (this->indic == false)
	{
		this->indic = true;
		this->data = n;
		this->left = new Tree;
		this->right = new Tree;
	}

	if (n < this->data)  
	{
		if (this->left != NULL) 
			this->left->add(n); 
	}
	if (n > this->data)
	{
		if (this->right != NULL)
			this->right->add(n);
	}
	
}

void Tree::show()
{
	if (indic ==true)
	{
		cout << data<<" ";
		this->left->show();		
		this->right->show();
	}
}


Tree::~Tree()
{

}

void Tree::del()
{
	if (indic == true)
	{
		this->right->del();
		this->left->del();
		delete this;
	}
	else
		delete this;
}

void Tree::find(int n, int &f)
{
	Tree * t = nullptr;
	f = 0;
	t = this;
	while (t->indic == true)
	{
		if (t->data == n)
		{
			f = 1;
			return ;
		}
		if (t->data < n)
			t = t->right;
		if (t->data > n)
			t = t->left;
	}
	if (f == 0)
	{
		f = 2;
		return ;
	}
}
void Tree::del_node(int n, int& f)
{
	f = 0;
	if (indic == true)
	{
		if (data < n)
			this->right->del_node(n, f);
		if (data > n)
			this->left->del_node(n, f);
		if (data == n)
		{
			f = 1;
			Tree* temp = this;
			if (temp->right->indic == false && temp->left->indic == false)
			{
				temp = temp->right;
				this->data = temp->data;
				this->left = temp->left;
				this->right = temp->right;
				this->indic = false;
				return;
			}
			if (temp->right->indic == true && temp->left->indic == false)
			{
				temp = temp->right;
				this->data = temp->data;
				this->left = temp->left;
				this->right = temp->right;
				return;

			}
			if (temp->right->indic == false && temp->left->indic == true)
			{
				temp = temp->left;
				this->data = temp->data;
				this->left = temp->left;
				this->right = temp->right;
				return;
			}
			if (temp->right->indic == true && temp->left->indic == true)
			{
				Tree* t = temp->right;
				while (t->left->indic == true)
					t = t->left;
				temp->data = t->data;
				temp->right->del_node(t->data, f);

			}
			this->data = temp->data;
			this->left = temp->left;
			this->right = temp->right;
			
		}
	}
	else
		f = 2;
	
}