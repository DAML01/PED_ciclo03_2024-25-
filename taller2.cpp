#include <iostream>
#include <fstream>
#include<vector>
#include<string>

using namespace std;
int main (){
   //para escribir
ofstream  file("primerarchivo.txt", ios::app);
if (file.is_open())
{
    file <<"este es mi segunda linea" <<endl;
    cout<<"texto guardado correctamente, procediendo a cerrar" <<endl;
    file.close();
    
}
else{
    cerr<<"archivo creado incorrectamente" <<endl;
}

    //para leer
ifstream file("primerarchivo.txt", ios::in);
vector<int> primerarchivo;
int aux;
if (file.is_open())
{
    while (file>>aux)
    {
        cout<<"guardando" <<aux <<endl;
        //.pushback es una funcion que funciona con la libreria de vectores.
        primerarchivo.push_back(aux);
    }
    
}
else
{
cerr<<"Error al abrir el fichero";
return 0;
}
for (int i = 0; i < primerarchivo.size(); i++)
{
    cout<<"nota" <<i+1 <<" es: " <<primerarchivo[i] <<endl;
}

return 0;

}

