/*
Módulo Consultorio:
Esta parte del proyecto estará dirigida a los diferentes profesionales que atienden y registran la
evolución de las mascotas en una base de datos de historias clínicas. El sistema deberá contar con un listado de
las mascotas que están registradas para ser atendidas ese día, para visualizarla, el veterinario deberá
identificarse en el sistema por medio de su número de matrícula y contraseña y accediendo a la opción indicada.
De esta manera el veterinario llamará por apellido y nombre a la mascota que atenderá, una vez realizada esta
tarea procede al ingreso de la evolución, en un texto de no más de 380 caracteres. Luego de realizada esta
operación la mascota debe desaparecer del listado.
Los datos de interés para el veterinario en este proceso son: Apellido y Nombres de la mascota (el
apellido corresponde al dueño o familia), DNI del dueño, Localidad, Edad (calculada con la fecha de nacimiento
registrada), Peso.
La historia clínica de la mascota es común para todos los veterinarios, por lo tanto se deberá visualizar
fecha de atentación de la misma y el nombre del veterinario que la redacto.

Módulo Recepción:
Este módulo satisface las necesidades del personal que asiste a los veterinarios en la atención al
público. Desde aquí se hace ingreso de las mascotas, y la registración de los turnos.
Esta aplicación debe permitir obtener un informe de las mascotas atendidos en determinada fecha
por un determinado veterinario.



*/


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;





//----- Variables globales -----//
string nombre,auxnombre, contra, edad;
int clave=0, auxclave=0;
char dni[10];
char opca;
bool encontrado = false;

//Prototipos de funciones//
void altas();
void bajas();
void consultas();
void buscar();
void modificar();

//----- Programa Principal -----//
int main(){

    system ("color f9");
    int opc;

    do{
    system("cls"); 
    
    cout<<"\n\tBIENVIDO AL SISTEMA DE LA VETERINARIA!\n\n";
    cout<<"\n\t(1).-Registrar Mascota";
    cout<<"\n\t--------------------------";
    cout<<"\n\t(2).-Dar de baja una mascota";
    cout<<"\n\t--------------------------";
    cout<<"\n\t(3).-Consultar el libro de todas nuestras mascotas";
    cout<<"\n\t--------------------------";
    cout<<"\n\t(4).-Buscar un turno registrado";
    cout<<"\n\t--------------------------";
    cout<<"\n\t(5).-Modificaciones";
    cout<<"\n\t--------------------------";
    cout<<"\n\t(6).-Salir";
    cout<<"\n\t--------------------------";
    cout<<"\n\n\tElige una opcion:  ";
    cin>>opc;
    switch (opc)
    {
case 1:{
    system("cls");
    altas();
    cout<<"\n\t\t";
    system ("pause");
    break;
}
case 2:{
    system("cls");
    bajas();
    cout<<"\n\t\t";
    system ("pause");
    break;
}

case 3:{
    system("cls");
    consultas();
    cout<<"\n\t\t";
    system ("pause");
    break;
}
case 4:{
    system("cls");
    buscar();
    cout<<"\n\t\t";
    system ("pause");
    break;
}
case 5:{
    system("cls");
    modificar();
    cout<<"\n\t\t";
    system ("pause");

    break;
}
case 6:{
    cout<<"\n\n\tHa elegido salir...\n\n\t\t"; system ("pause");
    break;
}
default:{
    cout<<"\n\n\tHa elegido una opcion inexistente...\n\n\t\t"; system ("pause");
    break;
}
    }

    }while (opc!=6);

    system("cls");

    return 0;
}




//----- Desarollo de funciones -----//
void altas()
{
 
    ofstream escritura;
    ifstream consulta;

    do{
    escritura.open("mascotas.txt", ios::out | ios::app);
    consulta.open("mascotas.txt", ios::in);

    if (escritura.is_open() && consulta.is_open()){


            bool repetido=false;

            cout<<"\n";
            cout<<"\tIngrese el NUMERO de MATRICULA:    ";
            cin>>auxclave;
            
 
            consulta>>clave;
            while (!consulta.eof()){
                consulta>>nombre>>contra>>dni>>edad;
                if (auxclave==clave){
                    cout<<"\t\tYa existe este numero de matricula.\n";
                    repetido=true;
                    break;
                }
                consulta>>clave;
            }

            if (repetido==false){
            	cout<<"\tIngresa la CONTRASENIA: ";
                cin>>contra;
                cout<<"\tIngresa el nombre de la MASCOTA:   ";
                cin>>nombre;
                cout<<"\tDNI del dueño de la MASCOTA:    ";
                cin>>dni;
                cout<<"\tIngresa la edad de la MASCOTA:     ";
                cin>>edad;
                escritura<<auxclave<<" "<<nombre<<" "<<contra<<" "<<dni<<" "<<edad<<endl;
                cout<<"\n\tRegistro agregado...\n";
            }

            cout<<"\n\tDesea ingresar INFORMACION de otra mascota? (S/N): ";
            cin>>opca;

    }else{
        cout<<"El archivo no se pudo abrir \n";
    }

    escritura.close();
    consulta.close();

    }while (opca=='S' or opca=='s');

}

void bajas()
{
    ofstream aux;
    ifstream lectura;

    encontrado=false;

    aux.open("auxiliar.txt", ios::out);
    lectura.open("mascotas.txt", ios::in);

    if (aux.is_open() && lectura.is_open()){

        cout<<"\n";
        cout<<"\tIngrese el NUMERO de MATRICULA de la mascota que desea eliminar: ";
        cin>>auxclave;
            
    
            lectura>>clave;
            while (!lectura.eof()){
                lectura>>nombre>>contra>>dni>>edad;
                if (auxclave==clave){
                        encontrado=true;
                        cout<<"\n";
                        cout<<"\tNumero de Matricula:    "<<clave<<endl;
                        cout<<"\tContraseña: "<<contra<<endl;
                        cout<<"\tNombre de la mascota:   "<<nombre<<endl;
                        cout<<"\tDNI del dueño:    "<<dni<<endl;
                        cout<<"\tEdad de la mascota:     "<<edad<<endl;
                        cout<<"\t________________________________\n\n";
                        cout<<"\tRealmente deseas eliminar el registro actual (S/N)? ---> ";
                        cin>>opca;

                        if (opca=='S' or opca=='s'){
                            cout<<"\n\n\t\t\tRegistro eliminado...\n\n\t\t\a";
                        }else{
                            aux<<clave<<" "<<nombre<<" "<<contra<<" "<<dni<<" "<<edad<<endl;
                        }

                    }else{
                        aux<<clave<<" "<<nombre<<" "<<contra<<" "<<dni<<" "<<edad<<endl;
                    }
                lectura>>clave;
            }
    }else{
        cout<<"\n\tEl archivo no se pudo abrir\n";
    }

    if (encontrado==false){
                cout<<"\n\tNo se encontro ningun registro con este NUMERO de MATRICULA: "<<auxclave<<"\n\n\t\t\t";
            }

    aux.close();
    lectura.close();
    remove ("mascotas.txt");
    rename("auxiliar.txt", "mascotas.txt");
}


void consultas()
{


    ifstream lectura;
    lectura.open("alumnos.txt", ios::out | ios::in);
    if (lectura.is_open()){
       
       lectura>>clave;
       while (!lectura.eof()){
            lectura>>nombre>>contra>>dni>>edad;
            cout<<"\n";
            cout<<"\tNumero de MATRICULA:    "<<clave<<endl;
            cout<<"\tContrasenia "<<contra<<endl;
            cout<<"\tNombre de la mascota:   "<<nombre<<endl;
            cout<<"\tDNI del dueño:    "<<dni<<endl;
            cout<<"\tEdad de la mascota:     "<<edad<<endl;
            lectura>>clave;
            cout<<"\t________________________________\n";
       }

    }else{
        cout<<"El archivo no se pudo abrir \n";
    }
    lectura.close();
}


void buscar()
{
    ifstream lectura;
    lectura.open("alumnos.txt", ios::out | ios::in);

    encontrado=false;

    if (lectura.is_open()){
        cout<<"\n\tIngresa la clave del alumno que deseas buscar: ";
        cin>>auxclave;

        lectura>>clave;
        while(!lectura.eof()){
            lectura>>nombre>>contra>>dni>>edad;
     

        if(auxclave==clave){
            cout<<"\n";
            cout<<"\tClave:    "<<clave<<endl;
            cout<<"\tNombre:   "<<nombre<<endl;
            cout<<"\tSemestre: "<<contra<<endl;
            cout<<"\tGrupo:    "<<dni<<endl;
            cout<<"\tEdad:     "<<edad<<endl;
            cout<<"\t________________________________\n";
            encontrado=true;
            break;
        }

     
        lectura>>clave;
        }
        if (encontrado==false){
            cout<<"\n\n\tNo hay registros con la clave: "<<auxclave<<"\n\n\t\t\t";
        }
    }else{
        cout<<"\n\tAun no se pudo abrir el archivo...";
    }

    lectura.close();
}

void modificar()
{
    ofstream aux;
    ifstream lectura;

    encontrado=false;

    aux.open("auxiliar.txt", ios::out);
    lectura.open("alumnos.txt", ios::in);

    if (aux.is_open() && lectura.is_open()){

        cout<<"\n";
        cout<<"\tIngresa la clave del alumno que deseas modificar: ";
        cin>>auxclave;

            lectura>>clave;
            while (!lectura.eof()){
                lectura>>nombre>>contra>>dni>>edad;
                if (auxclave==clave){
                    encontrado=true;
                    cout<<"\n";
                    cout<<"\tClave:    "<<clave<<endl;
                    cout<<"\tNombre:   "<<nombre<<endl;
                    cout<<"\tSemestre: "<<contra<<endl;
                    cout<<"\tGrupo:    "<<dni<<endl;
                    cout<<"\tEdad:     "<<edad<<endl;
                    cout<<"\t________________________________\n\n";
                    cout<<"\tIngresa el nuevo nombre del alumno con la clave: "<<auxclave<<"\n\n\t---> ";
                    cin>>auxnombre;

                    aux<<clave<<" "<<auxnombre<<" "<<contra<<" "<<dni<<" "<<edad<<endl;
                    cout<<"\n\n\t\t\tRegistro modificado...\n\t\t\a";
                    }else{
                    aux<<clave<<" "<<nombre<<" "<<contra<<" "<<dni<<" "<<edad<<endl;
                    }
                lectura>>clave;
            }
    }else{
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }

    if (encontrado==false){
                cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclave<<"\n\n\t\t\t";
            }

    aux.close();
    lectura.close();
    remove ("alumnos.txt");
    rename("auxiliar.txt", "alumnos.txt");
}



