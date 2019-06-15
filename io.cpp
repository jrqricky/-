#include "io.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

char ldisk[L][B];

void read_block(int i, char *p) {
    memcpy(p, ldisk[i], B);
}

void write_block(int i, char *p) {
    memcpy(ldisk[i], p, B);
}

void read_file() {
    FILE *fp = fopen("ldisk.txt", "r");
    for (int i = 0; i < L; i++)
        fread(ldisk[i], sizeof(char), B, fp);
    fclose(fp);
}

void write_file() {
    FILE *fp = fopen("ldisk.txt", "w+");
    for(int i = 0; i < L; i++)
        fwrite(ldisk[i], sizeof(char), B, fp);
    fclose(fp);
}
