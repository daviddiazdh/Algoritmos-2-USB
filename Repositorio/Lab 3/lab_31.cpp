#include <iostream>
#include <vector> 
#include <utility>
#include <cmath>
#include <iterator>

using namespace std;

vector <pair<int, int>> merge(vector<pair<int, int>> U, vector<pair<int, int>> V, vector<pair<int, int>> T, int m, int n) {

    int i = 0;
    int j = 0;

    U.push_back({100000,U.size()});
    V.push_back({100000,U.size()});
    for(int k = 0; k < m + n; k++){
        
        if(U[i].first < V[j].first){
            T[k] = U[i];
            i += 1;
        } else {
            T[k] = V[j];
            j += 1;
        }
    }

    return T;

}

vector<pair<int, int>> merge_sort(vector<pair<int, int>> T, float n) {
    if( n == 1 ){
        return T;
    } else {
        vector<pair<int, int>> U(T.begin(), T.begin() + floor( n / 2 ));

        vector<pair<int, int>> V(T.begin() + floor( n / 2 ), T.end());

        U = merge_sort(U, floor( n / 2 ));
        V = merge_sort(V, ceil( n / 2 ));
        return merge(U, V, T, floor( n / 2 ), ceil( n / 2 ));
    }
}

using namespace std;

int main() 
{   

vector<int> respuesta;

int cantidad;

cin >> cantidad;

int contador = 0;
while(contador < cantidad){

    vector <int> lista;

    int tamano;
    cin >> tamano;

    int k = 0;
    while(k < tamano){
        int elemento;
        cin >> elemento;
        lista.push_back(elemento);
        k += 1;
    } 
    
    vector <pair<int, int>> lista_pos;

    int j = 0;
    for( int  i : lista ){

        lista_pos.push_back({i,j});
        j += 1;

    }


    /*Merge Sort*/
    lista_pos = merge_sort(lista_pos, lista.size());


    /* Lógica más importante del programa 
        1. Suma los elementos hasta el índice.
        2. Compara con el siguiente (Si es más grande que el siguiente, 
        agrega uno a la variable respuesta y repite 1 y 2; si no, se sale del bucle)
        3. Guarda la variable respuesta en un arreglo "lista_resp" en orden.
    */

    unsigned i = 0;

    vector <int> lista_iter(tamano); 

    while(i < lista_pos.size()){
        long long suma = lista_pos[i].first;
        int iteraciones = 0;

        unsigned j = 0;
        unsigned k = i;
        while(k < lista_pos.size()){
            while(j < k){
                suma += lista_pos[j].first;
                j += 1;
                iteraciones += 1;
            }

            if(suma >= lista_pos[k + 1].first){
                k += 1;
            } else{
                break;
            }

        } 
        
        lista_iter[lista_pos[i].second] = iteraciones;

        i += 1;
    }

    for( int i : lista_iter ){

        cout << i << " ";

    }
    cout << endl;


}



return 0;
}