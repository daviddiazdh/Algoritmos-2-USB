#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //Recibo el string s
    string s;
    cin >> s;

    //Defino un vector que hará las de bucket para contar cuantos elementos y de que tipo quedan en s
    vector<int> caracteres_rest(26);
    //Creo dos strings t y u, los del problema
    string t;
    string u;

    for(char caracter : s){   
        //Determino en cual de los 26 espacios iría el caracter
        int index = caracter - 'a';
        //Le indico a la casilla que aumente dicho espacio, para indicar que hay un elemento más allí
        caracteres_rest[index] += 1;
    }

    //Una corrida en frio de este programa podría ser:
    // s = abdc
    // t =
    // u = 
    // -----------
    // Pasa el primer caracter y verifica que no haya uno más pequeño (NO HAY)
    // t = a          Como no hay más pequeño que a, entonces paso a directo a u
    // t = 
    // u = a
    // ------
    // Algo similar pasaría con b
    // t = 
    // u = ab
    // ------
    // Pasa el caracter d
    // t = d     Consigue uno más pequeño que queda en s, este es c, así que va a buscar a c
    // -----
    // Pasa el caracter c
    // t = dc      No consigue ninguno más pequeño que c en s, así que ahora sí pasa c
    // t = d
    // u = abc     No consigue nadie más pequeño que d en s, así que pasa d
    // t = 
    // u = abcd

    //La lógica se basa en directamente pasar los elementos al string t
    for(char caracter : s){
        //Primero agrego el caracter a el string t
        t += caracter;

        //Busco su posicion en caracteres_rest y le indico que debe disminuir uno, porque ya lo 'saqué' de s
        int index = caracter - 'a';
        caracteres_rest[index] -= 1;

        //Defino una bandera que controla si puedo empezar a pasar elementos de t a u

        while (t.size() != 0){
            
            //Defino la cola de t como su ultimo elemento en el arreglo
            char cola = t[t.size() - 1];
            bool bandera_2 = true;


            int i = 0;
            //Reviso todos los elementos que están antes de mi caracter para ver si alguno queda
            while(i < cola - 'a'){
                //Si existe un caracter más pequeño que el que tengo, no puedo pasar este, priorizo los más pequeños.
                if (caracteres_rest[i] > 0)
                {
                    bandera_2 = false;
                    break;
                }
                i += 1;
            }

            //Se ejecuta el if si no hay más pequeños que dicho caracter, en ese caso, paso la cola a u y la desecho de t.
            if(bandera_2){
                u += cola;
                t.pop_back();
            //En caso que sí hayan más pequeños, entonces hago un break para buscar el siguiente caracter.
            } else {
                break;
            }
        }
    }

    cout << u;

    return 0;
}