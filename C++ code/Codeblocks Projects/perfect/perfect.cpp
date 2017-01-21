#include <iostream>
#include <cstdlib>

using namespace std;

bool is_perfect (long int in)
{
    int r;
    int sum = 0;
    int i;

    for (i=1; i<in; i++)
    {
        if (in % i == 0)
        {
            sum = sum + i;
        }
    }
    if (sum == in)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    int x = 1;
    bool out;

    while (x != 0)
    {
        cout << "Enter a number to test for perfectness: ";
        cin >> x;
        if (cin.eof())
        {
            x = 0;
            cout << endl;
        }
        if (x != 0)
        {
            out = is_perfect (x);
            if (out == true)
            {
                cout << x << " is perfect" << endl;
            }
            else
            {
                cout << x << " is not perfect" << endl;
            }
        }
    }
    cout << "Goodbye." << endl;
    return 0;
}

