#include <stdio.h>

int wordcount(int argc, char* argv[3]) {
    FILE *file;
    file = fopen(argv[argc - 1 ], "r");
    char readChar;
    char previousChar = ' ';
    int linesAmount = 1;
    int fileSizeBytes = 0;
    int wordAmount = 0;
    if (file == NULL) {
        printf("File %s not found :(\n", argv[argc - 1]);
        return -1;
    } else {
        while ((readChar = fgetc(file)) != EOF) {
            fileSizeBytes += sizeof(readChar);
            if (readChar == '\n') {
                linesAmount++;
            }
            if (previousChar == ' ' || previousChar == '\t' || previousChar == '\n') {
                if (readChar != ' ' && readChar != '\t' && readChar != '\n') {
                    wordAmount++;
                }
            }
            previousChar = readChar;
        }
    }

    if (fileSizeBytes == 0) {
        linesAmount = 0;
        wordAmount = 0;
    }

    for (int i = 1; i < argc - 1; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            printf("Insert -w or --words command to get amount of words in the file\n");
            printf("Insert -c or --bytes command to get amount of bytes in the file\n");
            printf("Insert -l or --lines command to get amount of lines in the file\n");
        } else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--lines") == 0) {
            // printf("Lines in the file: %d \n", linesAmount);
            return linesAmount;
        } else if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--words") == 0) {
            // printf("Words in the file: %d \n", wordAmount);
            return wordAmount;
        } else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--bytes") == 0) {
            // printf("Size of the file in bytes: %d \n", fileSizeBytes);
            return fileSizeBytes;
        } else {
            printf("No such command. Insert   ./launcher --help pathOfTheFile to see commands available");
            return -2;
        }
    }

    fclose(file);
}


int mult(int a, int b) {
  return a * b;
}
