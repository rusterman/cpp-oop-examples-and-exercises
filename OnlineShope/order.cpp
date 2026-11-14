#include "Order.h"

Order::Order(int id, string name) {
    orderID = id;
    customerName = name;
}

// Add product to order
void Order::addProduct(const Product& product) {
    orderedProducts.push_back(product);
}

double Order::calculateOrderTotal() const {
    double total = 0;

    for (const Product& product : orderedProducts) {
        total += product.getProductPrice();
    }

    return total;
}

int Order::getOrderID() const {
    return orderID;
}

string Order::getCustomerName() const {
    return customerName;
}

const vector<Product>& Order::getOrderedProducts() const {
    return orderedProducts;
}