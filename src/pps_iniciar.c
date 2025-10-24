#include "pps_iniciar.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libwordle.h"
#include "wordle_dicc.h"
#include "test_dicc.h"


FILE *fich_log;
unsigned int clave_cesar;
unsigned int n_palabras;
char **diccionario;


int iniciar(char *fdic, char *flog, char modo) {
    FILE *fich_dicc = fopen(fdic, "r");
    int resultado_carga;

    fich_log = fopen(flog, "w");
    if(fich_log == NULL) {
        fclose(fich_dicc);
        return NOLOG; 
    }
    resultado_carga = cargar_diccionario(fich_dicc);  
     if(fich_dicc == NULL) {
        return NODIC; 
    }
    
    fclose(fich_dicc);

    if (resultado_carga < 0) {
        vaciar_diccionario();
        fclose(fich_log);
        return resultado_carga; 
    }

    if (modo == 'j') {
        int resultado_juego = jugar_wordle();
        vaciar_diccionario();
        fclose(fich_log); 
        return resultado_juego;
    } else if (modo == 't') {
        testear_dicc(fdic, flog);
        vaciar_diccionario();
        fclose(fich_log);
        
        return 0;
    } else {
        vaciar_diccionario();
        fclose(fich_log);
        
        return NOMOD; 
    }
}
