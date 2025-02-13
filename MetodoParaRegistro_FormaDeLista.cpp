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
    DatosUsuario *sig, *ant;
};
// NODOS PARA LOS DATOS DE LA LISTA
struct Movimientos
{
    int Retiro;
    float Deposito;
    float NuevoSaldo;
    Movimientos *sig, *ant;
};

// CLASE PARA CREAR UNA LISTA DE DATOS DE MOVIMIENTOS CREADOS
class ListaDoble_Movimientos
{
private:
    Movimientos *MInicio;
    Movimientos *MFinal;

    DatosUsuario *DInicio;
    DatosUsuario *DFinal;


public:
    //CONSTRUCTOR
    ListaDoble_Movimientos();//Constructor e inicializador para toda la lista usuarios y movimientos 

    void MostrarMenu();

    //REGISTRO DE USUARIOS PARA GENERACIÓN DE NODOS
    void RegistrarUsuario();
    //MUESTRA DE USUARIOS EN NODO
    void MostrarUsuario();


    //BORRADO DE USUARIOS Y DATOS
    void BorrarTodos_DatosUsuario();
    void BorrarTodos_DatosUsuario(DatosUsuario*);

    //BORRADO DE MOVIMIENTOS Y DATOS
    
    //DESTRUCTOR
    ~ListaDoble_Movimientos();//Destructor para toda la lista de Usuarios y movimientos
};

//CONSTRUCTOR

ListaDoble_Movimientos::ListaDoble_Movimientos()
{
            //INICIALIZAR LISTAS EN NULL PARA QUE ESTE VACIO EL PROGRAMA AL INICIO

//inicialización de datos para lista de movimientos en NULL para que sus respectivas listas esten vacias 
MInicio=NULL;
MFinal=NULL;

//inicialización de datos para lista de Usuarios en NULL para que sus respectivas listas esten vacias 
DInicio=NULL;
DFinal=NULL;
}

//DESTRUCTOR
ListaDoble_Movimientos::~ListaDoble_Movimientos()
{
    BorrarTodos_DatosUsuario();
}

void ListaDoble_Movimientos::BorrarTodos_DatosUsuario()
{
    BorrarTodos_DatosUsuario(DInicio);
    DInicio = NULL;
    DFinal = NULL;
}

void ListaDoble_Movimientos::BorrarTodos_DatosUsuario(DatosUsuario *salt)
{
    while (salt !=NULL)
    {
        DatosUsuario *temp=salt;
        salt= salt->sig;
        delete temp;
    }

}

//FIN DE PROCESO DE DESTRUCCIÓN


void ListaDoble_Movimientos::RegistrarUsuario()
{
    //INICIO DE DECLARACION DE VARIABLES PARA LA FUNCION

    DatosUsuario instanciaUsuario;

    //variables locales para trabajar internamente
    string usuario;
    string contrasena;

    //instanciamiento de los nodos igualando a variables locales
    instanciaUsuario.nombreUsuario=usuario;
    instanciaUsuario.contrasenhaUsuario=contrasena;

    //FIN DE DECLARACION DE VARIABLES

    //INICIO DE PROGRAMA
    
    int n=164, exclam=173, e=130;

    cout << "Ingrese usuario: ";
    cin >> usuario;
    cout << "Ingrese contrase" <<char(n); cout<<"a: ";//ASCII ñ se lee "ingres contraseña"
    cin >> contrasena;

    DatosUsuario *nuevo= new DatosUsuario;
    nuevo->nombreUsuario=usuario;
    nuevo->contrasenhaUsuario=contrasena;
    nuevo->sig=DInicio;
    nuevo->ant=NULL;
    if (DInicio!=NULL)
    {
        DInicio->ant=nuevo;
    }
    else
    {
        DFinal=nuevo;
    }
    DInicio=nuevo;
}


void ListaDoble_Movimientos::MostrarUsuario()
{
DatosUsuario *salt=DInicio;
while (salt !=NULL)
{
    cout<<"usuario es:" <<salt->nombreUsuario <<endl;
    cout<<"contrasena es:" <<salt->contrasenhaUsuario <<endl;
    salt->sig;
    break;
}

}

int main()
{
    ListaDoble_Movimientos instancia;
    
    instancia.RegistrarUsuario();
    instancia.MostrarUsuario();
}