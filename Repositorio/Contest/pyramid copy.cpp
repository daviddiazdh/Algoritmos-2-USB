#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int piramide(int x){
    
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

    cout << "Cantidad de cartas usadas: " << key << endl;

    cout << "Cartas restantes: " << x - key << endl;

    cout << "Tamaño de la pirámide: " << contador << endl;

    return x - key;
}

int main() 
{  
    int x; 
    cout << "Diga el número: ";
    cin >> x; 
    int piramides = 0;

    while(x > 2){
        x = piramide(x);
        piramides += 1;
    } 

    cout << "Construiste " << piramides << " piramides";



    return 0;
}