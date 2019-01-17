#include <iostream>
#include <vector>
#include <queue>


using namespace std;

typedef pair<int, int> road; // road of cost .first to vertex .second
using country = vector<vector<road>>;

int mst(country &mapOfRoads) {
    int n = mapOfRoads.size();
    vector <bool> visited(n, false);
    visited[0] = true;
    priority_queue<road, vector<road>, greater<road> > queueToVisit;

    for (road roadFromFirstVertex : mapOfRoads[0]){
        queueToVisit.push(roadFromFirstVertex);
    }


    int already_added_to_mst_count = 1;
    int total_cost = 0;
    while(already_added_to_mst_count < n){
        int cost = queueToVisit.top().first;
        int nextVertex = queueToVisit.top().second;
        queueToVisit.pop();

        if(not visited[nextVertex]){
            visited[nextVertex] = true;
            total_cost += cost;
            already_added_to_mst_count++;
            for (road roadFromNextVertex: mapOfRoads[nextVertex]){
                queueToVisit.push(roadFromNextVertex);
            }
        }

    }

    return total_cost;
}


int main(){
    int n, m;
    while(cin>>n>>m){
        int cost_before = 0;
        country mapOfRoads(n);
        for(int i=0; i < m; ++i){
            int u, v, cost;
            cin>>u>>v>>cost;
            mapOfRoads[u].push_back({cost, v});
            mapOfRoads[v].push_back({cost, u});
            cost_before += cost;
        }
        int minimum_cost = mst(mapOfRoads);
        cout<<cost_before - minimum_cost<<endl;
    }
}