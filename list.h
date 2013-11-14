#include <stdlib.h>
#include <stdio.h>
#include "structs.h"

#ifndef LIST_H
#define _LIST_H_

struct publicacion *create_list();
void add_node(struct publicacion **primero);
void show_list(struct publicacion *primero);
void show_publication(struct publicacion *, int);
void update_publication (struct publicacion *, int);
void delete_list(struct publicacion *primero);


#endif /* _LIST_H_ */
