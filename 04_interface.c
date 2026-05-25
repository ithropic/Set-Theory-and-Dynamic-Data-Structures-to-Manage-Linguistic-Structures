#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
#include <conio.h>   
#include "03_interface.h"

// Menu animaiton functions

void animate_text(const char* text, int speed_ms) {
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        Sleep(speed_ms);
    }
}

void print_banner() {
 
    SetConsoleOutputCP(CP_UTF8);
printf(
"\n"
"▄████▄ ████▄  ████▄  ▄█████   ██      ▄▄▄  ▄▄▄▄    ██     ██  ▄▄▄  ▄▄▄▄  ▄▄ ▄▄ \n"
"██▄▄██ ██  ██ ██  ██ ▀▀▀▄▄▄   ██     ██▀██ ██▄██   ██ ▄█▄ ██ ██▀██ ██▄█▄ ██▄█▀ \n"
"██  ██ ████▀  ████▀  █████▀   ██████ ██▀██ ██▄█▀    ▀██▀██▀  ▀███▀ ██ ██ ██ ██ \n"
"\n"
"═══════════════════════════════════════════════════════════════════════════════\n"
"                        SET OPERATIONS & TEXT PROCESSING\n"
"                           By AHMED BRAHIM Rayene G06\n"
"═══════════════════════════════════════════════════════════════════════════════\n\n"
);
}



void loading_bar(const char* task_name) {
    int width = 40;
    printf(" %s\n", task_name);
    for (int i = 0; i <= width; i++) {
        printf("\r ");
        for (int j = 0; j < i; j++) printf("█"); 
        for (int j = i; j < width; j++) printf("-"); 
        printf(" %d%%", (i * 100) / width);
        
        fflush(stdout);
        Sleep(25); 
    }
    printf("\n\n");
}



int get_flickering_choice() {
    int show_pointer = 1;
    
  
    while (1) {
        
        if (show_pointer) {
            printf("\r > Choice: _ "); 
        } else {
            printf("\r > Choice:   "); 
        }
        fflush(stdout);
        
        show_pointer = !show_pointer; 

        
        for (int i = 0; i < 15; i++) {
            
            
            if (_kbhit()) {
                char c = _getch(); 
                
                
                if (c >= '1' && c <= '9') {
                    printf("\r > Choice: %c \n", c); 
                    return c - '0'; 
                }
            }
            Sleep(30); 
    }
}
}