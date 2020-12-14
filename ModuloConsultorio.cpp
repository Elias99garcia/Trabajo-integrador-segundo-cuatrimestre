#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

const char nombreUsuarios[20]="veterinario.dat";
const char nombreTurnos[20]="Turnos.dat";
struct fecha


{
    int dia,mes,anio;
};
struct registroTurnos
{
    int matricula;
    fecha FechaAtencion;
    int dniDueno;
    char detalle[360];
};
struct registro
{
    
    char usuario[20];
    char contrasena[20];
    char apellidoNombre[20];
    
};
struct registroMascota
{
    char apellidoNombre[50];
    char domicilio[30];
    int dniDueno;
    char localidad[30];
    fecha fechaNacimiento;
    float peso;
    int telefono;
    char detalleUltimaAtencion[360];
    char fechaUltimaAtencion[100];
};
struct nodo
 {
     registroTurnos turnos;
     nodo *siguiente;
 };
 
 
 
void leerPasw(char frase[]);
void IniciarSesion(int &ingresa);
int menu();
void registrarEvolucion(nodo *&frente, nodo *&fondo, registroTurnos auxiliar);
void cargarYmostrar(nodo *&frente, nodo *&fondo, registroTurnos auxiliar);
void cargarNodo(nodo *&frente, nodo *&fondo, registroTurnos auxiliar);



main()
{
	system ("color f9");
    setlocale(LC_ALL, "spanish");
    int ingresa=0;
    nodo *frente, *fondo;
      registroTurnos aux;
      frente=NULL;
      fondo=NULL;
      int opcion;
      do{
          opcion=menu();
          switch(opcion)
          {
              case 1: system("cls");
                      IniciarSesion(ingresa);
                      printf("\n\n");
                      system("pause");
                      printf("cls");
              break;
              case 2: if(ingresa==1)
                       {
                        system("cls");
                      cargarYmostrar(frente,fondo,aux);
                       }
                      else {
                      printf("\n\t\t\t------------------------------------------------------");
                      printf("\n\t\t\t PARA VISUALIZAR TURNOS, INICIE SESION...             ");
                      printf("\n\t\t\t------------------------------------------------------");
                      break;
                      }
                      printf("\n\n");
                      system("pause");
                      printf("cls");
                      
              break;
              case 3:if(ingresa==1)
                     {
                         registrarEvolucion(frente,fondo,aux);
                     }
                      else {
                      printf("\n\t\t\t------------------------------------------------------");
                      printf("\n\t\t\t PARA REGISTRAR EVOLUCION DE LA MASCOTA, INICIE SESION...             ");
                      printf("\n\t\t\t------------------------------------------------------");
                      
                      }
                      printf("\n\n");
                      system("pause");
                      printf("cls");
              break;
              case 4: printf("\n\t\t\t------------------------------------------------------");
                      printf("\n\t\t\t  SALIENDO DEL PROGRAMA...                            ");
                      printf("\n\t\t\t------------------------------------------------------");
              break;
              default:    printf("\n\t\t\t------------------------------------------------------");
                          printf("\n\t\t\t  ERROR, DEBE INGRESAR UNA OPCION. . .                ");
                          printf("\n\t\t\t------------------------------------------------------");
              break;
          }
      }while(opcion!=3);



system("pause");
}

int menu()
{
    
    int opcion;
    system("cls");
    printf("\n\t\t\t==============================================================");
    printf("\n\t\t\t      M O D U L O  C O N S U L T O R I O                      ");
    printf("\n\t\t\t==============================================================");
    printf("\n\t\t\t  1-Iniciar Sesion                                      ");
    printf("\n\t\t\t--------------------------------------------------------------");
    printf("\n\t\t\t  2-Visualizar lista de espera de turnos                      ");
    printf("\n\t\t\t--------------------------------------------------------------");
    printf("\n\t\t\t  3-Registrar una evolucion de la mascota                     ");
    printf("\n\t\t\t--------------------------------------------------------------");
    printf("\n\t\t\t  4-S A L I R   de   la   A P L I C A C I O N                 ");
    printf("\n\t\t\t--------------------------------------------------------------");
    printf("\n\t\t\t  INGRESE SU OPCION --> ");
    scanf("%d",&opcion);
    
    return opcion;
}

void IniciarSesion(int &ingresa)
{
    char usuario[20],contra[20], apenom[20];
    char caracter;
    int i=0,b=0,cantidad;
    int intento=0;
    registro usuarios,aux[20];
   FILE *archivo;
   archivo=fopen(nombreUsuarios,"rb");
   fread(&usuarios,sizeof(registro),1,archivo);
   while(!feof(archivo))
   {
        strcpy(aux[i].usuario,usuarios.usuario);
        strcpy(aux[i].contrasena,usuarios.contrasena);
        strcpy(aux[i].apellidoNombre,usuarios.apellidoNombre);
   
         i++;
         
         fread(&usuarios,sizeof(registro),1,archivo);
     }
         cantidad=i; 
       
        
       
       for(int a; a<cantidad; a++)
       {
          system("cls");
           printf("\n\t\t----------------------------");
           printf("\n\t\t   INICIO DE SESION           ");
           printf("\n\t\t----------------------------");
           printf("\n\t\t USUARIO-> ");
           _flushall();
           gets(usuario);
           printf("\n\t\t APELLIDO Y NOMBRE -> ");
           gets(apenom);
           printf("\n\t\t CONTRASEÑA -> ");
           
           leerPasw(contra);
           
			
		
       
       if(strcmp(usuario,aux[a].usuario)==0 and strcmp(apenom,aux[a].apellidoNombre)==0 and strcmp(contra,aux[a].contrasena)==0){
           ingresa=1;
           break;
       }
       else intento ++;
       if(intento==5)
       {
           printf("\n\t\t\t SE HA SUPERADO EL LIMITE DE INTENTOS ...");
           ingresa=0;
           break;
       }
       
        
   
     }
}
void leerPasw(char frase[])
{
    int i=0;
    _flushall();

    do
    {
        frase[i] = (unsigned char)getch();

        if(frase[i]!=8)  
        {
            printf("*");  
            i++;
        }
        else if(i>0)    
        {
            printf("\b \b");
            i--;  
        }
    
        _flushall();

    }while(frase[i-1]!=13);  

    frase[i-1] = NULL;
    
}

void cargarYmostrar(nodo *&frente, nodo *&fondo, registroTurnos auxiliar)
{
    FILE *archivo;
    int cantidad=1;
    archivo=fopen(nombreTurnos,"r+b");
    fread(&auxiliar,sizeof(registroTurnos),1,archivo);
    while(!feof(archivo))
    {
        cargarNodo(frente,fondo,auxiliar);
        fread(&auxiliar,sizeof(registroTurnos),1,archivo);
    }
    
    system("pause");
    
    nodo *aux1;
    aux1=frente;
    system("cls");
    printf("\n======================================================");
    printf("\n\t\t               LISTADO DE TURNOS                  ");
    printf("\n======================================================");
    
    while(aux1!=NULL)
    {
        printf("\n------------------------------------------");
        printf("\n\t Numero del turno  #%d",cantidad);
        printf("\n------------------------------------------");
        printf("\n Matricula del veterinario: %d",aux1->turnos.matricula);
        printf("\n FECHA ->   %d / %d / %d ",aux1->turnos.FechaAtencion.dia,aux1->turnos.FechaAtencion.mes,aux1->turnos.FechaAtencion.anio);
        printf("\n DNI Dueno: %d",aux1->turnos.dniDueno);
        printf("\n\n");
        aux1=aux1->siguiente;
        cantidad++;
        
    }  
    
    system("pause");  
}
void cargarNodo(nodo *&frente, nodo *&fondo, registroTurnos auxiliar)
{
    nodo *auxiliar1;
    auxiliar1=new nodo;
    if(auxiliar1!=NULL)
    {
        auxiliar1->turnos=auxiliar;
        auxiliar1->siguiente=NULL;
        if(frente==NULL)
        frente=auxiliar1;
        else 
        fondo->siguiente=auxiliar1;
        fondo=auxiliar1;
    }
    else printf("\n\n LA COLA SE ENCUENTRA LLENA...");
}

void registrarEvolucion(nodo *&frente, nodo *&fondo, registroTurnos auxiliar)
{
    system("cls");
    printf("\n\t\t=============================================");
    printf("\n\t\t         T U R N O   A C T U A L             ");
    printf("\n\t\t=============================================");
    registroTurnos Auxiliar;
    if(frente!=NULL)
    {
        nodo *p;
        p=frente;
        Auxiliar.matricula=p->turnos.matricula;
        Auxiliar.FechaAtencion.dia=p->turnos.FechaAtencion.dia;
        Auxiliar.FechaAtencion.mes=p->turnos.FechaAtencion.mes;
        Auxiliar.FechaAtencion.anio=p->turnos.FechaAtencion.anio;
        Auxiliar.dniDueno=p->turnos.dniDueno;
        frente=p->siguiente;
        delete (p);
         
        if(frente==NULL) fondo=NULL;
        printf("\n\t----------------------------------------- ");
        printf("\n\t MATRICULA VETERINARIO: %d",Auxiliar.matricula);
        printf("\n\t FECHA : %d/ %d/ %d",Auxiliar.FechaAtencion.dia,Auxiliar.FechaAtencion.mes,Auxiliar.FechaAtencion.anio);
        printf("\n\t DNI DEL DUEÑO: %d",Auxiliar.dniDueno);
        printf("\n\t----------------------------------------- ");
        printf("\n\n\n");
        
    }
    FILE *archi;
    int verif=0;
    registroMascota mascota;
    archi=fopen("Mascotas.dat","r+b");
    fread(&mascota,sizeof(registroMascota),1,archi);
    printf("\n\t VERIFICAR EXISTENCIA DE HISTORIA CLINICA...");
    printf("\n\n");
    while(!feof(archi))
	 {
	     if(Auxiliar.dniDueno==mascota.dniDueno)
	     {
         printf("\n NOMBRE Y APELLIDO: %s",mascota.apellidoNombre);
	     printf("\n DOMICILIO: %s",mascota.domicilio);
	     printf("\n DNI DEL DUEÑO: %d",mascota.dniDueno);
	     printf("\n LOCALIDAD: %s",mascota.localidad);
	     printf("\n FECHA NACIMIENTO: %d/ %d /%d ",mascota.fechaNacimiento.dia,mascota.fechaNacimiento.mes,mascota.fechaNacimiento.anio);
	     printf("\n PESO MASCOTA: %.2f",mascota.peso);
	     printf("\n TELEFONO DE CONTACTO: %d",mascota.telefono);
	     
	     printf("\n\n");
         }
         else verif=1;
         fread(&mascota,sizeof(registroMascota),1,archi);
     }
     if(verif==1)
     {
         printf("\n\t ES LA PRIMERA VEZ DE ESTA MASCOTA EN EL CONSULTORIO...");
     }
     fclose(archi);
     printf("\n\n------------------------------------");
     printf("\n\t     REGISTRAR DEVOLUCIÓN           ");
     printf("\n------------------------------------");
     
     FILE *archiTurnos;
     registroTurnos turnosAux;
     archiTurnos=fopen(nombreTurnos,"r+b");
     fread(&turnosAux,sizeof(registroTurnos),1,archiTurnos);
     while(!feof(archiTurnos))
     {
         if(Auxiliar.dniDueno==turnosAux.dniDueno)
         {
             printf("\n\t : ");
             _flushall();
             gets(turnosAux.detalle);
             fwrite(&turnosAux,sizeof(registroTurnos),1,archiTurnos);
         }
         fread(&turnosAux,sizeof(registroTurnos),1,archiTurnos);
     }
     
     printf("\n\n----------------------------------------------------");
     printf("\n\t  DEVOLUCION GUARDADA, ELIMINANDO TURNO ACTUAL...");
     printf("\n------------------------------------------------------");
     
     printf("\n\n\n");
    system("pause");
}
