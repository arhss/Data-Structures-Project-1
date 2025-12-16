/*
 * This file contains the functions related to the products of the Warehouse Management System.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "messages.h"
#include "products.h"

product *productsHead = NULL;

// Adds a product to the list
void addProduct(char *ean)
{
   // Searches if the product already exitsts..
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

   product *newNode = createProduct(ean);

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

// Allocates memory and Configures a product
product *createProduct(char *ean)
{
   product *node = malloc(sizeof(product));
   if (!node)
   {
      puts(PRODUCT_MALLOC);
      freeData();
      exit(1);
   }

   strcpy(node->key, ean);

   printf("Name: ");
   fgets(node->name, sizeof(node->name), stdin);
   strNewLine(node->name); // Removes newline from a string's end

   printf("Quantity: ");
   scanf("%d", &node->quantity);

   printf("Price: ");
   scanf("%lf", &node->price);

   node->next = NULL;

   return node;
}

// Prints product(s) from an incomplete EAN
void recommendProducts(char *ean, int len)
{
   product *temp = productsHead;
   while (temp != NULL)
   {
      if (strncmp(temp->key, ean, len) == 0) // Compare EANs using the given length
         puts(temp->key);
      temp = temp->next;
   }
}

// Prints products
void printProducts(char *str, int len)
{
   // Prints all products..
   product *temp = productsHead;
   if (strncmp(str, "*", 1) == 0)
   {
      while (temp != NULL)
      {
         printf("%s: %s, quantity: %d\n", temp->name, temp->key, temp->quantity);
         temp = temp->next;
      }
   }

   // Prints based on the full or partial EAN..
   int flag = FALSE;
   temp = productsHead;
   while (temp != NULL)
   {
      if (strncmp(temp->key, str, len) == 0)
      {
         printf("%s: %s, quantity: %d\n", temp->name, temp->key, temp->quantity);
         flag = TRUE;
      }
      temp = temp->next;
   }

   // Prints product based on its name..
   if (flag == TRUE)
      return;
   temp = productsHead;
   while (temp != NULL)
   {
      if (strcmp(temp->name, str) == 0)
         printf("%s: %s, quantity: %d\n", temp->name, temp->key, temp->quantity);
      temp = temp->next;
   }
}

// Frees products' list memory
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
}