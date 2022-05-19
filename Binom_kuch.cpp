#include "Binom_kuch.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <vector>

binom_kuch::tree_node::tree_node(int v)
{
	value = v;
}



binom_kuch::binom_kuch()
{
	add_el(4);
	add_el(3);
	add_el(10);
	add_el(11);

	add_el(20);
	add_el(30);
	add_el(10);
	add_el(2);

	add_el(4);
	add_el(3);
	add_el(10);
	add_el(11);
	add_el(20);
	add_el(30);
	add_el(10);
	add_el(2);

	add_el(4);
	add_el(3);
	add_el(10);
	add_el(11);
	add_el(20);
	add_el(30);
	add_el(10);
	add_el(2);
	add_el(4);
	add_el(3);
	add_el(10);
	add_el(11);
	add_el(20);
	add_el(30);
	add_el(10);
	add_el(2);

	del_el();
}

void binom_kuch::add_el(int v)
{
	if (root.size() == 0)
	{
		root.push_back(v);
		root[0].is_life = true;
	}
	else if (root[0].is_life == false)
	{
		root[0].value = v;
		root[0].is_life = true;
	}
	else
	{
		if (root[0].is_life == true)
		{
			if (root[0].value > v)
			{
				int fakev = root[0].value;
				root[0].value = v;
				root[0].sons.push_back(fakev);
			}
			else
			{
				root[0].sons.push_back(v);
			}
		}
	}
	for (int i = 0; i < root.size() - 1; i++)
	{
		if ((root[i].sons.size() == root[i + 1].sons.size()) 
			&& (root[i].is_life == true) 
			&& (root[i + 1].is_life == true))
		{
			if (root[i].value > root[i + 1].value)
			{
				root[i + 1].sons.push_back(root[i]);
				root[i].is_life = false;
				root[i].sons.clear();
			}
			else
			{
				root[i].sons.push_back(root[i + 1]);
				root[i + 1] = root[i];
				root[i].is_life = false;
				root[i].sons.clear();
			}
		}
		if ((root[i + 1].is_life == false) 
			&& (root[i].sons.size() == i + 1))
		{
			root[i + 1] = root[i];
			root[i].is_life = false;
			root[i].sons.clear();
		}
	}
	if (root[root.size() - 1].sons.size() == root.size())
	{
		root.push_back(root[root.size() - 1]);
		root[root.size() - 2].is_life = false;
		root[root.size() - 2].sons.clear();
	}
}

void binom_kuch::del_el()
{
	int del_i = 0, del_v = 100, i = 1;
	for (; i < root.size(); i++)
	{
		if ((root[i].value < del_v) && (root[i].is_life == true))
		{
			del_v = root[i].value;
			del_i = i;
		}
	}
	tree_node del_el = root[del_i];
	root[del_i].is_life = false;
	root[del_i].sons.clear();
	for (int j = 0; j < del_el.sons.size(); j++)
	{
		this->addd_el(del_el.sons[j]);
	}
}

void binom_kuch::addd_el(tree_node t)
{
	if (root[t.sons.size()].is_life == true)
	{
		if (t.value > root[t.sons.size()].value)
		{
			root[t.sons.size()].sons.push_back(t);
			t.is_life = false;
			t.sons.clear();
		}
		else
		{
			t.sons.push_back(root[t.sons.size()]);
			root[t.sons.size()] = t;
			t.is_life = false;
			t.sons.clear();
		}
	}
	else
	{
		root[t.sons.size()] = t;
	}
	for (int i = 0; i < root.size() - 1; i++)
	{
		if ((root[i].sons.size() == root[i + 1].sons.size()) 
			&& (root[i].is_life == true) 
			&& (root[i + 1].is_life == true))
		{
			if (root[i].value > root[i + 1].value)
			{
				root[i + 1].sons.push_back(root[i]);
				root[i].is_life = false;
				root[i].sons.clear();
			}
			else
			{
				root[i].sons.push_back(root[i + 1]);
				root[i + 1] = root[i];
				root[i].is_life = false;
				root[i].sons.clear();
			}
		}
		if ((root[i + 1].is_life == false) 
			&& (root[i].sons.size() == i + 1))
		{
			root[i + 1] = root[i];
			root[i].is_life = false;
			root[i].sons.clear();
		}
	}
}