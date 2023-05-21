#include <iostream>
void Menu();

void PrintArrays()
{
    std::cout << "Users: " << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << customer[i].name << std::endl;
    }
    std::cout << std::endl;
    std::cout << "VIPs: " << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << vip[i].name << std::endl;
    }
    std::cout << std::endl;
}

struct NumClients
{
    int num_users;
    int num_vips;
};

NumClients CountNumOfClients()
{
    int num_users = 0;
    int num_vips = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (customer[i].name != "")
        {
            num_users++;
        }
        if (vip[i].name != "")
        {
            num_vips++;
        }
    }
    return {num_users, num_vips};
}

void show()
{
    NumClients num_clients = CountNumOfClients();
    int num_users = num_clients.num_users;
    int num_vips = num_clients.num_vips;

    std::cout << "Number of users: " << num_users << std::endl;
    std::cout << std::endl;
    std ::cout << "Number of VIPs: " << num_vips << std::endl;
    std::cout << std::endl;
}

void add()
{
    NumClients num_clients = CountNumOfClients();
    int numberUser = num_clients.num_users;
    int numberVip = num_clients.num_vips;

    std::cout << "Number of users: " << numberUser << std::endl;
    std ::cout << std::endl;
    std ::cout << "Number of VIPs: " << numberVip << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (customer[i].name == "")
        {
            numberUser--;
        }
        if (vip[i].name == "")
        {
            numberVip--;
        }
    }
    if (numberUser == SIZE || numberVip == SIZE)
    {
        std::cout << "No more space..." << std::endl;
        std::cout << std::endl;
        Menu();
    }
    std::string name;
    std::string id;
    int balance;
    std::string number;
    std::string password;
    bool user_found = false;
    bool boolVip = false;

    std::cout << "enter name: ";
    std::cin >> name;
    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (customer[i].name == name)
        {
            std::cout << "User already exists..." << std::endl;
            user_found = true;
            break;
        }
    }

    if (!user_found)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (vip[i].name == name)
            {
                std::cout << "User already exists..." << std::endl;
                user_found = true;
                break;
            }
        }
    }

    std::cout << "enter id: ";
    std::cin >> id;
    std::cout << std::endl;

    std::cout << "enter number: ";
    std::cin >> number;
    std::cout << std::endl;

    std::cout << "enter password: ";
    std::cin >> password;
    std::cout << std::endl;

    std::cout << "enter balance: ";
    std::cin >> balance;
    std::cout << std::endl;

    std::cout << "is vip? (1 = t / 0 = F): ";
    std::cin >> boolVip;
    std::cout << std::endl;

    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (customer[i].name == "")
        {
            customer[i].name = name;
            customer[i].id = id;
            customer[i].number = number;
            customer[i].password = password;
            customer[i].balance = balance;
            std::cout << "user added." << std::endl;
            std::cout << std::endl;
            Menu();
        }
        else if (vip[i].name == "" && boolVip == true)
        {
            vip[i].name = name;
            vip[i].id = id;
            vip[i].number = number;
            vip[i].password = password;
            vip[i].balance = balance;
            std::cout << "user added." << std::endl;
            std::cout << std::endl;
            Menu();
        }
        else if (i == SIZE - 1)
        {
            std::cout << "No more space..." << std::endl;
            std::cout << std::endl;
            Menu();
        }
        else if (customer[i].name != "" && (vip[i].name != "" && boolVip == true))
        {
            std::cout << "occupied" << std::endl;
            std::cout << std::endl;
            Menu();
        }
    }
    numberUser++;
    std::cout << "user added." << std::endl;
    std::cout << std::endl;
    Menu();
}

void remove()
{
    std::string name;
    std::cout << "enter name: ";
    std::cin >> name;
    std::cout << std::endl;
    std::cout << "enter password: ";
    std::string password;
    std::cin >> password;
    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (customer[i].name == name && customer[i].password == password)
        {
            customer[i].name = "";
            customer[i].id = "0";
            customer[i].number = "0";
            customer[i].password = "";
            customer[i].balance = 0;
            std::cout << "user removed." << std::endl;
            std::cout << std::endl;
            Menu();
        }
        else if (vip[i].name == name && vip[i].password == password)
        {
            vip[i].name = "";
            vip[i].id = "0";
            vip[i].number = "0";
            vip[i].password = "";
            vip[i].balance = 0;
            std::cout << "user removed." << std::endl;
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

void Edit()
{
    std::string name;
    std::cout << "enter name: ";
    std::cin >> name; // repetitttive bs 3adi \<3
    std::cout << std::endl;
    std::cout << "enter password: ";
    std::string password;
    std::cin >> password;
    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (customer[i].name == name && customer[i].password == password)
        {
            std::string name;
            int id;
            int number;
            std::string password;
            int balance;

            std::cout << "enter name: ";
            std::cin >> name;
            std::cout << "enter id: ";
            std::cin >> id;
            std::cout << "enter number: ";
            std::cin >> number;
            std::cout << "enter password: ";
            std::cin >> password;
            std::cout << "enter balance: ";
            std::cin >> balance;
            std::cout << std::endl;

            customer[i].name = name;
            customer[i].id = id;
            customer[i].number = number;
            customer[i].password = password;
            customer[i].balance = balance;
            std::cout << "Edit successful." << std::endl;
            std::cout << std::endl;
        }
        else if (vip[i].name == name && vip[i].password == password)
        {
            std::string name;
            int id;
            int number;
            std::string password;
            int balance;

            std::cout << "enter name: ";
            std::cin >> name;
            std::cout << "enter id: ";
            std::cin >> id;
            std::cout << "enter number: ";
            std::cin >> number;
            std::cout << "enter password: ";
            std::cin >> password;
            std::cout << "enter balance: ";
            std::cin >> balance;
            std::cout << std::endl;

            vip[i].name = name;
            vip[i].id = id;
            vip[i].number = number;
            vip[i].password = password;
            vip[i].balance = balance;
            std::cout << "Edit successful." << std::endl;
            std::cout << std::endl;
        }
        else if (i == SIZE - 1) // FIXME: if user not found then it will print this
        {
            std::cout << "user not found..." << std::endl;
            std::cout << std::endl;
        }
    }
}

void Promote() // FIXME
{
    NumClients num_clients = CountNumOfClients();
    int numberVip = num_clients.num_vips;

    std::string name;
    std::string password;

    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << std::endl;

    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (customer[i].name == name && customer[i].password == password)
        {
            std::string name;
            int id;
            int number;
            std::string password;
            int balance;
            int discount;

            for (int i = 0; i < SIZE; i++)
            {
                if (vip[i].name == "")
                {
                    vip[i].name = customer[i].name;
                    vip[i].id = customer[i].id;
                    vip[i].number = customer[i].number;
                    vip[i].password = customer[i].password;
                    vip[i].balance = customer[i].balance;
                }
            }

            std::cout << "enter discount: ";
            std::cin >> discount;
            std::cout << std::endl;

            // delete customer
            customer[i].name = "";
            customer[i].id = "0";
            customer[i].number = "0";
            customer[i].password = "";
            customer[i].balance = 0;

            std::cout << "Promotion successful." << std::endl;
            std::cout << std::endl;
        }
        else if (vip[i].name == name && vip[i].password == password)
        {
            std::cout << "User is already a VIP..." << std::endl;
            std::cout << std::endl;
            Menu();
        }
        else if (numberVip == SIZE)
        {
            std::cout << "No more space..." << std::endl;
            std::cout << std::endl;
        }
        else if (i == SIZE - 1)
        {
            std::cout << "user not found..." << std::endl;
            std::cout << std::endl;
            Menu();
        }
    }
}
void Register()
{
    int x;
    std::cout << "1. Add" << std::endl;
    std::cout << "2. Remove" << std::endl;
    std::cout << "3. Edit" << std::endl;
    std::cout << "4. Promote" << std::endl;
    std::cout << "5. Menu" << std::endl;
    std::cout << "6. Print Arrays" << std::endl;
    std::cout << "7. Count Number of Clients" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << std::endl;
    std::cout << "Choose: ";
    std::cin >> x;
    std::cout << std::endl;

    switch (x)
    {
    case 1:
        add();
        break;
    case 2:
        remove();
        break;
    case 3:
        Edit();
        break;
    case 4:
        Promote();
        break;
    case 5:
        Menu();
        break;
    case 6:
        PrintArrays();
        break;
    case 7:
        show();
        break;
    case 8:
        std::cout << "exiting..." << std::endl;
        return;
        break;
    default:
        std::cout << "invalid input..." << std::endl;
        std::cout << std::endl;
        Register();
        break;
    }
}