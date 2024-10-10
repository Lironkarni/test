#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename (without extension)>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        // קבלת שם הקובץ ללא הסיומת
        const char *base_filename = argv[i];

        // הוספת הסיומת .as לשם הקובץ
        char filename_with_extension[256];
        snprintf(filename_with_extension, sizeof(filename_with_extension), "%s.as", base_filename);

        // בדיקה אם הקובץ עם הסיומת .as קיים
        FILE *file = fopen(filename_with_extension, "r");
        if (!file) {
            printf("Error: File %s does not exist. Skipping.\n", filename_with_extension);
            continue;
        }
        fclose(file);

        // קריאה לפונקציה להעתקת הקובץ עם שם הקובץ המלא
        copy_file_with_new_extension(filename_with_extension);
    }

    return 0;
}
