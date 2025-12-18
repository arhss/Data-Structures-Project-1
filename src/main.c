#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "products.h"

int main(void)
{
   int len;
   char ean[14], buffer[5];

   while (1)
   {
      printf("Dwse ean ");
      input(ean, sizeof(ean));
      len = strlen(ean);

      if (len == 13)
         addProduct(ean);
      else if (len >= 4 && len < 13)
      {
         recommendProducts(ean, len);
         // continue;
      }
      else
         puts("Error!");

      printf("Continue? (Y)es / (N)o ");
      input(buffer, sizeof(buffer));
      if ((strncmp(buffer, "N", 1) == 0) ||
          (strncmp(buffer, "n", 1) == 0))
         break;
   }

   // printf("Case 1\n");
   // printProducts("*");
   // printf("\n");

   // printf("Case 2.1\n");
   // printProducts("123456");
   // printf("\n");

   // printf("Case 2.2\n");
   // printProducts("123456789abcd");
   // printf("\n");

   // printf("Case 3\n");
   // printProducts("petros");
   // printf("\n");

   freeData();
   return 0;
}