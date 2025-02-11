#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;
//NODOS PARA EL USUARIO
struct DatosUsuario
{
    string nombreUsuario;
    string contrasenhaUsuario;
    float saldo;
};
//NODOS PARA LOS DATOS DE LA LISTA
struct Movimientos
{
    int Retiro;
    int Deposito;
    float NuevoSaldo;
    Movimientos *sig, *ant;
};


//CLASE PARA CREAR UNA LISTA DE DATOS DE MOVIMIENTOS CREADOS
class ListaDoble_Movimientos{
private:
Movimientos *pInicio;
Movimientos *pFinal;
public:
ListaDoble_Movimientos(): pInicio(NULL), pFinal(NULL){};//Constructor
void MetodoRetiro();//Insertar datos de los "Retiros y Depostios"


};



//PROCEDER A CREAR FUNCION PARA INSERTAR LOS DATOS
void ListaDoble_Movimientos::MetodoRetiro()
{
DatosUsuario datos; //instancia usuario esto es una "estructura"
int saldo=100;
datos.saldo=saldo;//se puede declarar una variable local para trabajar los datos internamente
cout<<"el saldo es 100" <<endl;
Movimientos dMovimientos;//instancia de los "retiros y depositos" esto es una "estructura"
int retiro=50;
dMovimientos.Retiro=retiro;//se puede declarar una variable local para trabajar los datos internamente
cout<<"el retiro será 50" <<endl;

cout<< endl <<endl;//saltos de linea


cout<<"proceso de resta" <<endl;

int nuevoSaldo;
nuevoSaldo = saldo - retiro;//resta realizada con variables locales

cout<<"su nuevo saldo es:" <<nuevoSaldo <<endl;//salida de los datos


cout<<"metodo 2" <<endl;
int nuevoSaldo2;
nuevoSaldo2= datos.saldo-dMovimientos.Retiro;//proceso realizado con variables globales 
cout<<"nuevo saldo es:" <<nuevoSaldo2 <<endl;//salida de los datos
 
}


int main()
{
    ListaDoble_Movimientos prueba;
    prueba.MetodoRetiro();
    return 0;
}