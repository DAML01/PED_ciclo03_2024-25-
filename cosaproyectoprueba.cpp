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


