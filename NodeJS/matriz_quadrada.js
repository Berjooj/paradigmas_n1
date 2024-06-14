const math = require('mathjs');
const fs = require('fs');

function multiplicarMatrizes(A, B) {
    return math.multiply(A, B);
}

async function main() {
    const tamanhos = [500, 1000, 1500, 2000, 2500, 3000];

    for (const n of tamanhos) {
        for (let j = 1; j <= 10; j++) {
            const A = math.random([n, n]);
            const B = math.random([n, n]);

            const start = process.hrtime.bigint();
            multiplicarMatrizes(A, B);
            const end = process.hrtime.bigint();

            const tempo = Number(end - start) / 1e9;

            const mensagem = `Tempo para matriz de tamanho ${n} (teste ${j}): ${tempo.toFixed(4)}s`;
            console.log(mensagem);

            fs.appendFileSync('matriz_quadrada_node.txt', mensagem + '\n');
        }
    }
}

main();
