#include <stdio.h>
#include <string.h>

#define MAX_ROMAN_LENGTH 13
#define NUM_BITS 12

enum RomanValues {
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000,
};

int valorRomano(char c) {
    switch (c) {
        case 'I': return I;
        case 'V': return V;
        case 'X': return X;
        case 'L': return L;
        case 'C': return C;
        case 'D': return D;
        case 'M': return M;
        default: return 0;
    }
}

int romanoParaDecimal(const char *numRo) {
    int resultado = 0;
    int len = strlen(numRo);

    for (int i = 0; i < len; i++) {
        int valorAtual = valorRomano(numRo[i]);
        int valorProximo = (i < len - 1) ? valorRomano(numRo[i + 1]) : 0;

        if (valorAtual < valorProximo) {
            resultado -= valorAtual;
        } else {
            resultado += valorAtual;
        }
    }

    return resultado;
}

void imprimirBinario(int decimal) {
    printf(" na base 2: ");
    int flag = 0;

    for (int i = NUM_BITS; i >= 0; i--) {
        int bit = (decimal >> i) & 1;
        if (bit == 1 || flag == 1) {
            printf("%d", bit);
            flag = 1;
        }
    }

    if (flag == 0) {
        printf("0");
    }

    printf("\n");
}

int main() {
    char numRo[MAX_ROMAN_LENGTH];
    scanf("%s", numRo);

    int decimal = romanoParaDecimal(numRo);

    printf("%s", numRo);
    imprimirBinario(decimal);

    printf("%s na base 10: %d\n", numRo, decimal);

    printf("%s na base 16: %x\n", numRo, decimal);

    return 0;
}