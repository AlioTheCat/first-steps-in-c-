#include <iostream>
using namespace std;

class Maillon
{
private:
    bool empty;
    int content;
    Maillon* pt;
public:
    Maillon() {
        pt = 0;
        empty = true;
    }

    Maillon(int c, Maillon* next = 0) {
        content = c;
        pt = next;
        empty = false;
    }

    Maillon operator=(Maillon m){
        content = m.content;
        pt = m.pt;
        empty = m.empty;
        return *this;
    }
    
    bool is_empty(){
        return empty;
    }

    int get_content(){
        return content;
    };

    Maillon* get_next(){
        return pt;
    }

    void set_content(int n){
        content = n;
    }

    void set_next(Maillon* loc){
        pt = loc;
    }

    void set_isempty(bool p){
        empty = p;
    }

    /*
    Maillon operator=(Maillon m){

    }*/
};


class ChainList
    {
    private:
        Maillon* head;
        int size;
    public:
        ChainList(){
            head = new Maillon ();
            size = 0;
        }

        ChainList(const ChainList& base){
            head = new Maillon;
            Maillon* newcurs = head;
            Maillon* current = base.head;
            while ( !(current -> is_empty()) ) {
                Maillon* next = new Maillon;
                *newcurs = Maillon (current -> get_content(), next);
                newcurs = newcurs -> get_next();
                current = current -> get_next();
            }
            size = base.size;
        }

        ~ChainList(){
            Maillon* nxt = head;
            while ( !(nxt -> is_empty()) ) {
                Maillon* tmp = nxt;
                //cout << nxt -> get_content()<< endl;
                nxt = (nxt -> get_next());
                delete tmp;
            }
        }



        ChainList operator=(ChainList obj){
            this -> ~ChainList ();
            
            head = new Maillon ();
            Maillon* newcurs = head;
            Maillon* current = obj.head;
            
            while ( !(current -> is_empty()) ) {
                Maillon* next = new Maillon;
                *newcurs = Maillon (current -> get_content(), next);
                newcurs = newcurs -> get_next();
                current = current -> get_next();
            }
            size = obj.size;
            return *this;
        }

        ChainList operator+(ChainList obj){
            ChainList left = *this;
            ChainList right = obj;
            Maillon* bottom = left.head;
            while ( !(bottom -> is_empty()) ) {
                bottom = (bottom -> get_next());
            }
            *bottom = *right.head;
            left.size += right.size;
            return left;
        }
        
        void push(int n){
            head = new Maillon (n, head); //On fait pointer vers une nouvelle instance dans laquelle l'ancienne est imbriquée.
            size += 1;
        }

        int operator|(ChainList obj){ //Produit scalaire
            
            Maillon* newcurs = head;
            Maillon* current = obj.head;

            int prod_scal = 0;
            
            while ( !(current -> is_empty()) && !(newcurs -> is_empty())) {
                prod_scal += (newcurs -> get_content()) * (current -> get_content());
                newcurs = newcurs -> get_next();
                current = current -> get_next();
            }
            return prod_scal;
        }

        int get_size(){
            return size;
        }
        
        int pop(){
            Maillon* nxt = (*head).get_next();
            if ( !(nxt -> is_empty()) ) {
                int m = (head -> get_content());
                head = (head -> get_next());
                return m;
                size -= 1;
            }
            else{
                cout << "Stack is empty" << endl;
            }
        
        }

        void print(){
            Maillon* nxt = head;
            while ( !(nxt -> is_empty()) ) {
                int m = (nxt -> get_content());
                nxt = (nxt -> get_next());
                cout << m << " -> ";
            }
            cout << "//" << endl;
        }
    };

int main(int argc, char const *argv[])
{
    ChainList t;
    t.push(5);
    t.push(7);
    t.push(3);
    ChainList t2;
    t2.push(4);
    t2.push(1);
    t2.push(6);
    t.print();
    t2.print();
    cout << (t | t2);
};
