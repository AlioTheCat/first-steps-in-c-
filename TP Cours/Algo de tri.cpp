#include <iostream>
using namespace std;

void print_array(int tab[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << tab[i] << " ";
	}
	cout << endl;;
}

int main()
{
	int l[] = { 30,50,8,4,56,25,13 };
	int l_size = 7;
	cout << "Array initial : ";;
	print_array(l, l_size);
	for (int i = 0; i < l_size; i++)
	{
		for (int j = 0; j + 1 < l_size - i; j++)
			if ( l[j] > l[j + 1] )
			{
				int tmp = l[j];
				l[j] = l[j + 1];
				l[j + 1] = tmp;
			}
	}
	cout << "Array final : ";;
	print_array(l, l_size);
	return 0;
}