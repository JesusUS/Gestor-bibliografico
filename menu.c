#include "menu.h"

void print_menu (){
	
	printf ("1.- Insertar referencia bibliografica\n");
	printf ("2.- Mostrar resumen\n");
	printf ("3.- Mostrar informacion de una publicacion\n");
	printf ("4.- Modificacion de una publicacion\n");
	printf ("5.- Borrar referencia a partir de us ID\n");
	printf ("6.- Exportar a fichero\n");
	printf ("7.- Importar desde fichero\n");
	printf ("8.- Ordenar por fechas descendente\n");
	printf ("9.- Salir\n");
	printf ("\n-------------------------------------------------\n\n");
	
}

int data_read(){
	
	char *ptr = NULL;
	size_t n = 0;
	int opcion = 0;
	
	getline(&ptr, &n, stdin);	
	opcion = (int) strtol (ptr, (char **)NULL, 10);
	free (ptr);
	
	return opcion;
	
}

char *string_read(){
	
	char *ptr = NULL;
	size_t n = 0;
	
	getline(&ptr, &n, stdin);	
	
	return ptr;
	
}
