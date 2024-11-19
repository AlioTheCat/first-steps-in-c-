#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
};

void minmax(int* tab, int size, int* min, int* max){
    *min = tab[0];
    *max = tab[0];
    for (int i=0; i<size; i++){
        if (tab[i] < *min) {
            *min = tab[i];
        }
        if (tab[i] > *max) {
            *max = tab[i];
        }
    }
}

//void nb_occ{string mot}{};


int main()
{
    int a = 0;
    int b = 1;
    int l[7] = {4,8,0,2,1,6,19};
    int* min= &a;
    int* max= &b;
    minmax(l, 7, &a, &b);
    cout << *min << endl << *max << endl;
    return 0;
}