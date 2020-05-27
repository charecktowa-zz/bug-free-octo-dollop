#include "../include/crud.h"
#include "../include/info.h"

int alta_clientes(Clientes cliente)
{
    FILE *fp;
    puts("Bienvenido al sistema de alta de clientes.");

    // Primero comprobamos si el archivo existe
    if (file_exist("archivo.txt") == true) {
        fp = fopen("archivo.txt", "a");
        fseek(fp, 0L, SEEK_END);
        /* Ahora que se comprueba que el archivo existe se escribe en el */
        fwrite(alta(cliente), sizeof(cliente), 1, fp);

        fclose(fp);
    } else {
        printf("Creando archivo nuevo...\n");
        fp = fopen("archivo.txt", "w");
        fclose(fp);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
/*
int baja_clientes(Clientes cliente)
{

    return EXIT_SUCCESS;
}
*/

int buscar_clientes(Clientes cliente)
{
    FILE *fp = fopen("archivo.txt", "rb");
    if (!fp) {
        fprintf(stderr, "Error al abrir el archivo!\n");
        return EXIT_FAILURE;
    } else {
        fseek(fp, 0L, SEEK_END);
        size_t size = ftell(fp);
        fseek(fp, 0L, SEEK_SET);

        Clientes *read = (Clientes *)malloc(sizeof(Clientes) * size);
        
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
