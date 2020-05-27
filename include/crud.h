#ifndef _CRUD_H
#define _CRUD_H 

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char email[50];
    char nombre[100];
    short edad;
}Clientes;

Clientes nuevo_cliente;

int alta_clientes(Clientes cliente);
int baja_clientes(Clientes cliente);
int buscar_clientes(Clientes cliente);

#endif
