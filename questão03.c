#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char placa[10], dia[20];
    
    scanf("%s", placa);
    scanf("%s", dia);

    if (strlen(placa) == 7 || strlen(placa) == 8) {
        int i;
        for (i = 0; i < 3; ++i) {
            if (!isalpha(placa[i])) {
                printf("Placa invalida\n");
                return 0;
            }
        }
        if (placa[3] != '-') {
            printf("Placa invalida\n");
            return 0;
        }
        for (i = 4; i < strlen(placa); ++i) {
            if (!isdigit(placa[i])) {
                printf("Placa invalida\n");
                return 0;
            }
        }
    } else {
        printf("Placa invalida\n");
        return 0;
    }

    for (int i = 0; i < strlen(dia); ++i) {
        dia[i] = toupper(dia[i]);
    }

    if (strcmp(dia, "SEGUNDA-FEIRA") == 0) {
        if (placa[6] == '0' || placa[6] == '1') {
            printf("%s nao pode circular segunda-feira\n", placa);
        } else {
            printf("%s pode circular segunda-feira\n", placa);
        }
    } else if (strcmp(dia, "TERCA-FEIRA") == 0) {
        if (placa[6] == '2' || placa[6] == '3') {
            printf("%s nao pode circular terca-feira\n", placa);
        } else {
            printf("%s pode circular terca-feira\n", placa);
        }
    } else if (strcmp(dia, "QUARTA-FEIRA") == 0) {
        if (placa[6] == '4' || placa[6] == '5') {
            printf("%s nao pode circular quarta-feira\n", placa);
        } else {
            printf("%s pode circular quarta-feira\n", placa);
        }
    } else if (strcmp(dia, "QUINTA-FEIRA") == 0) {
        if (placa[6] == '6' || placa[6] == '7') {
            printf("%s nao pode circular quinta-feira\n", placa);
        } else {
            printf("%s pode circular quinta-feira\n", placa);
        }
    } else if (strcmp(dia, "SEXTA-FEIRA") == 0) {
        if (placa[6] == '8' || placa[6] == '9') {
            printf("%s nao pode circular sexta-feira\n", placa);
        } else {
            printf("%s pode circular sexta-feira\n", placa);
        }
    } else if (strcmp(dia, "SABADO") == 0 || strcmp(dia, "DOMINGO") == 0) {
        printf("Nao ha proibicao no fim de semana\n");
    } else {
        printf("Dia da semana invalido\n");
    }

    return 0;
}