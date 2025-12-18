/*
 * Add description
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "products.h"
#include "messages.h"
#include "utils.h"

product *productsHead = NULL;

// This function is used in _, when a valid code is given, in order to add a product into the list.
void addProduct(char *ean)
{
   product *temp = productsHead;

   // Searches if the product already exitsts..
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

   product *newNode = createProduct(ean);
   printf(PRODUCT_CREATED_SUCCESSFULLY, newNode->key);

   if (productsHead == NULL) // If the list is empty
   {
      productsHead = newNode;
      return;
   }

   // Searches for the end of the list..
   temp = productsHead;
   while (temp->next != NULL)
      temp = temp->next;
   temp->next = newNode;
}

// Used by addProduct() in order to allocate memory and configure a product.
product *createProduct(char *ean)
{
   product *node = malloc(sizeof(product));
   if (!node)
   {
      puts(PRODUCT_MALLOC_ERROR);
      freeData();
      exit(1);
   }

   strcpy(node->key, ean);

   printf("Name: ");
   input(node->name, sizeof(node->name));

   while(1)
   {
      printf("Quantity: ");
      scanf("%d", &node->quantity);
      if (node->quantity >= 0)
         break;
      puts(PRODUCT_QUANTITY_ERROR);
   }
   
   while(1)
   {
      printf("Price: ");
      scanf("%lf", &node->price);
      if (node->price > 0)
         break;
      puts(PRODUCT_PRICE_ERROR);
   }
   
   clearBuffer(); // Clear any leftover '\n' from the buffer

   node->next = NULL;

   return node;
}

// Used in _, when a valid but incomplete code is given, in order to recommend product(s) with similar codes.
void recommendProducts(char *ean, int len)
{
   int flag = TRUE;
   product *temp = productsHead;
   while (temp != NULL)
   {
      // Compares based on the incomplete's code length..
      if (strncmp(temp->key, ean, len) == 0)
      {
         if (flag)
         {
            puts(RECOMMENDATION_TEXT);
            flag = FALSE;
         }
         printf(PRODUCT_RECOMMEND, temp->key);
      }
      temp = temp->next;
   }

   if (flag)
      printf(PRODUCT_NOT_FOUND, ean);
}

// Used in _ in order to print products in several ways.
void printProducts(char *str)
{
   int len = strlen(str);
   product *temp;

   /* Case 1:
      Prints all.. */
   if (strcmp(str, "*") == 0)
   {
      temp = productsHead;
      while (temp != NULL)
      {
         printf(PRODUCT_PRINT, temp->key, temp->name, temp->quantity, temp->price);
         temp = temp->next;
      }
   }

   /* Case 2:
      Prints product(s) based on full or partial code.. */
   int flag = FALSE;
   temp = productsHead;
   while (temp != NULL)
   {
      if (strncmp(temp->key, str, len) == 0)
      {
         printf(PRODUCT_PRINT, temp->key, temp->name, temp->quantity, temp->price);
         flag = TRUE;
      }
      temp = temp->next;
   }
   if (flag == TRUE) // If case 2 has been executed successfully
      return;

   /* Case 3:
      Prints product(s) based on name.. */
   temp = productsHead;
   while (temp != NULL)
   {
      if (strcmp(temp->name, str) == 0)
         printf(PRODUCT_PRINT, temp->key, temp->name, temp->quantity, temp->price);
      temp = temp->next;
   }
}

// Used in freeData() in order free the memory of the products' list.
void freeProducts()
{
   product *temp = productsHead;
   while (temp != NULL)
   {
      product *next = temp->next; // Keep the next node before freeing the current
      free(temp);
      temp = next;
   }
   productsHead = NULL;
   puts(FREE_PRODUCTS);
}