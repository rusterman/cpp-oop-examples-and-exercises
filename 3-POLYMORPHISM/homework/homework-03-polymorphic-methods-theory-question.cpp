#include <iostream>

using namespace std;

/*
    Note!

    Please note that you should not write code or implement solutions; 
    just provide your answers to the following question:
*/


/*
    Scenario:

    You are developing a C++ program to simulate a car race. 
    The program will have a base class called Vehicle and two derived classes, Car and Motorcycle. 
    The Vehicle class will have methods to get and set the vehicle's speed, direction, and position. 
    The Car and Motorcycle classes will inherit these methods from the Vehicle class and may also have their own unique methods.

    Exercise:

    Decide which of the following methods should be polymorphic in the Vehicle class:
       - getSpeed()
       - setSpeed()
       - getDirection()
       - setDirection()
       - getPosition()
       - move()
*/

/*
    Solution:
    Burda cavab move() methodudur. Cunki hereket mentiqi motorcycle da ve car da ferqlidir.Diger getter setter methodlar ise saddece qiymet qebul edib qiymet qaytarir.
    Umumiyyetle ekser vaxt getter/setter funksiyalari polimorfik olmur.(istisnalar xaric).
        
*/



/*
    Exercise_2: Polymorphic Methods in E-Commerce

    Scenario:

    You are developing an e-commerce platform. 
    The platform will have a base class called Product and several derived classes, such as Book, Electronic, and Clothing. 
    The Product class will have methods to get and set the product's name, price, and description. 
    The derived classes will inherit these methods from the Product class and may also have their own unique methods.

    Exercise:

    Decide which of the following methods should be polymorphic in the Product class:
       - getName()
       - setName()
       - calculateTax()
       - calculateShipping()
       - getPrice()
       - setPrice()
       - getDescription()
       - setDescription()
*/

/*
    Solution:
    Burda cavab calculateTax() ,  calculateShipping() dir.Bu methodlarin mentiqi butun child klasslarda ferqlidir.Meselen Book klassi olsun bezi olkelerde 
    kitablardan vergi almirlar bezilerinde alinir.Bezi olkelerde elektronik esyalardan vergi cox alinir bezi lkelrede ise az ve s.Diger getter/setter funksiyalari
    ise ancaq qiymet qebul edib qiymet qaytarir.
        
*/



/*
    Exercise_3: Polymorphic Methods in Backend Development

    Scenario:

    You are developing a backend for a social media platform. 
    The backend will have a base class called User and several derived classes, 
    such as RegularUser, ContentCreator, and Administrator. 
    The User class will have methods to get and set the user's name, email address, and profile picture. 
    The derived classes will inherit these methods from the User class and may also have their own unique methods.

    Exercise:

    Decide which of the following methods should be polymorphic in the User class:
       - getName()
       - manageUsers()
       - setName()
       - postContent()
       - getEmailAddress()
       - setEmailAddress()
       - getProfilePicture()
       - deleteContent()
       - setProfilePicture()
*/

/*
    Solution:
    Burda cavab  postContent() , deleteContent() dir.
    manageUsers() - polimorfik deyil.Sadece adminstrator sinifine aid olan bir methoddur. 
    postContent() - post un  movzusu meselen regularUser de insanar metn mesaj paylasa bilerler contentCreator sinifinin numayendeleri sekil video paylasa biler.
    deleteContent() - bu da child classlard ferqlidir.meselen regular user dekiler oz mesajlarin ve yazdiqlari metni sile bilerler amma content creator lar oz videolarin
    sekillerin ve postlarinin altina yazilmis reyleri sile bilerler.
    digerleri ise getter/setter methodlaridir ki onlar ancaq melumat qebul edib qaytarirlar.Amma polimorfik olanlar child classlarda coxuzlu ve coxformali olurlar.
    yeni temelde eynidiler amma child classlarda ferqli esas emliyyatin ferqli formasin aparirlar.

    
*/



int main() {


}
