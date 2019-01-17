#include <iostream>
#include <string>
#include <vector>

using namespace std;


void printVectorAsChars(vector<int> vectorToPrint){
    for(int x: vectorToPrint){
        cout<<char(x + 97);
    }
    cout<<endl;
}


void permutate_rec(vector<int> out, vector<bool> &used_letters, int last_letter, int count, int n){
    if (count == n){
        printVectorAsChars(out);
    }
    else {
        for (int i=0; i<n; i++){
            if (not used_letters[i] and last_letter != i - 1){
                used_letters[i] = true;
                out.push_back(i);
                permutate_rec(out, used_letters, i, count + 1, n);
                out.pop_back();
                used_letters[i] = false;
            }
        }
    }
}


void permutate(int n){
    vector<int> out;
    vector<bool> used_letters(n, false);
    permutate_rec(out, used_letters, -2, 0, n); // -1 because first letter in output can be any
}


int main(){
    int n;
    cin>>n;
    permutate(n);
}