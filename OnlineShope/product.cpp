#include "Product.h"

Product :: Product(int id, string name, double price){
    productID = id;
    productName = name;
    productPrice = price;

}
int Product ::getProductID() const{
    return productID;
}

string Product ::getProductName() const{
    return productName;
}

double Product ::getProductPrice() const{
    return productPrice;
}