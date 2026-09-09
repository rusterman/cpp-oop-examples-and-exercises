#include <iostream>
#include <string>

using namespace std;


class User{
    protected:
    string name;
    public:
    User(string name){
        this -> name = name;
    }
    virtual void login(){
        cout << "Login" << endl;
    }
    virtual void logout(){
        cout << "Logout..." << endl;
    }
    virtual void performAction(){
        cout << "Perform Action...." <<endl;
    }
    virtual void viewProfile(){
        cout << "Viewing the profil of " << name << endl;
    }
};
class AdminUser : public User{
    public:
    AdminUser(string name) : User(name){}

};
class Siteuser : public User{
    public:
    Siteuser(string name) : User(name){}
    virtual void postCommet(){
        cout<<"Comment posted by " << name << endl;
    }

};
class ModeratorUser : public AdminUser{
    public:
    ModeratorUser(string name) : AdminUser(name){}
    virtual void moderateContent(){
        cout << "Content moderated by " <<name <<endl;
    }

};
class ManagerUser : public AdminUser{
    public:
    ManagerUser(string name) : AdminUser(name){}
    virtual void manageUsers(){
        cout << "Users managed by " << name << endl;
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


