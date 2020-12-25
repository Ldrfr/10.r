#define _CRT_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
#include<locale.h>
#include<string.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int j, n = 0;
    char word[100][100];
    FILE* fp1 = fopen("text.txt", "r+");
    FILE* fp2 = fopen("output.txt", "w");
    if (fp1 == NULL) return 1;
    char* str = (char*)malloc(100 * sizeof(char));
    //char* str_print = (char*)malloc(100 * sizeof(char));
    fgets(str, 100, fp1); //считал файл в строку для записи
    //char* rec = (char*)malloc(sizeof(char));
    //strcpy(str_print, str);
    //strcpy(str_print, rec);
    //////////////////////////////////////////////////////////////////////////////////////
    char* str1 = strtok(str, " ");//разбивная строка
    char* s = (char*)malloc(100 * sizeof(char));//выделяю массив для записи
    char* t = 0;
    char* last = 0;
    s[0] = '\0';
    strcat(s, str1);//объединил с 1 словом
    str1 = strtok(NULL, " "); //вернул на исходную строку
    while (str1 != NULL) {
        strcat(s, " ");
        strcat(s, str1); //объединил
        t = str1;
        str1 = strtok(NULL, " .");//просто добавил воды(точку) -> удалил 
        if (str1 == NULL)
            last = t;
    }
    /////////////////////////////////////////////////////////////////////////////////////// all works with dot in the end -> clear string   
    for (int i = 0; s[i] != '\0';)//пока не конец (можно ноль поменять на точку или сделать и то ито)
    {
        while (s[i] == ' ' && s[i] != '\0')
            i++;//считаем до какого символа надо взять слово из нашей строки
        if (s[i] != '\0')
        {
            j = 0;
            while (s[i] != ' ' && s[i] != '\0')
                word[n][j++] = s[i++];//n-ое слово равно части строки до символа которого мы замерили
            word[n][j] = '\0';
            n++;//переходим к следующему слову
        }
    }


    /*char* str2 = strtok(str_print, " ");//для повторяющихся слов дублирую
    char* recording2 = (char*)malloc(100 * sizeof(char));
    recording2[0] = '\0';
    strcat(recording2, str2);
    str2 = strtok(NULL, " "); 
    while (str2 != NULL) {
        strcat(recording2, " ");
        strcat(recording2, str2); //объединил
        str2 = strtok(NULL, " .");//просто добавил воды(точку) -> удалил 
    }
    ///////////////////////////// теперь раздробить по словам recording2

    char* recording3 = (char*)malloc(100 * sizeof(char));
    recording3[0] = '\0';

    while (recording2 != NULL) {
        if (strtok(recording2, last) != 0)
            strcat(recording3, recording2);
        else continue;
        strcat(recording3, " ");
    }
    char* str3 = strtok(recording2, last);
    strcat(recording3, str3);
    str3 = strtok(NULL, " ");
    
    while (str3 != NULL) {
        strcat(recording3, " ");
        if (str3 != last)
            strcat(recording3, str3);
        else continue;
        //str3 = strtok(NULL, " .");
    }
    int i = 1000;
    s = strtok(rec, " ");
    s = strtok(NULL, " ");
    while (s != NULL) {
        if (strlen(s) < i && strlen(s) > 0) {
            i = strlen(s);
            strcat(capcha, s);
            strcat(capcha, " ");
        }
        s = strtok(NULL, " ");
    }*/


    fprintf(fp2, "%s\n", s);
    fprintf(fp2, "%s\n", last);
    printf("Просто слова:\n");
    for (int i = 0; i < n; i++) {
        puts(word[i]);
    }
    printf("То что нужно:\n");
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(word[i], word[n -1]) != 0) {
            puts(word[i]);
        }
    }
    fprintf(fp2, "Просто слова:\n");
    for (int i = 0; i < n; i++) {
        fprintf(fp2, "%s\n", word[i]);
    }
    fprintf(fp2, "То что нужно:\n");
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(word[i], word[n - 1]) != 0) {
            fprintf(fp2, "%s\n", word[i]);
        }
    }
    //fprintf(fp2, "%s\n", recording2);
    //fprintf(fp2, "%s\n", str3);
    //printf("%s", last);
    fclose(fp1);
    fclose(fp2);
}