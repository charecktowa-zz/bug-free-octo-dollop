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
        press();
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
        bool exist_client = true;
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
                exist_client = true;
            } else exist_client = false;
            fread(&cliente, sizeof(cliente), 1, current_file);
        }

        if (exist_client)
            fprintf(stderr, "El cliente: %s no existe, no se ha borrado nada.\n\n", correo);

        fclose(current_file);
        fclose(aux_file);

        remove(file_name);
        rename(file_name_aux, file_name);


    } else {
        fprintf(stderr, "El archivo %s, no existe, primero créelo"
                        "y llenelo de información!\n\n\n", file_name);

        return EXIT_FAILURE;
    }
 
    press();
    return EXIT_SUCCESS;
}

int modificar_cliente(Clientes cliente) 
{
    FILE *current_file, *aux_file;
    char correo[100];

    if (file_exist(file_name)) {
        bool client_exist = false;
        current_file = fopen(file_name, "rb");
        aux_file = fopen(file_name_aux, "ab");

        printf("Ingrese el correo del usuario a modificar: ");
        fgets(correo, 100, stdin);
        
        fseek(current_file, 0L, SEEK_SET);
        fread(&cliente, sizeof(cliente), 1, current_file);

        while (!feof(current_file)) {
            if (strncmp(correo, cliente.email, 100) == 0) 
            {
                client_exist = true;
                puts("Modificando usuario: \n");
                printf("Nombre: %s\nCorreo: %s\nEdad: %hi\n\n",
                                                             cliente.nombre, 
                                                             cliente.email, 
                                                             cliente.edad);

                fwrite(alta(cliente), sizeof(cliente), 1, aux_file);
            } else {
                fseek(aux_file, 0L, SEEK_END);                
                fwrite(&cliente, sizeof(cliente), 1, aux_file);
            }
            fread(&cliente, sizeof(cliente), 1L, current_file);
        } 

        if (!client_exist)
            fprintf(stderr, "El cliente %s no existe, no se hizo nada!\n", correo);

    } else {
        fprintf(stderr, "El archivo %s, no existe, créelo primero.\n", file_name);
        return EXIT_FAILURE;
    }

    fclose(current_file);
    fclose(aux_file);

    remove(file_name);
    rename(file_name_aux, file_name);

    press();

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

        fseek(fp, 0L, SEEK_END);
        int sz = ftell(fp);

        Clientes *clientes = (Clientes *)malloc(sizeof(cliente) * (sz));
        Clientes temp;

        /* Empieza a leer el archivo */
        fseek(fp, 0, SEEK_SET);

        /* Primero almacenamos todo en memoria */
        int members = 0;
        fread(&cliente, sizeof(cliente), 1, fp);
        while (!feof(fp)) {
            clientes[members] = cliente;
            fread(&cliente, sizeof(cliente), 1, fp);
            members++;
        }
        
        for (int i = 1; i < members; i++) {
            for (int j = 0; j < members - i; j++) {
                if (strcmp(clientes[j].nombre, clientes[j+1].nombre) > 0) {
                    temp = clientes[j];
                    clientes[j] = clientes[j + 1];
                    clientes[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < members; i++){
            printf("=============================================\n");
            printf("Nombre: %s\nCorreo: %s\nEdad: %hi\n"
                    "Pelicula: %s\nFecha: %s\nClasificacion: %s\nCalificacion: %d\n", 
                                                        clientes[i].nombre,
                                                        clientes[i].email,
                                                        clientes[i].edad, 
                                                        clientes[i].peli_info.nombre,
                                                        clientes[i].peli_info.fecha,
                                                        clientes[i].peli_info.clasificacion, 
                                                        clientes[i].peli_info.calificacion);
        }
        free(clientes);
        fclose(fp);
    }

    printf("\n\nPresione 'enter' para continuar...\n");
    getchar();
    
    return EXIT_SUCCESS;
}
