#include "iostream"
#include "cstring"
using namespace std;

const int longCad=20;       //estructura dada para el manejo de información
struct costoPorArticulo {
    char nombre[longCad +1];
    int cantidad;
    float precio;
    float costoXArticulo;
};

void leerDatos (costoPorArticulo [], int);          //función que lee y llena el arreglo
void costoXArticulo (costoPorArticulo [], int);     //función que calcula el costo por artículo
void desplegarDatos (costoPorArticulo [], int);     //función que despliega el arreglo
float costoTotal (costoPorArticulo [], int);        //función que retorna el costo total

int main (void){
    cout << endl << "PROCESO DE INFORMACION DE PRODUCTOS COMPRADOS" << endl << endl;
    cout << "Introduzca la cantidad de articulos comprados: ";
    int n;
    cin >> n;
    cout << endl;
    struct costoPorArticulo factura[n];     //se crea un arreglo de 'n' casillas para la estructura
    leerDatos (factura, n);
    costoXArticulo (factura, n);
    desplegarDatos (factura, n);
    cout << "El costo total es de : $" << costoTotal (factura, n) << endl;  //se imprime el valor retornado
    return 0;
}

void leerDatos(costoPorArticulo lista[], int n){
    for (int i=0;i<n;i++){
        //se itera 'n' veces, llenando cada campo de la estrucutra correspondiente
        cout << "Introduzca el nombre del articulo: ";
        cin >> lista[i].nombre;
        cout << "Introduzca la cantidad de articulos: ";
        cin >> lista[i].cantidad;
        cout << "Introduzca el precio del articulo: $";
        cin >> lista[i].precio;
        cout << endl;
    }
}

void costoXArticulo (costoPorArticulo lista [],int n){
    for (int i=0;i<n;i++)
        //se realiza la multiplicación para el costo total por artículo
        lista[i].costoXArticulo=lista[i].cantidad*lista[i].precio;
}

void desplegarDatos (costoPorArticulo lista[], int n){
    for (int i=0;i<n;i++){
        //se despliega el contenido del arreglo con una iteración
        cout << "Articulo: " << lista[i].nombre << endl;
        cout << "Cantidad: " << lista[i].cantidad << endl;
        cout << "Precio: $" << lista[i].precio << endl;
        cout << "Costo por articulo: $" << lista[i].costoXArticulo << endl << endl;
    }
}

float costoTotal (costoPorArticulo lista[], int n){
    //se genera una variable que almacenará el total de los costos y será retornada a la función main
    float total;
    for (int i=0;i<n;i++)
        total+=lista[i].costoXArticulo;
    return total;
}