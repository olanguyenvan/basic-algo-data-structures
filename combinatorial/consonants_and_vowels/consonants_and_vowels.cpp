#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef vector<char> VC;
typedef vector<VC> VVC;


void printVector(vector<char> vectorToPrint){
    for(char x: vectorToPrint){
        cout<<x;
    }
    cout<<endl;
}

void permutate_rec(vector<char> consonants, vector<char> vowels, vector<char> out, vector<bool> &used_consonants,
        vector<bool> &used_vowels, int count, int n){
    if (count == 2 * n){
        printVector(out);
    }
    else{
        if( count % 2 == 0){
            for (int i=0; i<n; i++){
                if (not used_consonants[i]){
                    used_consonants[i] = true;
                    out.push_back(consonants[i]);
                    permutate_rec(consonants, vowels, out, used_consonants, used_vowels, count + 1, n);
                    out.pop_back();
                    used_consonants[i] = false;
                }
            }
        }

        else {
            for (int i=0; i<n; i++){
                if (not used_vowels[i]){
                    used_vowels[i] = true;
                    out.push_back(vowels[i]);
                    permutate_rec(consonants, vowels, out, used_consonants, used_vowels, count + 1, n);
                    out.pop_back();
                    used_vowels[i] = false;
                }
            }
        }
    }
}

void permutation(vector<char>consonants, vector<char> vowels){
    int n = consonants.size();
    vector<char> out;
    vector<bool> used_consonants(n, false);
    vector<bool> used_vowels(n, false);

    permutate_rec(consonants, vowels, out, used_consonants, used_vowels, 0, n);
}

int main() {
    int n;
    vector<char> vowels;
    vector<char> consonants;
    char x;

    while (cin>>n) {
        for(int j=0; j<n; j++){
            cin>>x;
            consonants.push_back(x);
        }

        for(int j=0; j<n; j++){
            cin>>x;
            vowels.push_back(x);
        }

        permutation(consonants, vowels);
    }
}