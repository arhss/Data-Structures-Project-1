#ifndef ORDERS_H
#define ORDERS_H

typedef struct orderList
{
   int customerID;
   char name[65];
   char **products;
   int *quantity;
   int priority;
} order;

#endif