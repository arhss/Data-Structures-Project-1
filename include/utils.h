#ifndef UTILS_H
#define UTILS_H

#define TRUE 1
#define FALSE 0
#define clearBuffer() int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}

void strNewLine(char *str);
void freeData();

#endif