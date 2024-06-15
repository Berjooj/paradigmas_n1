const fs = require('fs');

const memo = new Array(100).fill(0);

function fibonacci(n)
{
    if (n <= 1)
        return n;

    let prev = 0, atual = 1, prox;

    if (memo[n] !== 0) return memo[n];

    for (let i = 2; i <= n; i++)
    {
        if (memo[i] !== 0)
        {
            prev = atual;
            atual = memo[i];
            continue;
        }

        prox = prev + atual;
        prev = atual;
        atual = prox;

        memo[i] = atual;
    }

    memo[n] = atual;

    return atual;
}


async function main()
{
    const tempoExecucao = [];

    for (let i = 1; i <= 100; i++)
    {
        const inicio = process.hrtime.bigint();

        fibonacci(90);

        const fim = process.hrtime.bigint();

        tempoExecucao.push(Number(fim - inicio) / 1e9);
        fs.appendFileSync('fibonacci.txt', tempoExecucao[tempoExecucao.length - 1].toFixed(10) + "\n");
    }

    tempoExecucao.sort((a, b) => a - b);

    let media = 0;
    for (let i = 5; i < 95; i++)
        media += tempoExecucao[i];
    media /= 90;


    const log = 'Fibonacci iterativo de 90' + fibonacci(90) + '\n\n' +
        'Pior tempo de execução: ' + Math.max(...tempoExecucao).toFixed(10) + 's\n' +
        'Melhor tempo de execução: ' + Math.min(...tempoExecucao).toFixed(10) + 's\n' +
        'Tempo médio de execução (90 execuções): ' + media.toFixed(10) + 's\n';

    console.log(log);
}

main();
