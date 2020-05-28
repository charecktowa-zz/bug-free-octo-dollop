#ifndef _CRUD_H
#define _CRUD_H 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[50];
    
    char fecha[11];
    char clasificacion[3];
    int calificacion;
}Peliculas;

typedef struct {
    char email[50];
    char nombre[100];
    short edad;

    Peliculas peli_info;

}Clientes;

Clientes nuevo_cliente;

int alta_clientes(Clientes cliente);
int baja_clientes(Clientes cliente);
int modificar_cliente(Clientes cliente);
int listar_clientes(Clientes cliente);

#endif
