#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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
FILE *archivo;
main()
{
      setlocale(LC_ALL, "spanish");
      registroTurnos turnos;
      archivo=fopen("Turnos.dat","r+b");
      if (archivo == NULL)
	{
		printf("Archivo no existente. Se procedera a su creacion");
		
		archivo = fopen("veterinario.dat", "a+b");
		
		if (archivo == NULL)
		{
			printf("Error al crear el archivo.");
			printf("\nFin del programa....");
			exit(1);
		}
		
		printf("\nArchivo creado exitosamente...\n\n");
		system("cls");
		system("pause");
	
	}
	 fclose(archivo);
	 rewind(archivo);
	 archivo=fopen("Turnos.dat","ab");
	 printf("\n Matricula veterinario:");
	 _flushall();
	 scanf("%d",&turnos.matricula);
	 printf("\n fecha: ");
	 printf("\n dia:");
	 scanf("%d",&turnos.FechaAtencion.dia);
	 printf("\n mes:");
	 scanf("%d",&turnos.FechaAtencion.mes);
	 printf("\n anio:");
	 scanf("%d",&turnos.FechaAtencion.anio);
 
	 printf("\n dni dueño: ");
	 scanf("%d",&turnos.dniDueno);
	 
	 fwrite(&turnos,sizeof(registroTurnos),1,archivo);
	 
	 fclose(archivo);
	 
	 rewind(archivo);
	 
	 
	 archivo=fopen("Turnos.dat","rb");
	 fread(&turnos,sizeof(registroTurnos),1,archivo);
	 while(!feof(archivo))
	 {
	     printf("\n matricula: %d",turnos.matricula);
	     printf("\n fecha : %d/ %d/ %d",turnos.FechaAtencion.dia,turnos.FechaAtencion.mes,turnos.FechaAtencion.anio);
	     printf("\n dni dueño: %d",turnos.dniDueno);
	     
	     printf("\n");
	     fread(&turnos,sizeof(registroTurnos),1,archivo);
     }
	 
	 
	 
	 
	 
      



system("pause");
}

