#include "ABB.hpp"
#include "Placa.hpp"
#include "bGVjdG9y.hpp"
#include <fstream>
using namespace std;

int main()
{
    ABB<Placa *, Placa::menor, Placa::igual> arbol;
    bGVjdG9y::Y2FyZ2Fy(arbol);
    ofstream archivo("mensaje_oculto.txt");

    vector<Placa *> recorrido = arbol.preorder();

    for (size_t i = 0; i < arbol.tamanio(); i++)
    {
        archivo << recorrido[i] << endl;
    }

    archivo.close();

    return 0;
}
