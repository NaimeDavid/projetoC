#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<math.h>

int main() {
	setlocale(LC_ALL, "");
	int e_menu;

	printf("\t[1] - Digitar os valores do primeiro ponto\n\t[2] - Digitar os valores do segundo ponto\n\t[3] - Mostrar a dist�ncia entre os pontos\n\t[4] - Sair\n");
	scanf_s("%i", &e_menu);
	while (e_menu < 1 || e_menu > 4) {
		printf("VALOR INV�LIDO - Tente novamente\n");
		printf("\t[1] - Digitar os valores do primeiro ponto\n\t[2] - Digitar os valores do segundo ponto\n\t[3] - Mostrar a dist�ncia entre os pontos\n\t[4] - Sair\n");
		scanf_s("%i", &e_menu);
	}
	if (e_menu == 3) {
		printf("Primeiro voc� precisa informar os pontos: ");
		printf("\t\n[1] - Digitar os valores do primeiro ponto\n\[2] - Digitar os valores do segundo ponto\n\t");
		scanf_s("%i", &e_menu);

	}

	
	return 0;
}