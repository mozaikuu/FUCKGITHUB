#include <iostream>
#include "Clients.cpp"

void Register();
void Menu();

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
    bool changePass = false;

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

    std::cout << "your password was: ";
    for (int i = 0; i < SIZE; i++)
    {
        if (customer[i].name == userTemp && customer[i].id == idTemp && customer[i].number == numberTemp)
        {
            std::cout << customer[i].password << std::endl;
            std::cout << std::endl;
            changePass = true;
            break;
        }
        else if (vip[i].name == userTemp && vip[i].id == idTemp && vip[i].number == numberTemp)
        {
            std::cout << vip[i].password << std::endl;
            std::cout << std::endl;
            changePass = true;
            break;
        }
        else if (i == SIZE - 1)
        {
            std::cout << "user not found..." << std::endl;
            std::cout << std::endl;
            Menu();
        }
    }
    std::cout << "change pass? (1 = y / 0 = N): ";
    std::cout << std::endl;
    std::cin >> changePass;

    if (changePass == true)
    {
        std::cout << "enter new password: ";
        std::cin >> passTemp;
        std::cout << std::endl;

        std::cout << "confirm new password: ";
        std::cin >> passTemp2;
        std::cout << std::endl;

        if (passTemp == passTemp2)
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (customer[i].name == userTemp && customer[i].id == idTemp && customer[i].number == numberTemp)
                {
                    customer[i].password = passTemp;
                    std::cout << "password changed." << std::endl;
                    std::cout << std::endl;
                    Menu();
                }
                else if (vip[i].name == userTemp && vip[i].id == idTemp && vip[i].number == numberTemp)
                {
                    vip[i].password = passTemp;
                    std::cout << "password changed." << std::endl;
                    std::cout << std::endl;
                    Menu();
                }
                else if (i == SIZE - 1)
                {
                    std::cout << "user not found..." << std::endl;
                    std::cout << std::endl;
                    Menu();
                }
            }
        }
        else
        {
            std::cout << "passwords do not match..." << std::endl;
            std::cout << std::endl;
            forgotPassword();
        }
    }
    else
    {
        exit(0);
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
        std::cout << "press enter while empty to exit." << std::endl;

        std::cout << "\tenter username: ";
        std::cin >> x;

        std::cout << "\tenter password: ";
        std::cin >> y;
        std::cout << std::endl;

        if (x == "" || y == "")
        {
            exit(0);
        }

        for (int i = 0; i < SIZE; i++)
        {
            if (customer[i].name == x && customer[i].password == y)
            {
                currUser = customer[i].name;
                currPass = customer[i].password;
                return currUser;
            }
            else if (vip[i].name == x && vip[i].password == y)
            {
                currUser = vip[i].name;
                currPass = vip[i].password;
                return currUser;
            }
            else if (i == SIZE - 1)
            {
                std::cout << "user not found..." << std::endl;
                std::cout << std::endl;
            }
        }
    } while (x != currUser || y != currPass);
}

std::string login()
{
    std::cout << "Logging in..." << std::endl;
    std::cout << std::endl;
    std::string name = Find();
    return name;
}

void Menu()
{
    int x;
    std::cout << "menu." << std::endl;
    std::cout << "1. login." << std::endl;
    std::cout << "2. register." << std::endl;
    std::cout << "3. forgot password." << std::endl;
    std::cout << "4. Search." << std::endl;
    std::cout << "5. exit." << std::endl;
    std::cout << std::endl;
    std::cout << "enter number: ";
    std::cin >> x;
    std::cout << std::endl;

    switch (x)
    {
    case 1:
        ATM();
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
        break;
    default:
        std::cout << "invalid input..." << std::endl;
        std::cout << std::endl;
        Menu();
        break;
    }
    Menu();
}