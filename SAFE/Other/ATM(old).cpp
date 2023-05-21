#include <iostream>
#include "clients.cpp"

void exists()
{
    std::string name;
    std::cout << "enter name:" << std::endl;
    std::cin >> name;
    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (customer[i].name == name)
        {
            std::cout << "user exists." << std::endl;
            std::cout << std::endl;
        }
        else if (vip[i].name == name)
        {
            std::cout << "user exists." << std::endl;
            std::cout << std::endl;
        }
        else if (i == SIZE - 1)
        {
            std::cout << "user does not exist." << std::endl;
            std::cout << std::endl;
        }
    }
}

void forgotPassword()
{
    std::string userTemp;
    std::string idTemp;
    std::string numberTemp;
    std::string passTemp;
    std::string passTemp2;

    std::cout << "forgot password..." << std::endl;
    std::cout << std::endl;

    std::cout << "enter username: ";
    std::cin >> userTemp;
    std::cout << std::endl;

    std::cout << "enter id: ";
    std::cin >> idTemp;
    std::cout << std::endl;

    std::cout << "enter number: ";
    std::cin >> numberTemp;
    std::cout << std::endl;

    std::cout << "enter new password: ";
    std::cin >> passTemp;
    std::cout << std::endl;

    std::cout << "confirm new password: ";
    std::cin >> passTemp2;
    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (customer[i].name == userTemp && customer[i].id == idTemp && customer[i].number == numberTemp)
        {
            if (passTemp == passTemp2)
            {
                customer[i].password = passTemp;
                std::cout << "password changed sucessfully." << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << "passwords do not match." << std::endl;
                std::cout << std::endl;
            }
            std::cout << "password has been changed" << std::endl;
            std::cout << std::endl;
        }
        else if (vip[i].name == userTemp && vip[i].id == idTemp && vip[i].number == numberTemp)
        {
            if (passTemp == passTemp2)
            {
                customer[i].password = passTemp;
                std::cout << "password changed sucessfully." << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << "passwords do not match." << std::endl;
                std::cout << std::endl;
            }
        }
        else if (i == SIZE - 1)
        {
            std::cout << "Error: wrong username, ID or number." << std::endl;
            std::cout << std::endl;
        }
    }
}

std::string Find()
{
    std::string x;
    std::string y;
    std::string currUser;
    std::string currPass;

    do
    {
        std::cout << "enter username: ";
        std::cin >> x;
        std::cout << std::endl;

        std::cout << "enter password: ";
        std::cin >> y;
        std::cout << std::endl;

        for (int i = 0; i < SIZE; i++)
        {
            if (customer[i].name == x && customer[i].password == y)
            {
                currUser = customer[i].name;
                currPass = customer[i].password;
                std::cout << "welcome " << currUser << std::endl;
                std::cout << std::endl;
                return currUser;
            }
            else if (vip[i].name == x && vip[i].password == y)
            {
                currUser = vip[i].name;
                currPass = vip[i].password;
                std::cout << "welcome " << currUser << std::endl;
                std::cout << std::endl;
                return currUser;
            }
            else if (i == SIZE - 1)
            {
                std::cout << "Error: wrong username or password." << std::endl;
                std::cout << std::endl;
                return;
            }
        }
    } while (currUser != x && currPass != y);
}

void ATM();

void login()
{
    std::cout << "login..." << std::endl;
    std::cout << std::endl;
    std ::string USER = Find();
    ATM();
}

void Menu()
{
    int x;
    std::cout << "what would you like to do?" << std::endl;
    std::cout << "1. login." << std::endl;
    std::cout << "2. register." << std::endl;
    std::cout << "3. forgot password." << std::endl;
    std::cout << "4. search." << std::endl;
    std::cout << "5. exit." << std::endl;
    std::cout << std::endl;
    std::cout << "Choose: ";
    std::cin >> x;
    std::cout << std::endl;

    switch (x)
    {
    case 1:
        login();
        break;
    case 2:
        Register();
        break;
    case 3:
        forgotPassword();
        break;
    case 4:
        exists();
        break;
    case 5:
        std::cout << "exiting..." << std::endl;
        return;
    default:
        std::cout << "Error: invalid input." << std::endl;
        std::cout << std::endl;
        Menu();
        break;
    }
    Menu();
}