#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{  
    string entrada;
    vector<char> brackets;
    cin >> entrada;

    long long contador = 0;
    long long i = 0;
    long long tamano = entrada.length();

    while (i < tamano){
        /*
            La idea del algoritmo es que para cada elemento del string 'entrada' guardo en un vector de caracteres
            solo los brackets de apertura, segun vayan apareciendo. 
            Luego, cada vez que encuentre un bracket de cierre lo comparo con el ultimo bracket de apertura que esta en el vector,
            si son del mismo tipo, no sumo nada al contador; en caso contrario, sumo 1 al contador. 
            Tambien lo que hago es eliminar el bracket de apertura porque ya le conseguí su pareja.
            Así hasta que llegue al tamaño de la entrada. 

            Ahora bien, puede ser que no encuentre un bracket de cierre para cada bracket de apertura. En ese caso, 
            el tamaño de el vector de brackets de apertura seria diferente de 0, entonces respondo que ante ese caso no es un RBS.

            Si logra quedar vacío es porque era valido. 

            Sin embargo, quedaba reforzar una condicion, la de que haya mas brakets de cierre que de apertura,
            en ese caso podrian eliminarse todos los brackets de apertura y me quedaria el vector de brackets de apertura vacio, 
            pero no seria valida. Para quitar este caso, se verifica que por cada bracket de cierre que consiga,
            el vector de brackets de apertura no este vacio. Si llegase a estar vacio cuando consigo un bracket de cierre, 
            es porque no tengo suficientes brackets de apertura para los brackets de cierre.
        */
        if(entrada[i] == 40 || entrada[i] == 60 || entrada[i] == 91 || entrada[i] == 123)
        {
            //Si es un bracket de apertura, lo incluye en brackets.
            brackets.push_back(entrada[i]);
        }
        if(entrada[i] == 41 || entrada[i] == 62 || entrada[i] == 93 || entrada[i] == 125)
        {
            //Si es un bracket de cierre y no hay brackets de apretura en brackets, es imposible.
            if(brackets.size() == 0)
            {
                printf("Impossible");
                return 0;
            }
            
            //Si el ultimo bracket de apertura y el bracket de cierre son del mismo tipo, no suma el contador; en caso contrario, suma el contador.
            if(!((brackets[brackets.size() - 1] == 40 && entrada[i] == 41) || (brackets[brackets.size() - 1] == 60 && entrada[i] == 62) || (brackets[brackets.size() - 1] == 91 && entrada[i] == 93) || (brackets[brackets.size() - 1] == 123 && entrada[i] == 125)))
            {
                contador += 1;
            }
            //Borro el ultimo bracket de apertura porque se le hallo un bracket de cierre ya.
            brackets.pop_back();
        }
        i += 1;
    }

    if(brackets.size() != 0)
    {
        //Si no pude eliminar todos los brackets de apertura, entonces no hay suficientes brackets de cierre, es imposible.
        printf("Impossible");
    } else 
    {
        //Si pude eliminar los brackets de apertura, es porque hay uno para cada uno, asi que todo bien, devuelvo el contador.
        printf("%d", contador);
    }

    return 0;
}