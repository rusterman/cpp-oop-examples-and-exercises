#include <iostream>
#include <string>
#include <vector>
using namespace std;
class LibraryItem{
    protected: 
    string title;
    string authorOrDirector;
    int publicationYear;
    public:
    LibraryItem(string title , string authorOrDirector , int publicationYear){
        this -> title = title;
        this -> authorOrDirector = authorOrDirector;
        this -> publicationYear = publicationYear;
    }
    void virtual DisplayInfo(){
        cout << "Title: " << title <<endl;
        cout << "Author or Director: " << authorOrDirector <<endl;
        cout << "Publication Year: " << publicationYear <<endl;
    }

};
class Book : public LibraryItem{
    private:
    string isbn;
    public:
    Book(string title , string authorOrDirector , int publicationYear , string isbn) : LibraryItem(title , authorOrDirector , publicationYear){
        this -> isbn = isbn;
    }
    void DisplayInfo(){
        LibraryItem ::DisplayInfo();
        cout << "ISBN: " << isbn << endl;
    }

};
class DVD : public LibraryItem{
    private: 
    int runtime;
    public:
    DVD(string title , string authorOrDirector , int publicationYear , int runtime) : LibraryItem(title , authorOrDirector , publicationYear){
        this -> runtime = runtime;
    }
    void DisplayInfo(){
        LibraryItem :: DisplayInfo();
        cout << "Runtime: " << runtime << endl;
    }
};
class Library{
    private:
    vector<LibraryItem*>items;
    public:
    void addItem(LibraryItem*item){
        items.push_back(item);
    }
    void displayAllItems(){
        for(int i = 0 ; i<items.size() ; i++){
            items[i] ->DisplayInfo();
            cout << "------------" <<endl;
        }
    }


};

int main(){
    system("cls");
    Library library;

    Book book("The Great Gatsby", "F. Scott Fitzgerald", 1925, "978-3-16-148410-0");
    DVD  dvd("Inception", "Christopher Nolan", 2010, 148);

    library.addItem(&book);
    library.addItem(&dvd);

    library.displayAllItems();
    return 0;

}
