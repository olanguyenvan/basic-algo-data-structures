#include <iostream>
#include <vector>
using namespace std;

using graph = vector<vector<int> >;


void printGraph(const graph &G){
    cout<<endl<<"---printing graph---"<<endl;
    for(int i = 0; i < G.size(); i++){
        vector<int> row = G[i];
        cout<<i<<" must be before :";
        for (int j = 0; j < row.size() ; j ++){
            cout<<row[j]<<" ";
        }
        cout<<endl;
    }
}


void printVector(const vector<int> v){
    cout<<endl;
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


void printTopology(const graph precedence, vector<int> degree_in){
    vector<int> tasksWithDegreeZero;
    int n = degree_in.size();
//    for(int i = 0; i < n; i++){
    for(int i = n - 1; i >= 0; i--){
        if (degree_in[i] == 0){
            tasksWithDegreeZero.push_back(i);
        }
    }

    int printedTasks = 0;

    int currentlyExecutingTask;
    while(tasksWithDegreeZero.size() != 0){
        currentlyExecutingTask = tasksWithDegreeZero.back();
        tasksWithDegreeZero.pop_back();
        printedTasks++;
        cout<<currentlyExecutingTask;
        if(printedTasks < n){
            cout<<" ";
        }

        degree_in[currentlyExecutingTask] = -1; //so we dont find it again
        vector<int> tasksThatMustBeAfterCurrentlyExecutingTask = precedence[currentlyExecutingTask];

//        for(int i = 0; i < tasksThatMustBeAfterCurrentlyExecutingTask.size(); i++){
        for(int i = tasksThatMustBeAfterCurrentlyExecutingTask.size() - 1; i >= 0; i--){
            int after_task = tasksThatMustBeAfterCurrentlyExecutingTask[i];
            degree_in[after_task]--;
            if (degree_in[after_task] == 0){
                // add task
                tasksWithDegreeZero.push_back(after_task);
                int tmp;
                for (int j = tasksWithDegreeZero.size() - 1; j > 0; j--){
                    if(tasksWithDegreeZero[j-1] < tasksWithDegreeZero[j]){
                        tmp = tasksWithDegreeZero[j-1];
                        tasksWithDegreeZero[j-1] = tasksWithDegreeZero[j];
                        tasksWithDegreeZero[j] = tmp;
                    }else{
                        break;
                    }
                }
            }
        }

    }
    cout<<endl;
}



int main(){
    int n, m; // n vertices and m edges
    while(cin>>n>>m){
        graph precedence(n);
        vector<int> degree_in(n);

        for(int i=0; i<m; ++i){
            int task_before, task_after;
            cin>>task_before>>task_after;
            precedence[task_before].push_back(task_after);
            degree_in[task_after]++;
        }
        printTopology(precedence, degree_in);
    }

}