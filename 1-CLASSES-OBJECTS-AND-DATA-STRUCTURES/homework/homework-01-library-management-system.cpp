#include <iostream>
#include <string>
using namespace std;
/*
    Exercise: Library Management System
    Description:
    Design and implement a Library Management System using classes and access specifiers in C++. 
    The system should allow you to manage books in a library.
    Requirements:
    1. Create a class named "Book" with the following attributes: 
        Title (a string)
        Author (a string)
        Publication Year (an integer)
        ISBN (a string)
    2. Make the attributes private to encapsulate them.
    3. Include member functions to:
        Set the book details (title, author, publication year, ISBN).
        Display the book details.

    4. Create objects of the "Book" class and demonstrate accessing and modifying the attributes using member functions.
    Tips:
    Use access specifiers (public and private) to control access to class members.
    You can choose to implement the member functions directly in the class declaration (inline) or define them outside the class.
    Test the functionality of the class by creating book objects, setting their details, and displaying the information.
    This exercise will help you practice using access specifiers to control the visibility of class members and understand the concept of encapsulation.
*/
/*  Solution */
class Book{
    private:
    string Title;
    string Author;
    int PublicYear;
    string ISBN;
    public:
    void setBookDetails(string bookname  ,string author , int year , string isbn){
       Title = bookname;
       Author = author;
       PublicYear = year;
       ISBN = isbn;
    }
    void displayBookDetails(){
        cout << Title <<endl;
        cout << Author << endl;
        cout << PublicYear << endl;
        cout << ISBN << endl;
    }

};
int main() {

    /*      Example usage:     */
    Book book1;
    book1.setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", 1925, "9780743273565");

    Book book2;
    book2.setBookDetails("To Kill a Mockingbird", "Harper Lee", 1960, "9780060935467");

    // Display book details
    cout << "Book 1 Details:" << endl;
    book1.displayBookDetails();
    cout << endl;

    cout << "Book 2 Details:" << endl;
    book2.displayBookDetails();
    cout << endl;

    return 0;
}
