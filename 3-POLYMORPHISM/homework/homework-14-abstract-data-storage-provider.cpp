#include <iostream>
#include <string>

using namespace std;
class DataStorageProvider {
    public:
    int attemp = 0;
    virtual void storeData(string name) const = 0;
    void logStorageAttempt(string name){
        cout << "Storage attempt for data: " << name << " logged." << endl;
    }
};
class RelationalDatabaseStorage : public DataStorageProvider {
    public:
    void storeData(string name) const override{
        cout << "Storing data in a relational database: " << name <<endl;
    }
};
class CloudNoSQLStorage : public DataStorageProvider {
    public:
    void storeData(string name) const override{
        cout << "Storing data in a cloudNoSql database: "<< name <<endl;
    }
};
int main(){
    RelationalDatabaseStorage relational1;
    CloudNoSQLStorage cloud1;

    relational1.storeData("Sample data 1");
    relational1.logStorageAttempt("Sample data 1");

    cout << endl;

    cloud1.storeData("Sample data 2");
    cloud1.logStorageAttempt("Sample data 2");



}
