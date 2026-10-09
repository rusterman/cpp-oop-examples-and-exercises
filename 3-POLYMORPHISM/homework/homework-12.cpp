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
// Base class for user authentication
class Authenticator {
public:
    virtual bool authenticate(const string& username, const string& password) const = 0;
};

// Mark BasicAuthenticator as final (so it cannot be inherited)
class BasicAuthenticator final : public Authenticator {
public:
    BasicAuthenticator(const string& validUsername, const string& validPassword)
        : validUsername_(validUsername), validPassword_(validPassword) {}

    bool authenticate(const string& username, const string& password) const override {
        return username == validUsername_ && password == validPassword_;
    }

private:
    string validUsername_;
    string validPassword_;
};

// If you try to inherit from BasicAuthenticator, it will cause a compilation error
/*
class CustomAuthenticator : public BasicAuthenticator {
public:
    CustomAuthenticator(const string& validUsername, const string& validPassword)
        : BasicAuthenticator(validUsername, validPassword) {}
};
*/

int main() {
    BasicAuthenticator basicAuth("admin", "admin123");

    if (basicAuth.authenticate("admin", "admin123")) {
        cout << "Authentication successful!" << endl;
    } else {
        cout << "Authentication failed!" << endl;
    }

    // Uncommenting this will cause an error if BasicAuthenticator is final
    /*
    CustomAuthenticator customAuth("user", "pass");
    if (customAuth.authenticate("user", "pass")) {
        cout << "Authentication successful!" << endl;
    } else {
        cout << "Authentication failed!" << endl;
    }
    */

    return 0;
}
