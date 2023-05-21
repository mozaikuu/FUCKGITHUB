#include <iostream>
#ifndef Clients
#define Clients

const int SIZE = 20;

class Customer
{
public:
    // static int num_users;
    std::string name;
    std::string id;
    std::string number;
    std::string password;
    int balance;

    Customer(std::string name, std::string id, int bal, std::string number, std::string password)
    {
        this->name = name;
        this->id = id;
        this->balance = bal;
        this->number = number;
        this->password = password;
        // num_users++;
    }
};

class Vip : public Customer
{
public:
    int discount;
    // static int num_vips;

    Vip(std::string name, std::string id, int bal, std::string number, std::string password, int discount) : Customer(name, id, bal, number, password)
    {
        this->discount = discount;
        // num_vips++;
    }
};

// class Admin : public Customer
// {
// public:
//     // static int num_admins;

//     Admin(std::string name, std::string id, int bal, std::string number, std::string password) : Customer(name, id, bal, number, password)
//     {
//         // num_admins++;
//     }
// };
// admin("admin", "0", 99999999999, "01501844888", "admin"); // if admin == true then login as admin without password

Customer customer[SIZE] = {Customer("moussa", "1", 1000, "01042333253", "pass1"),
                           Customer("fawaz", "2", 2000, "01556703723", "pass2"),
                           Customer("rawan", "3", 3000, "01042333253", "pass3"),
                           Customer("hatem", "4", 4000, "01556703523", "pass4"),
                           Customer("esmail", "5", 5000, "01042333253", "pass5"),
                           Customer("basmala", "6", 6000, "01556703523", "pass6"),
                           Customer("youssef", "7", 7000, "01042333253", "pass7"),
                           Customer("shahd", "8", 8000, "01556703423", "pass8"),
                           Customer("amira", "9", 9000, "01042333253", "pass9"),
                           Customer("samaa", "10", 10000, "01556703423", "pass10"),
                           Customer("", "0", 0, "0", ""),
                           Customer("", "0", 0, "0", ""),
                           Customer("", "0", 0, "0", ""),
                           Customer("", "0", 0, "0", ""),
                           Customer("", "0", 0, "0", ""),
                           Customer("", "0", 0, "0", ""),
                           Customer("", "0", 0, "0", ""),
                           Customer("", "0", 0, "0", ""),
                           Customer("", "0", 0, "0", ""),
                           Customer("", "0", 0, "0", "")};

Vip vip[SIZE] = {Vip("basmala", "1", 1000, "01042333253", "pass1", 10),
                 Vip("mohamed", "2", 2000, "01556703423", "pass2", 20),
                 Vip("ali", "3", 3000, "01042333253", "pass3", 30),
                 Vip("khaled", "4", 4000, "01556703423", "pass4", 40),
                 Vip("mahmoud", "5", 5000, "01042333253", "pass5", 50),
                 Vip("hassan", "6", 6000, "01556703423", "pass6", 60),
                 Vip("youssef", "7", 7000, "01042333253", "pass7", 70),
                 Vip("omar", "8", 8000, "01556703423", "pass8", 80),
                 Vip("mohsen", "9", 9000, "01042333253", "pass9", 90),
                 Vip("wael", "10", 10000, "01556703423", "pass10", 100),
                 Vip("", "0", 0, "0", "", 0),
                 Vip("", "0", 0, "0", "", 0),
                 Vip("", "0", 0, "0", "", 0),
                 Vip("", "0", 0, "0", "", 0),
                 Vip("", "0", 0, "0", "", 0),
                 Vip("", "0", 0, "0", "", 0),
                 Vip("", "0", 0, "0", "", 0),
                 Vip("", "0", 0, "0", "", 0),
                 Vip("", "0", 0, "0", "", 0),
                 Vip("", "0", 0, "0", "", 0)};

#endif