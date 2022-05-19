#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class binom_kuch
{
	class tree_node
	{
	public:
		int value;
		bool is_life = false;
		vector<tree_node> sons;
		tree_node(int v);
	};
	vector<tree_node> root;
public:
	binom_kuch();
	void add_el(int v);
	void del_el();
	void addd_el(tree_node t);
};