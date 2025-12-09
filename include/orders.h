#ifndef ORDERS_H
#define ORDERS_H

typedef struct orderList
{
   int key;
   char name[65];
   char **productsArray;
   int *quantity;
   // priority
   struct orderList *next;
} order;

extern order *ordersHead;

void addOrder(char *ean);
order *createOrder(char *ean);
void freeOrders();

#endif