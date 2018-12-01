#include <iostream>
#include <vector>

using namespace std;


int compute_exp_mod(int n, int k, int m){
    if (k == 0){
        return 1;
    }
    n = n % m;

    if (k % 2 == 0){

        int recursive_result = compute_exp_mod(n, k/2, m);
        return (recursive_result * recursive_result) % m;
    }
    else {
        n = n % m;
        return n * compute_exp_mod(n, k-1, m) % m;
    }
}



int main() {

    int n, k,  m, remainder;
    while (cin>>n>>k>>m) {
        cout<<compute_exp_mod(n, k, m)<<endl;
    }
}
