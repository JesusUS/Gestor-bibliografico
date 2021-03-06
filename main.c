#include "menu.h"
#include "list.h"

struct publicacion *primero;

int main(){
	
	int seguir = 1;
	int opcion = 0, id = 0;
	
	while (seguir){
		
		print_menu();
		printf("\nOpcion: ");			
		opcion = data_read();	
		
		switch (opcion){	
					
			case 1:
				
				if (primero == NULL)
					primero = create_list();
				else if (primero != NULL)
					add_node (&primero);				
				break;
			case 2:
				show_list(primero);
				break;
			case 3:
				printf ("ID: ");
				id = data_read();
				show_publication(primero, id);
				break;
			case 4:
				printf ("ID: ");		
				id = data_read();
				update_publication (primero, id);
				break;
			case 5:
				printf ("ID: ");
				id = data_read();				
				delete_publication (primero, id);
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				seguir = 0;
				delete_list(primero);
				break;				
		}
				
	}
	
	return 0;
	
}
