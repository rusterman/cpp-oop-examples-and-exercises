#include <iostream>
#include <string>

using namespace std;


/*
    Inheritance and Polymorphism with Static members
*/

/*
    Exercise: Create a library management program with C++ that models different types of items 
    (books and DVDs) and their late fee calculations. 
    Implement the missing parts of the code and complete the tasks below.

    Tasks:

    1. Implement the missing parts of the code, including the calculateLateFee method for both the Book and DVD classes.
    2. Initialize and update the totalItems static member in the LibraryItem class when a new item is created.
    3. In the main function, create instances of both Book and DVD, display their information, and calculate late fees for them.
    4. Finally, display the total number of library items using the totalItems static member.
*/

class LibraryItem {
    public:
        LibraryItem(const string& title ) : title(title) {
        }

        virtual double calculateLateFee(int daysLate) const = 0;

        virtual void displayInfo() const {
            cout << "Title: " << title << endl;
        }

        // Add a static member to keep track of the total library items
        // your code ...
         static double totalItems;

    protected:
        string title;
};
double LibraryItem::totalItems = 0;

// Define the static member totalItems for the LibraryItem class here
// Initialize it to 0.

class Book : public LibraryItem {
    public:
        Book(const string& title, const string& author) : LibraryItem(title), author(author) {
           totalItems++;
        }

        double calculateLateFee(int daysLate) const override {
            return daysLate*2;
        }

        void displayInfo() const override {
            LibraryItem::displayInfo();
            cout << "Author: " << author << std::endl;
        }

    private:
        string author;
};

class DVD : public LibraryItem {
    public:
        DVD(const string& title, int duration) : LibraryItem(title), duration(duration) {
            totalItems++;
        }

        double calculateLateFee(int daysLate) const override {
            return daysLate*3;
        }

        void displayInfo() const override {
            LibraryItem::displayInfo();
            cout << "Duration: " << duration << " minutes" << endl;
        }

    private:
        int duration;
};


int main() {
    Book book1("The Karamazov Brothers" , "Feodor Dostoevski");
    DVD dvd1("Oxford listening DVD" , 7);
    book1.calculateLateFee(10);
    dvd1.calculateLateFee(8);
    book1.displayInfo();
    dvd1.displayInfo();
    cout << "Total Item " << LibraryItem::totalItems << endl;
    cout << "Book Late fee: " << book1.calculateLateFee(3) << endl; 
    cout << "DVD Late fee: " <<  dvd1.calculateLateFee(7) << endl;
}
