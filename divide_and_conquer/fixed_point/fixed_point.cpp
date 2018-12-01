#include <iostream>
#include <vector>

using namespace std;


int fixed_position_counting_from_1(const vector<double>& v, int a, int left, int right){
//    cout<<"a="<<a<<" left="<<left<<" right="<<right<<endl;
    if (left > right){
        return 0;
    }

    else if(left == right){
//        cout<<"left=right, a + v[left] = "<<a + v[left]<<"  left+1="<<left+1<<endl;
        if (a + v[left] == left + 1){ // + 1 because counting indexes from 1
            return left + 1;
        };
        return -1;
    }

    else{

        int middle = (left + right) / 2;
//        cout<<"middle = "<<middle<<"middle +1= "<<middle+1<<",        a + v[middle]="<<a + v[middle]<<endl;
        if(middle + 1 <= a + v[middle]){ // + 1 because counting indexes from 1
            return fixed_position_counting_from_1(v, a, left, middle);
        }
        return fixed_position_counting_from_1(v, a, middle + 1, right);
    }
}

int main() {
    long long n;
    int count_sequencions = 1;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];

        int m;
        cin >> m;
        cout<<"Sequence #"<<count_sequencions<<endl;
        while (m--) {
            int a;
            cin >>a;
            int found_fixed_position = fixed_position_counting_from_1(V, a, 0, n - 1); // + 1 because counting indexes from 1
            if(found_fixed_position > 0){
                cout<<"fixed point for "<<a<<": "<<found_fixed_position<<endl;
            }
            else {
                cout<<"no fixed point for "<<a<<endl;
            }
        }
        cout<<endl;
        count_sequencions++;
    }
}
