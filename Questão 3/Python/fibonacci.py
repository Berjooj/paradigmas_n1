import time
import numpy as np

memo = [0] * 100

def fibonacci(n):
    if n <= 1:
        return n

    prev, atual = 0, 1

    if memo[n] != 0:
        return memo[n]

    for i in range(2, n + 1):
        if memo[i] != 0:
            prev = atual
            atual = memo[i]
            continue

        prox = prev + atual
        prev = atual
        atual = prox

        memo[i] = atual

    memo[n] = atual

    return atual

def main():
    tempo_execucao = []

    for _ in range(1, 101):
        inicio = time.perf_counter_ns()

        fibonacci(90)

        fim = time.perf_counter_ns()

        tempo_execucao.append((fim - inicio) / 1e9)
        with open('fibonacci.txt', 'a') as f:
            f.write(f"{tempo_execucao[-1]:.10f}\n")

    tempo_execucao.sort()

    media = np.mean(tempo_execucao[5:95])

    log = (
        f'Fibonacci iterativo de 90: {fibonacci(90)}\n\n'
        f'Pior tempo de execução: {max(tempo_execucao):.10f}s\n'
        f'Melhor tempo de execução: {min(tempo_execucao):.10f}s\n'
        f'Tempo médio de execução (90 execuções): {media:.10f}s\n'
    )

    print(log)

if __name__ == "__main__":
    main()
