#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (b[j] > b[j + 1])
            {
                swap(a[j], a[j + 1]);
                swap(b[j], b[j + 1]);
            }
        }
    }

    int min = INT_MIN, count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (min < a[i])
        {
            cout << a[i] << " " << b[i] << endl;
            min = b[i];
            ++count;
        }
    }
    cout << "Total activities: " << count << endl;
}