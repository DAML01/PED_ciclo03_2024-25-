#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;
// NODOS PARA EL USUARIO
struct DatosUsuario
{
    string nombreUsuario;
    string contrasenhaUsuario;
    float saldo;
};
// NODOS PARA LOS DATOS DE LA LISTA
struct Movimientos
{
    int Retiro;
    int Deposito;
    float NuevoSaldo;
    Movimientos *sig, *ant;
};

// CLASE PARA CREAR UNA LISTA DE DATOS DE MOVIMIENTOS CREADOS
class ListaDoble_Movimientos
{
private:
    Movimientos *pInicio;
    Movimientos *pFinal;

public:
    ListaDoble_Movimientos() : pInicio(NULL), pFinal(NULL) {}; // Constructor
    void Ingreso_Dato_Retiro();                                // Usuario ingresará cantidad a retirar
    void MetodoRetiro(int);                                    // Insertar datos de los "Retiros y Depostios"
};

void ListaDoble_Movimientos::Ingreso_Dato_Retiro()
{
    Movimientos retiro; // Creacion de la instancia para acceder al dato del nodo
    char respuesta;
    do // bucle que pregunte si quiere retirar el dinero
    {
        cout << "¿Desea retirar dinero?(s/n):" << endl;
        cin >> respuesta;
        if (respuesta == 's')
        {
            cout << "ingrese el monto a retirar(para salir presione 'n'):" << endl;
            cin >> retiro.Retiro; // la instancia manadara el dato a el nodo y se registrará en el mismo (falta hacer que sea global y para cada usuario en especifico)
        }
    } while (respuesta == 's'); // sale del bucle

    cout << "salio" << endl;
    cout << "llamando a funcion metodo retiro" << endl;
    MetodoRetiro(retiro.Retiro); // llama la funcion MetodoRetiro que usara como argumento (retiro "instancia" . Retiro "variable local")
}

// PROCEDER A CREAR FUNCION PARA REALIZAR LA RESTA Y CREAR NUEVO SALDO
void ListaDoble_Movimientos::MetodoRetiro(int retiro) // se usa el dato que proviene de ":Ingreso_Dato_Retiro()" para trabajar la cantidad que quiere ingresar
{
    DatosUsuario datos; // instancia usuario esto es una "estructura"
    int saldo = 100;
    datos.saldo = saldo; // se puede declarar una variable local para trabajar los datos internamente
    cout << "el saldo es 100" << endl;
    Movimientos dMovimientos; // instancia de los "retiros y depositos" esto es una "estructura"

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
    
}

int main()
{
    ListaDoble_Movimientos prueba;
    int retiro;
    prueba.MetodoRetiro(retiro);
    prueba.Ingreso_Dato_Retiro();
    return 0;
}
