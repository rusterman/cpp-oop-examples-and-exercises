#include<iostream>
using namespace std;
class BackendService{
    public:
    void connect(){
        cout << "Connected..." <<endl;
    }
    virtual void performTask(){
        cout << "The general task has been completed." <<endl;
    }
};
class DatabaseService : public BackendService{
    public:
    void connect(const string connectionString){
        cout << "Connected to DatabaseService with connectionString" <<endl;
    }
    virtual void performTask()override{
        cout << "Database task completed" <<endl;
    }
};
class APIService : public BackendService{
    public:
    void connect(const string APIKey){
        cout << "Connected to APIService with APIKey"<<endl;
    }
    virtual void performTask()override{
        cout << "APIService task completed" <<endl;
    }
    void connect(){
        cout << "Connected to APIService without APIKey" <<endl;
    }

};

int main(){
    BackendService genericService;
    DatabaseService database;
    APIService api;

    genericService.connect(); 
    genericService.performTask(); 

    database.connect("db_connection_string"); 
    database.performTask();

    api.connect("api_key"); 
    api.performTask(); 

    api.connect(); 
}
