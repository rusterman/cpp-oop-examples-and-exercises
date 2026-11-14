#pragma once

#include<iostream>
#include<string>

using namespace std;

class Product{
private:
    int productID;
    string productName;
    double productPrice;

public:
    Product(int id, string name, double price);

    int getProductID() const;
    string getProductName() const;
    double getProductPrice() const;
    
};