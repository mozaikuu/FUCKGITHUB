#include <iostream>
#include "Classes.cpp"

// void GUI();

void Find()
{

    std::string x;
    std::string y;
    std::string currUser;
    std::string currPass;
    // do
    // {
    // std::cout << "\tusername: ";
    // std::cin >> x;
    // std::cout << "\tpassword: ";
    // std::cin >> y;
    std::cout << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "user: " + customer[i].password << std::endl;
        // std::string user = customer[i].name;
        // std::string pass = customer[i].password;
        // currUser = user;
        // currPass = pass;
        // std::cout << "user: " + user << std::endl;
        // if (x == user && y == pass)
        // {
        //     std::cout << "welcome " + customer[i].name << std::endl;
        // }
        // else if ((x != user || y != pass) && i == SIZE - 1)
        // {
        //     std::cout << "invalid username or password..." << std::endl;
        // }
    }
    // } while (true);
}
// cip
void login()
{

    std::cout << "logging in..." << std::endl;

    Find();
    // Menu();
    //  GUI();
};

//*** change passwords ***
//*** unique passwords ***
//*** add/remove users ***
