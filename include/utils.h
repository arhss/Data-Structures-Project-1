#ifndef UTILS_H
#define UTILS_H

#define TRUE 1
#define FALSE 0
#define clearBuffer() int ch; while ((ch = getchar()) != '\n' && ch != EOF) {} // Clear any leftover '\n' from the buffer

void strNewLine(char *str);
void freeData();

#endif