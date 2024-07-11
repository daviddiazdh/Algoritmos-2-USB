#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main()
{
    //Hacer que los outputs sean mostrados cuando finalice el programa
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int filas;
    int columnas;  

    //Se recibe tanto los elementos a insertar como los querys
    scanf("%d", &filas);
    scanf("%d", &columnas);

    int contador_filas;
    vector<int> contador_columnas(columnas, 0);
    int det_fila = 0;
    int det_columna = 0;

    vector<vector<int>> hay_uno;

    vector<int> interseccion_x;
    vector<int> interseccion_y;

    int j;
    int i = 0;
    while (i < filas){
        j = 0;
        contador_filas = 0;
        while(j < columnas){
            int elemento;

            //Recibe cada elemento
            scanf("%d", &elemento);

            //De una vez verifica si es un 1 o un 0
            //Usaré un contador en filas para verificar la correctitud de la matriz
            //Este sumará uno si es un 1 y restará -1 si es un 0. 
            //Al final podré saber si una fila entera está llena de unos o ceros
            //Una lógica parecida para saber si una columna está llena de unos o ceros
            if(elemento == 1){
                contador_filas += 1;
                contador_columnas[j] += 1;
                hay_uno.push_back({i,j});
            } else{

                contador_filas -= 1;
                contador_columnas[j] -= 1;
            }

            //Solo cuando se terminen las filas
            if(i == filas - 1){
                //Si el contador de columnas sumó lo mismo que filas, entonces es porque la fila está llena de 1's
                if(contador_columnas[j] == filas){
                    det_columna += 1;
                    //intersección_y guarda qué columna tiene solo 1's
                    interseccion_y.push_back(j);
                //Si el contador de columnas sumó lo mismo que -filas, entonces es porque la fila está llena de 0's
                } else if(contador_columnas[j] == -filas){
                    det_columna += 1;
                }
            }
            //En cualquiera de ambos casos aumento det_columna que ma ayuda a saber si es válida la matriz por columnas

            j += 1;
        }
        
        //Cuando termino con una fila, si el contador_filas suma lo que columnas es porque esa fila está llena de 1's
        if(contador_filas == columnas){
            det_fila += 1;
            //intersección_x guarda qué filas tiene solo 1's
            interseccion_x.push_back(i);
        //Cuando termino con una fila, si el contador_filas suma lo que -columnas es porque esa fila está llena de 0's
        } else if(contador_filas == -columnas){
            det_fila += 1;
        }
        //En cualquiera de ambos casos aumento det_fila que ma ayuda a saber si es válida la matriz por filas

        i += 1;
    }

    bool bandera = true;

    for(vector<int> i : hay_uno){
        //Si hay_uno dice que hay un uno en esa posición, también lo debe decir intersección_x e intersección_y, sino el arreglo no es válido
        if(find(interseccion_x.begin(), interseccion_x.end(), i[0]) == interseccion_x.end()             //La función find ayuda a encontrar i[0] en interseccion_x
        && find(interseccion_y.begin(), interseccion_y.end(), i[1]) == interseccion_y.end()){           //La función find ayuda a encontrar i[1] en interseccion_y
            cout << "NO";
            bandera = false;
            break;
        }
    }

    //Solo se ejecuta si pasa la prueba anterior.
    if(bandera){
        //Si una columna está medio llena de ceros o de unos se puede considerar no válida
        if(det_fila == 0 || det_columna == 0){
            cout << "NO";
        //De lo contrario, habría pasado todas las pruebas para ser válida
        } else {
            cout << "YES" << endl;
            i = 0;
            //Vamos a imprimir como 0 todas, excepto las que hallan estado en la intersección, porque en la original están las de la intersección
            while(i < filas){
                j = 0;
                if(find(interseccion_x.begin(), interseccion_x.end(), i) == interseccion_x.end()){   //La función find ayuda a encontrar i en interseccion_x
                    while(j < columnas){
                        cout << 0 << " ";
                        j += 1;
                    }
                } else{
                    while(j < columnas){
                        if(find(interseccion_y.begin(), interseccion_y.end(), j) != interseccion_y.end()){  //La función find ayuda a encontrar j en interseccion_y
                            cout << 1 << " ";
                        } else {
                            cout << 0 << " ";
                        }
                        j += 1;
                    }
                }
                i += 1;
                cout << endl;
            }
        }
    }

    //Una posible corrida en frio sería: 
    // 0 1 0
    // 1 1 1
    // El algoritmo verifica que sea válida en la matriz si para todo 1 que haya, exista una columna o una fila asociada a él.
    // El algoritmo guardaría en los arreglos lo siguiente: 
    // interseccion_x = {1}    Donde hay filas de 1's
    // interseccion_y = {1}    Donde hay columnas de 1's
    // hay_uno = {{0,1}, {1,0}, {1,1}, {1,2}}   En qué posiciones hay 1's
    // A la hora de imprimir, simplemente haremos que todas sean cero, excepto las posiciones donde i está en interseccion_x y j en interseccion_y
    // Solo hay una posicion que cumple con eso i = 1 y j = 1.
    // La matriz resultante sería:
    // 0 0 0
    // 0 1 0


    return 0;
}