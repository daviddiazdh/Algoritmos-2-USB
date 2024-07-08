#include <iostream>
using namespace std;

//Estructura del nodo
struct Node {
    //data es el valor del nodo
    int data;
    //Agregué position que es la posicion del nodo, aunque varios nodos pueden tener la misma posicion si llegan a tener la misma data. 
    //Una mejor explicación de esto está en main()
    int position;
    //color define el color del nodo, recordando que trabajamos con un arbol rojinegro
    string color = "RED";
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;

};

struct RedBlackTree {
    Node* root;
    Node* NIL;

    //Constructor que define los árboles rojinegros
    RedBlackTree()
    {
        NIL = new Node();
        NIL -> data = 0;
        NIL -> color = "BLACK";
        NIL -> left = NIL->right = NIL;
        root = NIL;
    }

    //Función que ejecuta la rotación hacia la izquierda para preservar el arbol rojinegro.
    void leftRotate(Node* x)
    {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != NIL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    //Función que ejecuta la rotación hacia la derecha para preservar el arbol rojinegro.
    void rightRotate(Node* x)
    {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != NIL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    //Esta es la correción que tiene que tener el insert de un arbol binario tradicional para que no viole las características del arbol rojinegro
    //Por supuesto, incluye las rotaciones
    void fixInsert(Node* k)
    {
        while (k != root && k->parent->color == "RED") {
            if (k->parent == k->parent->parent->left) {
                Node* u = k->parent->parent->right; // uncle
                if (u->color == "RED") {
                    k->parent->color = "BLACK";
                    u->color = "BLACK";
                    k->parent->parent->color = "RED";
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = "BLACK";
                    k->parent->parent->color = "RED";
                    rightRotate(k->parent->parent);
                }
            }
            else {
                Node* u = k->parent->parent->left; // uncle
                if (u->color == "RED") {
                    k->parent->color = "BLACK";
                    u->color = "BLACK";
                    k->parent->parent->color = "RED";
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = "BLACK";
                    k->parent->parent->color = "RED";
                    leftRotate(k->parent->parent);
                }
            }
        }
        root->color = "BLACK";
    }

    //Esta es la función regular de búsqueda en árboles binarios
    Node* searchHelper(Node* node, int data)
    {
        if (node == NIL || data == node -> data ) {
            return node;
        }
        if (data < node->data) {
            return searchHelper(node->left, data);
        }
        return searchHelper(node->right, data);
    }

    //Función tradicional de árboles binarios, incluyendo una última llamada a fix_insert() que adecua el insert al caso de árboles rojinegros
    void insert(int data, int pos)
    {
        Node* new_node = new Node();
        new_node -> data = data;
        new_node->left = NIL;
        new_node->right = NIL;
        new_node -> position = pos;

        Node* parent = nullptr;
        Node* current = root;

        // BST insert
        while (current != NIL) {
            parent = current;
            if (new_node->data < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        new_node->parent = parent;

        if (parent == nullptr) {
            root = new_node;
        }
        else if (new_node->data < parent->data) {
            parent->left = new_node;
        }
        else {
            parent->right = new_node;
        }

        if (new_node->parent == nullptr) {
            new_node->color = "BLACK";
            return;
        }

        if (new_node->parent->parent == nullptr) {
            return;
        }

        fixInsert(new_node);
    }
    
    //Se llama a la función search_helper que ya definimos como la búsqueda tradicional de un árbol binario, claramente se le debía pasar la root y la data.
    Node* search(int data)
    {
        return searchHelper(root, data);
    }
};

int main()
{
    //Hacer que los outputs sean mostrados cuando finalice el programa
    cin.tie(NULL);

    //Se crea el objeto de tipo RedBlackTree (Arbol rojinegro)
    RedBlackTree rbt;

    int elementos;
    int querys;  

    //Se recibe tanto los elementos a insertar como los querys
    cin >> elementos >> querys;
    
    //Diseño acorde a la logica del problema de SPOJ
    int pos = 0;
    int pos_cont = 0;
    int elementos_cont = elementos;
    int elemento_ant;

    /*
    La variable pos va a asignar a los elementos que tengan el mismo data con la misma posicion, siempre va a ser la primera aparicion:
    Ejemplo: 
    En el siguiente arreglo se tendrían las siguientes posiciones: 
    [1,4,4,4,5,5,7]
     0 1 1 1 4 4 5
    pos_cont es el que lleva el conteo real de las posiciones, es quien nos permite que de 1 pasemos a 4.

    elementos_cont va a ser una variable que usaré para verificar que no esté en la primera iteración, porque no existe elemento anterior para la primera iteración.
    elemento_ant va a ser una variable que usaré para guardar el elemento anterior.
    */

    while (elementos > 0){
        
        int elemento;
        
        scanf("%d", &elemento);

        //Si estamos en la primera iteración, te sales
        if(elementos_cont != elementos){
            //Si el elemento es igual al anterior, entonces inserto en el árbol, indicando que su posición es pos; no post_cont
            if(elemento == elemento_ant){
                rbt.insert(elemento, pos);

            //De lo contrario, uso post_cont para actualizar la posición real del elemento.
            } else {
                //Cuando utilizo pos_cont es porque el elemento no es igual al anterior, entonces debo actualizar pos para que si se repite, tenga el nuevo valor.
                rbt.insert(elemento, pos_cont);
                pos = pos_cont;
            }
        } else{
            rbt.insert(elemento, pos_cont);
            pos = pos_cont;
        }
        
        //Siempre actualizo el elemento anterior
        elemento_ant = elemento;
        //Siempre actualizo pos_cont; pero no siempre actualizo pos
        pos_cont += 1;
        //Siempre resto uno a los elementos, como siempre
        elementos -= 1;
    }

    while (querys > 0){
        
        int query;
        
        //Recibo cada consulta
        scanf("%d", &query);

        //Verifico que la respuesta de search no sea NIL, porque de serlo, entonces debería imprimir -1
        //Si es distinta de NIL, entonces imprimo el atributo position del nodo que halló.
        //Nota que no importa que nodo halló, siempre devuelve la posición del primero, esto gracias al while anterior que nos daba casos como: 
        /*
        [1,4,4,4,5,5,7]
         0 1 1 1 4 4 5
        Por ejemplo, si le pido que busque 4, él encuentra alguno de esos 4, pero como devuelve la posición, su respuesta será 1, porque todos tienen ese 1 en position.
        */
        if(rbt.search(query) != rbt.NIL){
            //Imprimo la primera aparición del elemento a buscar
            printf("%d\n", rbt.search(query) -> position);
        } else {
            //Imprimo -1 porque no fue hallado el elemento
            printf("%d\n", -1);
        }

        querys -= 1;
    }

    return 0;
}