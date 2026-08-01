#include "lexer.h"
#include <stdio.h>
#include <string.h>

void lexer_analizer(const char *codigo){
  if(strncmp(codigo, "print", 5) == 0 ){
    printf("TOKEN_PRINT\n");
  }
  
  if (codigo[5] == '(') {
    printf("TOKEN_LEFT_PAREN\n");
  }

  if (codigo[6] == '"') {
    printf("INICIO_STRING\n");
  }

  int i = 7;
  while (codigo[i] != '"' && codigo[i] != '\0') {
    printf("%c", codigo[i]);
    i++;
  }

  printf("\n");
}