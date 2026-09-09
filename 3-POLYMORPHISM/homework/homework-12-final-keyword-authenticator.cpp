#include <iostream>

using namespace std;

/*
    Polymorphism

    12. Final

    --- Final Class ---
*/


/*
    In this exercise, the task for the student is to decide whether the BasicAuthenticator class should be marked as final or not. 
    They should also attempt to create a derived class (CustomAuthenticator) and observe whether the compiler allows it. 
    Encourage them to uncomment the relevant lines, compile the code, 
    and analyze the compilation results to understand the concept of marking a class as final.
*/

// Base class for user authentication
class Authenticator{
    public:
        // TODO: Declare a pure virtual function for authentication
        virtual bool authenticate(const string& username, const string& password) const = 0;
};


// TODO: Decide whether to mark the following class as final or not
class BasicAuthenticator final : public Authenticator{
    public:
        BasicAuthenticator(const string& validUsername, const string& validPassword)
            : validUsername_(validUsername), validPassword_(validPassword) {}

        // TODO: Implement the authenticate function
        bool authenticate(const string& username, const string& password) const override {
            return username == validUsername_ && password == validPassword_;
        }

    private:
        string validUsername_;
        string validPassword_;
};

// TODO: Create a derived class (you can name it CustomAuthenticator) that attempts to extend BasicAuthenticator
// Uncommenting the following lines should result in a compilation error if BasicAuthenticator is marked as final

    /*class CustomAuthenticator : public BasicAuthenticator {
    public:
        CustomAuthenticator(const string& validUsername, const string& validPassword)
            : BasicAuthenticator(validUsername, validPassword) {}
    };*/  

    /*BasicAuthenticator bu sinifin qarsisina final acar sozu yazilanda ondan inherit etmek mumkun olmur.ona gore de yeni yazilan CustomAuthenticator
    klassi da xeta verecek.Main hissede yaazilmis obyektde xeta verecek cunki hemin obyekt BasicAuthenticatordan inherit etmeye calisir.Amma  final class
    olmasa ondan inherit etmek mumkun olan main hissede yazdigimiz obyektde mumkun olar ve her sey problemsiz isleyer.*/



int main() {

    // TODO: Create an instance of BasicAuthenticator
    BasicAuthenticator basicAuth("admin", "admin123");

    // TODO: Authenticate using the BasicAuthenticator
    if (basicAuth.authenticate("admin", "admin123")) {
        cout << "Authentication successful!" << endl;
    } else {
        cout << "Authentication failed!" << endl;
    }

    // TODO: Create an instance of CustomAuthenticator (if allowed) and attempt authentication

    
        /*CustomAuthenticator customAuth("user", "pass");

        if (customAuth.authenticate("user", "pass")) {
            cout << "Authentication successful!" << endl;
        } else {
            cout << "Authentication failed!" << endl;
        }
        */

    return 0;
}
