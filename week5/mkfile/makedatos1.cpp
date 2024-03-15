#include <iostream>
#include <cstdlib>
#include <ctime>

#include <fstream> // Para trabajar con archivos

using std::cout;
using std::endl;

using std::ofstream;

int main()
{
    int posicion;
    int step;
    int i;
    srand(time(0));

    posicion = 100;
    i = 0;

    ofstream archivo("datos1.dat");

    if (!archivo)
    {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    while (posicion > 0)
    {
        step = rand() % 3 - 1;
        posicion += step;
        archivo << i << " " << posicion << endl;
        i++;
    }

    archivo.close();

    return 0;
}
