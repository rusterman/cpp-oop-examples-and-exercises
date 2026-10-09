#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    Exercise: Library Management System

    In this exercise, we'll create a simple Library Management System 
    using object-oriented programming and inheritance in C++.
    This exercise simulates a real-world application in software engineering where 
    different types of library items are managed within a library system.

    Background:
    Imagine you are developing a library management software for a university. 
    The software needs to handle two types of items: Books and DVDs. 
    Both items have common properties such as title, author/director, and publication year, 
    but they also have some specific properties. 
    Books have an ISBN (International Standard Book Number) while DVDs have a runtime.

    Requirements:

    1. Create a base class called LibraryItem with the following attributes and methods:
            Attributes: title, authorOrDirector, publicationYear
            Methods: displayInfo() - Display the common attributes of the library item.
    
    Note! ~ Make displayInfo method "virtual" in parent class,
    which is the part of polymorphism that will be described in the next chapter.

    ~ "virtual void displayInfo() {...}" - Virtual methods will be described broadly in the next chapter.

    2. Derive two classes Book and DVD from the LibraryItem base class. 
        Add the following attributes and methods to each derived class:
            Book class:
                Additional attribute: isbn
                Additional method: displayInfo() - Override the base class method to include ISBN.
            DVD class:
                Additional attribute: runtime
                Additional method: displayInfo() - Override the base class method to include runtime.

    3. Create a class called Library which can store an array/vector of pointers to LibraryItem objects. 
    It should have the following methods:
        addItem() - Add a new library item to the collection.
        displayAllItems() - Display information about all items in the library.
*/

/*
    Explanation:
        This exercise demonstrates the concept of inheritance in C++ where the Book and DVD classes 
        inherit properties and methods from the LibraryItem base class. 
        The Library class manages a collection of library items, both books and DVDs. 
*/


/* Solution */



int main() {

    /*      Example usage:     */
    Library library;

    Book book("The Great Gatsby", "F. Scott Fitzgerald", 1925, "978-3-16-148410-0");
    DVD  dvd("Inception", "Christopher Nolan", 2010, 148);

    library.addItem(&book);
    library.addItem(&dvd);

    library.displayAllItems();

    /* 
        [Sample Output]

        Title: The Great Gatsby
        Author/Director: F. Scott Fitzgerald
        Publication Year: 1925
        ISBN: 978-3-16-148410-0
        ------------------------
        Title: Inception
        Author/Director: Christopher Nolan
        Publication Year: 2010
        Runtime: 148 minutes
        ------------------------
    */

    return 0;
}