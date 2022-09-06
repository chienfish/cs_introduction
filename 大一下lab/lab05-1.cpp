#include <iostream>
using namespace std;

class BankAcc
{
    private:
        double NTD;
        double USD;
        double EUD;
    public:
        BankAcc (double N, double U, double E)
        {
            NTD = N;
            USD = U;
            EUD = E;            
        }       

        double valuelnNTD()
        {
            return NTD + (30*USD) + (40*EUD);  
        }

        double valuelnUSD()
        {
            return USD + (NTD/30) + (4*EUD/3);
        }

        double valuelnEUD()
        {
            return EUD + (NTD/40) + (3*USD/4);  
        }

        void output()
        {
            cout << valuelnNTD() << " " << valuelnUSD() << " " \
            << valuelnEUD() << endl ;
        }
};


int main()
{
    double N, U, E;
    cin >> N >> U >> E;
    BankAcc Acc(N,U,E);

    Acc.output();
}

