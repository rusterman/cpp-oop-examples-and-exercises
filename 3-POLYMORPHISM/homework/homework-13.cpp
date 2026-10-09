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
    virtual void connect() const = 0;
};

// MySqlConnection class – bunu final etmək olar, çünki başqa siniflərdən irsi almağa ehtiyac yoxdur
class MySqlConnection final : public DatabaseConnection {
public:
    void connect() const override {
        cout << "Connecting to MySQL database..." << endl;
        // Burada MySQL-ə qoşulma loqikası ola bilər
    }
};

// PostgresConnection class – bunu da final etmək olar
class PostgresConnection final : public DatabaseConnection {
public:
    void connect() const override {
        cout << "Connecting to PostgreSQL database..." << endl;
        // Burada PostgreSQL-ə qoşulma loqikası ola bilər
    }
};

// Database connection factory
class ConnectionFactory {
public:
    // Bu metodları static etmək daha məntiqlidir, çünki obyekt yaratmadan istifadə etmək olar
    static DatabaseConnection* createMySQLConnection() {
        return new MySqlConnection();
    }

    static DatabaseConnection* createPostgresConnection() {
        return new PostgresConnection();
    }
};

int main() {
    // Factory vasitəsilə obyektlər yaradılır
    DatabaseConnection* mysqlConnection = ConnectionFactory::createMySQLConnection();
    DatabaseConnection* postgresConnection = ConnectionFactory::createPostgresConnection();

    mysqlConnection->connect();
    postgresConnection->connect();

    // Yaddaş sızıntısının qarşısını almaq üçün obyektləri silirik
    delete mysqlConnection;
    delete postgresConnection;

    return 0;
}
