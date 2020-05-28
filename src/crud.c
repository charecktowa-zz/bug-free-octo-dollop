#include "../include/crud.h"
#include "../include/info.h"
#include "../include/menu.h"

#include <stdio.h>

/* No es lo correcto poner esto aqui, pero a nadie le
   gustan las variables globales
*/
const char *file_name = "archivo.bin";
const char *file_name_aux = "archivo.bin.aux";


int alta_clientes(Clientes cliente)
{
    FILE *fp;
    puts("Bienvenido al sistema de alta de clientes.");

    // Primero comprobamos si el archivo existe
    if (file_exist(file_name)) {
        fp = fopen(file_name, "ab");
        fseek(fp, 0L, SEEK_END);
        /* Ahora que se comprueba que el archivo existe se escribe en el */
        fwrite(alta(cliente), sizeof(cliente), 1, fp);

        fclose(fp);
    } else {
        printf("Creando archivo nuevo...\n");
        fp = fopen(file_name, "wb");
        fclose(fp);
        getchar();
        alta_clientes(cliente);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int baja_clientes(Clientes cliente)
{
    /* Para poder dar de baja clientes necesito un aux */
    FILE *current_file, *aux_file;

    if (file_exist(file_name)) {
        puts("========== Sistema de Borrado ==========\n");
        
        current_file = fopen(file_name, "rb");
        aux_file = fopen(file_name_aux, "ab");

        printf("Ingrese el correo del usuario a eliminar: ");
        char correo[50];
        fgets(correo, 50, stdin);

        fseek(current_file, 0L, SEEK_SET);
         
        fread(&cliente, sizeof(cliente), 1, current_file);   
        while (!feof(current_file)) {
            if (strncmp(correo, cliente.email, 50)) 
            {
                fseek(aux_file, 0L, SEEK_END);                
                fwrite(&cliente, sizeof(cliente), 1, aux_file);
            }
            fread(&cliente, sizeof(cliente), 1, current_file);
        }

        fclose(current_file);
        fclose(aux_file);

        remove(file_name);
        rename(file_name_aux, file_name);

    } else {
        fprintf(stderr, "El archivo %s, no existe, primero créelo"
                        "y llenelo de información!\n", file_name);

        return EXIT_FAILURE;
    }

 
    return EXIT_SUCCESS;
}

int modificar_cliente(Clientes cliente) 
{
    FILE *current_file, *aux_file;

    if (file_exist(file_name)) {
        current_file = fopen(file_name, "rb");
        aux_file = fopen(file_name_aux, "ab");

        
    } else {

    }

    return EXIT_SUCCESS;
}

int listar_clientes(Clientes cliente)
{
    clear_screen();
    FILE *fp = fopen(file_name, "rb");
    if (!fp) {
        fprintf(stderr, "Error al abrir el archivo!\n");
        return EXIT_FAILURE;
    } else {

        Clientes *clientes = (Clientes *)malloc(sizeof(Clientes));

        /* Empieza a leer el archivo */
        fseek(fp, 0, SEEK_SET);

        fread(clientes, sizeof(cliente), 1, fp);
        while (!feof(fp)) {
            printf("Nombre: %s\nE-mail: %s\nEdad: %hi\n",
                                                        clientes->email,
                                                        clientes->nombre,
                                                        clientes->edad);
            puts("===========================");
            fread(clientes, sizeof(cliente), 1, fp);
        }

        free(clientes);
        fclose(fp);
    }

    getchar();

    return EXIT_SUCCESS;
}
