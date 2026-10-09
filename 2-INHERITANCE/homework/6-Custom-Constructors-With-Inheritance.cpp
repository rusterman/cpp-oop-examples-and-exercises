#include <iostream>
#include <string>

using namespace std;


/*
    Exercise Title: Understanding Custom Constructors with Inheritance
*/


/*
    Tasks:

    1. In the below code describe the purpose of the GameObject class. 
    What common functionality does it provide for its derived classes?

    2. Explain the concept of inheritance as demonstrated in the code. 
    How are the Player, Enemy, and Character classes related to the GameObject class?

    3. Identify and describe the purpose of the constructors in the derived classes (Player, Enemy, Character). 
    How do they initialize the member variables of the derived classes and the base class?

    4. In the main function, three objects are created: player, enemy, and character. 
    Explain how these objects are constructed using the provided constructors.

    5. Describe the benefits of using inheritance in this scenario. 
    How does it contribute to code organization and reusability?

    6. Imagine you need to add a new class called Weapon that inherits from GameObject and has an additional attribute called damage. 
    Extend the code to include the Weapon class and demonstrate its usage in the main function.

    7. Modify the Character class to include an additional attribute, 
    such as experience, and update its constructor and displayInfoCharacter method accordingly. 
    Reflect on how these changes affect the overall structure of the program.

    8. Discuss potential improvements or alternative approaches that 
    could be taken to design a similar system with better maintainability and extensibility.
*/



class GameObject {
    public:
        GameObject(const string& name) : name(name) {
            // Common initialization for all game objects
        }

        void displayInfo() {
            cout << "Name: " << name << "\n";
        }

    private:
        string name;
};


class Player : public GameObject {
    public:
        Player(const string& name, int health) : GameObject(name), health(health) {
            // Specific initialization for players
        }

        void displayInfoPlayer() {
            displayInfo();
            cout << "Health: " << health << "\n";
        }

    private:
        int health;
};


class Enemy : public GameObject {
    public:
        Enemy(const std::string& name, int damage) : GameObject(name), damage(damage) {
            // Specific initialization for enemies
        }

        void displayInfoEnemy() {
            displayInfo();
            cout << "Damage: " << damage << "\n";
        }

    private:
        int damage;
};


class Character : public GameObject {
    public:
        Character(const std::string& name, int level) : GameObject(name), level(level) {
            // Specific initialization for characters
        }

        void displayInfoCharacter() {
            displayInfo();
            cout << "Level: " << level << "\n";
        }

    private:
        int level;
};


int main() {

    system("clear");

    /*   Example Usage   */
    Player player("Hero", 100);
    Enemy enemy("Goblin", 20);
    Character character("Adventurer", 5);

    player.displayInfoPlayer();
    cout << endl;

    enemy.displayInfoEnemy();
    cout << endl;

    character.displayInfoCharacter();

    /*
        [Output]
        
        Name: Hero
        Health: 100

        Name: Goblin
        Damage: 20

        Name: Adventurer
        Level: 5
    */

    return 0;
}