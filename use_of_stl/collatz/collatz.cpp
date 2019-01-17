#include <iostream>
#include <vector>
#include <string>

using namespace std;


int findIndexInSequence(vector<int> sequence, int value){
    int index = -1;
    for(int i = 1; i < sequence.size(); i++){
        if (sequence[i] == value){
            return i;
        }
    }
    return index;
}


int computeCycleLength(vector<int> sequence, int x, int y, int n){
    int count = 0;
    int indexInSequence;
    while(true){
        indexInSequence = findIndexInSequence(sequence, n);
        if (indexInSequence >= 0){
            return count - indexInSequence;
        }
        if( n > 100000000)
            return n;
        else{
            sequence.push_back(n);
            if (n % 2 == 0){
                n = n / 2 + x;
            }
            else{
                n =  3 * n  + y;
            }
        }
        count++;
    }
}


int main(){
    string command;
    string name;
    int i = 0;
    int money;
    int personIndex;
    vector<int> sequence;

    int x, y, startingNumber;
    while(cin>>x>>y>>startingNumber){
        cout<<computeCycleLength(sequence, x, y, startingNumber)<<endl;
    }
}
