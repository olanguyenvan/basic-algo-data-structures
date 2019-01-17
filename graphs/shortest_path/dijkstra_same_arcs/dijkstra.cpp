#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using graph = vector<vector<int> >;

void printShortestPath(graph &Graph, int start_vertex, int end_vertex){
    int n = Graph.size();
    vector<bool> visited(n, false);

    vector<int> parent(n);
    parent[start_vertex] = -1;
    queue<int> queue_vertices;
    queue_vertices.push(start_vertex);
    vector<int> distance(n, n);
    distance[0] = 0;
    bool end_vertex_reached = false;

    while(!queue_vertices.empty() and !end_vertex_reached){
        int v = queue_vertices.front();
        queue_vertices.pop();
        if(not visited[v]){
            visited[v] = true;
            for(int u: Graph[v]){
                if(distance[u] > distance[v] + 1){
                    queue_vertices.push(u);
                    parent[u] = v;
                    distance[u] = distance[v] + 1;
                    if(u == end_vertex){
                        end_vertex_reached = true;
                    }
                }
            }
        }
    }


    vector<int> reversed_path_from_start_to_end;
    reversed_path_from_start_to_end.push_back(end_vertex);
    int current_vertex = end_vertex;
    do{
        current_vertex = parent[current_vertex];
        reversed_path_from_start_to_end.push_back(current_vertex);
    }while(parent[current_vertex] != -1);

    for(int i = reversed_path_from_start_to_end.size() - 1; i >= 0; i--){
        cout<< reversed_path_from_start_to_end[i]<<" ";
    }
    cout<<endl;

}

int main (){
    int n, m;
    int x, y;
    while(cin>>n>>m){
        graph Graph(n);
        for (int i=0; i<m; i++){
            cin>>x>>y;
            Graph[x].push_back(y);
            Graph[y].push_back(x);
        }
        printShortestPath(Graph, 0, n-1);
    }
}