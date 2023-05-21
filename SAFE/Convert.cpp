#include <iostream>
using namespace std;
double usd_to_egp(double usd_amount)
{
    const double exchange_rate = 30.84;
    return usd_amount * exchange_rate;
}

double egp_to_usd(double egp_amount)
{
    const double exchange_rate = 30.84;
    return egp_amount / exchange_rate;
}

int main()
{
    double usd_amount, egp_amount;

    cout << "Enter amount in USD: ";
    cin >> usd_amount;
    egp_amount = usd_to_egp(usd_amount);
    cout << usd_amount << " USD = " << egp_amount << " EGP" << endl;

    cout << "Enter amount in EGP: ";
    cin >> egp_amount;
    usd_amount = egp_to_usd(egp_amount);
    cout << egp_amount << " EGP = " << usd_amount << " USD" << endl;

    return 0;
}