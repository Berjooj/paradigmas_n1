#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double** multiplicarMatrizes(double** matriz1, double** matriz2, double n);
double** inicializarMatriz(double n, double valorRandomico);
void limparMatriz(double** matriz, double n);

int main() {
	double tamanhoMatriz[6] = {500, 1000, 1500, 2000, 2500, 3000};

	FILE* logFile = fopen("matriz_quadrada_c_double.txt", "w");

	if (logFile == NULL) {
		printf("Erro ao abrir o arquivo de log!\n");
		return 1;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 1; j <= 3; j++) {
			double n = tamanhoMatriz[i];
			double** matriz = inicializarMatriz(n, 1);

			clock_t inicio = clock();

			double** matrizResultado = multiplicarMatrizes(matriz, matriz, n);

			clock_t fim = clock();

			double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

			fprintf(logFile, "Tempo para matriz de tamanho %.lf (teste %d): %fs\n", n, j, tempo);
			printf("Tempo para matriz de tamanho %.lf (teste %d): %lfs\n", n, j, tempo);

			limparMatriz(matriz, n);
			limparMatriz(matrizResultado, n);
		}
	}

	getch();

	fclose(logFile);
	return 0;
}

double** multiplicarMatrizes(double** matriz1, double** matriz2, double n) {
	double** matrizResultado = inicializarMatriz(n, 0);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			matrizResultado[i][j] = 0;
			for (int k = 0; k < n; k++)
				matrizResultado[i][j] += matriz1[i][k] * matriz2[k][j];
		}

	return matrizResultado;
}

double** inicializarMatriz(double n, double valorRandomico = 1) {
	double** matriz = (double**)malloc(n * sizeof(double*));

	for (int i = 0; i < n; i++)
		matriz[i] = (double*)malloc(n * sizeof(double));

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

void limparMatriz(double** matriz, double n) {
	for (int i = 0; i < n; i++)
		free(matriz[i]);
	free(matriz);
}
