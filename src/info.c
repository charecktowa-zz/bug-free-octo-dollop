#include "info.h"
#include "crud.h"
#include "menu.h"

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
    fgets(cliente.email, 50, stdin);

    printf("Ingrese el nombre completo del cliente: ");
    fgets(cliente.nombre, 100, stdin);

    printf("Ingrese la edad del cliente: ");
    scanf("%hi", &cliente.edad);

    return tmp;
}
