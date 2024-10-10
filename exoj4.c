#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_user {
    char *first_name;
    char *last_name;
    int age;
};

int main() {
    FILE *file = fopen("exercice4.txt", "r");
    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
        return EXIT_FAILURE;
    }

    struct s_user user;
    char buffer[256];

    
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (sscanf(buffer, "Prénom : %s", user.first_name) == 1) {
            user.first_name = malloc(strlen(buffer) + 1);
            strcpy(user.first_name, buffer + strlen("Prénom : "));
            user.first_name[strcspn(user.first_name, "\n")] = 0; // Enlever le retour à la ligne
        }
        else if (sscanf(buffer, "Nom : %s", user.last_name) == 1) {
            user.last_name = malloc(strlen(buffer) + 1);
            strcpy(user.last_name, buffer + strlen("Nom : "));
            user.last_name[strcspn(user.last_name, "\n")] = 0; // Enlever le retour à la ligne
        }
        else if (sscanf(buffer, "Age: %d", &user.age) == 1) {
            // Age es