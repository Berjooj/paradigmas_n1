const fs = require('fs');

const memo = new Array(100).fill(0);

function fibonacci_recursivo(n)
{
    if (n <= 1)
        return n;

    if (memo[n] !== 0) return memo[n];

    memo[n] = fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);

    return memo[n];

}

async function main()
{
    const tempoExecucao = [];

    for (let i = 1; i <= 100; i++)
    {
        const inicio = process.hrtime.bigint();

        fibonacci_recursivo(90);

        const fim = process.hrtime.bigint();

        tempoExecucao.push(Number(fim - inicio) / 1e9);
        fs.appendFileSync('fibonacci_recursivo.txt', tempoExecucao[tempoExecucao.length - 1].toFixed(10) + "\n");
    }

    tempoExecucao.sort((a, b) => a - b);

    let media = 0;
    for (let i = 5; i < 95; i++)
        media += tempoExecucao[i];
    media /= 90;


    const log = 'Fibonacci_recursivo iterativo de 90 (' + fibonacci_recursivo(90) + ')\n\n' +
        'Pior tempo de execução: ' + Math.max(...tempoExecucao).toFixed(10) + 's\n' +
        'Melhor tempo de execução: ' + Math.min(...tempoExecucao).toFixed(10) + 's\n' +
        'Tempo médio de execução (90 execuções): ' + media.toFixed(10) + 's\n';

    console.log(log);
}

main();
