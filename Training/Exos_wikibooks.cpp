#include <iostream>
using namespace std;

/*
Source : https://fr.wikibooks.org/wiki/Programmation_C%2B%2B/Les_pointeurs/Exercices
*/


// Exo1

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
};

// Exo 2

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

int occurencesA(string mot){
    char* curseur = &mot[0];
    int count = 0;
    while (*curseur != '\0') {
        if (*(curseur++) == 'A') {
            count++;
        }
    }
    return count;
}




int main()
{
    int a = 0;
    int b = 1;
    int l[7] = {4,8,0,2,1,6,19};
    int* min= &a;
    int* max= &b;
    minmax(l, 7, &a, &b);
    cout << *min << endl << *max << endl;
    cout << occurencesA("AndzudiAzudibzdAeufyvuzefAeiufz");
    return 0;
}