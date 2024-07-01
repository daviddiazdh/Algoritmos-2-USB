#include <iostream>
#include <vector> 
#include <cmath>
#include <utility>
#include <string>

using namespace std;

long long n = -1;

void empilar(vector<long long> &lista, long long x){
    /*
    Esta funcion lo que hace es agregar un nuevo elemento a la pila, me conviene usar push_back(x) 
    que simplemente coloca el elemento al final de la pila.
    Note que cada vez que empilo, aumento en uno a n, esto significa que n contendrá siempre la cantidad de elementos - 1,
    esto porque lo inicié en -1.
    */
    lista.push_back(x);
    n += 1;

}

void desempilar(vector<long long> &lista){
    /*
    A diferencia del anterior ejercicio, en este sí me conviene usar pop_back() 
    porque es una función bastante eficiente ya que borra el último elemento de la lista, 
    no tiene que hacer nada más. Claro siempre me aseguro que n != -1, 
    porque eso sería borrar un elemento de una lista vacía.
    */
    if(n != -1){
        n -= 1;
        lista.pop_back();
    }

}

void imprimir_salida(vector<long long> &lista){
    /*
    Esta función simplemente devuelve el elemento al que esté apuntando el índice n,
    que es una variable global. 

    Ejemplo: 
    [20,10,5,15,8] 
                n=4
    Imprimiría: 8

    Mientras que si
    [20,10,5,15,8] 
    n=-1
    Imprimiría: Empty!
    */
    if(n == -1){
        cout << "Empty!\n";
    } else {
        //Note que siempre busco el último del arreglo, que es en esencia lo que debe salir en la pila.
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
        
        //Si se escribe 1, se empila el siguiente elemento.
        if(instruccion == 1){
            cin >> x;
            empilar(cola, x);
        //Si se escribe 2, se desempila el elemento dispuesto, en este caso, el que apunte n.
        } else if(instruccion == 2){
            desempilar(cola);
        //Si se escribe 3, se escribe el elemento que está diespuesto a ser desempilado.
        } else if(instruccion == 3){
            imprimir_salida(cola);
        }
        
        casos -= 1;
    }
} 