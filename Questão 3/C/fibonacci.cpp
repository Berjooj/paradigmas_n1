#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int fibonacci(int n) {
	if (n <= 1)
		return n;

	long long int prev = 0, atual = 1, prox;

	for (int i = 2; i <= n; i++) {
		prox = prev + atual;
		prev = atual;
		atual = prox;
	}

	return atual;
}

int compare(const void* a, const void* b) {
	return (*(long double*)a - *(long double*)b);
}

int main() {
	float tempoExecucao[100] = {0};

	FILE* logFile = fopen("fibonacci.txt", "w");

	if (logFile == NULL) {
		printf("Erro ao abrir o arquivo de log!\n");
		return 1;
	}

	for (int i = 0; i < 100; i++) {
		clock_t inicio = clock();

		fibonacci(90);

		clock_t fim = clock();

		fprintf(logFile, "%.30llf\n", (long double)(fim - inicio) / CLOCKS_PER_SEC);
	}

	// remove as 5 piores e as 5 melhores medições e calcula a média
	long double media = 0;

	// ordena o vetor
	qsort(tempoExecucao, 100, sizeof(float), compare);

	for (int i = 5; i < 95; i++)
		media += tempoExecucao[i];

	media /= 90;

	// fprintf(logFile, "Fibonacci iterativo de 90 (%llu)\n\n", fibonacci(90));
	// fprintf(logFile, "Pior tempo de execucao: %lfs\n", tempoExecucao[99]);
	// fprintf(logFile, "Melhor tempo de execucao: %lfs\n", tempoExecucao[0]);
	// fprintf(logFile, "Tempo médio de execucao (90 execuções): %.12lfs\n", media);

	printf("Fibonacci iterativo de 90 (%llu)\n\n", fibonacci(90));
	printf("Pior tempo de execucao: %.30lfs\n", tempoExecucao[99]);
	printf("Melhor tempo de execucao: %.30lfs\n", tempoExecucao[0]);
	printf("Tempo medio de execucao (90 execucoes): %.30lfs\n", media);

	return 0;
}
