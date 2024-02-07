#include <iostream>
using namespace std;
int main()
{
    int n, s1=0, s2=0, s3=0;
    cin >> n;
    int a[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
        s1 += a[i][0];
        s2 += a[i][1];
        s3 += a[i][2];
    }

    if (s1 == 0 && s2 == 0 && s3 == 0)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}