#include <iostream>
#include <string>

using namespace std;


/*
    Exercise: Backend Service Hierarchy

    Create a C++ program that models a hierarchy of backend services. 
    You will define a base class BackendService with two methods: connect() and performTask(). 
    Then, create two derived classes, DatabaseService and APIService, each with their own implementations of these methods. 
    Finally, introduce method overloading and method hiding in the derived classes.

    Here are the steps to complete the exercise:

    1. Define a base class BackendService with the following methods:
     - void connect(): This method should print a message indicating that it's connected to a generic backend service.
     - virtual void performTask(): This method should print a message indicating that it's performing a generic task.

    2. Create a derived class DatabaseService that inherits from BackendService. 
    In the DatabaseService class:
     - Overload the connect() method to accept a std::string parameter connectionString. Print a message indicating that it's connected to a database with the given connection string.
     - Override the performTask() method to print a message indicating that it's performing a database-specific task.

    3. Create a derived class APIService that inherits from BackendService. 
    In the APIService class:
     - Overload the connect() method to accept a std::string parameter apiKey. 
       Print a message indicating that it's connected to an API with the given API key.
     - Override the performTask() method to print a message indicating that it's performing an API-specific task.
     - Introduce method hiding by adding a new connect() method without parameters. 
       In this method, print a message indicating that it's connected to an API without an API key.

    4. In the main() function:
     - Create instances of BackendService, DatabaseService, and APIService.
     - Call the connect() and performTask() methods on each of these instances 
       to observe method overloading, overriding, and method hiding.

    Your program should demonstrate the different behaviors of these methods based on the class hierarchy.
*/


/*  Solution:  */
class BackendService {
public:
    void connect() {
        cout << "Connected to a generic backend service" << endl;
    }
    virtual void performTask() {
        cout << "Performing a generic backend task" << endl;
    }
    virtual ~BackendService() {}
};

class DatabaseService : public BackendService {
public:
    void connect(const string& connectionString) {
        cout << "Connected to database with connection string: " << connectionString << endl;
    }
    void performTask() override {
        cout << "Performing a database-specific task" << endl;
    }
};

class APIService : public BackendService {
public:
    void connect(const string& apiKey) {
        cout << "Connected to API with API key: " << apiKey << endl;
    }
    void performTask() override {
        cout << "Performing an API-specific task" << endl;
    }
    void connect() { 
        cout << "Connected to API without API key" << endl;
    }
};




int main() {

    /*    Example Usage    */
    BackendService genericService;
    DatabaseService database;
    APIService api;

    genericService.connect(); // Calls the base class method
    genericService.performTask(); // Calls the base class method

    database.connect("db_connection_string"); // Calls the derived class method (overloaded)
    database.performTask(); // Calls the derived class method (overridden)

    api.connect("api_key"); // Calls the derived class method (overloaded with a parameter)
    api.performTask(); // Calls the derived class method (overridden)

    // Method hiding example
    api.connect(); // Calls the derived class method (hiding the base class method)

}
