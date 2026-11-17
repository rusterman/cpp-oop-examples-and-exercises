#include<iostream>
#include<string>
using namespace std;
class Book {
private:
    string title;
    string author;
    int year;

public:
   
    Book() {
        title = "";
        author = "";
        year = 0;
    }

   
    Book(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }

    
    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
};
int main(){


    const int librarySize = 5;
    Book library[librarySize];

    cout << "Enter details for " << librarySize << " books:" << endl;
    for (int i = 0; i < librarySize; ++i) {
        string title, author;
        int year;

        cout << "Book " << i + 1 << endl;
        cout << "Title: ";
        getline(cin >> ws, title);
        cout << "Author: ";
        getline(cin >> ws, author);
        cout << "Year: ";
        cin >> year;

        library[i] = Book(title, author, year);
    }

    cout << endl << "Library Contents:" << endl;
    for (int i = 0; i < librarySize; ++i) {
        cout << "Book " << i + 1 << ":" << endl;
        library[i].display();
    }

    

return 0;
}