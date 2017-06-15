//austinmw
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


vector<float> local_average(vector<string> w, int loc)
{
    // Calculates averages determined by strings and loc
    vector<float> averages;
    int index(0), total(0);

    while (index < (w.size()-loc+1))
    {
        total = 0;
        for (int i = 0; i < loc; i++)
        {
            total += w[index+i].size();
        }
        index ++;
        float avg = (float)total / (float)loc;
        averages.push_back(avg);
    }
    return averages;
}

int main()
{
    int loc;
    vector<vector<string> > w;
    vector<float> output;

    // Example cases
    w.push_back({"abc", "abd", "a", "b", "c"});
    w.push_back({"a", "z", "w", "aaa", "123"});
    w.push_back({"abc", "abc", "a", "b", "c"});
    w.push_back({"abc", "a", "b", "c", "abd"});
    w.push_back({"a", "bcd", "e"});
    w.push_back({"a", "b", "abcedae", "w", "x", "z"});
    w.push_back({"a", "22", "333", "1"});

    for (int k = 0; k != w.size(); k++)
    {
        cout << "string vector w = ";
        for (auto j : w[k])
            cout << j << " ";

        cout << "\nEnter loc: ";
        cin >> loc;
        if (loc <= 0 || loc > w[k].size())
            cerr << "Fcn X error\n\n";
        else
        {
            if (w[k].size() > 0)
            {
                output = local_average(w[k], loc);
                for (auto i : output)
                    cout << i << " ";
                cout << endl << endl;
            }
            else
                cerr << "Fcn X error\n\n";
        }
    }
    return 0;
}
