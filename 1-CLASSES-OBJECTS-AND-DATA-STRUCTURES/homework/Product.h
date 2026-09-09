#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product{
private:
    int productID;
    string productName;
    double productPrice;

public:
    Product(int id, const string& name, double price)
        : productID(id), productName(name), productPrice(price) {}

    int getProductID() const { return productID; }
    string getProductName() const { return productName; }
    double getProductPrice() const { return productPrice; }
};

#endif