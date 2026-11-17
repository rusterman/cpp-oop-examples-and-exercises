
#include <iostream>
#include <string>
using namespace std;




class Book {
private:
    string title;
    string author;
    int publicationYear;
    string isbn;

public:
    
    void setBookDetails(string t, string a, int year, string i) {
        title = t;
        author = a;
        publicationYear = year;
        isbn = i;
    }

    
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << publicationYear << endl;
        cout << "ISBN: " << isbn << endl;
    }
};
int main() {
    Book myBook;

    myBook.setBookDetails("Harry Potter", "J.K. Rowling", 1997, "123456");

    myBook.displayBookDetails();

    return 0;
}