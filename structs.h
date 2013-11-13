#include <stdio.h>
#include <stdlib.h>

#ifndef STRUCTS_H
#define _STRUCTS_H_

struct publicacion {
	int tipo_contribucion;
	int id;
	char *titulo_publicacion;
	char *nombre_fuente;
	char *autores;
	int ano_publicacion;
	long isbn_issn;
	char *lugar_conferencia;
	int vol_revista;
	int num_revista;
	struct publicacion *next;
};

#endif /* _STRUCTS_H_ */
