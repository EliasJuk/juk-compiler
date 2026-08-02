#include "lexer.h"
#include <stdio.h>
#include <string.h>

static int skip_whitespace(const char *codigo, int i) {
  while (isspace((unsigned char) codigo[i])) {
    i++;
  }

  return i;
}


void lexer_analizer(const char *codigo){
  int i = 0;

  if(strncmp(&codigo[i], "print", 5) == 0 ){
    printf("TOKEN_PRINT\n");
    i += 5;
  }

  i = skip_whitespace(codigo, i);
  
  if (codigo[i] == '(') {
    printf("TOKEN_LEFT_PAREN\n");
    i++;
  }

  if (codigo[i] == '"') {
    printf("INICIO_STRING\n");
    i++;
  }

  while (codigo[i] != '"' && codigo[i] != '\0') {
    printf("%c", codigo[i]);
    i++;
  }

  if (codigo[i] == '"') {
    printf("\nFIM_STRING\n");
    i++;
  }

  if (codigo[i] == ')') {
    printf("TOKEN_RIGHT_PAREN\n");
    i++;
  }

  if (codigo[i] == ';') {
    printf("TOKEN_SEMICOLON\n");
  }
}