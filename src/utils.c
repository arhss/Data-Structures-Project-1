/*
 * Add description
 */

#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "products.h"
#include "orders.h"

void input(char *dest, int size)
{
   char *ptr;
   if (fgets(dest, size, stdin) != NULL)
   {
      ptr = strchr(dest, '\n');

      if (ptr != NULL)
         *ptr = '\0';
      else
         clearBuffer();
   }
}

void clearBuffer(void)
{
   int ch;
   while ((ch = getchar()) != '\n' && ch != EOF){}
}

void freeData()
{
   freeProducts();
   // freeOrders();
}