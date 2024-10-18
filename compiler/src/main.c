#include <stdio.h>

int main(int argc, char *argv[]){
  if(argc < 2){
    printf("Informe um arquivo .juk\n");
    return 1;
  }

  FILE *arquivo = fopen(argv[1], "r");

  if(arquivo == NULL) {
    printf("Não foi possivel abrir o arquivo");
    return 1;
  }

  printf("Arquivo aberto com sucesso!\n");
  
  // Lê e exibe o arquivo caractere por caractere
  int caractere;
  while ((caractere = fgetc(arquivo)) != EOF) {
    printf("%c", caractere);
  }

  fclose(arquivo);

  return 0;
}