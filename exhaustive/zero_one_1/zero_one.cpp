#include <iostream>
#include <vector>
using namespace std;


void printVector(const vector<int> v){
    for(int i = 0; i < v.size() - 1; i++){
        cout<<v[i]<<" ";
    }
    cout<<v[v.size()-1]<<endl;
}


void printAllCombinationsRec(vector<int> v, int index){
    if (index == v.size()){
        printVector(v);
        return;
    }
    v[index] = 0;
    printAllCombinationsRec(v, index + 1);

    v[index] = 1;
    printAllCombinationsRec(v, index + 1);

}

void printAllCombinations(int n){
    vector<int> v(n);
    printAllCombinationsRec(v, 0);
}

int main(){
    int n; // n vertices and m edges
    while(cin>>n){
        printAllCombinations(n);
    }
}
