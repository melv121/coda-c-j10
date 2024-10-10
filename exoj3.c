#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

int main() {
    FILE *file = fopen("exercices3.txt", "r");
    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
        return EXIT_FAILURE;
    }

    char **lines = malloc(MAX_LINES * sizeof(char *));
    if (lines == NULL) {
        perror("Erreur d'allocation mémoire");
        fclose(file);
        return EXIT_FAILURE;
    }

    int count = 0;
    char buffer[MAX_LENGTH];

    while (fgets(buffer, sizeof(buffer), file) != NULL && count < MAX_LINES) {
       
        buffer[strcspn(buffer, "\n")] = 0;
        
        
        lines[count] = malloc((strlen(buffer) + 1) * sizeof(char));
        if (lines[count] == NULL) {
            perror("Erreur d'allocation mémoire");
            break;
        }

        strcpy(lines[count], buffer);
        count++;
    }

    fclose(file);


    for (int i = 0; i < count; i++) {
        printf("%s\n", lines[i]);
        free(lines[i]);  
    }

    free(lines);

    return EXIT_SUCCESS;
}