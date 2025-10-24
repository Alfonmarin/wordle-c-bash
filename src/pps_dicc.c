#include "wordle_dicc.h"
#include <string.h>
#include <stdlib.h>



void cifrado_cesar(int op, char *pword){
  int i;
  int len = strlen(pword);
  fprintf(fich_log,"DGB[cifrado_cesar]: INICIO\n");

  for(i = 0; i< len; i++){
    if(op == 0){
      pword[i] = 'A' + (pword[i] - 'A' + clave_cesar) % 26;
    } else{
      pword[i] = 'A' + (pword[i] - 'A' - clave_cesar + 26) % 26;
    }
  }
  fprintf(fich_log,"DGB[cifrado_cesar]: FIN\n");
  
}


int en_diccionario(char *word) {
    int i;
    fprintf(fich_log, "DGB[en_diccionario]: INICIO\n");
    cifrado_cesar(0, word);

    for (i = 0; (unsigned int)i < n_palabras; i++){
      if(memcmp(diccionario[i], word, LONG_PALABRA_WORDLE) == 0){
      cifrado_cesar(1, word);
      fprintf(fich_log, "DGB[en_diccionario]: FIN\n");
      return 1;
      }
    }
    cifrado_cesar(1, word);
    fprintf(fich_log, "DGB[en_diccionario]: FIN\n");
    
    return 0;

}

void elegir_palabra(char *ppal, int pos){

  fprintf(fich_log,"DGB[elegir_palabra]: INICIO\n");

  if(pos >=0 && (unsigned int)pos < n_palabras){
    memcpy(ppal, diccionario[pos], LONG_PALABRA_WORDLE);
  }else{
    fprintf(fich_log, "ERR[elegir_palabra]: POS FUERA DE RANGO\n");
  }
  fprintf(fich_log,"DGB[elegir_palabra]: FIN\n");
}

int cargar_diccionario(FILE *fich_dicc) {
    int i;

    wordle_cabecera_dicc_t cabecera;
    
    fprintf(fich_log, "DGB[cargar_diccionario]: INICIO\n");
    

    fread(&cabecera, sizeof(wordle_cabecera_dicc_t), 1, fich_dicc);
    clave_cesar = cabecera.clave;
    n_palabras = cabecera.n_palabras;
    if (fich_dicc == NULL){
      fprintf(fich_log, "Falla la lectura del archivo del diccionario\n");
      return NOLEE;
    }
    if (clave_cesar < 1 || clave_cesar > 25) {
    fprintf(fich_log, "ERR[cargar_diccionario]: CLAVE DE CIFRADO FUERA DE RANGO\n");
      return NOCLA;
    }

    diccionario = (char **)calloc(cabecera.n_palabras, sizeof(char *));
    if (diccionario == NULL) {
        return NOMEM; 
    }

    for (i = 0; i < (int)cabecera.n_palabras; i++) {
        char *word = (char *)calloc(LONG_PALABRA_WORDLE + 1,sizeof(char));
        fread(word, sizeof(char), LONG_PALABRA_WORDLE + 1, fich_dicc);
        diccionario[i] = word;
   
    }

    return (int)cabecera.n_palabras; 
}

void vaciar_diccionario(void) {
    unsigned int i;
    fprintf(fich_log, "DGB[vaciar_diccionario]: INICIO\n");
    if(diccionario != NULL) {
        for(i = 0; i < n_palabras; i++) {
            free(diccionario[i]);
        }
        free(diccionario);
        diccionario = NULL;
    }
    fprintf(fich_log, "DGB[vaciar_diccionario]: FIN\n");
}
