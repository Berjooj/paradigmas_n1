#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

short int** multiplicarMatrizes(short int** matriz1, short int** matriz2, short int n);
short int** inicializarMatriz(short int n, short int valorRandomico);
void limparMatriz(short int** matriz, short int n);

int main() {
	short int tamanhoMatriz[6] = {500, 1000, 1500, 2000, 2500, 3000};

	FILE* logFile = fopen("matriz_quadrada_c.txt", "w");

	if (logFile == NULL) {
		printf("Erro ao abrir o arquivo de log!\n");
		return 1;
	}

	for (short int i = 0; i < 6; i++) {
		for (short int j = 1; j < 11; j++) {
			short int n = tamanhoMatriz[i];
			short int** matriz = inicializarMatriz(n, 1);

			clock_t inicio = clock();

			short int** matrizResultado = multiplicarMatrizes(matriz, matriz, n);

			clock_t fim = clock();

			double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

			fprintf(logFile, "Tempo para matriz de tamanho %d (teste %d): %fs\n", n, j, tempo);
			printf("Tempo para matriz de tamanho %d (teste %d): %fs\n", n, j, tempo);

			limparMatriz(matriz, n);
			limparMatriz(matrizResultado, n);
		}
	}

	getch();

	fclose(logFile);
	return 0;
}

short int** multiplicarMatrizes(short int** matriz1, short int** matriz2, short int n) {
	short int** matrizResultado = inicializarMatriz(n, 0);

	for (short int i = 0; i < n; i++)
		for (short int j = 0; j < n; j++) {
			matrizResultado[i][j] = 0;
			for (short int k = 0; k < n; k++)
				matrizResultado[i][j] += matriz1[i][k] * matriz2[k][j];
		}

	return matrizResultado;
}

short int** inicializarMatriz(short int n, short int valorRandomico = 1) {
	short int** matriz = (short int**)malloc(n * sizeof(short int*));

	for (short int i = 0; i < n; i++)
		matriz[i] = (short int*)malloc(n * sizeof(short int));

	for (short int i = 0; i < n; i++) {
		for (short int j = 0; j < n; j++) {
			if (valorRandomico)
				matriz[i][j] = j + 1;
			else
				matriz[i][j] = 0;
		}
	}

	return matriz;
}

void limparMatriz(short int** matriz, short int n) {
	for (short int i = 0; i < n; i++)
		free(matriz[i]);
	free(matriz);
}
