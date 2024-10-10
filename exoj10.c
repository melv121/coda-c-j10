#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * get_file(FILE * fp)
{
    char * content;
    char buffer[10];

    content = malloc(sizeof(char));
    content[0] = '\0';

    while(fgets(buffer, 10, fp) != NULL)
    {
        content = realloc(content, (strlen(buffer) * sizeof(char)) + strlen(content) * sizeof(char));
        content = strcat(content, buffer);
    }

    return content;
}

int main()
{
    FILE *fp = fopen("exercices1.txt", "r");
    char  *file_content;

    if (fp == NULL)
    {
        printf("Le fichier exercices1.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    file_content = get_file(fp);
    
    printf("%s\n", file_content);
    
    fclose(fp);
    free(fp);
	return 0;
}