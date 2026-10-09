#include <iostream>
#include <string>

using namespace std;

/*
    Polymorphism

    15. Abstract Classes as Interfaces
*/

/*
    Exercise: Backend Data Storage Interface

    Instructions:

    1. Define an abstract interface named DataStorage with the following pure virtual functions:
        void storeData(const string& data): This function should represent storing data.
        string retrieveData(): This function should represent retrieving data.
        Implement two concrete classes that inherit from the DataStorage interface:

    2. FileStorage: Implement the functions to store and retrieve data using a file.
        DatabaseStorage: Implement the functions to store and retrieve data using a database.
        In the main function:

    3. Create an instance of FileStorage, store and retrieve some data.
    4. Create an instance of DatabaseStorage, store and retrieve some data.
*/


// Abstract interface for data storage
class DataStorage {
public:
    virtual void storeData(const string& data) = 0;     // pure virtual
    virtual string retrieveData() = 0;                  // pure virtual
    virtual ~DataStorage() {}
};

// Concrete class implementing data storage using a file
class FileStorage : public DataStorage {
private:
    string fileData;
public:
    void storeData(const string& data) override {
        fileData = data;
        cout << "Data stored in file: " << data << endl;
    }

    string retrieveData() override {
        return fileData;
    }

    ~FileStorage() {
        cout << "FileStorage Destructor" << endl;
    }
};

// Concrete class implementing data storage using a database
class DatabaseStorage : public DataStorage {
private:
    string dbData;
public:
    void storeData(const string& data) override {
        dbData = data;
        cout << "Data stored in database: " << data << endl;
    }

    string retrieveData() override {
        return dbData;
    }

    ~DatabaseStorage() {
        cout << "DatabaseStorage Destructor" << endl;
    }
};

int main() {
    // Using FileStorage
    FileStorage fileStorage;
    fileStorage.storeData("FileStorage Data");
    cout << "FileStorage: " << fileStorage.retrieveData() << endl;

    // Using DatabaseStorage
    DatabaseStorage databaseStorage;
    databaseStorage.storeData("DatabaseStorage Data");
    cout << "DatabaseStorage: " << databaseStorage.retrieveData() << endl;

    return 0;
}
