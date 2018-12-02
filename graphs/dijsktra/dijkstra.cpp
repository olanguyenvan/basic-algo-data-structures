#include<iostream>
#include<queue>

using namespace std;
typedef pair<int,int> P;
using graph =  vector<vector<P> >;


int calculateMst(const graph &Graph){
    int n = Graph.size();
    vector<bool> visited(n, false);
    visited[0] = true;

    priority_queue<P, vector<P>, greater<P> > priorityQueue;

    for(P vertexVisibleFrom0: Graph[0]){
        priorityQueue.push(vertexVisibleFrom0); // at first only add vertices visible from the frist one to the queue
    }

    int visitedNodesCount = 1;
    int sum = 0;
    while (visitedNodesCount < n){

        int cost = priorityQueue.top().first;
        int vertex = priorityQueue.top().second;
        priorityQueue.pop();

        if (not visited[vertex]){ // we could have added this vertex multiple times to queue
            visited[vertex] = true;

            for(P visibleVertexFromCurrentOne: Graph[vertex]){
                priorityQueue.push(visibleVertexFromCurrentOne);
            }
            sum += cost;
            visitedNodesCount++;
        }
    }

    return sum;
}

int main(){
    P edgeFrom0To1, edgeFrom0To2;
    edgeFrom0To1.first = 11; //cost
    edgeFrom0To1.second = 1;
    edgeFrom0To2.first = 20;
    edgeFrom0To2.second = 2;


    P edgeFrom1To0,edgeFrom1To2,  edgeFrom1To3;
    edgeFrom1To0.first = 11;
    edgeFrom1To0.second = 0;
    edgeFrom1To2.first = 5;
    edgeFrom1To2.second = 2;
    edgeFrom1To3.first = 12;
    edgeFrom1To3.second = 3;

    P edgeFrom2To0, edgeFrom2To1, edgeFrom2To3;
    edgeFrom2To0.first = 20;
    edgeFrom2To0.second = 0;
    edgeFrom2To1.first = 5;
    edgeFrom2To1.second = 1;
    edgeFrom1To3.first = 4;
    edgeFrom1To3.second = 3;


    P edgeFrom3To1, edgeFrom3To2;
    edgeFrom3To1.first = 12;
    edgeFrom3To1.second = 1;
    edgeFrom3To2.first = 4;
    edgeFrom3To2.second = 2;

    graph Graph(4);
    Graph[0].push_back(edgeFrom0To1);
    Graph[0].push_back(edgeFrom0To2);

    Graph[1].push_back(edgeFrom1To0);
    Graph[1].push_back(edgeFrom1To2);
    Graph[1].push_back(edgeFrom1To3);

    Graph[2].push_back(edgeFrom2To0);
    Graph[2].push_back(edgeFrom2To1);
    Graph[2].push_back(edgeFrom2To3);

    Graph[3].push_back(edgeFrom3To1);
    Graph[3].push_back(edgeFrom3To2);


    cout<<"calcualte mst cost: "<<endl;
    cout<<calculateMst(Graph);
}