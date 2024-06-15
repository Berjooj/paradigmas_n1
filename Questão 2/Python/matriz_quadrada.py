import numpy as np
import time

def multiplicar_matrizes(A, B):
    return A @ B

def main():
    tamanhos = [500, 1000, 1500, 2000, 2500, 3000]
    resultados = []

    with open('matriz_quadrada_python.txt', 'w') as f:
        for n in tamanhos:
            for j in range(1, 11):
                # Preenche as matrizes A e B com valores aleatórios
                A = np.random.rand(n, n)
                B = np.random.rand(n, n)

                start_time = time.perf_counter()
                C = multiplicar_matrizes(A, B)
                end_time = time.perf_counter()

                tempo = end_time - start_time
                mensagem = f"Tempo para matriz de tamanho {n} (teste {j}): {tempo:.4f}s"
                print(mensagem)
                f.write(mensagem + '\n')

if __name__ == "__main__":
    main()
