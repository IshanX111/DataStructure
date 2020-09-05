#include<bits/stdc++.h>
using namespace std;
int graph[20][20], visited[20], node, edge, i, j;
int check[20];
int k=0;
void dfs(int v)
{
    int j;
    visited[v] = 1;
    check[k]=v;
    k++;
    printf(" %d->",v);
    for(j=1; j <= node; j++)
    {
        if(graph[v][j] && !visited[j])
            dfs(j);
    }
}

int main()
{
    printf("Enter no of Node: ");
    scanf("%d",&node);

    printf("Enter no of Edge: ");
    scanf("%d", &edge);

    int so, des;
    for(int i=1; i<=edge; i++)
    {
        scanf("%d %d",&so, &des);
        graph[so][des] = 1;
        graph[des][so] = 1;
        //for undirected graph
    }

    int v;
    printf("\nEnter the starting node: ");
    scanf("%d", &v);
    printf("DFS traversal: ");
    dfs(v);
    cout<<endl;
    int desired_node;
    int c=0;
    cout<<"Enter the desired Node ";
    cin>>desired_node;
    for(int i=0; i<node; i++)
    {
        if(check[i]==desired_node)
        {
            c++;
            break;
        }
    }
    if(c==0)
    {
        cout<<"There's no way or the node is not connected "<<endl;
    }
    else
    {
        cout<<"Found"<<endl;
    }

}
