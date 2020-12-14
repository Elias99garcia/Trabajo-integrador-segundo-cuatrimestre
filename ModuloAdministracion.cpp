/*
Módulo Administración:
La gerencia del centro veterinario es la encargada de realizar el alta de los veterinarios que trabajan
en la institución, así como también de los empleados que realizan la registración de los turnos y mascotas.
Es el área encargada desea visualizar las atenciones realizadas por los profesionales según las en el
mes.
Para incentivar a los veterinarios, la gerencia otorga un bono mensual al profesional que haya
registrado la mayor cantidad de turnos en ese periodo.
*/


#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <string.h>
using namespace std;

//----- EstructuraS -----//
struct fecha
{
    int dia;
    int mes;
    int anio;
};
struct fecha2
{
    int dia2;
    int mes2;
    int anio2;
};

struct RegVeterinario
{
    int nombreVeterinario;
    char ApeNomb[40];
    fecha fec; 
};
struct RegAyudante
{
    int nombreAyudante;
    char ApeNombA[40];
    fecha2 fec; 
};

//----- Prototipos de funciones-----//

int menuPrincipal();   
void mensaje(char const *cadena);
void registrarDatos(FILE *veterinario);
bool DatosAyudante(FILE *veterinario); 
void listadoVeterinario(FILE *veterinario); 
void listadoAyudante(FILE *veterinario); 


int main(){
   
    system ("color f9");
    int N=0, nroLic=0, nOp = 0;
    int nroOp = 0;
    FILE *ArchVeterinario; 
    ArchVeterinario = fopen("veterinario.dat","w+b");
    if(ArchVeterinario == NULL)
    {// Evalua, Si hubo error, muestra mensaje y termina.
        system("CLS");
        mensaje("Ocurrio un error en la apertura del Archivo");
        exit(1);
    }


    do
    {
        nOp = menuPrincipal();
        switch(nOp)
        {
            case 1:
                registrarDatos(ArchVeterinario);
                break;

            case 2:
                bool band;
                band = DatosAyudante(ArchVeterinario);
                if(band)
                ArchVeterinario = fopen("veterinario.dat","r+b"); //Se abre de nuevo el archivo, porque
                break; //Fue cerrado en el borrado físico.

            case 3:
                listadoVeterinario(ArchVeterinario);
                listadoAyudante(ArchVeterinario);
            break;

            case 4:
                system("CLS");
                mensaje("F i n d e l P r o g r a m a");
                break;

            default:
                system("CLS");
                mensaje("Ha ingresado un numero no valido");
                break;
        } //Fin del switch().

    }while(nOp != 4); //Fin del Ciclo Do
} 


//--------------Desarollo de las funciones--------------//


//-----MENU PRINCIPAL-----//
int menuPrincipal(){

 int opc=0;
 system("CLS");
 cout<<"\t---------------------------------------------------------\n";
 cout<<"\t M O D U L O   A D M I N I S T R A C I O N \n";
 cout<<"\t---------------------------------------------------------\n";

 cout<<"\t-- (1) Introduzca DATOS DEL VETERINARIO\n";

 cout<<"\t---------------------------------------------------------\n";

 cout<<"\t-- (2) Introduca DATOS del AYUDANTE\n";

 cout<<"\t---------------------------------------------------------\n";

 cout<<"\t-- (3) ATENCION POR VETERINARIOS\n";

 cout<<"\t---------------------------------------------------------\n";

 cout<<"\t-- (4) S A L I R del S I S T E M A \n";

 cout<<"\t---------------------------------------------------------\n\n";
 cout<<" Seleccione Opcion: ";
 scanf("%d", &opc);
 return opc;
}






void registrarDatos(FILE *veterinario)
{
    RegVeterinario reg; 
    int nroReg=0; 
    char continua='N';
    do{
        system("CLS");
        cout<<"\t------------------------------------------\n";
        cout<<"\t M O D U L O   A D M I N I S T R A C I O N \n";
        cout<<"\t------------------------------------------\n\n";
        cout<<"\n\t Introduzca el numero del veterinario a REGISTRAR: ";
		cin>>reg.nombreVeterinario;
        _flushall();
        printf("\n\t Apellido y Nombre: "); gets(reg.ApeNomb);
        cout<<"\n\t ----Fecha de nacimiento---- \n";
        cout<<"\n\t Dia: ";
		cin>>reg.fec.dia;
        cout<<"\n\t Mes: ";
		cin>>reg.fec.mes;
        cout<<"\n\t Anio: ";
		cin>>reg.fec.anio;
        fwrite(&reg, sizeof(RegVeterinario), 1, veterinario); //Graba el registro lógico.
        _flushall();
        
        cout<<"\n\n¿Quiere continuar ingresando VETERINARIOS? (S/N): ";
        scanf("%c", &continua);
    }while(continua == 'S' || continua == 's');
    system("CLS");
    mensaje("Fin de la carga"); //Muestra el mensaje.
} //Fin de la función registrarTaxis.


/*------------------------------------------------*/
bool DatosAyudante(FILE *veterinario)
{
    RegAyudante reg; 
    int nroReg=0; 
    char continua='N';
    do{
        system("CLS");
        cout<<"\t------------------------------------------\n";
        cout<<"\t M O D U L O   A D M I N I S T R A C I O N \n";
        cout<<"\t------------------------------------------\n\n";
        printf("\n\tApellido y Nombre del ayudante: "); scanf("%d",&reg.nombreAyudante);
        _flushall();
        cout<<"\n\t ----Fecha de nacimiento---- \n";
        cout<<"\n\t Dia: ";
		cin>>reg.fec.dia2;
        cout<<"\n\t Mes: ";
		cin>>reg.fec.mes2;
        cout<<"\n\t Anio: ";
		cin>>reg.fec.anio2;
        fwrite(&reg, sizeof(RegAyudante), 1, veterinario); //Graba el registro lógico.
        _flushall();
        cout<<"\n\n¿Quiere continuar ingresando Ayudantes? (S/N): ";
        cin>>continua;
    }while(continua == 'S' || continua == 's');
    system("CLS");
    mensaje("Fin de la carga"); 
} 


//----------Funcion para listar DATOS----------//
void listadoVeterinario(FILE *veterinario){
 RegVeterinario reg; 

 
//----- Titulo del listado -----//

 system("CLS");
 cout<<"\t---------------------------------------------------------\n";
 cout<<"\t                 LISTA DE VETERINARIOS\n";
 cout<<"\t---------------------------------------------------------\n\n";
 cout<<"\tNum de VET";
 cout<<"  Nombre";
 cout<<"\t Fecha de NAC."<<endl;
 cout<<"\t---------------------------------------------------------\n\n";

 rewind(veterinario); 
 fread(&reg, sizeof(reg), 1, veterinario); 
 if (feof(veterinario)){
    system("CLS");
    mensaje("El Archivo esta vacio\n No se ENCONTRO INFORMACION.");
 }

 else{
    
    while(!feof(veterinario)){ //Repite hasta el último registro.
        printf("\t %d ", reg.nombreVeterinario);
        printf("\t %s ", reg.ApeNomb );
        printf("\t %d/%d/%d ", reg.fec.dia, reg.fec.mes, reg.fec.anio);
        printf("\n");
        
        
        
        fread(&reg, sizeof(RegVeterinario), 1, veterinario);
    }
 }
 
       
 mensaje("(HAGA CLICK O ENTER PARA PASAR A LA VENTANA DEL AYUDANTE)");
}

void mensaje(char const *cadena){

cout<<"\n\n\n---------------------------------------------------------\n";
cout<<"\n %s "<<cadena;
cout<<"\n\n---------------------------------------------------------*\n\n\t";
system("PAUSE");
} 



void listadoAyudante(FILE *veterinario){
 RegAyudante reg; 

 
 system("CLS");
 cout<<"\t---------------------------------------------------------\n";
 cout<<"\t                 LISTA DE AYUDANTES\n";
 cout<<"\t---------------------------------------------------------\n\n";
 cout<<"\tNombre";
 cout<<"\t Fecha de NAC."<<endl;
 cout<<"\t---------------------------------------------------------\n\n";

 rewind(veterinario); 
 fread(&reg, sizeof(reg), 1, veterinario); 
 if (feof(veterinario)){
    system("CLS");
    mensaje("El Archivo esta vacio\n No se ENCONTRO INFORMACION.");
 }

 else{
    
    while(!feof(veterinario)){ //Repite hasta el último registro.
        printf("\t %d ", reg.nombreAyudante);
        printf("\t %d/%d/%d ", reg.fec.dia2, reg.fec.mes2, reg.fec.anio2);
        printf("\n");
        
        
        
        fread(&reg, sizeof(RegAyudante), 1, veterinario);
    }
 }
 
       
 mensaje("\t\t\t\tMODULO DE ADMINISTRACION ");
}


