#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int cifra_min(int x)
{
    int min = 9;
    int m;
    if (x == 0) return 0;
    while (x != 0)
    {
        m = x % 10;
        if (m <= min) min = m;
        x = x / 10;
    }
    return min;
}

int cifra_max(int x)
{
    int max = 0;
    int m;
    while (x != 0)
    {
        m = x % 10;
        if (m >= max) max = m;
        x = x / 10;
    }
    return max;
}

bool comp(int a, int b)
{
    if (cifra_min(a) < cifra_min(b)) return 1;
    else if (cifra_min(a) > cifra_min(b)) return 0;
    else if (cifra_min(a) == cifra_min(b))
    {
        if (cifra_max(a) < cifra_max(b)) return 1;
        else if (cifra_max(a) > cifra_max(b)) return 0;
        else if (cifra_max(a) == cifra_max(b))
        {
            if (a < b) return 1;
            else return 0;
        }
    }
}


int main()
{
    int n;
    vector <int> a;
    int i = 0;
    while (cin >> n)
    {
        a.push_back(n);
    }
    sort(a.begin(), a.end(), comp);
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}