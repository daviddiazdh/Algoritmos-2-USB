#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    //Recibo todos los casos de prueba a ejecutar
    int casos;
    cin >> casos;

    while(casos > 0){
        
        //Recibo cada numero a agregar al arreglo
        long long n;
        cin >> n;
        vector<long long> numeros = {};
        vector<long long> diferencia = {};

        //Agrego cada elemento a un arreglo llamado numeros
        int i = 0;
        while(i < n){
            
            long long numero;
            cin >> numero;

            numeros.push_back(numero);

            i += 1;
        }

        //Uso sort() para ordenar el arreglo numeros
        sort(numeros.begin(), numeros.end());

        //Agrego al arreglo llamado diferencias, las diferencias de cada elemento con su anterior, 
        //sin embargo, si la diferencia entre ellos es nula, entonces no lo agrego. 
        //Esto es porque, a fines del calculo que haré, no me convienen las diferencias nulas porque no aportan información
        i = 0;
        while(i < n - 1){

            if(numeros[i+1] != numeros[i]){
                diferencia.push_back(numeros[i+1] - numeros[i]);
            }
            i += 1;
        }

        //Hasta este punto un ejemplo podría ser el siguiente:  1 4 1 7
        //numeros = {1, 1, 4, 7}
        //diferencia = {3, 3}  Porque son las diferencias no nulas entre los elementos

        i = 0;
        int j = 0;
        int suma = 0;
        int longitud = diferencia.size();
        
        int conteo_max = 0;
        int conteo = 0;

        //Es en este punto donde se encuentra la lógica más importante del programa
        //Me di cuenta que dos elementos van a poder igualarse si su diferencia es menor que la longitud del arreglo
        // 4 se puede igualar a 7 porque 7-4 = 3 y 3 < 4 (Longitud total del arreglo)
        // O sea, voy a poder escoger dos números entre 1 y 4 que los igualen, en este caso es 4 y 1, 4 + 4 = 7 + 1 = 8 
        // Basandome en esta idea, puedo determinar en el vector diferencia la secuencia de diferencias más grande que sea menor a n para determinar
        // cuántos voy a poder igualar

        //Tomemos uno de los ejemplos: 103 102 104
        // Los ordeno y guardo sus diferencias numeros = {102, 103, 104}
        // diferencias = {1, 1}
        //Mi misión es hallar el segmento más grande que suma una cantidad menor que la longitud del arreglo original (3)
        // En este caso, puedo tomar ambos números sin que se pase de 3 porque 2 < 3, así que la cantidad de diferencias que puedo tomar son 2
        // Esto significa que puedo tomar 3 elementos. 

        //Ejemplo de corrida en frio:
        //La metodología que utilizo lo que hace es mover unos apuntadores para ir hallando el segmento más grande cuya suma sea menor que n.
        // Imagina un ejemplo como: numeros = {1,2,5,10,20}    n = 5
        // Esto sería diferencias ->   diferencias = {1,3,5,10}   
        // {1,3,5,10}
        // i j 
        // Puedo tomar 1 porque 1 < 5    conteo = 1
        // {1,3,5,10}
        // i   j 
        // Puedo tomar 1 y 3 porque 1 + 3 < 5  conteo = 2
        //{1,3,5,10}
        // i    j 
        // No puedo tomar 1, 3 y 5 porque 1 + 3 + 5 > 5   conteo = 1
        // {1,3,5,10}
        //    i j
        // No puedo tomar 3 y 5 porque 3 + 5 > 8       conteo = 0
        //{1,3,5,10}
        //    i j
        // No puedo tomar 5 solo porque 5 = 5   conteo = 0
        // {1,3,5,10}
        //        i j
        // Finalmente, no puedo tomar 10 porque 10 > 5    conteo = 0

        //En todo el desarrollo se tuvo que el máximo conteo fue 2, por lo tanto, el segmento más grande de diferencias fue 2, que representa 3 números.
        //Por lo tanto, la respuesta sería 3.

        while(i < longitud and j < longitud){
            //Caso en el que se puede extender el segmento cuando i=j
            if(i == j && diferencia[i] < n){
                suma = conteo = 0;
                suma += diferencia[i];
                conteo += 1;
                j += 1;
            //Caso en el que no se puede extender el segmento cuando i=j
            } else if(i == j && diferencia[i] >= n){
                suma = conteo = 0;
                i += 1;
                j += 1;
            //Caso en el que se puede extender el segmento cuando i != j
            } else if(i != j && suma + diferencia[j] < n){
                suma += diferencia[j];
                conteo += 1;
                j += 1;
            //Caso en el que no se puede extender el segmento cuando i != j
            } else if ( i != j && suma + diferencia[j] >= n){
                suma -= diferencia[i];
                conteo -= 1;
                i += 1;
            }

            //De hallarse un conteo más grande que el ya registrado, se actualiza
            if(conteo > conteo_max){
                conteo_max = conteo;
            }
        }

        cout << conteo_max + 1 << endl;

        casos -= 1;
    }

    

    return 0;
}