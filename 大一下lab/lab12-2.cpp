#include <iostream>
using namespace std;

int step = 0;
void Tower_of_Hanoi(int N, char A, char B, char C);

int main()
{
    int N;
    cin >> N;

    Tower_of_Hanoi(N, 'A', 'B', 'C');
    cout << "Total steps:" << step << "\n";

    return 0;
}

void Tower_of_Hanoi(int N, char A, char B, char C)
{
    if (N >= 1)
    {
        step ++;
        Tower_of_Hanoi(N-1, A, C, B);
        
        cout << "Move " << N << " from " << A << " to " << C << "\n";

        Tower_of_Hanoi(N-1, B, A, C);
    }
}