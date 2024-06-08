#include <iostream>
#include <vector>
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
    return x - key;
}

int main() 
{  

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