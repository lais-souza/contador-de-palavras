/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

int main() {

  char c;
  int space = 0;
  int number = 0;
  int point = 0;
  int aux = 0;
  int contagem_de_palavras = 0;
   
  while (c != '\n'){
    scanf ("%c",&c);
   
	//condição para quando acabar a frase
	if (c == '\n' && space == 0){
		if(point == 1){
			contagem_de_palavras--;
		}
		else{
			contagem_de_palavras++;
		}
	}
	//condição para quando tiver um ou mais espaços na frase
	if (c == ' ' && space == 0){
		contagem_de_palavras++;
		space = 1;
	}
	else if (c == ' ' && space == 1){
		space = 1;
	}
	else if (c != ' ' && space == 1){
		space = 0;
	}
	//condição para quando tiver pontuação na frase
	if ((c == '.' || c == ',' || c == '-' || c == ':') && point == 0){
		point = 1;
	}
	else if (c != '.' && c != ',' && c != '-' && c != ':' && c != '!' && c != '?'&& point == 1){
		contagem_de_palavras++;
		if(c == ' '){
			contagem_de_palavras--;
		}
		point = 0;
	}
	//condição para quando tiver número em ponto flutuante
	if ((c == '.' || c == ',') && number == 0){
		number = 1;
	}
	if ((c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') && number == 1){
		contagem_de_palavras++;
		number = 0;
		aux = 1;
	}
	if ((c == ' ' || c == ',' || c == '.') && aux == 1){
		contagem_de_palavras--;
		aux = 0;
	}
	
}
  
		printf("%d\n",contagem_de_palavras);

  return 0;
}
