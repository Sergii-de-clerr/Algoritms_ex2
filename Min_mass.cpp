#include "Min_mass.h"
#include <iostream>
#include <ctime>

Oned_mass::Oned_mass()
{
	this->random();
}

void Oned_mass::random()
{
	srand(time(0));
	for (int i = 0; i < SIZE4; i++)
	{
		main_mass[i] = rand();
	}
}

void Oned_mass::print_arr()
{
	cout << "Array" << endl;
	for (int i = 0; i < SIZE4; i++)
	{
		cout << main_mass[i] << " ";
	}
	cout << endl;
}

int Oned_mass::max_el()
{
	int res = main_mass[0];
	for (int i = 0; i < SIZE4; i++)
	{
		if (main_mass[i] > res)
			res = main_mass[i];
	}
	return res;
}

int Oned_mass::min_el()
{
	int res = main_mass[0];
	for (int i = 0; i < SIZE4; i++)
	{
		if (main_mass[i] < res)
			res = main_mass[i];
	}
	return res;
}

//void Oned_mass::bubble_nostonks()
//{
//	bool is_sort;
//	do
//	{
//		is_sort = true;
//		for (int i = 0; i < SIZE - 1; i++)
//		{
//			if (main_mass[i] < main_mass[i + 1])
//			{
//				is_sort = false;
//				int fake = main_mass[i];
//				main_mass[i] = main_mass[i + 1];
//				main_mass[i + 1] = fake;
//			}
//		}
//	} while (is_sort == false);
//}

void Oned_mass::search_min(int v)
{
	for (int g = 0; g < v; g++)
	{
		int res = main_mass[g], res_i = g, fake_res;
		for (int i = g; i < SIZE4; i++)
		{
			if (main_mass[i] < res)
			{
				res = main_mass[i];
				res_i = i;
			}
		}
		fake_res = main_mass[g];
		main_mass[g] = res;
		main_mass[res_i] = fake_res;
	}
}

void Oned_mass::bubble_stonks()
{
	bool is_sort;
	do
	{
		is_sort = true;
		for (int i = 0; i < SIZE4 - 1; i++)
		{
			if (main_mass[i] > main_mass[i + 1])
			{
				is_sort = false;
				int fake = main_mass[i];
				main_mass[i] = main_mass[i + 1];
				main_mass[i + 1] = fake;
			}
		}
	} while (is_sort == false);
}

//void Oned_mass::middle_stonks()
//{
//	Oned_mass arr;
//	arr.clone_arr(*this);
//	arr.bubble_nostonks();
//	for (int i = 0; i < (SIZE / 2); i++)
//	{
//		main_mass[SIZE / 2 - i] = arr.main_mass[2 * i];
//		main_mass[(SIZE / 2) + 1 + i] = arr.main_mass[2 * i + 1];
//	}
//}
//
//void Oned_mass::chess_stonks()
//{
//	Oned_mass arr;
//	arr.clone_arr(*this);
//	arr.bubble_nostonks();
//	for (int i = 0; i < (SIZE / 2); i++)
//	{
//		main_mass[2 * i] = arr.main_mass[i];
//		main_mass[2 * i + 1] = arr.main_mass[SIZE - 1 - i];
//	}
//}
//
//void Oned_mass::twogroup_stonks()
//{
//	bool is_sort;
//	do
//	{
//		is_sort = true;
//		for (int i = 0; i < SIZE - 2; i += 2)
//		{
//			if (main_mass[i] > main_mass[i + 2])
//			{
//				is_sort = false;
//				int fake = main_mass[i];
//				main_mass[i] = main_mass[i + 2];
//				main_mass[i + 2] = fake;
//			}
//		}
//	} while (is_sort == false);
//	do
//	{
//		is_sort = true;
//		for (int i = 1; i < SIZE - 2; i += 2)
//		{
//			if (main_mass[i] < main_mass[i + 2])
//			{
//				is_sort = false;
//				int fake = main_mass[i];
//				main_mass[i] = main_mass[i + 2];
//				main_mass[i + 2] = fake;
//			}
//		}
//	} while (is_sort == false);
//}

void Oned_mass::clone_arr(Oned_mass arr)
{
	for (int i = 0; i < SIZE4; i++)
	{
		main_mass[i] = arr.main_mass[i];
	}
}