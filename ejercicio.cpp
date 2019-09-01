#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
}*inicio, *fin;

class Pila{
    public:
        Pila(){
            inicio = nullptr;
        }
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n->dato = valor;
            n->sig= nullptr;
            return n;
        }

        void push(int valor){
            Nodo *n= crearNodo(valor);
            n->sig=inicio;
            inicio=n;
            
        }
        
        void mostrar(){
            Nodo *n = inicio;
            while(n){
                cout<<n->dato<<endl;
                n=n->sig;
            }
        }
        

        Nodo* pop(){
            Nodo* temp = inicio;
            inicio= inicio->sig;
            return temp;
        }

};

class Cola{
    public:
        Cola(){
            inicio = nullptr;
            fin = nullptr;
        }
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n->dato = valor;
            n->sig= nullptr;
            return n;
        }

        void push(int valor){
            Nodo *n= crearNodo(valor);
            if(!inicio){
                inicio=n;
                fin=n;
            }
            else{
                fin->sig=n;
                fin=n;
            }
        }

        void invertir(){
            Nodo *n = inicio;
            inicio = fin;
            inveritAux(n);
            fin->sig = nullptr;
        }

        void inveritAux(Nodo* n){
            if(n->sig && n->sig!=fin){
                inveritAux(n->sig);
            }
            fin->sig = n;
            fin=n;
        }

        void mostrar(){
            Nodo *n = inicio;
            while(n){
                cout<<n->dato<<endl;
                n=n->sig;
            }
        }

        void pop(){
            Nodo* temp = inicio;
            inicio= inicio->sig;
            free(temp);
        }

        void transform(Pila p){
            Nodo *n = inicio;
            while(n){
                p.push(n->dato);
                n = n->sig;
            }
        }

};
int main(int argc, char** argv) {

    Cola cola1;
    Pila pila1;
    
    cola1.push(2);
    cola1.push(4);
    cola1.push(8);
    cola1.push(16);
    cola1.push(32);
    cola1.mostrar();
    cola1.invertir();
    cout<<"Se invirtio la cola"<<endl;
    cola1.mostrar();
    cola1.transform(pila1);
    cout<<"Se lleno la pila"<<endl;
    pila1.mostrar();
    return 0;
}