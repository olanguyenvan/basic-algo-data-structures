#include <iostream>
#include <vector>
using namespace std;


void printVector(const vector<int> v){
    cout<<"(";
    for(int i = 0; i < v.size() - 1; i++){
        cout<<v[i]<<",";
    }
    cout<<v[v.size()-1]<<")"<<endl;
}


bool ok(const vector<int> &v, int n, int index){

    vector<int> count_occurances(n + 1, 0);
    // count occurances until the index
    for (int j=0; j <= index; j++){
        count_occurances[v[j]]++;
        if(count_occurances[v[j]] == 2){
            return false;
        }
    }
    return true;
}


void printAllPermutationsRec(vector<int> v, int n, int index){
    if (index == n){
        printVector(v);
        return;
    }

    for(int i=1; i<=n; i++){
        v[index] = i;
        if(ok(v, n, index)){
            printAllPermutationsRec(v, n, index + 1);
        }
    }
}

void printAllPermutations(int n){
    vector<int> v(n);
    printAllPermutationsRec(v, n, 0);
}

int main(){
    int n; // n vertices and m edges
    while(cin>>n){
        printAllPermutations(n);
    }
}
