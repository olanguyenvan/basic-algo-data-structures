#include <iostream>
#include <vector>

using namespace std;


bool position(double x, const vector<double>& v, int left, int right) {
    if (left > right) {
        return false;
    }
    else if (left + 1 == right) {
        return x == v[left] or x == v[right];
    }
    else if (left == right ){
        return x == v[left];
    }
    int m = (left + right) / 2;

    if (x < v[m]){
        if(v[m + 1] == x){
            return true;
        }
        return position(x, v, left, m - 1);
    }
    else {
        if(v[m - 1] == x){
            return true;
        }
        return position(x, v, m, right);
    }

}



bool resistant_search(double x, const vector<double>& v){
    return position(x, v, 0, v.size() - 1);
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            bool found_or_not = resistant_search(x, V);
            if(found_or_not){
                cout<<x<<" found in the array."<<endl;
            }else{
                cout<<x<<" NOT found in the array."<<endl;
            }
        }
    }
}