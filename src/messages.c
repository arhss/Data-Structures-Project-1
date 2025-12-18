/*
 * Add description
 */

#include "messages.h"

// Messages used in products.c
const char *PRODUCT_ALREADY_EXISTS = "This product already exists, it's quantity has increased..";
const char *PRODUCT_MALLOC_ERROR = "Error allocating memory for a product..";
const char *PRODUCT_QUANTITY_ERROR = "The quantity must be at least 0!";
const char *PRODUCT_PRICE_ERROR = "The price must be greater than 0!";
const char *PRODUCT_CREATED_SUCCESSFULLY = "Product %s has been created successfully!\n";
const char *RECOMMENDATION_TEXT = "Did you mean:";
const char *PRODUCT_RECOMMEND = " %s\n";
const char *PRODUCT_NOT_FOUND = "%s product not found!\n";
const char *PRODUCT_PRINT = "Code: %s, Name: %s, Quantity: %d, Price: %.2lf$\n";
const char *FREE_PRODUCTS = "Products' list has been freed.";

// Messages used in orders.c