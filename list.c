#include "list.h"
#include "menu.h"
#include <string.h>


/**
 * Funcion que crea la lista
 * 
 * 
 * */
struct publicacion *create_list(){
	
	struct publicacion *node = (struct publicacion *) malloc (sizeof (struct publicacion));
	char *tipo_contribucion;

	printf ("Conferencia o Articulo(c/a): ");
	tipo_contribucion = string_read();
	if ( strcmp (tipo_contribucion,"c\n") == 0){
		node->tipo_contribucion = 0;
	} else if ( strcmp (tipo_contribucion,"a\n") == 0){
		node->tipo_contribucion = 1;
	}
	
	free  (tipo_contribucion);
	
	printf ("\nID: ");
	node->id = data_read();
	
	printf("\nTitulo de publicacion: ");
	node->titulo_publicacion = string_read();
	
	printf("\nNombre de la fuente: ");
	node->nombre_fuente = string_read();
	
	printf("\nAutores: ");
	node->autores = string_read();
	
	printf("\nAño de publicacion: ");
	node->ano_publicacion = data_read();
	
	printf("\nISBN/ISSN: ");
	node->isbn_issn = (long) data_read();
	
	if (node->tipo_contribucion == 0){
		printf ("\nLugar de la conferencia: ");
		node->lugar_conferencia = string_read();
	} else if (node->tipo_contribucion == 1){
		printf ("\nVolumen de la revista: ");
		node->vol_revista = data_read();
		printf ("\nNumero de la revista: ");
		node->num_revista = data_read();
	}
	
	node->next = NULL;
		
	printf ("\n");
	
	return node;

}

/**
 * Funcion que añade un nodo a la lista que ya esta creada
 * 
 * 
 * */
void add_node(struct publicacion **primero){
		
	struct publicacion *node = (struct publicacion *) malloc (sizeof (struct publicacion));
	char *tipo_contribucion;

	printf ("Conferencia o Articulo(c/a): ");
	tipo_contribucion = string_read();
	
	if ( strcmp (tipo_contribucion,"c") ){
		node->tipo_contribucion = 0;
	} else if ( strcmp (tipo_contribucion,"a") ){
		node->tipo_contribucion = 1;
	}
	
	free (tipo_contribucion);
	
	printf ("\nID: ");
	node->id = data_read();
	
	printf("\nTitulo de publicacion: ");
	node->titulo_publicacion = string_read();
	
	printf("\nNombre de la fuente: ");
	node->nombre_fuente = string_read();
	
	printf("\nAutores: ");
	node->autores = string_read();
	
	printf("\nAño de publicacion: ");
	node->ano_publicacion = data_read();
	
	printf("\nISBN/ISSN: ");
	node->isbn_issn = (long) data_read();
	
	if (node->tipo_contribucion == 0){
		printf ("\nLugar de la conferencia: ");
		node->lugar_conferencia = string_read();
	} else if (node->tipo_contribucion == 1){
		printf ("\nVolumen de la revista: ");
		node->vol_revista = data_read();
		printf ("\nNumero de la revista: ");
		node->num_revista = data_read();
	}
	
	node->next = *primero;
	*primero = node;
		
	printf ("\n");
	return;
		
}


/**
 * Funcion que muestra la lista entera
 * 
 * 
 * */
void show_list(struct publicacion *primero){
	
	struct publicacion *aux = primero;
	while (aux != NULL){
		
		printf ("ID: %i\n", aux->id);
		if (strlen(aux->titulo_publicacion) < 30)
			printf ("Titulo de la publicacion: %s\n", aux->titulo_publicacion);
		else
			fwrite (aux->titulo_publicacion, sizeof(char), 30, stdout);
		printf ("\n-----------------------------------\n");
		
		aux = aux->next;
	}
	
}


/**
 * Funcion que muestra toda la informacion de una publicacion cuyo ID se pasa como argumento a la funcion
 * 
 * 
 * */
void show_publication(struct publicacion *primero, int id){
	
	struct publicacion *aux;
	aux = primero;
	
	while (aux != NULL){
		if ( aux->id == id ){
			printf ("\n-----------\n");
			printf ("Titulo de la publicacion: %s", aux->titulo_publicacion);
			printf ("Nombre de la fuente: %s", aux->nombre_fuente);
			printf ("Autores: %s", aux->autores);
			printf ("Ano de publicacion: %i\n", aux->ano_publicacion);
			printf ("ISBN/ISSN: %li\n", aux->isbn_issn);
			
			if (aux->tipo_contribucion == 0)
				printf ("Lugar de la conferencia: %s", aux->lugar_conferencia);
			else if (aux->tipo_contribucion == 1){
				printf ("Volumen de la revista: %i\n", aux->vol_revista);
				printf ("Numero de la revista: %i\n", aux->num_revista);
			}
			printf ("-----------\n");
		}		
		aux = aux->next;
	}
	
}

/**
 * Funcion que modifica una publicacion, pasando su id como argumento a la funcion
 * 
 * 
 * */
void update_publication (struct publicacion *primero, int id){
	
	struct publicacion *aux;
	aux = primero;
	char *titulo_publicacion;
	
	while (aux != NULL){
		
		if (aux->id == id){
			
			printf ("Titulo de la publicacion: ");
			titulo_publicacion = string_read();
			strcpy(aux->titulo_publicacion, titulo_publicacion);
			free (titulo_publicacion);
			
			return;
			
		} else {
			aux = aux->next;
		}
		
	}
	
	return;
	
}

/**
 * Funcion que libera toda la memoria reservada por el resto de funciones
 * 
 * 
 * */
void delete_list(struct publicacion *primero){
	
	struct publicacion *tmp;	
		
	while (primero != NULL){

		tmp = primero;
		primero = primero->next;
		free (tmp->titulo_publicacion);
		free (tmp->nombre_fuente);
		free (tmp->autores);
		if (tmp->tipo_contribucion == 0)
			free (tmp->lugar_conferencia);
		
		free (tmp);

	}
		
}
