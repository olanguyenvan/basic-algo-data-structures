#include <iostream>
#include <vector>

using namespace std;
using matrix = vector<vector<long long int> >;


matrix multiply2per2MatricesMod(const matrix &M1, const matrix &M2, int m){
    long long int a = M1[0][0];
    long long int b = M1[0][1];
    long long int c = M1[1][0];
    long long int d = M1[1][1];
    long long int e = M2[0][0];
    long long int f = M2[0][1];
    long long int g = M2[1][0];
    long long int h = M2[1][1];
    long long int p1 = a * (f - h);
    long long int p2 = (a + b) * h;
    long long int p3 = (c + d) * e;
    long long int p4 = d * (g - e);
    long long int p5 = (a + d) * (e + h);
    long long int p6 = (b - d) * (g + h);
    long long int p7 = (a - c) * (e +f);
    matrix multipied_matrix(2);
    multipied_matrix[0].push_back((p5 + p4 - p2 + p6) % m);
    multipied_matrix[0].push_back((p1 + p2) % m);
    multipied_matrix[1].push_back((p3 + p4) % m);
    multipied_matrix[1].push_back((p1 + p5 - p3 - p7) % m);
    return multipied_matrix;
}


matrix compute_power_of_matrix_mod(const matrix &M, int n, int m){
    if (n == 0){
        matrix unit_matrix(2);
        unit_matrix[0].push_back(1);
        unit_matrix[0].push_back(0);
        unit_matrix[1].push_back(0);
        unit_matrix[1].push_back(1);
        return unit_matrix;
    }

    if (n % 2 == 0){
        matrix recursive_result = compute_power_of_matrix_mod(M, n / 2, m);
        return multiply2per2MatricesMod(recursive_result, recursive_result, m);
    }

    return multiply2per2MatricesMod(M,  compute_power_of_matrix_mod(M, n - 1, m), m);
}

void printMatrix(const matrix &M){
    cout<<M[0][0]<<" "<<M[0][1]<<endl;
    cout<<M[1][0]<<" "<<M[1][1]<<endl;
}


int main() {

    int n, m;
    long long int a, b, c, d;
    while (cin>>a) {
        matrix M(2);

        cin>>b>>c>>d;

        M[0].push_back(a);
        M[0].push_back(b);
        M[1].push_back(c);
        M[1].push_back(d);

        cin>>n>>m;
        matrix multiplied_matrix = compute_power_of_matrix_mod(M, n, m);

        printMatrix(multiplied_matrix);
        cout<<"----------"<<endl;
    }
}
