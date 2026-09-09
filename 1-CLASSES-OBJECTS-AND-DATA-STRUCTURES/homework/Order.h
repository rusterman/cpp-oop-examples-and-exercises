#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <vector>
#include "Product.h"
using namespace std;

class Order{
private:
    int orderID;
    string customerName;
    vector<Product*> orderedProducts;

public:
    Order(int id, const string& name)
        : orderID(id), customerName(name) {}

    void addProduct(Product* product) {
        orderedProducts.push_back(product);
    }
    double calculateOrderTotal() const {
        double total=0.0;
        for(const auto& product : orderedProducts){
            total+=product->getProductPrice();
        }
        return total;
    }
    
    int getOrderID() const { return orderID; }
    string getCustomerName() const { return customerName; }
    const vector<Product*>& getOrderedProducts() const { return orderedProducts; }
};

#endif