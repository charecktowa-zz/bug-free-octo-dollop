#include "../include/menu.h"

void buffer_clear(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void clear_screen(void) 
{
    system("@cls||clear");
}

void press(void) 
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; ++j) {
            printf ("\rCargango%.*s   \b\b\b", j, "....");
            fflush (stdout);

            #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
                sleep(1);
            #endif

            #if defined(_WIN32) || defined(_WIN64)
                Sleep(100);
            #endif

        }
    }
}

/* Imprime el menu */
int main_menu(void)
{
    int choice_entry = -1;
    while (choice_entry != 0) {
        clear_screen();
        puts("=====Netflix=====");

        puts("1. Alta de Clientes.");
        puts("2. Baja de Clientes.");
        puts("3. Modificar clientes");
        puts("4. Listar todos los clientes");
        puts("0. Salir.");

        printf("Opción: ");
        scanf("\n%d", &choice_entry);
        buffer_clear();

        menu(choice_entry);
    }
    return EXIT_SUCCESS;
}

void menu(int option) 
{
    switch (option) {
        case 1: alta_clientes(nuevo_cliente); break;
        case 2: baja_clientes(nuevo_cliente); break;
        case 3: modificar_cliente(nuevo_cliente); break;
        case 4: listar_clientes(nuevo_cliente); break;
        case 0: puts("Hasta luego!"); exit(EXIT_SUCCESS); break;

        default:
            fprintf(stderr, "Error al leer la opción.\n");
            getchar();
    }
}
