#include<bits/stdc++.h>
using namespace std;

int graph[20][20], que[20], visited[20], node, edge, i, j, frnt = 0, rear = -1;
int parent[20];
int level[200];
//int prior[200];

void setting_infinity(int n)
{

    int i;
    for(i=1; i<=n; i++)
    {
        level[i]=INT_MAX;
    }

}
void bfs(int v)
{

    vector<pair<int,int>>vp;
    vp.clear();
    for(i = 1; i <= node; i++)  //for all node
    {
        if(graph[v][i]) //if there is any adjunct node and the node is not visited
        {
            ///visited part ta dilam na cause amr barbar update kora lage //etar khetre  path abr inifinite hoye jay
            /*if(parent[i]==0){
                    parent[i]=v;
            }*/
            if(level[v]+graph[v][i]<level[i])
            {

                level[i]=level[v]+graph[v][i];
                parent[i]=v;

            }
            vp.push_back(make_pair(level[i],i)); ///making priority queue
            //prior[i]=level[i];
            //int m;
            //for(int j=0;j<=n;j++){
            //}
            //que[++rear] = i; //push in the queue
        }

    }
    sort(vp.begin(),vp.end());
    for(int k=0; k<vp.size(); k++)
    {

        que[++rear]=vp[k].second;


    }

    if(frnt <= rear)///queue is not empty
    {
        if(visited[que[frnt]] != 1 )//parent[que[frnt]]==0
        {

            visited[que[frnt]] = 1;
            //printf(" %d ", que[frnt]);

        }

        bfs(que[frnt++]);

    }
}

int main()
{
    //graph input

    printf("Enter no of Node: ");
    scanf("%d",&node);

    setting_infinity(node);
    printf("Enter no of Edge: ");
    scanf("%d", &edge);

    int so, des,cost;
    for(int i=1; i<=edge; i++)
    {
        scanf("%d%d%d",&so,&des,&cost);
        graph[so][des] = cost;
        //graph[des][so] = cost;
        //for undirected graph
    }

    int v;
    printf("\nEnter the starting node: ");
    scanf("%d", &v);
    level[v]=0;
    visited[v] = 1;

    bfs(v);
    cout<<endl;
    int y,x;
    cout<<"Enter the desired node : "<<endl;
    cin>>y;
    x=y;
    while(y!=v)
    {
        y=parent[y];
        cout<<y<<" ";
    }
    cout<<endl;
    //cout<<"Enter node to know the cost "<<endl;
    //int ll;
    //cin>>ll;
    cout<<level[x]<<endl;
    //return 0;
    //int n;
    //cin>>n;
    //setting_infinity(n);

    //for(i=0;i<n;i++){
    //cout<<level[i]<<endl;
    //}
    //checka();
    //for(i=0;i<n;i++){
    //cout<<level[i]<<endl;
    //}


}

