#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOLZINA 1000010

int main(int argc, char** argv) {

        if (argc != 3) {
            printf("[Napaka]: program potrbuje dva argumenta.\n");
            return 1;
        }

    FILE* vhod = fopen(argv[1], "rt");
    FILE* izhod = fopen(argv[2], "w");

    int najDolzina = 0;
    char* vrstica = malloc(MAX_DOLZINA * sizeof(char));
    char* najVrstica = malloc(MAX_DOLZINA * sizeof(char));

    // domaca naloga
    // while ((line = read_line(source) != NULL)

    // fgets vrne string
    // char* fgets(char* niz, int n, FILE* stream)
    // -- iz toka <stream> prebere vrstico dolzine <n> z '\n' in
    // jo shrani v niz <str>
    while(fgets(vrstica, MAX_DOLZINA, vhod) != NULL) {
        // printf("%s", vrstica); 
        int dolzina = strlen(vrstica);
        if (dolzina > najDolzina) {
            najDolzina = dolzina;
            // char *stcpy(char)
            strcpy(najVrstica, vrstica);
        }
    }
    // printf("\n");

    fprintf(izhod, "%s", najVrstica);

    fclose(vhod);
    fclose(izhod);

    free(vrstica);
    free(najVrstica);

    return 0;
}