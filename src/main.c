#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "products.h"

int main(void)
{

   int len;
   char ean[14], idk99;

   while (1)
   {
      printf("Dwse ean ");
      fgets(ean, sizeof(ean), stdin);
      strNewLine(ean);
      len = strlen(ean);

      if (len == 13)
         addProduct(ean);
      else if (len >= 4 && len < 13)
         recommendProducts(ean, len);
      else
         puts("Error!"); // wrong ean

      printf("Continue? ");
      scanf("%c", &idk99);
      if (idk99 == 'X')
         break;
   }

   printProducts("*", 1);

   freeData();
   return 0;
}