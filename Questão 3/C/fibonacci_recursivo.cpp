#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int memo[100] = {0};

long long int fibonacci_recursivo(int n) {
	if (n <= 1)
		return n;

	if (memo[n] != 0) return memo[n];

	memo[n] = fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);

	return memo[n];
}

int compare(const void* a, const void* b) {
	return (*(float*)a - *(float*)b);
}

int main() {
	float tempoExecucao[100] = {0};

	FILE* logFile = fopen("fibonacci_recursivo.txt", "w");

	if (logFile == NULL) {
		printf("Erro ao abrir o arquivo de log!\n");
		return 1;
	}

	for (int i = 1; i <= 100; i++) {
		clock_t inicio = clock();

		fibonacci_recursivo(50);

		clock_t fim = clock();

		fprintf(logFile, "%.30llf\n", (long double)(fim - inicio) / CLOCKS_PER_SEC);
	}

	// remove as 5 piores e as 5 melhores medições e calcula a média
	float media = 0;

	// ordena o vetor
	qsort(tempoExecucao, 100, sizeof(float), compare);

	for (int i = 5; i < 95; i++)
		media += tempoExecucao[i];

	media /= 90;

	printf("Fibonacci recursivo de 90 (%llu)\n\n", fibonacci_recursivo(90));
	printf("Pior tempo de execucao: %.30lfs\n", tempoExecucao[99]);
	printf("Melhor tempo de execucao: %.30lfs\n", tempoExecucao[0]);
	printf("Tempo medio de execucao (90 execucoes): %.30lfs\n", media);

	return 0;
}
