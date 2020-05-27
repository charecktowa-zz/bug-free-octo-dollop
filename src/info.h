#ifndef _INFO_H
#define _INFO_H

#include "crud.h"

#include <stdio.h>
#include <stdbool.h>

bool file_exist(const char *fname);
bool is_empty(FILE *file);
Clientes *alta(Clientes cliente);

#endif
