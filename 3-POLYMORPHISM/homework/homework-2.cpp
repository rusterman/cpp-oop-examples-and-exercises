#include <iostream>
#include <string>

using namespace std;

/*
    Exercise: Polymorphism in a Backend Application

    Scenario:
    You are developing a backend application for a library management system. 
    The application needs to handle various types of items in the library, such as books, e-books, and audio CDs. 
    Each of these items has specific properties and actions associated with them.

    Requirements:

    1. Create a base class called LibraryItem with the following properties and methods:
        Properties:
        title (string): The title of the library item.
        year (int): The year of publication.
        Methods:
        virtual void checkout(): A virtual function that marks the item as checked out.
        virtual void checkin(): A virtual function that marks the item as checked in.
        virtual void displayInfo(): A virtual function that displays information about the item, 
        including its title and year of publication.

    2. Create three derived classes: Book, EBook, and AudioCD, each inheriting from LibraryItem. 
       These classes should have their own specific properties and methods:
        Book:
        Properties:
        author (string): The author of the book.
        Methods:
        Override the displayInfo() method to include information about the author.
        EBook:
        Properties:
        format (string): The format of the e-book (e.g., PDF, EPUB).
        Methods:
        Override the displayInfo() method to include information about the format.
        AudioCD:
        Properties:
        artist (string): The artist of the audio CD.
        Methods:
        Override the displayInfo() method to include information about the artist.

    3. In the main() function, create instances of Book, EBook, and AudioCD objects, each representing a library item.
    4. Create an array of pointers to LibraryItem objects and store the addresses of the items in the array.
    5. Use a loop to iterate through the array and perform the following actions:
        Check out and check in each item to simulate library operations.
        Display information about each item using the displayInfo() method.
    

    Example Output:

    Book Title: "The Great Gatsby"
    Author: F. Scott Fitzgerald
    Year: 1925
    Status: Checked out

    EBook Title: "The Hitchhiker's Guide to the Galaxy"
    Format: EPUB
    Year: 1979
    Status: Checked in

    Audio CD Title: "Abbey Road"
    Artist: The Beatles
    Year: 1969
    Status: Checked out

*/

// Solution
class LibraryItem {
protected:
    string title;
    int year;
    bool checkedOut;
public:
    LibraryItem(const string& t, int y) : title(t), year(y), checkedOut(false) {}
    virtual void checkout() {
        checkedOut = true;
    }
    virtual void checkin() {
        checkedOut = false;
    }
    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Year: " << year << endl;
        cout << "Status: " << (checkedOut ? "Checked out" : "Checked in") << endl;
    }
    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
private:
    string author;
public:
    Book(const string& t, int y, const string& a) : LibraryItem(t, y), author(a) {}
    void displayInfo() override {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Status: " << (checkedOut ? "Checked out" : "Checked in") << endl;
    }
};

class EBook : public LibraryItem {
private:
    string format;
public:
    EBook(const string& t, int y, const string& f) : LibraryItem(t, y), format(f) {}
    void displayInfo() override {
        cout << "EBook Title: " << title << endl;
        cout << "Format: " << format << endl;
        cout << "Year: " << year << endl;
        cout << "Status: " << (checkedOut ? "Checked out" : "Checked in") << endl;
    }
};

class AudioCD : public LibraryItem {
private:
    string artist;
public:
    AudioCD(const string& t, int y, const string& ar) : LibraryItem(t, y), artist(ar) {}
    void displayInfo() override {
        cout << "Audio CD Title: " << title << endl;
        cout << "Artist: " << artist << endl;
        cout << "Year: " << year << endl;
        cout << "Status: " << (checkedOut ? "Checked out" : "Checked in") << endl;
    }
};



int main() {

    /*      Example usage:     */ 
     Book book("The Great Gatsby", 1925, "F. Scott Fitzgerald");
    EBook ebook("The Hitchhiker's Guide to the Galaxy", 1979, "EPUB");
    AudioCD cd("Abbey Road", 1969, "The Beatles");

    LibraryItem* items[] = { &book, &ebook, &cd };

    for (int i = 0; i < 3; i++) {
        items[i]->checkout();  
        items[i]->displayInfo();
        items[i]->checkin();    
        items[i]->displayInfo();
        cout << "------------------------" << endl;

    

    return 0;
}
