#include<iostream>
#include<cmath>
#include<climits>
#define MAX_NODES 10
using namespace std;

void bellmanFord(int src,int nodes,int graph[MAX_NODES][MAX_NODES]){
     int distance[MAX_NODES];
     for(int i=0;i<nodes;i++){
        distance[i] = INT_MAX;
     }
     distance[src] = 0;

     for(int k=0;k<nodes-1;k++){
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                if(graph[i][j] != 0 && distance[i] != INT_MAX && distance[i] + graph[i][j] < distance[j]){
                    distance[j] = distance[i] + graph[i][j]; 
                }
            }
        }
     }

     //check for negative cycle
     bool negativeCycle = false;
     for(int k=0;k<nodes-1;k++){
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                if(graph[i][j] != 0 && distance[i] != INT_MAX && distance[i] + graph[i][j] < distance[j]){
                    negativeCycle = true;
                    break;
                }
            }
        }
     }
     if(negativeCycle){
        cout<<"Graph contains negative cycle"<<endl;
     }
     else{
        cout<<"Vertex     distance from src:"<<endl;
        for(int i=0;i<nodes;i++){
            if(distance[i] == INT_MAX)
            cout<<i<<" -> "<<"not reachable"<<endl;
            else
            cout<<i<<" -> "<<distance[i]<<endl;
        }
     }
}

int main(){
    int nodes,graph[MAX_NODES][MAX_NODES],src;
    cout<<"Enter the number of nodes:";
    cin>>nodes;
    cout<<"Enter the adjancency matrix:";
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cin>>graph[i][j];
        }
    }
    cout<<"Enter the source node:";
    cin>>src;
    bellmanFord(src,nodes,graph);
    return 0;
}