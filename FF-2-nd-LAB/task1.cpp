#include <iostream>
#include <cstring>
using namespace std;
#define MAX 200
#include<ctime>
class BigIntMultiplication
{
private:
    int numA[MAX], numB[MAX], result[MAX];
    int lenA, lenB;
public:
    BigIntMultiplication()
    {
        memset(numA, 0, sizeof(numA));
        memset(numB, 0, sizeof(numB));
        memset(result, 0, sizeof(result));
        lenA = lenB = 0;
    }
    void storeNumber(int num, int arr[], int &length)
    {
        while (num > 0)
        {
            arr[length++] = num % 10;
            num /= 10;
        }
    }
    void multiply(int A, int B)
    {
        if (A == 0 || B == 0)
        {
            cout << "0" << endl;
            return;
        }
        storeNumber(A, numA, lenA);
        storeNumber(B, numB, lenB);
        for (int i = 0; i < lenA; i++)
        {
            for (int j = 0; j < lenB; j++)
            {
                result[i + j] += numA[i] * numB[j];
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
        }
        printResult();
    }

    void printResult()
    {
        int lenResult = lenA + lenB;
        while (lenResult > 1 && result[lenResult - 1] == 0)
        {
            lenResult--;
        }
        for (int i = lenResult - 1; i >= 0; i--)
        {
            cout << result[i];
        }
        cout << endl;
    }
};

int main()
{
    int A, B;
    cout << "Enter two integers: ";
    cin >> A >> B;
    BigIntMultiplication multiplier;
    cout << "Product: ";
    clock_t time1 = clock();
    multiplier.multiply(A, B);
    clock_t time2 = clock();
    double time_spand = double(double(time2-time1)/ CLOCKS_PER_SEC);
    cout<<"\n time required: "<<time_spand;
    return 0;
}
