#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** multiplicarMatrizes(int** matriz1, int** matriz2, int n);
int** inicializarMatriz(int n, int valorRandomico);
void limparMatriz(int** matriz, int n);

int main() {
	int tamanhoMatriz[6] = {500, 1000, 1500, 2000, 2500, 3000};

	FILE* logFile = fopen("matriz_quadrada_c.txt", "w");

	if (logFile == NULL) {
		printf("Erro ao abrir o arquivo de log!\n");
		return 1;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 1; j < 11; j++) {
			int n = tamanhoMatriz[i];
			int** matriz = inicializarMatriz(n, 1);

			clock_t inicio = clock();

			int** matrizResultado = multiplicarMatrizes(matriz, matriz, n);

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

int** multiplicarMatrizes(int** matriz1, int** matriz2, int n) {
	int** matrizResultado = inicializarMatriz(n, 0);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			matrizResultado[i][j] = 0;
			for (int k = 0; k < n; k++)
				matrizResultado[i][j] += matriz1[i][k] * matriz2[k][j];
		}

	return matrizResultado;
}

int** inicializarMatriz(int n, int valorRandomico = 1) {
	int** matriz = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++)
		matriz[i] = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (valorRandomico)
				matriz[i][j] = j + 1;
			else
				matriz[i][j] = 0;
		}
	}

	return matriz;
}

void limparMatriz(int** matriz, int n) {
	for (int i = 0; i < n; i++)
		free(matriz[i]);
	free(matriz);
}
