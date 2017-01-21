#include <iostream>

using namespace std;

int main()
//divisorsum
{
int i;
for (i=2; i<=1000; i++) {
    int n;
    int sum = 0;
    for (n=1; n<i; n++) {
        if (i % n == 0) {
            sum = sum + n;
        }
    }
    cout << sum << endl;
}
    return 0;
}
