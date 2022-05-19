#include "Bin_tree_fin.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

bin_tree_fin::tree_node::tree_node(int v)
{
	value = v;
}



bin_tree_fin::bin_tree_fin()
{
	this->random();
}

void bin_tree_fin::add_node(int v)
{
	if (root == NULL)
	{
		root = new tree_node(v);
		return;
	}
	tree_node *curnode = root;
	bool is_add = false;
	while (is_add == false)
	{
		if (curnode->value > v)
		{
			if (curnode->left == NULL)
			{
				tree_node *temp = new tree_node(v);
				curnode->left = temp;
				is_add = true;
			}
			else
			{
				curnode = curnode->left;
			}
		}
		else
		{
			if (curnode->right == NULL)
			{
				tree_node* temp = new tree_node(v);
				curnode->right = temp;
				is_add = true;
			}
			else
			{
				curnode = curnode->right;
			}
		}
	}
}

void bin_tree_fin::random()
{
	srand(time(0));
	int ch;
	for (int i = 0; i < SIZE; i++)
	{
		ch = (rand() % 100) + 1;
		this->add_node(ch);
		this->origin << ch << ", ";
	}
}

void bin_tree_fin::print_tree()
{
	cout << origin.str();
	int main_mass[SIZE * SIZE];
	this->zapovn(main_mass, root, 0);
	int j = 0, scale = 60;
	cout << endl;
	for (int i = 1; i < SIZE * SIZE; i *= 2)
	{
		int fake_i = j + i;
		for (; j < fake_i; j++)
		{
			cout << setw(scale) << "";
			if ((main_mass[j] < 101) && (main_mass[j] > -1))
			{
				cout << main_mass[j];
			}
		}
		cout << endl;
		scale /= 1.5;
	}
}

void bin_tree_fin::zapovn(int main_mass[], tree_node* curnode, int i)
{
	main_mass[i] = curnode->value;
	if (curnode->left != NULL)
		this->zapovn(main_mass, curnode->left, (i * 2 + 1));
	if (curnode->right != NULL)
		this->zapovn(main_mass, curnode->right, (i * 2 + 2));
	return;
}

string bin_tree_fin::pryam_obh()
{
	stringstream s;
	this->pryam(root, s);
	return s.str();
}

void bin_tree_fin::pryam(tree_node* curnode, stringstream &s)
{
	if (curnode->left != NULL)
		this->pryam(curnode->left, s);
	s << curnode->value << ", ";
	if (curnode->right != NULL)
		this->pryam(curnode->right, s);
}

string bin_tree_fin::obern_obh()
{
	stringstream s;
	this->obern(root, s);
	return s.str();
}

void bin_tree_fin::obern(tree_node* curnode, stringstream &s)
{
	if (curnode->right != NULL)
		this->obern(curnode->right, s);
	s << curnode->value << ", ";
	if (curnode->left != NULL)
		this->obern(curnode->left, s);
}

string bin_tree_fin::vnyzz_obh()
{
	stringstream s;
	this->vnyzz(root, s);
	return s.str();
}

void bin_tree_fin::vnyzz(tree_node* curnode, stringstream& s)
{
	s << curnode->value << ", ";
	if (curnode->left != NULL)
		this->vnyzz(curnode->left, s);
	if (curnode->right != NULL)
		this->vnyzz(curnode->right, s);
}

string bin_tree_fin::vverh_obh()
{
	stringstream s;
	this->vverh(root, s);
	return s.str();
}

void bin_tree_fin::vverh(tree_node* curnode, stringstream& s)
{
	if (curnode->right != NULL)
		this->vverh(curnode->right, s);
	if (curnode->left != NULL)
		this->vverh(curnode->left, s);
	s << curnode->value << ", ";
}