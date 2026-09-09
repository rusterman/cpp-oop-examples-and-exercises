#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Product{
    private:
    int ProductId;
    string ProductName;
    double ProductPrice;
    public:
    Product(int ProductId = 0 , string ProductName = "0" , double ProductPrice = 0){
        this -> ProductId = ProductId;
        this -> ProductName = ProductName;
        this -> ProductPrice = ProductPrice;
    }
    int getId() const {
        return ProductId;
    }
    string getProductName()const{
        return ProductName;
    }
    double getProductPrice()const{
        return ProductPrice;
    }


};
class Order{
    private:
    int OrderId;
    string CustomerName;
    vector<Product> products;
    public:
    Order(int OrderId = 0 , string CustomerName = "0"){
        this -> OrderId = OrderId;
        this -> CustomerName = CustomerName;
    }
    void addProduct(Product product){
        products.push_back(product);
    }
    double calculateOrderTotal(){
        double total = 0;
        for(int i = 0; i < products.size(); i++){
            total = total + products[i].getProductPrice();
        }
        return total;
    }
    int getOrderID(){
        return OrderId;
    }

    string getCustomerName(){
        return CustomerName;
    }

    vector<Product> getOrderedProducts(){
        return products;
    }
};
int main() {

    system("cls");

    // Create products
    Product p1(1, "Product 1", 10.0);
    Product p2(2, "Product 2", 20.0);
    Product p3(3, "Product 3", 30.0);

    // Create an order
    Order order(1, "John Doe");

    // Add products to the order
    order.addProduct(p1);
    order.addProduct(p2);
    order.addProduct(p3);

    // Calculate the order total
    double total = order.calculateOrderTotal();

    // Display the order details
    cout << "Order ID: " << order.getOrderID() << endl;
    cout << "Customer Name: " << order.getCustomerName() << endl;
    cout << "Ordered Products:" << endl;

    for (const Product& product : order.getOrderedProducts()) {
        cout << " - " << product.getProductName() << endl;
    }
    
    cout << "Total: $" << total << endl;

    return 0;
}
