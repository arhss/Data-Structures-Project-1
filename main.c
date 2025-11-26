#include <stdio.h>
#include <string.h>

#include "utils/utils.h"
#include "errors/errors.h"
#include "products/products.h"


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
      else if (len >= 4 && len <= 12)
      {
         ch = strCharCount(ean, len);
         if (ch >= 4)
         {
            puts("Proteine");
            break;
         }
      }
      else
         puts("Error!");
   }

   freeProducts();
   return 0;
}