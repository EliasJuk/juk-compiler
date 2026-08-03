#include "lexer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int skip_whitespace(const char *codigo, int i) {
  while (isspace((unsigned char) codigo[i])) {
    i++;
  }

  return i;
}

void lexer_analizer(const char *codigo){
  int i = 0;

  i = skip_whitespace(codigo, i);

  if(strncmp(&codigo[i], "print", 5) == 0 ){
    printf("TOKEN_PRINT\n");
    i += 5;
  }

  i = skip_whitespace(codigo, i);
  
  if (codigo[i] == '(') {
    printf("TOKEN_LEFT_PAREN\n");
    i++;
  }

  i = skip_whitespace(codigo, i);

  if (codigo[i] == '"') {
    printf("INICIO_STRING\n");
    i++;
  }

  int inicio_string = i;
  

  while (codigo[i] != '"' && codigo[i] != '\0') {
    printf("%c", codigo[i]);
    i++;
  }

  int tamanho_string = i - inicio_string;
  printf("\nTAMANHO_STRING: %d\n", tamanho_string);

  if (codigo[i] == '\0') {
    printf("\nERRO_LEXICO: string nao finalizada.\n");
    return;
  }

  if (codigo[i] == '"') {
    printf("\nFIM_STRING\n");
    i++;
  }

  i = skip_whitespace(codigo, i);

  if (codigo[i] == ')') {
    printf("TOKEN_RIGHT_PAREN\n");
    i++;
  }

  i = skip_whitespace(codigo, i);

  if (codigo[i] == ';') {
    printf("TOKEN_SEMICOLON\n");
  }

  // Reservar memória para armazenar a string
  char *texto = malloc(tamanho_string + 1);

  if (texto == NULL) {
    printf("Erro ao reservar memoria para a string.\n");
    return;
  }

  for (int j = 0; j < tamanho_string; j++) {
    texto[j] = codigo[inicio_string + j];
  }

  texto[tamanho_string] = '\0';

  printf("STRING: %s\n", texto);

  // Libera a memoria
  free(texto);
}