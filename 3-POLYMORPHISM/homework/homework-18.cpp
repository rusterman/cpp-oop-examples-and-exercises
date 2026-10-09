#include <iostream>
#include <string>

using namespace std;

/*
    Polymorphism

    15. Abstract Classes as Interfaces
*/


/*
    Exercise: E-Commerce System Design

    Instructions:

    1. Define Product Management Interface:
        Create an interface named ProductManager with a virtual function displayProductDetails that takes an int productId as a parameter.
    2. Implement Abstract Cart Class:
        Create an abstract class named AbstractCart that extends the ProductManager interface.
        Provide common functionality for managing a shopping cart, including adding to the cart, 
        removing from the cart, displaying the cart, and an abstract method checkout.
    3. Implement Concrete Online Store Class:
        Create a concrete class named OnlineStore that implements both the ProductManager interface and extends the AbstractCart abstract class.
        Implement the displayProductDetails method for an online store-specific product details display.
        Implement the checkout method for online store-specific checkout logic.
    4. Implement Concrete Mobile App Class:
        Create a concrete class named MobileApp that implements both the ProductManager interface and extends the AbstractCart abstract class.
        Implement the displayProductDetails method for a mobile app-specific product details display.
        Implement the checkout method for mobile app-specific checkout logic.

    Tips:
        Tip 1: Think about the functionalities that are common to both the online store and mobile app, and those that are specific to each.
        Tip 2: Ensure that the abstract class provides a common structure for shopping cart management.
        Tip 3: Implement the virtual functions in the derived classes with specific details related to the online store and mobile app.
        Tip 4: Use virtual destructors in the interface and abstract class for proper cleanup.
        Tip 5: Test your implementations by creating instances of the classes and 
        performing operations like displaying product details, adding/removing items from the cart, and checking out.
*/


// ProductManager interface
class ProductManager {
public:
    virtual void displayProductDetails(int productId) const = 0;
    virtual ~ProductManager() {}
};

// AbstractCart abstract class extending ProductManager
class AbstractCart : public ProductManager {
protected:
    vector<int> cart;
public:
    void addToCart(int productId) {
        cart.push_back(productId);
        cout << "Product " << productId << " added to cart." << endl;
    }

    void removeFromCart(int productId) {
        for (auto it = cart.begin(); it != cart.end(); ++it) {
            if (*it == productId) {
                cart.erase(it);
                cout << "Product " << productId << " removed from cart." << endl;
                return;
            }
        }
        cout << "Product " << productId << " not found in cart." << endl;
    }

    void displayCart() const {
        cout << "Cart contents: ";
        if (cart.empty()) {
            cout << "Cart is empty." << endl;
            return;
        }
        for (int id : cart) {
            cout << id << " ";
        }
        cout << endl;
    }

    // Abstract method for checkout
    virtual void checkout() const = 0;

    virtual ~AbstractCart() {}
};

// Concrete OnlineStore class
class OnlineStore : public AbstractCart {
public:
    void displayProductDetails(int productId) const override {
        cout << "OnlineStore: Displaying details for product " << productId << endl;
    }

    void checkout() const override {
        cout << "OnlineStore: Checking out with " << cart.size() << " items." << endl;
    }
};

// Concrete MobileApp class
class MobileApp : public AbstractCart {
public:
    void displayProductDetails(int productId) const override {
        cout << "MobileApp: Displaying details for product " << productId << endl;
    }

    void checkout() const override {
        cout << "MobileApp: Checking out with " << cart.size() << " items." << endl;
    }
};

int main() {
    // OnlineStore usage
    OnlineStore onlineStore;
    onlineStore.displayProductDetails(101);
    onlineStore.addToCart(101);
    onlineStore.addToCart(102);
    onlineStore.displayCart();
    onlineStore.checkout();

    cout << endl;

    // MobileApp usage
    MobileApp mobileApp;
    mobileApp.displayProductDetails(201);
    mobileApp.addToCart(201);
    mobileApp.removeFromCart(202);
    mobileApp.displayCart();
    mobileApp.checkout();

    return 0;
}