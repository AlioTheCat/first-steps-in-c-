#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}



int main(int argc, char const *argv[])
{
    int a = 5;
    int b = 7;
    swap(&a, &b);
    cout << a << endl << b << endl;
    return 0;
}

