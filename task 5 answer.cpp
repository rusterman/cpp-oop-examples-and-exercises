#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
private:
    int productID;
    string productName;
    double productPrice;

public:
    Product(int id, const string& name, double price) {
        productID = id;
        productName = name;
        productPrice = price;
    }

    int getProductID() const { return productID; }
    string getProductName() const { return productName; }
    double getProductPrice() const { return productPrice; }
};

class Order {
private:
    int orderID;
    string customerName;
    vector<Product> orderedProducts;

public:
    Order(int id, const string& customer) {
        orderID = id;
        customerName = customer;
    }

    void addProduct(const Product& product) {
        orderedProducts.push_back(product);
    }

    double calculateOrderTotal() const {
        double total = 0.0;
        for (const Product& p : orderedProducts) {
            total += p.getProductPrice();
        }
        return total;
    }

    int getOrderID() const { return orderID; }
    string getCustomerName() const { return customerName; }
    const vector<Product>& getOrderedProducts() const { return orderedProducts; }
};

int main() {

    Product p1(1, "Product 1", 10.0);
    Product p2(2, "Product 2", 20.0);
    Product p3(3, "Product 3", 30.0);

    Order order(1, "John Doe");

    order.addProduct(p1);
    order.addProduct(p2);
    order.addProduct(p3);

    double total = order.calculateOrderTotal();

    cout << "Order ID: " << order.getOrderID() << endl;
    cout << "Customer Name: " << order.getCustomerName() << endl;
    cout << "Ordered Products:" << endl;

    for (const Product& product : order.getOrderedProducts()) {
        cout << " - " << product.getProductName() << endl;
    }

    cout << "Total: $" << total << endl;

    return 0;
}