#include "Binar_kuch.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <vector>

binar_kuch::tree_node::tree_node(int v)
{
	value = v;
}



binar_kuch::binar_kuch()
{
	this->add_node(2);
	this->add_node(4);
	this->add_node(8);
	this->add_node(6);
	this->add_node(10);
	this->add_node(5);
	this->add_node(1);
	this->add_node(7);
	this->add_node(20);
	this->delete_first();
	//this->random();
}

void binar_kuch::add_node(int v)
{
	if (root == NULL)
	{
		root = new tree_node(v);
		max_el++;
		return;
	}
	max_el++;
	vector<bool> is_right(find_way());
	//find_add(root, is_right, is_right.size() - 1, v);
	final_add_proverka(root, is_right, is_right.size() - 1, v);
}

//void binar_kuch::add(tree_node* curnode, int i, int v)
//{
//
//}

vector<bool> binar_kuch::find_way()
{
	vector<bool> is_right;
	double fakem = max_el;
	while (fakem != 1)
	{
		fakem = fakem / 2.;
		double x, y;
		y = std::modf(fakem, &x);
		if (y == 0.5)
		{
			is_right.push_back(1);
		}
		else
		{
			is_right.push_back(0);
		}
		fakem = x;
	}
	return is_right;
}

//void binar_kuch::find_add(tree_node* curnode, vector<bool> is_right, int i, int v)
//{
//	if (i > 0)
//	{
//		if (is_right[i] == 0)
//		{
//			final_add_proverka(curnode->left, is_right, --i);
//		}
//		else
//		{
//			final_add_proverka(curnode->right, is_right, --i);
//		}
//	}
//	else
//	{
//		if (curnode->left == NULL)
//			curnode->left = new tree_node(v);
//		else
//			curnode->right = new tree_node(v);
//	}
//}

void binar_kuch::final_add_proverka(tree_node* curnode, vector<bool> is_right, int i, int v)
{
	if (i > 0)
	{
		if (is_right[i] == 0)
		{
			final_add_proverka(curnode->left, is_right, --i, v);
		}
		else
		{
			final_add_proverka(curnode->right, is_right, --i, v);
		}
	}
	else
	{
		if (curnode->left == NULL)
			curnode->left = new tree_node(v);
		else
			curnode->right = new tree_node(v);
	}
	if (curnode->left != NULL)
	{
		if (curnode->left->value < curnode->value)
		{
			int fakev = curnode->left->value;
			curnode->left->value = curnode->value;
			curnode->value = fakev;
		}
	}
	if (curnode->right != NULL)
	{
		if (curnode->right->value < curnode->value)
		{
			int fakev = curnode->right->value;
			curnode->right->value = curnode->value;
			curnode->value = fakev;
		}
	}
}

void binar_kuch::delete_first()
{
	vector<bool> is_right(find_way());
	int r = this->delete_last(root, is_right, is_right.size() - 1);
	this->final_delete_proverka(root, r);
}

int binar_kuch::delete_last(tree_node* curnode, vector<bool> is_right, int i)
{
	if (i > 0)
	{
		if (is_right[i] == 0)
		{
			return delete_last(curnode->left, is_right, --i);
		}
		else
		{
			return delete_last(curnode->right, is_right, --i);
		}
	}
	else
	{
		if (curnode->right != NULL)
		{
			int r = curnode->right->value;
			curnode->right = NULL;
			return r;
		}
		else
		{
			int r = curnode->left->value;
			curnode->left = NULL;
			return r;
		}
	}
}

void binar_kuch::final_delete_proverka(tree_node* curnode, int v)
{
	if ((curnode->left != NULL) && (curnode->right != NULL))
	{
		if (curnode->left->value > curnode->right->value)
		{
			curnode->value = curnode->right->value;
			final_delete_proverka(curnode->right, v);
		}
		else
		{
			curnode->value = curnode->left->value;
			final_delete_proverka(curnode->left, v);
		}
	}
	else
	{
		if ((curnode->left == NULL) && (curnode->right == NULL))
		{
			curnode->value = v;
		}
		else
		{
			curnode->value = curnode->left->value;
			curnode->left->value = v;
		}
	}
}

void binar_kuch::random()
{
	srand(time(0));
	int ch;
	for (int i = 0; i < SIZE2; i++)
	{
		ch = (rand() % 100) + 1;
		this->add_node(ch);
		this->origin << ch << ", ";
	}
}

void binar_kuch::print_tree()
{
	cout << origin.str();
	int main_mass[SIZE2 * SIZE2];
	this->zapovn(main_mass, root, 0);
	int j = 0, scale = 60;
	cout << endl;
	for (int i = 1; i < SIZE2 * SIZE2; i *= 2)
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

void binar_kuch::zapovn(int main_mass[], tree_node* curnode, int i)
{
	main_mass[i] = curnode->value;
	if (curnode->left != NULL)
		this->zapovn(main_mass, curnode->left, (i * 2 + 1));
	if (curnode->right != NULL)
		this->zapovn(main_mass, curnode->right, (i * 2 + 2));
	return;
}