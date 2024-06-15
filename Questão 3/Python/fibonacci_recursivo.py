import time
import numpy as np

memo = [0] * 100

def fibonacci_recursivo(n):
    if n <= 1:
        return n

    if memo[n] != 0:
        return memo[n]

    memo[n] = fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2)

    return memo[n]

def main():
    tempo_execucao = []

    for _ in range(1, 101):
        inicio = time.perf_counter_ns()

        fibonacci_recursivo(90)

        fim = time.perf_counter_ns()

        tempo_execucao.append((fim - inicio) / 1e9)
        with open('fibonacci_recursivo.txt', 'a') as f:
            f.write(f"{tempo_execucao[-1]:.10f}\n")

    tempo_execucao.sort()

    media = np.mean(tempo_execucao[5:95])

    log = (
        f'Fibonacci_recursivo iterativo de 90: {fibonacci_recursivo(90)}\n\n'
        f'Pior tempo de execução: {max(tempo_execucao):.10f}s\n'
        f'Melhor tempo de execução: {min(tempo_execucao):.10f}s\n'
        f'Tempo médio de execução (90 execuções): {media:.10f}s\n'
    )

    print(log)

if __name__ == "__main__":
    main()
