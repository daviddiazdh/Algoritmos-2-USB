#include <iostream>
#include <vector> 
#include <cmath>
#include <utility>

using namespace std;

void encolar(vector<long long> &lista, long long x){

    lista.push_back(x);

}

long long desencolar(vector<long long> &lista){

    long long elemento = lista[0];

    lista.erase(lista.begin());

    return(elemento);
}

void imprimir_cola(vector<long long> lista){

    for(long long i : lista){
        cout << i << " ";
    }

    cout << endl;
}


int main () {

    vector<long long> cola;
    while(true){
        cout << "Diga qué desea hacer" << endl;
        cout << "1. Encolar" << endl << "2. Desencolar" << endl << "3. Mostrar la cola" << endl << "4. Terminar el programa" << endl;
        int answer;
        cin >> answer; 
        if(int(answer) == 1){
            int x;
            cout << "Diga el elemento a agregar" << endl;
            cin >> x;
            encolar(cola, int(x));
        } else if(int(answer) == 2){
            long long elemento = desencolar(cola);
            cout << "El elemento que sacó de la cola es: " << elemento << endl;
        } else if(int(answer) == 3){
            cout << "Su cola es la siguiente: " << endl;
            imprimir_cola(cola);
        } else if(int(answer) == 4){
            cout << "Hasta luego";
            break;
        }

    }

    return 0;
}
