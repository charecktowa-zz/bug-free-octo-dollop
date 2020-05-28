#include "../include/info.h"
#include "../include/crud.h"
#include "../include/menu.h"

bool file_exist(const char *fname) 
{
    bool state;
    FILE *filep = fopen(fname, "r");
    if (filep) {
        state = true;
        fclose(filep);
    }
    else 
        state = false;

    return state;
}

/* Función para llenar la estructura para después pasarla
   al archivo binario */
Clientes *alta(Clientes cliente) 
{
    Clientes *tmp = &cliente;
    printf("Ingrese el e-mail del cliente: ");
    fgets(tmp->email, 50, stdin);

    printf("Ingrese el nombre completo del cliente: ");
    fgets(tmp->nombre, 100, stdin);

    printf("Ingrese la edad del cliente: ");
    scanf("%hi", &tmp->edad);
    buffer_clear();

    puts("");

    printf("Ingrese el nombre de la pelicula: ");
    fgets(tmp->peli_info.nombre, 50, stdin);

    printf("Ingrese la fecha en que se vio la pelicula dd/mM/YyyY: ");
    fgets(tmp->peli_info.fecha, 10, stdin);

    printf("Ingrese la clasificacion de la pelicula: ");
    fgets(tmp->peli_info.clasificacion, 3, stdin);

    start:
    buffer_clear();
    printf("Ingrese la calificacion [5 MAX]: ");
    scanf("%i", &tmp->peli_info.calificacion);

    if (tmp->peli_info.calificacion < 1 || tmp->peli_info.calificacion > 5)
        goto start;
    
    printf("Guardado exitosamente!\n");
    press();
    return tmp;
}
