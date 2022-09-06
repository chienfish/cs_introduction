#include <iostream>
#include <cmath>
using namespace std;

class BankAcc
{
    public:
        double NTD;
        double USD;
        double EUD;
        BankAcc (double N = 0, double U = 0, double E = 0)
        {
            NTD = N;
            USD = U;
            EUD = E;            
        }    

        double valueInNTD()
        {
            return NTD + (30*USD) + (40*EUD);
        }
        double valueInUSD()
        {
            return USD + (NTD/30) + ((4*EUD)/3);
        }
        double valueInEUD()
        {
            return EUD + (NTD/40) + ((3*USD)/4);
        }
        void output()
        {
            cout << this -> NTD << " " << this -> USD << " " << this -> EUD << endl;
        }

};

BankAcc operator+ (BankAcc a, BankAcc b)
{
    BankAcc ret_acc(a.NTD + b.NTD, a.USD + b.USD, a.EUD + b.EUD);
    return ret_acc;
}

BankAcc operator- (BankAcc a, BankAcc b)
{
    BankAcc ret_acc(a.NTD - b.NTD, a.USD - b.USD, a.EUD - b.EUD);
    return ret_acc;
}

BankAcc operator% (BankAcc a, BankAcc b)
{
    BankAcc ret_acc(abs(a.NTD - b.NTD), abs(a.USD - b.USD), abs(a.EUD - b.EUD));
    return ret_acc;
}

BankAcc operator* (BankAcc a, BankAcc b)
{
    BankAcc ret_acc(a.NTD + 0.99*(b.NTD), a.USD + 0.99*(b.USD), a.EUD + 0.99*(b.EUD));
    return ret_acc;
}

BankAcc operator/ (BankAcc a, BankAcc b)
{
    BankAcc ret_acc(a.NTD - 1.01*(b.NTD), a.USD - 1.01*(b.USD), a.EUD - 1.01*(b.EUD));
    return ret_acc;
}

int main()
{
    double N1, U1, E1;
    double N2, U2, E2;
    cin >> N1 >> U1 >> E1;
    cin >> N2 >> U2 >> E2;
    BankAcc Acc1(N1,U1,E1);
    BankAcc Acc2(N2,U2,E2);

    BankAcc Acc3;
    Acc3 = Acc1 + Acc2;
    Acc3.output();
    Acc3 = Acc1 - Acc2;
    Acc3.output();
    Acc3 = Acc1 % Acc2;
    Acc3.output();
    Acc3 = Acc1 * Acc2;
    Acc3.output();
    Acc3 = Acc1 / Acc2;
    Acc3.output();

}