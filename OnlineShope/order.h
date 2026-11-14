#pragma once //class-ın təkrar elan olunmasının qarşısını alır

#include <iostream>
#include <string>
#include <vector>
#include "Product.h"

using namespace std;

class Order {
private:
    int orderID;
    string customerName;
    vector<Product> orderedProducts;

public:
    Order(int id, string name);

    void addProduct(const Product& product);

    double calculateOrderTotal() const;

    int getOrderID() const;
    string getCustomerName() const;

    const vector<Product>& getOrderedProducts() const;
};