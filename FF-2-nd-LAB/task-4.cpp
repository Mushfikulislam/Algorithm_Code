#include <iostream>
#include <string>
using namespace std;
int main()
{
    string X, Y;
    while (cin >> X >> Y)
    {
        string product = "0";
        int lenX = X.length();
        int lenY = Y.length();
        string result(lenX + lenY, '0');

        for (int i = lenX - 1; i >= 0; --i)
        {
            for (int j = lenY - 1; j >= 0; --j)
            {
                int mul = (X[i] - '0') * (Y[j] - '0');
                int sum = mul + (result[i + j + 1] - '0');
                result[i + j + 1] = (sum % 10) + '0';
                result[i + j] += (sum / 10);
            }
        }
        int start = 0;
        while (start < result.length() && result[start] == '0')
        {
            start++;
        }
        if (start == result.length())
        {
            cout << "0";
        }
        else
        {
            for (int i = start; i < result.length(); i++)
            {
                cout << result[i];
            }
        }
        cout << endl;
    }

    return 0;
}
