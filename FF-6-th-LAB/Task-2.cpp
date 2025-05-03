#include <iostream>
using namespace std;

const int MAX = 4;
void add(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}
void MMult(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    else
    {

        int m = n / 2;
        int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
        int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
        int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];
        int X1[MAX][MAX], X2[MAX][MAX], X3[MAX][MAX], X4[MAX][MAX];
        int X5[MAX][MAX], X6[MAX][MAX], X7[MAX][MAX], X8[MAX][MAX];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + m];
                A21[i][j] = A[i + m][j];
                A22[i][j] = A[i + m][j + m];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + m];
                B21[i][j] = B[i + m][j];
                B22[i][j] = B[i + m][j + m];
            }
//        MMult(A11, B11, X1, m);
        MMult(A12, B21, X2, m);
        MMult(A11, B12, X3, m);
        MMult(A12, B22, X4, m);
        MMult(A21, B11, X5, m);
        MMult(A22, B21, X6, m);
        MMult(A21, B12, X7, m);
        MMult(A22, B22, X8, m);

        add(X1, X2, C11, m);
        add(X3, X4, C12, m);
        add(X5, X6, C21, m);
        add(X7, X8, C22, m);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
            {
                C[i][j] = C11[i][j];
                C[i][j + m] = C12[i][j];
                C[i + m][j] = C21[i][j];
                C[i + m][j + m] = C22[i][j];
            }
    }
}

void printMatrix(int M[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n = 4;
    int A[MAX][MAX],B[MAX][MAX];
    int i=0, j=0, k=0;
    cout<<"Enter The Matrix A:"<<endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>A[i][j];
        }
    }
    cout<<"Enter The Matrix B:"<<endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>B[i][j];
        }
    }
    int C[MAX][MAX]= {0};

    MMult(A, B, C, n);

    cout << "Result Matrix C:" << endl;
    printMatrix(C, n);

    return 0;
}
