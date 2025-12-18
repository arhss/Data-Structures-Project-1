#ifndef PRODUCTS_H
#define PRODUCTS_H

typedef struct productList
{
   char key[14];
   char name[65];
   int quantity;
   double price;
   struct productList *next;
} product;

extern product *productsHead;

void addProduct(char *ean);
product *createProduct(char *ean);
void recommendProducts(char *ean, int len);
void printProducts(char *str);
void freeProducts();

#endif