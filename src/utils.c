/*
 * Add description
 */

#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "messages.h"
#include "products.h"
#include "orders.h"

//
void strNewLine(char *str)
{
   int len = strlen(str);
   if (str[len-1] == '\n')
      str[len-1] = '\0';
}

//
void freeData()
{
   freeProducts();
   freeOrders();
}