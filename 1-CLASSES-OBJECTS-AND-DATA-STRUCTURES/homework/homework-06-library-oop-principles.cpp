#include <iostream>
using namespace std;
class Book{
    private:
    string title;
    string author;
    int year;
    public:
    Book(string title = "Unknown" , string author = "Unknown" , int year = 0){
        this -> title = title;
        this -> author = author;
        this -> year = year;
    }
    void Display(){
        cout << title << endl;
        cout << author << endl;
        cout << year << endl;
    }

};

int main() {
    const int librarySize = 5;
    Book library[librarySize];
    for(int i = 0 ; i < librarySize ; i++){
        string title1 , author1;
        int year1;
        cout << i + 1 <<  "ci kitabin adi: ";
        getline(cin , title1);
        cout << i + 1 << "ci kitabin muellifi: ";
        getline(cin,author1);
        cout  << i+1 <<  "ci kitabin nesr olundugu il: ";
        cin >> year1;
        cin.ignore();
        library[i] = Book(title1 , author1 ,year1);
    }
    for(int i = 0 ; i < librarySize ; i++){
        cout << i + 1 << "ci kitab haqqinda melumat: " << endl;
        library[i].Display();
    }




}
