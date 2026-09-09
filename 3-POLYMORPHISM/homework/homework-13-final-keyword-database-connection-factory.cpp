#include <iostream>
#include <string>

using namespace std;

/*
    Polymorphism

    12. Final

    --- Final Class ---
*/

/*
    Analyze the code below and complete TODO list
*/

// Base class representing a database connection
class DatabaseConnection {
    public:
    virtual ~DatabaseConnection() = default;
        // Establishes a connection to the database
        virtual void connect() const = 0;
};

// TODO: Decide whether to mark the following class as final or not
class MySqlConnection final : public DatabaseConnection {
    public:
        void connect() const override {
            cout << "Connecting to MySQL database..." << endl;
            // TODO: Implement connection logic for MySQL
        }
};

// TODO: Decide whether to mark the following class as final or not
class PostgresConnection final : public DatabaseConnection {
    public:
        void connect() const override {
            cout << "Connecting to PostgreSQL database..." << endl;
            // TODO: Implement connection logic for PostgreSQL
        }
};

// Database connection factory
class ConnectionFactory {
    public:
        // TODO: Decide whether to mark the following methods as static or not
        // Factory method to create a MySQL connection
        static DatabaseConnection* createMySQLConnection() {
            return new MySqlConnection();
        }

        // Factory method to create a PostgreSQL connection
        static DatabaseConnection* createPostgresConnection() {
            return new PostgresConnection();
        }
}; // Bu methodlari static etmek mentiqlidir cunki hem main hissede kodu sadelesdirmek olar obyekt yaratmamis bir basa cagirmaq mumkun olar.Hemde onun meberi yoxdu
// sadece PostgreConnection() ve ya MySqlConnection() baglantisini qaytaran bir nov servis funksiyasidir. 


int main() {

    // TODO: Create instances of database connections using the factory
    ConnectionFactory factory;
    DatabaseConnection* mysqlConnection = factory.createMySQLConnection();
    DatabaseConnection* postgresConnection = factory.createPostgresConnection();
    DatabaseConnection* postgresConnection1 = factory.createMySQLConnection();
    ConnectionFactory::createMySQLConnection(); // bele de cagirmaq olar meselen daha sade

    // TODO: Decide whether to uncomment the following lines to delete instances
    delete mysqlConnection;
    delete postgresConnection;
    delete postgresConnection1;

    return 0;
}
