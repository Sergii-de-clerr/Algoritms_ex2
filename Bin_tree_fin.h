#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int SIZE = 16;

class bin_tree_fin
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
public:
	bin_tree_fin();
	void add_node(int v);
	void random();
	void print_tree();
	void zapovn(int main_mass[], tree_node* curnode, int i);
	string pryam_obh();
	void pryam(tree_node* curnode, stringstream &s);
	string obern_obh();
	void obern(tree_node* curnode, stringstream &s);
	string vnyzz_obh();
	void vnyzz(tree_node* curnode, stringstream& s);
	string vverh_obh();
	void vverh(tree_node* curnode, stringstream& s);
};