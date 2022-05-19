#include "Bin_tree_fin.h"
#include "Binar_kuch.h"
#include "Binom_kuch.h"
#include "Min_mass.h"

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ukr");

#pragma region Exercise 1

	/*bin_tree_fin r;
	r.print_tree();

	cout << r.obern_obh() << endl;
	cout << r.pryam_obh() << endl;

	system("pause");*/

#pragma endregion Завдання 1

#pragma region Exercise 3

	//binar_kuch b;
	//b.print_tree();

	///*cout << r.obern_obh() << endl;
	//cout << r.pryam_obh() << endl;*/

	//system("pause");

#pragma endregion Завдання 3

#pragma region Exercise 4

//binom_kuch b;
////b.print_tree();
//
///*cout << r.obern_obh() << endl;
//cout << r.pryam_obh() << endl;*/
//
//system("pause");

#pragma endregion Завдання 4

#pragma region Exercise 5

	Oned_mass mass1, mass2;
	mass2.clone_arr(mass1);

	clock_t start = clock();
	mass1.bubble_stonks();
	clock_t end = clock();
	//mass1.print_arr();

	//double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	double seconds = (end - start);

	cout << "sort: " << seconds << endl << endl;

	for (int i = 0; i < SIZE4; i += 50)
	{
		Oned_mass masst;
		masst.clone_arr(mass2);
		start = clock();
		masst.search_min(i);
		end = clock();
		//masst.print_arr();

		//seconds = (double)(end - start) / CLOCKS_PER_SEC;
		seconds = (end - start);

		cout << "search min " << i << ": " << seconds << endl;
	}

	system("pause");

#pragma endregion Завдання 5

}