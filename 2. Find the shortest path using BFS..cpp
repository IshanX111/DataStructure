#include<bits/stdc++.h>
using namespace std;

int graph[20][20], que[20], visited[20], node, edge, i, j, frnt = 0, rear = -1;
int parent[20];

void bfs(int v)
{
    //visited[v]=1;
    for(i = 1; i <= node; i++)  //for all node
    {
        if(graph[v][i] && !visited[i]) //if there is any adjunct node and the node is not visited
        {
            if(parent[i]==0)
            {
                parent[i]=v;
            }

            que[++rear] = i; //push in the queue
        }
    }
    if(frnt <= rear)///queue is not empty
    {
        if(visited[que[frnt]] != 1 )//parent[que[frnt]]==0
        {

            visited[que[frnt]] = 1;
            printf(" %d ", que[frnt]);

        }

        bfs(que[frnt++]);

    }
}

int main()
{
    //graph input

    printf("Enter no of Node: ");
    scanf("%d",&node);

    printf("Enter no of Edge: ");
    scanf("%d", &edge);

    int so, des;
    for(int i=1; i<=edge; i++)
    {
        scanf("%d%d",&so,&des);
        graph[so][des] = 1;
        graph[des][so] = 1;
        //for undirected graph
    }

    int v;
    printf("\nEnter the starting node: ");
    scanf("%d", &v);
    visited[v] = 1;
    printf("Level order traversal: %d ", v);
    bfs(v);
    cout<<endl;
    int y;
    cin>>y;
    while(y!=v)
    {
        y=parent[y];
        cout<<y<<" ";
    }
    cout<<endl;

    //return 0;
}
