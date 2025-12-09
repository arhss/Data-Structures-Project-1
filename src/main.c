#include <stdio.h>
#include <string.h>

#include "utils.h"

int main(void)
{
   
   int len, ch;
   char ean[14];

   while (1)
   {
      fgets(ean, sizeof(ean), stdin);
      strNewLine(ean);
      len = strlen(ean);

      if (len == 13)
      {
         addProduct(ean);
         break;
      }
      else if (len >= 4 && len < 13)
      {
         recommendProducts(ean, len);
         break;
      }
      else
         puts("Error!"); // wrong ean
   }

   freeData();
   return 0;
}