#include <iostream>
#include <vector>
using namespace std;


int get_pisano_period(int m){
    int a = 0;
    int b = 1;
    int c;
    for(int i=0; i < m * m; i++){
        c = (a + b) % m;
        a = b;
        b = c;
        if( a == 0 && b == 1){
            return i +1;
        }
    }
    return -1;
}



int main() {
    int n, m, pisano, remainder;
    while (cin >> n>> m) {
        pisano = get_pisano_period(m);
        remainder = n % pisano; // trzeba policzyc remainder + 1
        if (remainder > 0){
            int a = 0, b = 1, c = (a + b);
            for (int i=1; i < remainder; i++){
                c = (a + b) % m;
                a = b;
                b = c;
            }
            cout<<c % m<<endl;
        }
        else{
            cout<<0<<endl;
        }

    }
}
