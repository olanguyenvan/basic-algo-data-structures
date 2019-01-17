#include <iostream>
#include <vector>

using namespace std;
using graph = vector<vector<int>>;

vector <bool> painted_already;
vector <int> painted_colors;


void dfs(const graph &G, int current_vertex, int current_color){
    painted_colors[current_vertex] = current_color;
    painted_already[current_vertex] = true;

    for (int v: G[current_vertex]){
        if (!painted_already[v]){
            dfs(G, v, -current_color + 1);
        }
    }
}


void dfs(const graph &G) {
    int n = static_cast<int>(G.size());
    for (int vertex = 0; vertex<n; ++vertex){
        painted_already[vertex] = false;
    }

    for(int vertex = 0; vertex<n; vertex++){
        if (!painted_already[vertex]){
            dfs(G, vertex, 0);
        }
    }

    bool paintable = true;

    for(int vertex = 0; vertex < n and paintable; ++vertex){
        for(int child_vertex: G[vertex]){
            if (painted_colors[vertex] == painted_colors[child_vertex]){
                paintable = false;
                break;
            }
        }
    }
    if (paintable) cout<<"yes"<<endl;
    else cout<< "no" <<endl;
}

int main(){
    int n, m;
    while(cin>>n>>m){
        graph G(n);
        for(int i=0; i<m; ++i){
            int u, v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);

        }
        painted_already = vector<bool>(n);
        painted_colors = vector<int>(n);
        dfs(G);
    }
}