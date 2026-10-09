#include <iostream>
#include <string>

using namespace std;


/*
    Polymorphism

    11. Inheritance and Polymorphism at different levels
*/


/*
    Exercise: Enhancing User Hierarchy

    1. Create a ModeratorUser class:
        Create a new class ModeratorUser that inherits from AdminUser. 
        A moderator user has the ability to moderate content.
    2. Create a ManagerUser class:
        Create a new class ManagerUser that inherits from AdminUser. 
        A manager user has the ability to manage users.
    3. Implement new functions:
        ~ Add a new virtual function in User called viewProfile that prints a message like "Viewing the profile of [username]."
        ~ Add a new virtual function in SiteUser called postComment that prints a message like "Comment posted by [username]."
        ~ Add a new virtual function in ModeratorUser called moderateContent that prints a message like "Content moderated by [username]."
        ~ Add a new virtual function in ManagerUser called manageUsers that prints a message like "Users managed by [username]."
    4. Compile and run your program: Make sure it compiles and runs without errors.
*/



/*
    Solution
*/ class User {
protected:
    string username;
public:
    User(const string& uname) : username(uname) {}
    virtual ~User() {}

    virtual void login() {
        cout << username << " logged in." << endl;
    }
    virtual void logout() {
        cout << username << " logged out." << endl;
    }
    virtual void performAction() {
        cout << username << " performed a generic action." << endl;
    }
    virtual void viewProfile() {
        cout << "Viewing the profile of " << username << "." << endl;
    }
};

class SiteUser : public User {
public:
    SiteUser(const string& uname) : User(uname) {}
    void performAction() override {
        cout << username << " is browsing the site." << endl;
    }
    virtual void postComment() {
        cout << "Comment posted by " << username << "." << endl;
    }
};

class AdminUser : public SiteUser {
public:
    AdminUser(const string& uname) : SiteUser(uname) {}
    void performAction() override {
        cout << username << " is performing admin tasks." << endl;
    }
};

class ModeratorUser : public AdminUser {
public:
    ModeratorUser(const string& uname) : AdminUser(uname) {}
    void performAction() override {
        cout << username << " is moderating content." << endl;
    }
    virtual void moderateContent() {
        cout << "Content moderated by " << username << "." << endl;
    }
};

class ManagerUser : public AdminUser {
public:
    ManagerUser(const string& uname) : AdminUser(uname) {}
    void performAction() override {
        cout << username << " is managing users." << endl;
    }
    virtual void manageUsers() {
        cout << "Users managed by " << username << "." << endl;
    }
};



int main() {

    /*  Example usage:  */ 
    User* user1 = new ModeratorUser("ModUser123");
    User* user2 = new ManagerUser("ManagerUser456");

    user1->login();
    user1->performAction();
    user1->viewProfile();
    user1->logout();

    user2->login();
    user2->performAction();
    user2->viewProfile();
    user2->logout();

    // Specific actions for ModeratorUser and ManagerUser
    ModeratorUser* modUser = dynamic_cast<ModeratorUser*>(user1);
    if (modUser) {
        modUser->moderateContent();
    }

    ManagerUser* managerUser = dynamic_cast<ManagerUser*>(user2);
    if (managerUser) {
        managerUser->manageUsers();
    }

    delete user1;
    delete user2;
}


