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
    void MetodoRetiro();//int);
    void MetodoDeposito();//int);
    void Menu();
};

listaMovimientos::~listaMovimientos()
{
}

void listaMovimientos::MetodoRetiro()//int)
{
    DatosUsuario datos; // instancia usuario esto es una "estructura"
    int retiro;
    int saldo = rand() % (2000 - 500 + 1) + 500;
    datos.saldo = saldo; // se puede declarar una variable local para trabajar los datos internamente
    cout << "El saldo es: " << saldo << endl;
    Movimientos dMovimientos; // instancia de los "retiros y depositos" esto es una "estructura"
    cout << "Cuanto desea retirar?\n";
    cout << "Retiro: ";
    cin >> retiro;
    if (retiro <= saldo)
    {
        if (retiro > 500)
        {
            cout << "Limite alcanzado\n";
        }
        if (retiro % 5 == 0)
        {
            dMovimientos.Retiro = retiro; // se puede declarar una variable local para trabajar los datos internamente
            cout << "el retiro será " << retiro << endl;

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

void listaMovimientos::MetodoDeposito()//int) // Es lo mismo pero suma.
{
    DatosUsuario datos; // instancia usuario esto es una "estructura"
    int saldoF;
    int saldo = rand() % (2000 - 500 + 1) + 500;
    //int saldoF;
    saldoF = saldo;
    int deposito;
    datos.saldo = saldoF; // se puede declarar una variable local para trabajar los datos internamente
    cout << "el saldo es " << saldoF << endl;
    Movimientos dMovimientos; // instancia de los "retiros y depositos" esto es una "estructura"
    cout << "Cuanto desea depositar?\n";
    cout << "Deposito: ";
    cin >> deposito;
    if (deposito <= 500)
    {
        if (deposito % 5 == 0)
        {
            dMovimientos.Deposito = deposito; // se puede declarar una variable local para trabajar los datos internamente
            cout << "el deposito será " << deposito << endl;

            cout << endl
                 << endl; // saltos de linea

            cout << "proceso de suma" << endl;

            int nuevoSaldo;
            nuevoSaldo = saldoF + deposito; // resta realizada con variables locales

            cout << "su nuevo saldo es:" << nuevoSaldo << endl; // salida de los datos

            cout << "metodo 2" << endl;
            int nuevoSaldo2;
            nuevoSaldo2 = datos.saldo + dMovimientos.Deposito; // proceso realizado con variables globales
            cout << "nuevo saldo es:" << nuevoSaldo2 << endl;  // salida de los datos
        }
        else
        {
            cout << "No puedes depositar esa cantidad. Intenta nuevamente\n";
        }
    }
    else
    {
        cout << "Para depositar esa cantidad de dinero debes visitar una agencia\n";
    }
}

void listaMovimientos::Menu()
{
    int opcion;
    //int saldo = rand() % (2000 - 500 + 1) + 500;
    do
    {
        cout << "Bienvenido a Banco UCA \n";
        cout << "1.Retiro\n";
        cout << "2.Deposito\n";
        cout << "3.Cerrar sesion\n";
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            MetodoRetiro();//saldo);
            break;
        case 2:
            MetodoDeposito();//saldo);
            break;
        case 3:
            return;
            break;
        default:
            cout << "Opcion ivalida. Intente nuevamente\n";
            Menu();
            break;
        }
    } while (opcion != 3);
}

int main()
{
    listaMovimientos prueba2;
    prueba2.Menu();
    // prueba2.MetodoRetiro();
    // prueba2.MetodoDeposito();
    return 0;
}
/*#include "iostream"
//#include "cstdlib"
#include "ctime"
using namespace std;

int main(void)
{
    int n, a, b, i, numAleatorio;

    cout << "GENERACION DE NUMEROS ALEATORIOS" << endl << endl;

    srand(time(0));

    cout << "Cuantos queres? ";
    cin >> n;
    cout << "Valor márixmo de cada número aleatorio: ";
    cin >> b;

    for(i = 1; i <= n; i++)
        cout << rand() % (b + 1) << "  ";

    /*cout << "Cuantos queres? ";
    cin >> n;
    cout << "Introduzca el rango de valores:" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    for(i = 1; i <= n; i++){
        numAleatorio = a + rand() % (b + 1 - a);
        cout << numAleatorio << "  ";
    }*/

    //cout << endl << endl;
    //return 0;
