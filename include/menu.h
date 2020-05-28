#ifndef _MENU_H
#define _MENU_H 

#include <stdlib.h>
#include <stdio.h>

// Fancy Shmancy
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    #include <unistd.h>
#endif

#if defined(_WIN32) || defined(_WIN64)
    #include <Windows.h>
#endif

#include "info.h"

void buffer_clear(void);
void clear_screen(void);
void press(void);
int main_menu(void);
void menu(int option);

#endif
