#include <iostream>
#include <vector>
#include <string>

using namespace std;
using chess = vector<vector<char> >;


bool dfs(chess &Chess, int row, int column, int max_row_size, int max_col_size) {
    if (row >= max_row_size or column >= max_col_size or row < 0 or column < 0){
        return false;
    }

    switch (Chess[row][column]){
        case 'X':
            return false;
        case 't':
            return true;
        case '.':
            Chess[row][column] = 'X';
            return dfs(Chess, row - 1, column, max_row_size, max_col_size) or
            dfs(Chess, row, column - 1, max_row_size, max_col_size) or
            dfs(Chess, row + 1, column, max_row_size, max_col_size) or
            dfs(Chess, row, column + 1, max_row_size, max_col_size);
        default:
            return false;
    }
}

int main(){
    int n, m;
    int initial_row;
    int initial_column;
    while(cin>>n>>m){
        chess Chess(n);
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; j++){
                char x;
                cin>>x;
                Chess[i].push_back(x);
            }
        }
        cin>>initial_row>>initial_column;

        bool path_found = dfs(Chess, initial_row - 1, initial_column - 1, n, m);
        if (path_found) cout<<"yes"<<endl;
        else cout<<"no"<<endl;

    }
}