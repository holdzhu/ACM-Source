#include <iostream>
#include <stdexcept>
#include <algorithm>

typedef int ElemType;

int size;

int I, K;

ElemType *V;

void input() throw(std::invalid_argument, std::bad_alloc)
{
	std::cout << "Input the size of V: ";
	std::cin >> size;

	if (size <= 0)
	{
		throw std::invalid_argument("Invalid input!");
	}

	V = new ElemType[size];

	if (V == NULL)
	{
		throw std::bad_alloc();
	}

	std::cout << "Input the elements of V (separate by SPACE): ";
	for (int i = 0; i < size; ++i)
	{
		std::cin >> V[i];
	}

	std::cout << "Input i: ";
	std::cin >> I;
	
	if (I < 0 || I >= size)
	{
		throw std::invalid_argument("Invalid input!");
	}

	std::cout << "Input k: ";
	std::cin >> K;

	if (K <= 0)
	{
		throw std::invalid_argument("Invalid input!");
	}
}

void del()
{
	for (int i = I + K; i < size; ++i)
	{
		V[i - K] = V[i];
	}
	size = std::max(size - K, I);
}

void output()
{
	std::cout << "The result is: ";
	if (size == 0)
	{
		std::cout << "{}" << std::endl;
		return;
	}
	for (int i = 0; i < size; ++i)
	{
		std::cout << (i ? ',' : '{') << V[i];
	}
	std::cout << "}" << std::endl;
}

void finish()
{
	delete[] V;
}

int main()
{
	input();
	del();
	output();
	finish();
	return 0;
}
