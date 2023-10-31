#include<stdio.h>

int main(int argc, char ** argv) {
    int chr, count;
    FILE * fp,* fp1;
    if(argc != 4) {
        printf("usage ./a.out filepath findstr replacestr\n");
        return 1;
    }
    fp = fopen(argv[1], "r+");
    fp1 = fopen("swap","w+");
    if(fp == 0) {
        printf("file at filepath %s does not exist\n", argv[1]);
        return 1;
    }
    count = 0;
    while((chr = fgetc(fp)) != -1) {
        if(chr == argv[2][count]){
            count++;
        } else {
            count = 0;
        }
        if(argv[2][count] == 0) {
            count--;
            fseek(fp1, -1*count, SEEK_CUR);
            fputs(argv[3], fp1);
            count = 0;
        } else {
            fputc(chr, fp1);
        }
    }
    rewind(fp1);
    rewind(fp);
    while((chr = fgetc(fp1)) != -1) {
        fputc(chr, fp);
    }
    fclose(fp1);
    fclose(fp);
    remove("swap");
    return 0;
}
