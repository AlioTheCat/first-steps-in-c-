#include <iostream>
using namespace std;

class IntStack10
{
private:
    int content[10];
    int last = -1;

public:
    void push(int n){
        if ( last < 9 )
        {
            content[++last] = n;
        }
        else
        {
            cout << "Stack is full.";
        }
    };
    
    int pop(){
        if (last >= 0) {
            return content[last--];
        }
        else {
            cout << "Stack is empty";
            return 0;
        }
    };
    
    void print(){
        for (int i = 0; i <= last; i++)
        {
            cout << content[i] << " ";
        }
        cout << endl;;
    }
};

class IntStack
{
private:
    int size;
    int last = -1;
    int* content;
public:
    
    void InitStack(int n){
        this -> size = n;
        this -> content = new int[n]; // Le new permet d'accepter une taille variable.
    };

    void push(int n){
        if ( last < size - 1 )
        {
            content[++last] = n;
        }
        else
        {
            cout << "Stack is full.";
        }
    };
    
    int pop(){
        if (last >= 0) {
            return content[last--];
        }
        else {
            cout << "Stack is empty";
            return 0;
        }
    };
    
    void print(){
        for (int i = 0; i <= last; i++)
        {
            cout << content[i] << " ";
        }
        cout << endl;;
    }
};

class IntfiniteStack
{
private:
    int last = -1;
    int* content;
public:

    void push(int n){
        content[++last] = n;
    };
    
    int pop(){
        if (last >= 0) {
            return content[last--];
        }
        else {
            cout << "Stack is empty";
            return 0;
        }
    };
    
    void print(){
        for (int i = 0; i <= last; i++)
        {
            cout << content[i] << " ";
        }
        cout << endl;;
    }
};

int main() {
    IntStack10 stack;
    
    stack.push(2);
    stack.push(5);
    stack.push(1);

    stack.print();

    stack.pop();
    cout << stack.pop() << endl;;

    stack.print();

    IntStack stack2;
    stack2.InitStack(2);
    stack2.push(2);
    stack2.push(5);
    stack2.push(1);

    stack2.print();

    stack2.pop();
    cout << stack2.pop() << endl;;

    stack2.print();
}