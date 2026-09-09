#include<iostream>
using namespace std;
class LibraryItem{
    private:
    string title;
    int year;
    bool checkedout;
    public:
    LibraryItem(string title , int year , bool checkedout){
        this -> title = title;
        this -> year = year;
        this -> checkedout = checkedout;
    }
    ~LibraryItem(){};
    virtual void checkout(){
        checkedout = true;
    }
    virtual void checkin(){
        checkedout = false;    /* checkout , ve check in funksiyalarinin her hansi bir fealiyyeti yoxdur menim kodumda.Sadece tapsirirqda yazin deyilib deye yazmisam
        */
    }
    virtual void displayInfo(){
        cout << "Title: " << title << endl;
        cout << "Year: " << year << endl;
        cout << "Status: " << (checkedout ? "Checked out" : "Checked in") << endl;
    }
};
class Book : public LibraryItem{
    private:
    string author;
    public:
    Book(string title , int year , bool checkedout , string author) : LibraryItem(title , year , checkedout){
        this -> author = author;
    }
    virtual void displayInfo()override{
        LibraryItem :: displayInfo();
        cout << "Author: " << author << endl;
    }

};
class EBook : public LibraryItem{
    private:
    string format;
    public:
    EBook(string title , int year , bool checkedout , string format) : LibraryItem(title , year , checkedout){
        this -> format = format;
    }
    virtual void displayInfo(){
        LibraryItem :: displayInfo();
        cout << "Format: " << format <<endl;
    }
};
class AudioBook : public LibraryItem{
    private:
    string artist;
    public:
    AudioBook(string title , int year , bool checkedout , string artist) : LibraryItem(title , year , checkedout){
        this -> artist = artist;
    }
    virtual void displayInfo(){
        LibraryItem :: displayInfo();
        cout << "Artist: " << artist << endl;
    }
};
int main(){
    system("cls");
    Book book1("The Karamazov Brothers" , 1870 , true , "Fyodr Dostoevski"); // burda true - (Checked out un true oldugun gosterir) false ise checked in.
    EBook ebook1("Ses" , 1970 , false , "Sabahattin Ali");
    AudioBook audiobook1("Chess" , 1800 , true , "Stefan Zweig");
    LibraryItem * items[] = {&book1 , &ebook1 , &audiobook1};
    for(int i = 0 ; i < 3 ; i++){
        items[i] -> displayInfo();
        cout << "--------------" <<endl;
    }
   

}
