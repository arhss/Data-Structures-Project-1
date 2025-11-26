#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "errors.h"
#include "products.h"

product *productsHead = NULL;

void addProduct(char *ean)
{
   product *temp = productsHead;
   while (temp != NULL)
   {
      if (strcmp(temp->key, ean) == 0)
      {
         temp->quantity++;
         puts(PRODUCT_ALREADY_EXISTS);
         return;
      }
      temp = temp->next;
   }

   product *newNode = createNode(ean);

   if (productsHead == NULL)
   {
      productsHead = newNode;
      return;
   }

   temp = productsHead;
   while (temp->next != NULL)
      temp = temp->next;
   temp->next = newNode;
}

product *createProduct(char *ean)
{
   product *node = malloc(sizeof(product));
   if (node == NULL)
   {
      puts(PRODUCT_MALLOC);
      freeProducts();
      exit(1);
   }

   strcpy(node->key, ean);

   printf("Name: ");
   clearBuffer();
   fgets(node->name, sizeof(node->name), stdin);
   strNewLine(node->name);

   printf("Quantity: ");
   scanf("%d", &node->quantity);

   printf("Price: ");
   scanf("%f", &node->price);

   node->next = NULL;

   return node;
}

void removeProduct(char *ean)
{
   product *temp = productsHead;
   product *prev = NULL;

   while (temp != NULL)
   {
      if (strcmp(temp->key, ean) == 0)
      {
         if (prev == NULL)
            productsHead = temp->next;
         else
            prev->next = temp->next;

         product *next = temp;
         temp = temp->next;
         free(next);
         continue;
      }
      prev = temp;
      temp = temp->next;
   }
}

void freeProducts()
{
   product *temp = productsHead;
   while (temp != NULL)
   {
      product *next = temp->next;
      free(temp);
      temp = next;
   }
   productsHead = NULL;
}