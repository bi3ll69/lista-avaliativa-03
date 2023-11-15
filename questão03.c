#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char placa[10];
    char dia_semana[20];

    // Leitura da entrada
    scanf("%s", placa);
    scanf("%s", dia_semana);

    // Verificação do formato da placa
    if ((strlen(placa) != 7 && strlen(placa) != 8) || (placa[3] != '-' && placa[3] != 'N')) {
        printf("Placa invalida\n");
        return 0;
    }

    // Verificação do formato do dia da semana
    for (int i = 0; i < strlen(dia_semana); i++) {
        dia_semana[i] = toupper(dia_semana[i]);
    }

    if (strcmp(dia_semana, "SEGUNDA-FEIRA") != 0 && strcmp(dia_semana, "TERCA-FEIRA") != 0 &&
        strcmp(dia_semana, "QUARTA-FEIRA") != 0 && strcmp(dia_semana, "QUINTA-FEIRA") != 0 &&
        strcmp(dia_semana, "SEXTA-FEIRA") != 0 && strcmp(dia_semana, "SABADO") != 0 &&
        strcmp(dia_semana, "DOMINGO") != 0) {
        printf("Dia da semana invalido\n");
        return 0;
    }

    // Verificação do rodízio
    char ult_digito = placa[strlen(placa) - 1];
    int proibido = 0;

    switch (dia_semana[0]) {
        case 'S':
            printf("Nao ha proibicao no fim de semana\n");
            break;
        case 'Q':
            if (ult_digito == '0' || ult_digito == '1') proibido = 1;
            break;
        case 'T':
            if (ult_digito == '2' || ult_digito == '3') proibido = 1;
            break;
        case 'Q':
            if (ult_digito == '4' || ult_digito == '5') proibido = 1;
            break;
        case 'S':
            if (ult_digito == '6' || ult_digito == '7') proibido = 1;
            break;
        case 'S':
            if (ult_digito == '8' || ult_digito == '9') proibido = 1;
            break;
        default:
            printf("Dia da semana invalido\n");
            return 0;
    }

    if (proibido) {
        printf("%s nao pode circular %s\n", placa, dia_semana);
    } else {
        printf("%s pode circular %s\n", placa, dia_semana);
    }

    return 0;
}
