#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int SIZE2 = 16;

class binar_kuch
{
	class tree_node
	{
	public:
		int value;
		tree_node* left = NULL;
		tree_node* right = NULL;
		tree_node(int v);
	};
	tree_node* root = NULL;
	stringstream origin;
	int max_el = 0;
public:
	binar_kuch();
	void add_node(int v);
	//void add(tree_node* curnode, int i, int v);
	vector<bool> find_way();
	//void find_add(tree_node* curnode, vector<bool> is_right, int i, int v);
	void final_add_proverka(tree_node* curnode, vector<bool> is_right, int i, int v);
	void delete_first();
	int delete_last(tree_node* curnode, vector<bool> is_right, int i);
	void final_delete_proverka(tree_node* curnode, int v);
	void random();
	void print_tree();
	void zapovn(int main_mass[], tree_node* curnode, int i);
};