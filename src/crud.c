#include "../include/crud.h"
#include "../include/info.h"
#include "../include/menu.h"

#include <stdio.h>

int alta_clientes(Clientes cliente)
{
    FILE *fp;
    puts("Bienvenido al sistema de alta de clientes.");

    // Primero comprobamos si el archivo existe
    if (file_exist("archivo.txt")) {
        fp = fopen("archivo.txt", "a");
        fseek(fp, 0L, SEEK_END);
        /* Ahora que se comprueba que el archivo existe se escribe en el */
        fwrite(alta(cliente), sizeof(cliente), 1, fp);

        fclose(fp);
    } else {
        printf("Creando archivo nuevo...\n");
        fp = fopen("archivo.txt", "w");
        fclose(fp);
        getchar();
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
    clear_screen();
    FILE *fp = fopen("archivo.txt", "r");
    if (!fp) {
        fprintf(stderr, "Error al abrir el archivo!\n");
        return EXIT_FAILURE;
    } else {
        /* No estoy muy seguro que tan necesario sea esto */
        fseek(fp, 0L, SEEK_END);
        size_t size = ftell(fp);
        fseek(fp, 0L, SEEK_SET);

        Clientes *clientes = (Clientes *)malloc(sizeof(Clientes) * size);

        /* Empieza a leer el archivo */
        fseek(fp, 0, SEEK_SET);
        fread(clientes, sizeof(cliente), 1, fp);

        while (!feof(fp)) {
            puts("===========================");
            printf("E-mail: %s\nNombre: %s\nEdad: %hi\n\n",
                                                        clientes->email,
                                                        clientes->nombre,
                                                        clientes->edad);
            puts("===========================");
            fread(clientes, sizeof(cliente), 1, fp);
        }

        free(clientes);
    }

    getchar();

    fclose(fp);

    return EXIT_SUCCESS;
}
