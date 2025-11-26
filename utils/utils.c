#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "utils.h"

void strNewLine(char *str)
{
   int len = strlen(str);
   if (str[len-1] == '\n')
      str[len-1] = '\0';
}

int strCharCount(char *str, int len)
{
   int i, ch = 0;
   for (i = 0; i < len; i++)
   {
      if (isalpha(str[i]))
         ch++;
   }
   return ch;
}