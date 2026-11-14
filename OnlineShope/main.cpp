#include <iostream>
#include "Product.h"
#include "Order.h"

using namespace std;

int main(){

    Product pr1(1, "Book", 25.0);
    Product pr2(2, "Book2", 23.0);
    Product pr3(3, "Book3", 18.0);

    Order order(1, "John Doe");

    order.addProduct(pr1);
    order.addProduct(pr2);
    order.addProduct(pr3);

    cout <<"Order ID: " << order.getOrderID() << endl;
    cout << "Customer Name: " << order.getCustomerName() << endl;
    cout << "Ordered Products: " << endl;

    for( int i = 0; i < order.getOrderedProducts().size(); ++i ){
        cout << " -- " << order.getOrderedProducts()[i].getProductName() << " $ " << order.getOrderedProducts()[i].getProductPrice() << endl; 
    }

    cout << "Total: $ " << order.calculateOrderTotal() << endl;

return 0;

}
