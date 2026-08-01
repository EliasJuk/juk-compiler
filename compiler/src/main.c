#include <stdio.h>
#include <stdlib.h>

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

  // Tamanho do arquivo
  fseek(arquivo, 0, SEEK_END);
  long tamanho = ftell(arquivo);  
  rewind(arquivo);
  printf("Tamanho: %ld bytes\n", tamanho);

  // Alocar memoria para o codigo
  char *codigo = malloc(tamanho + 1);

  if (codigo == NULL) {
    printf("Nao foi possivel reservar memoria.\n");
    fclose(arquivo);
    return 1;
  }  

  // Liberar memoria
  fclose(arquivo);
  free(codigo);

  return 0;
}