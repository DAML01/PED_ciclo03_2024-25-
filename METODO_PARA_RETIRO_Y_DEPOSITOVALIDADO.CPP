#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

struct DatosUsuario
{
    string nombreUsuario;
    string contrasenhaUsuario;
    float saldo;
};

struct Movimientos
{
    int Retiro;
    int Deposito;
    Movimientos *sig, *ant;
};

class listaMovimientos
{
private:
    Movimientos *pInicio = nullptr;
    Movimientos *pFinal = nullptr;

public:
    listaMovimientos() : pInicio(NULL) {};
    ~listaMovimientos();
    void MetodoRetiro();
    void MetodoDeposito();
};

listaMovimientos::~listaMovimientos()
{
}

void listaMovimientos::MetodoRetiro()
{
    DatosUsuario datos; // instancia usuario esto es una "estructura"
    int saldo = 100;
    datos.saldo = saldo; // se puede declarar una variable local para trabajar los datos internamente
    cout << "el saldo es 100" << endl;
    Movimientos dMovimientos; // instancia de los "retiros y depositos" esto es una "estructura"
    int retiro = 56;
    if (retiro <= saldo)
    {
        if (retiro > 500)
        {
            cout << "Limite alcanzado\n";
        }
        if (retiro % 5 == 0)
        {
            dMovimientos.Retiro = retiro; // se puede declarar una variable local para trabajar los datos internamente
            cout << "el retiro será 50" << endl;

            cout << endl
                 << endl; // saltos de linea

            cout << "proceso de resta" << endl;

            int nuevoSaldo;
            nuevoSaldo = saldo - retiro; // resta realizada con variables locales

            cout << "Retiro exitoso\n";
            cout << "su nuevo saldo es:" << nuevoSaldo << endl; // salida de los datos
        }
        else
        {
            cout << "No se puede retirar esa cantidad.Intente nuevamente\n";
        }
    }
    else
        cout << "No dispones de suficientes fondos\n";
}

void listaMovimientos::MetodoDeposito() // Es lo mismo pero suma.
{
DatosUsuario datos; //instancia usuario esto es una "estructura"
int saldo=100;
datos.saldo=saldo;//se puede declarar una variable local para trabajar los datos internamente
cout<<"el saldo es 100" <<endl;
Movimientos dMovimientos;//instancia de los "retiros y depositos" esto es una "estructura"
int deposito=100;
if (deposito <= 500)
{
    if (deposito % 5 == 0)
    {
        dMovimientos.Deposito=deposito;//se puede declarar una variable local para trabajar los datos internamente
        cout<<"el deposito será 100" <<endl;

        cout<< endl <<endl;//saltos de linea


        cout<<"proceso de suma" <<endl;

        int nuevoSaldo;
        nuevoSaldo = saldo + deposito;//resta realizada con variables locales

        cout<<"su nuevo saldo es:" <<nuevoSaldo <<endl;//salida de los datos


        cout<<"metodo 2" <<endl;
        int nuevoSaldo2;
        nuevoSaldo2= datos.saldo+dMovimientos.Deposito;//proceso realizado con variables globales 
        cout<<"nuevo saldo es:" <<nuevoSaldo2 <<endl;//salida de los datos
    }else
    {
        cout << "No puedes depositar esa cantidad. Intenta nuevamente\n";
    }
}else
{
    cout << "Para depositar esa cantidad de dinero debes visitar una agencia\n";
}
}


int main(){
    listaMovimientos prueba2;
    prueba2.MetodoDeposito();
    return 0;
}
