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
    LibraryItem(const string& title) : title(title) {
        totalItems++;
    }

    virtual double calculateLateFee(int daysLate) const = 0;

    virtual void displayInfo() const {
        cout << "Title: " << title << endl;
    }

    static int totalItems; // static member

protected:
    string title;
};

// Define the static member
int LibraryItem::totalItems = 0;

class Book : public LibraryItem {
public:
    Book(const string& title, const string& author) 
        : LibraryItem(title), author(author) {}

    double calculateLateFee(int daysLate) const override {
        return daysLate * 0.50; // 50 cents per day
    }

    void displayInfo() const override {
        LibraryItem::displayInfo();
        cout << "Author: " << author << endl;
    }

private:
    string author;
};

class DVD : public LibraryItem {
public:
    DVD(const string& title, int duration) 
        : LibraryItem(title), duration(duration) {}

    double calculateLateFee(int daysLate) const override {
        return daysLate * 1.00; // 1 dollar per day
    }

    void displayInfo() const override {
        LibraryItem::displayInfo();
        cout << "Duration: " << duration << " minutes" << endl;
    }

private:
    int duration;
};

int main() {
    Book book("The Great Gatsby", "F. Scott Fitzgerald");
    DVD dvd("Inception", 148);

    cout << "--- Book Info ---" << endl;
    book.displayInfo();
    cout << "Late Fee (5 days): $" << book.calculateLateFee(5) << endl;

    cout << "\n--- DVD Info ---" << endl;
    dvd.displayInfo();
    cout << "Late Fee (3 days): $" << dvd.calculateLateFee(3) << endl;

    cout << "\nTotal Library Items: " << LibraryItem::totalItems << endl;

    return 0;
}