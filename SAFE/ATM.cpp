#include <iostream>
#include "Clients.cpp"

std::string Find();
std::string login();

int checkBalance(std::string name)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (customer[i].name == name)
        {
            std::cout << "Your Balance is: " << customer[i].balance << std::endl;
            std::cout << std::endl;
            return customer[i].balance;
        }
        else if (vip[i].name == name)
        {
            std::cout << "Your Balance: " << vip[i].balance << std::endl;
            std::cout << std::endl;
            return customer[i].balance;
        }
    }
}

bool isBroke(std::string name)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (customer[i].name == name)
        {
            if (customer[i].balance <= 0)
            {
                std::cout << "You are broke..." << std::endl;
                std::cout << std::endl;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (vip[i].name == name)
        {
            if (vip[i].balance <= 0)
            {
                std::cout << "You are broke..." << std::endl;
                std::cout << std::endl;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

void deposit(std::string name)
{
    int amount;
    std::cout << "enter amount: ";
    std::cin >> amount;
    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (customer[i].name == name)
        {
            std::cout << "Deposit successfully..." << std::endl;
            std::cout << "Your new balance is: " << vip[i].balance << std::endl;
            std::cout << std::endl;
        }
        else if (vip[i].name == name)
        {
            vip[i].balance += amount;
            std::cout << "Deposit successfully..." << std::endl;
            std::cout << "Your new balance is: " << vip[i].balance << std::endl;
            std::cout << std::endl;
        }
    }
}

void withdraw(std::string name)
{
    int amount;
    checkBalance(name);
    std::cout << "enter amount: ";
    std::cin >> amount;
    std::cout << std::endl;

    // FIXME: I cant steal from the bank
    for (int i = 0; i < SIZE; i++)
    {
        if (customer[i].name == name && isBroke(name) != true)
        {
            int netAmount;

            if (amount > customer[i].balance)
            {
                netAmount = customer[i].balance;
                customer[i].balance -= netAmount;
                std::cout << "withdraw successful..." << std::endl;
                std::cout << "You took: " << netAmount << std::endl;
                std::cout << "Your balance is: " << (customer[i].balance) << std::endl;
            }
            else
            {
                customer[i].balance -= amount;
                std::cout << "withdraw successful..." << std::endl;
                std::cout << "You took: " << amount << std::endl;
                std::cout << "Your balance now is: " << (customer[i].balance) << std::endl;
            }
            std::cout << std::endl;
        }
        else if (vip[i].name == name && isBroke(name) != true)
        {
            int netAmount;

            if (amount > vip[i].balance)
            {
                netAmount = vip[i].balance;
                vip[i].balance -= netAmount;
                std::cout << "withdraw successful..." << std::endl;
                std::cout << "You took: " << netAmount << std::endl;
                std::cout << "Your balance is: " << (vip[i].balance) << std::endl;
            }
            else
            {
                vip[i].balance -= amount;
                std::cout << "withdraw successful..." << std::endl;
                std::cout << "You took: " << amount << std::endl;
                std::cout << "Your balance now is: " << (vip[i].balance) << std::endl;
            }
            std::cout << "withdraw successful..." << std::endl;
            std::cout << std::endl;
        }
        else if (((vip[i].name == name) || (customer[i].name == name)) && checkBalance(name) <= 0)
        {
            std::cout << "Sorry but you can't withdraw" << std::endl;
            std::cout << std::endl;
        }
    }
}

void loan(std::string name)
{
    checkBalance(name);
    int amount;
    std::cout << "enter amount: ";
    std::cin >> amount;
    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (customer[i].name == name && checkBalance(name) >= 0 && amount <= 50000)
        {
            customer[i].balance -= amount;
            std::cout << "loan successful..." << std::endl;
            std::cout << customer[i].balance << std::endl;
            std::cout << std::endl;
        }
        else if (vip[i].name == name && checkBalance(name) >= 0 && amount <= 100000)
        {
            vip[i].balance -= amount * vip[i].discount;
            std::cout << "loan successful..." << std::endl;
            std::cout << vip[i].balance << std::endl;
            std::cout << std::endl;
        }
        else if (((vip[i].name == name) || (customer[i].name == name)) && checkBalance(name) < 0)
        {
            std::cout << "Sorry but you already took a loan" << std::endl;
            std::cout << std::endl;
        }
    }
}

void send_to(std::string from_user)
{
    std::string to_user;
    std::cout << "Send to: ";
    std::cin >> to_user;
    std::cout << std::endl;

    if (to_user == from_user)
    {
        std::cout << "You can't send to yourself..." << std::endl;
        std::cout << std::endl;
        return;
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (to_user == customer[i].name || to_user == vip[i].name)
        {
            break;
        }
        else if (i == SIZE - 1)
        {
            std::cout << "user does not exist..." << std::endl;
            std::cout << std::endl;
            return;
        }
    }
    int amount;
    std ::cout << checkBalance(from_user) << std::endl;
    std::cout << "enter amount: ";
    std::cin >> amount;
    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++) // more less ==
    {
        if (isBroke(from_user) == false)
        {
            if (customer[i].name == from_user)
            {
                if (customer[i].balance < amount)
                {
                    std::cout << "Sorry but you do not have the funds..." << std::endl;
                    std::cout << std::endl;
                    break;
                }
                else
                {
                    customer[i].balance -= amount;
                    std::cout << "sent successfully..." << std::endl;
                    std::cout << checkBalance(from_user) << std::endl;
                    std::cout << std::endl;
                    break;
                }
            }
            else if (vip[i].name == from_user)
            {
                if (vip[i].balance < amount)
                {
                    std::cout << "Sorry but you do not have the funds..." << std::endl;
                    std::cout << std::endl;
                    break;
                }
                else
                {
                    vip[i].balance -= amount;
                    std::cout << "sent successfully..." << std::endl;
                    std::cout << checkBalance(from_user) << std::endl;
                    std::cout << std::endl;
                    break;
                }
            }
            else if (customer[i].name == to_user)
            {
                if (customer[i].balance < amount)
                {
                    std::cout << "Sorry but you do not have the funds..." << std::endl;
                    std::cout << std::endl;
                    break;
                }
                else
                {
                    customer[i].balance += amount;
                    std::cout << "sent successfully..." << std::endl;
                    std::cout << checkBalance(from_user) << std::endl;
                    std::cout << std::endl;
                    break;
                }
            }
            else if (vip[i].name == to_user)
            {
                if (vip[i].balance < amount)
                {
                    std::cout << "Sorry but you do not have the funds..." << std::endl;
                    std::cout << std::endl;
                    break;
                }
                else
                {
                    vip[i].balance += amount;
                    std::cout << "sent successfully..." << std::endl;
                    std::cout << checkBalance(from_user) << std::endl;
                    std::cout << std::endl;
                    break;
                }
            }
            else if (i == SIZE - 1)
            {
                std::cout << "user does not exist..." << std::endl;
                std::cout << std::endl;
                break;
            }
        }
    }
}

void ATM()
{
    std::string name = login();
    int x;
    std::cout << "what would you like to do?" << std::endl;
    std::cout << "1. deposit." << std::endl;
    std::cout << "2. withdraw." << std::endl;
    std::cout << "3. check balance." << std::endl;
    std::cout << "4. loan." << std::endl;
    std::cout << "5. send money." << std::endl;
    std::cout << "6. return to Menu." << std::endl;
    std::cout << "7. exit." << std::endl;
    std::cout << std::endl;
    std::cout << "Choose: ";
    std::cin >> x;
    std::cout << std::endl;

    switch (x)
    {
    case 1:
        deposit(name);
        break;
    case 2:
        withdraw(name);
        break;
    case 3:
        checkBalance(name);
        break;
    case 4:
        loan(name);
        break;
    case 5:
        send_to(name);
        break;
    case 6:
        Menu();
        break;
    case 7:
        return;
        break;
    default:
        std::cout << "invalid input..." << std::endl;
        std::cout << std::endl;
        ATM();
        break;
    }
}