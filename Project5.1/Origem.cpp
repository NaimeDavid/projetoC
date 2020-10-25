#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<math.h>

int main() {
	setlocale(LC_ALL, "");

	/*Variáveis: 
	"e_menu" = para escolher a opçao do menu.
	"distancia" = para fazer o calculo. 
	"continuar" = para recomeçar tudo de novo.*/
	int e_menu, distancia, continuar;

	struct ponto2d {
		int x, y;
	}; struct ponto2d ponto_inicial, ponto_final;

	
	//Inicializei as variáveis para usar como condição de fechamento do ciclo do-while.
	ponto_inicial.x = 0, ponto_final.x = 0;
	ponto_inicial.y = 0, ponto_final.y = 0;
	
	do {
		printf("\n");
		printf("\t[1] - Digitar os valores do primeiro ponto\n\t[2] - Digitar os valores do segundo ponto\n\t[3] - Mostrar a distância entre os pontos\n\t[4] - Sair\n");
		printf("Insira: ");
		scanf_s("%i", &e_menu);

		//Condicional para descartar inserrções diferentes das opções no menu.
		while (e_menu < 1 || e_menu > 4) {
			printf("VALOR INVÁLIDO - Tente novamente\n");
			printf("\t[1] - Digitar os valores do primeiro ponto\n\t[2] - Digitar os valores do segundo ponto\n\t[3] - Mostrar a distância entre os pontos\n\t[4] - Sair\n");
			scanf_s("%i", &e_menu);
		}


		//Utilizei um do-while, para o código rodar até capturar todos os dados.
		do {
			switch (e_menu) {
			case 1: {
				printf("\nInsira o ponto A1: ");
				scanf_s("%i", &ponto_inicial.x);

				/*As condições "while" aqui, e no case 2, são para excluir inserção de números inválidos*/
				while (ponto_inicial.x < 1) {
					printf("\n*VALOR INVÁLIDO*\nInsira o ponto A1: ");
					scanf_s("%i", &ponto_inicial.x);
				}

				printf("Insira o ponto A2: ");
				scanf_s("%i", &ponto_inicial.y);

				while (ponto_inicial.y < 1) {
					printf("\n*VALOR INVÁLIDO*\nInsira o ponto A2: ");
					scanf_s("%i", &ponto_inicial.y);
				}
				printf("\n- Digite os valores do segundo ponto:\n");

			}
			case 2: {
				printf("Insira o ponto B1: ");
				scanf_s("%i", &ponto_final.x);
				while (ponto_final.x < 1) {
					printf("\n*VALOR INVÁLIDO*\nInsira o ponto B1: ");
					scanf_s("%i", &ponto_final.x);
				}

				printf("Insira o ponto B2: ");
				scanf_s("%i", &ponto_final.y);
				while (ponto_final.y < 1) {
					printf("\n*VALOR INVÁLIDO*\nInsira o ponto B2: ");
					scanf_s("%i", &ponto_final.y);
				}

				/*A condicional abaixo é para retornar ao case 1, caso a pessoa escolher, no menu, começar
				a inserir os dados pelo item [2]*/
				if (ponto_inicial.x < 1 || ponto_inicial.y < 1) {
					printf("\n- Digite os valores do primeiro ponto:\n");

					printf("\nInsira o ponto A1: ");
					scanf_s("%i", &ponto_inicial.x);
					while (ponto_inicial.x < 1) {
						printf("\n*VALOR INVÁLIDO*\nInsira o ponto A1: ");
						scanf_s("%i", &ponto_inicial.x);
					}

					printf("Insira o ponto A2: ");
					scanf_s("%i", &ponto_inicial.y);
					while (ponto_inicial.y < 1) {
						printf("\n*VALOR INVÁLIDO*\nInsira o ponto A2: ");
						scanf_s("%i", &ponto_inicial.y);
					}
				}
				//Adicionei o break a partir do case 2, pro código não pular a inserção dos valores.
			}break;
				/*Caso escolher o item 3 primeiro, o programa volta e pede pra inserir os dados [1] e [2], pra depois fazer o calculo*/
			case 3: {
				if (ponto_inicial.x <= 0 || ponto_inicial.y <= 0 || ponto_final.x <= 0 || ponto_final.y <= 0) {
					do {
						printf("\nPrimeiro você precisa informar os pontos: ");
						printf("\t\n[1] - Digitar os valores do primeiro ponto\n\[2] - Digitar os valores do segundo ponto\nInsira: ");
						scanf_s("%i", &e_menu);
					} while (e_menu < 1 || e_menu > 2);
				}
				break;

				//Se escolher o item 4 primeiro, o programa encerra.
			}default: {

				printf("\n\n**Programa Finalizado**\n\n");
				return 0;
			}
			}

		} while (ponto_inicial.x <= 0 || ponto_inicial.y <= 0 || ponto_final.x <= 0 || ponto_final.y <= 0);



		distancia = (sqrt(pow((ponto_inicial.x - ponto_final.x), 2) + pow((ponto_inicial.y - ponto_final.y), 2)));
		printf("\n");
		printf("______________________________________\n");
		printf("A distância entre os dois pontos é: %i\n\n", distancia);
		ponto_inicial.x=0, ponto_inicial.y=0, ponto_final.x=0, ponto_final.y = 0;


		printf("Desejar fazer um novo calculo?\n[1]: Sim\n[2]: Encerrar\nInsira: ");
		scanf_s("%i", &continuar);
		while (continuar < 1 || continuar>2) {
			printf("*Insira novamente* \nDesejar fazer um novo calculo?\n[1]: Sim\n[2]: Encerrar\nInsira: ");
			scanf_s("%i", &continuar);
			
		}
	}while (continuar == 1);
	

	return 0;
	system("pause");

}