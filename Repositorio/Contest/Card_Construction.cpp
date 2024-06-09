#include <iostream>
#include <vector>
using namespace std;

int piramide(int x){
    /*
    Esta función representa la recursividad que cumple una piramide de tamaño h.
    Denotamos la cantidad de cartas que usa una piramide de tamaño h por C(h).

    C(h) = C(h-1) + 2*h + (h - 1)
    Lo cual es
    C(h) = C(h-1) + 3*h - 1

    La funcion calculará la cantidad de cartas de cada piramide comenzando desde una de tamaño 1, 
    hasta que supere la cantidad de cartas 'x'. 
    Una vez que supere dicha cantidad podríamos saber la altura de la piramide y otras caracteristicas,
    pero solo nos interesa saber cuantas cartas sobran despues de la piramide mas grande, por eso devolvemos x - key, 
    siendo key una variable que guarda la cantidad de cartas de la ultima piramide valida.
    */
    int contador = 0;
    int ch = 2;
    int h = 2;
    int key;
    while(ch <= x){
        key = ch;
        ch = ch + 3*h - 1;
        h += 1;
        contador += 1;
    } 
    return x - key;
}

int main() 
{  
    /*
    El programa, para cada caso, llama a la funcion piramide() 
    que simplemente devuelve el resto de cartas que quedan despues de haber construido la piramide mas grande posible.
    Luego, la vuelve a llamar tantas veces como sea necesario hasta que x < 2, donde ya no se puede armar ninguna piramide.
    
    De ese modo, en x se está guardando la cantidad de cartas que te sobran despues de armar las piramides mas grandes posibles.
    */
    int casos;
    scanf("%d", &casos);

    while (casos > 0){

        int x;
        scanf("%d", &x);
        int piramides = 0;

        while(x >= 2){
            x = piramide(x);
            piramides += 1;
        } 

        cout << piramides << endl;

        casos -= 1;
    }

    return 0;
}