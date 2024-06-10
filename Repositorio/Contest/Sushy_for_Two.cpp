#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> merge(vector<int> U, vector<int> V, vector<int> T, int m, int n) {

    int i = 0;
    int j = 0;

    U.push_back(100000);
    V.push_back(100000);
    for(int k = 0; k < m + n; k++){
        
        if(U[i] < V[j]){
            T[k] = U[i];
            i += 1;
        } else {
            T[k] = V[j];
            j += 1;
        }
    }

    return T;

}

vector<int> merge_sort(vector<int> T, float n) {
    if( n == 1 ){
        return T;
    } else {
        vector<int> U(T.begin(), T.begin() + floor( n / 2 ));

        vector<int> V(T.begin() + floor( n / 2 ), T.end());

        U = merge_sort(U, floor( n / 2 ));
        V = merge_sort(V, ceil( n / 2 ));
        return merge(U, V, T, floor( n / 2 ), ceil( n / 2 ));
    }
}

int main() 
{   
    int tamano;
    cin >> tamano;
    int iterador = tamano;

    vector<int> resp_posibles;

    int key = 0;
    int contador = 1;
    int key_contador = 0;
    /*
    Por cada elemento que entre, cuento cuántas veces seguidas ha aparecido dicho elemento y lo comparo con la cantidad de veces que aparece el siguiente a él.
    De modo que no guardo nada en un arreglo, si no que comparo según entren. 
    Por ejemplo, si entra 22211122, primero cuenta cuántas veces seguidas aparece el 2, 3 veces y lo compara con las veces que aparece el 1 siguiente, 3 veces.
    Como 3 <= 3, dice que es posible seleccionar un segmento de tamaño 3 de cada uno y agrega esta posible respuesta al vector de respuestas.
    Luego hace lo mismo con el 11122, donde dice que 1 aparece 3 veces y 2 2 veces. 
    Como 3 > 2, dice que es posible seleccionar un segmento de tamaño 2 de cada uno y agrega esta posible respuesta al vector de respuestas.

    El vector de respuestas tiene que ser ordenado para saber cuál será el segmento de tamaño máximo (o la respuesta posible más grande en el vector de respuestas)

    Me aprovecho del Merge Sort que hace que el vector quede ordenado de forma ascendente para luego hacer print de el último elemento del vector.

    */

    while(iterador > 0)
    {
        int i;
        cin >> i;
        if(key == i)
        {
            contador += 1;
        } else if ((key != 0 && key != i) || (i == tamano - 1)) 
        {
            if(key_contador != 0 && contador >= key_contador){
                resp_posibles.push_back(key_contador);
            } else if (key_contador != 0 && contador < key_contador)
            {
                resp_posibles.push_back(contador);
            }
            key_contador = contador;
            contador = 1;
        }
        key = i;
        iterador -= 1;
        /*
        En key_contador se guarda la cantidad de elementos previos del mismo tipo
        Por ejemplo, en el segmento 11122211, 
        key_contador guardaría el tamaño del segmento de solo 1's para poder compararlo con el de solo 2's. 
        Así no pierdo la info del segmento previo.
        */
    }

    if(contador >= key_contador)
    {
        resp_posibles.push_back(key_contador);
    } else if (contador < key_contador)
    {
        resp_posibles.push_back(contador);
    }

    resp_posibles = merge_sort(resp_posibles, int(resp_posibles.size()));

    /*
    El vector de respuestas posibles guarda los segmentos de tamaño n de cada uno que se pueden formar, 
    pero se quiere es la longitud total del segmento, así que imprimo la respuesta multiplicada por 2.
    */
    cout << 2 * resp_posibles[resp_posibles.size() - 1];


    return 0;
}