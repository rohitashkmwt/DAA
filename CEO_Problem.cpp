#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

int main()
{
    int rts;
    cout << "Enter Number of available Routes:";
    cin >> rts;
    int *levels = new int[rts];
    int max = -1;

    //Longest Route can be obtaine by following loop...
    cout << "Enter levels/steps:";
    for (int i = 0; i < rts; i++)
    {
        cin >> levels[i];
        if (levels[i] > max)
            max = levels[i];
    }
    int lngstRt = max;

    //cThe following will create a table...
    int *table = new int[lngstRt];

    //Initial case...
    table[0] = 0;
    if (lngstRt > 1)
        table[1] = 1;
    if (lngstRt > 2)
        table[2] = 2;

    //filling dp table
    for (int i = 3; i < lngstRt; i++)
    {
        table[i] = table[i - 1] + table[i - 2];
    }

    //The following will find the Possible ways to become CEO....
    map<int, vector<vector<int>>> wy;
    vector<int> v;
    v.push_back(1);
    wy[0].push_back(v);
    v.push_back(2);
    wy[1].push_back(v);
    for (int i = 2; i < lngstRt; i++)
    {
        for (auto j = wy[i - 1].begin(); j != wy[i - 1].end(); j++)
        {
            vector<int> v = *j;
            v.push_back(i + 1);
            wy[i].push_back(v);
        }
        for (auto j = wy[i - 2].begin(); j != wy[i - 2].end(); j++)
        {
            vector<int> v = *j;
            v.push_back(i + 1);
            wy[i].push_back(v);
        }
    }

    //The following code snippet will print the obtained Possible ways....
    for (int i = 0; i < rts; i++)
    {
        if (levels[i] < 1)
        {
            cout << "You can not choose levels/steps like this. Try Again." << endl;
        }
        else
        {
            cout << "Possible ways to get top position by using following Routes: " << (i + 1) << ": " << table[levels[i] - 1] << endl;
            int k = levels[i] - 1;
            for (auto j = wy[k].begin(); j != wy[k].end(); j++)
            {
                vector<int> path = *j;
                for (int p = 0; p < path.size(); p++)
                {
                    (p == path.size() - 1) ? (cout << path[p]) : (cout << path[p] << "-> ");
                }
                cout << endl;
            }
        }
    }
}