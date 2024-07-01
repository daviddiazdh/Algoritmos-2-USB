#include <iostream>
#include <vector> 
#include <cmath>
#include <utility>
#include <string>

using namespace std;

long long n = 0;

void encolar(vector<long long> &lista, long long x){
    /*
    Esta funcion lo que hace es agregar un nuevo elemento a la cola, me conviene usar push_back(x) 
    que simplemente coloca el elemento al final de la cola.
    */
    lista.push_back(x);

}

void desencolar(vector<long long> &lista){
    /*
    No me conviene eliminar ningún elemento de la cola, porque aunque ocupe más memoria, 
    tardaría mucho más tiempo tener que eliminar cada elemento que saque de la cola. 
    Por lo tanto, lo que he hecho es utilizar un índice que hace las de apuntador en un arreglo,
    cada vez que se saque un elemento de la cola, entonces este índice aumentará en uno,
    haciendo que ya no se pueda acceder al mismo. 

    Ejemplo: 
    [1,2,3,4,5] 
    n=0

    Si desencolo, entonces n=1+1 -> n=2, de esa manera, olvido la parte izquierda del arreglo,
    o sea, el 1.
    [1,2,3,4,5] 
       n=1
    */
    if(n != lista.size()){
        n += 1;
    }

}

void imprimir_salida(vector<long long> &lista){

    /*
    Esta función simplemente devuelve el elemento al que esté apuntando el índice n,
    que es una variable global. 

    Ejemplo: 
    [20,10,5,15,8] 
    n=0
    Imprimiría: 20

    Mientras que si
    [20,10,5,15,8] 
                n=5
    Imprimiría: Empty!
    */

    if(n == lista.size()){
        cout << "Empty!\n";
    } else {
        long long elemento = lista[n];
        cout << elemento << "\n";
    } 

}

int main () {
    //Aumentar la rapidez de cin y cout
    ios_base::sync_with_stdio(false);

    //Hacer que los outputs sean mostrados cuando finalice el programa
    cin.tie(NULL);

    int casos;
    vector <long long> cola;
    cin >> casos;

    //Diseño acorde a la logica del problema de SPOJ
    while (casos > 0){
        
        int instruccion;
        long long x;
        cin >> instruccion;
        
        //Si se escribe 1, se encola el siguiente elemento.
        if(instruccion == 1){
            cin >> x;
            encolar(cola, x);
        //Si se escribe 2, se desencola el elemento dispuesto, en este caso, el que apunte n.
        } else if(instruccion == 2){
            desencolar(cola);
        //Si se escribe 3, se escribe el elemento que está diespuesto a ser desencolado.
        } else if(instruccion == 3){
            imprimir_salida(cola);
        }
        
        casos -= 1;
    }
} 