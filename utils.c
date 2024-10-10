#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"



void copy_file_with_new_extension(const char *filename) {
    // בדיקה אם הקובץ מסתיים ב-.as
    const char *extension = ".as";
    size_t len = strlen(filename);
    if (len < 3 || strcmp(filename + len - 3, extension) != 0) {
        printf("File %s does not have a .as extension. Skipping.\n", filename);
        return;
    }

    // בניית שם הקובץ החדש עם הסיומת .ad
    char new_filename[256];
    strncpy(new_filename, filename, len - 3);
    new_filename[len - 3] = '\0';
    strcat(new_filename, ".ad");

    // פתיחת הקובץ לקריאה
    FILE *input_file = fopen(filename, "r");
    if (!input_file) {
        perror("Failed to open input file");
        return;
    }

    // פתיחת הקובץ החדש לכתיבה
    FILE *output_file = fopen(new_filename, "w");
    if (!output_file) {
        perror("Failed to open output file");
        fclose(input_file);
        return;
    }

    // קריאה והעתקה של כל שורה מהקובץ המקורי לקובץ החדש
    char line[1024];
    while (fgets(line, sizeof(line), input_file)) {
        fputs(line, output_file);
    }

    // סגירת הקבצים
    fclose(input_file);
    fclose(output_file);

    printf("File %s copied to %s\n", filename, new_filename);
}