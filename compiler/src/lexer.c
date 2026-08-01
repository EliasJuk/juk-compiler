#include "lexer.h"
#include <stdio.h>
#include <string.h>

void lexer_analizer(const char *codigo){
  if(strncmp(codigo, "print", 5) == 0 ){
    printf("TOKEN_PRINT\n");
  }
}