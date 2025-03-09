#include <iostream>
#include <cmath>
#include<ctime>
using namespace std;

int power(int x, int n) {
    return pow(10, n);
}

int karatsuba(int x, int y) {

    if (x < 10 || y < 10) {
        return x * y;
    }

    int n = max(log10(x) + 1, log10(y) + 1);
    int half = n / 2;

    int a = x / power(10, half);
    int b = x % power(10, half);
    int c = y / power(10, half);
    int d = y % power(10, half);
    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int ad_plus_bc = karatsuba(a + b, c + d) - ac - bd;
    return ac * power(10, 2 * half) + ad_plus_bc * power(10, half) + bd;
}

int main() {
    int num1, num2;
    cout<<" Enter two Integer number: ";
    cin>>num1>>num2;
    clock_t time1 = clock();
    int result = karatsuba(num1, num2);
    clock_t time2 = clock();
    cout << "Result: " << result << endl;
    double time_spand = double(double(time2-time1)/ CLOCKS_PER_SEC);
    cout<<"\n time required: "<<time_spand;
    return 0;
}

