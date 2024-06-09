#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> MAX_HEAPIFY(vector<int> A, int i, int n){
    int largest;
    int l = i*2 + 1; 
    int r = i*2 + 2;

    if(l < n && A[l] > A[i]){
        largest = l;
    } else {
        largest = i;
    }

    if(r < n && A[r] > A[largest]){
        largest = r;
    }

    if(largest != i){
        int temp;
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        A = MAX_HEAPIFY(A, largest, n);
    }

    return A;
}

vector<int> BUILD_MAX_HEAP(vector<int> A){
    float n = A.size();
    for(int i = floor(n/2) - 1; i >= 0; i--){
        A = MAX_HEAPIFY(A, i, n);
    }

    return A;
}

vector<int> HEAP_SORT(vector<int> A){

    A = BUILD_MAX_HEAP(A);
    int n = A.size();
    for(int i = n - 1; i >= 1; i--){
        int temp;
        temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        A = MAX_HEAPIFY(A, 0, i);
    }
    
    return A;
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

    Me aprovecho del BUILD-MAX-HEAP que hace que el vector quede ordenado de forma descendente para luego hacer print de el primer elemento del vector.

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

    resp_posibles = BUILD_MAX_HEAP(resp_posibles);

    /*
    El vector de respuestas posibles guarda los segmentos de tamaño n de cada uno que se pueden formar, 
    pero se quiere es la longitud total del segmento, así que imprimo la respuesta multiplicada por 2.
    */
    cout << 2 * resp_posibles[0];


    return 0;
}