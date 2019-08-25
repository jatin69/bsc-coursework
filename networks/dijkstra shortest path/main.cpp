#include <iostream>
using namespace std;

#define MAX_NODES 8
#define INFINITY 10000000

int n=MAX_NODES;

/* dist[i][j] is the distance from i to j */
int dist[MAX_NODES][MAX_NODES];

typedef enum {permanent, tentative} label_type;

struct state
{
    int predecessor;
    int length;
    label_type label;

} state[MAX_NODES];

void init_graph();
void shortest_path(int destination, int source, int[]);

int main()
{
    cout<<"\n\t DIJKSTRA's Shortest Path \t\n";
    int path[MAX_NODES];
    for(int i=0; i<MAX_NODES; i++)
    {
        path[i]=-1;
    }

    init_graph();
    int source=0;
    int destination;
    cout<<"\n\n\nEnter the destination Node : ";
    cin>>destination;

    shortest_path(destination,source,path);

    cout<<"\n\nPATH FOUND IS :\t\t";
    int i;
    for( i=0; i<MAX_NODES; i++)
    {
        if(path[i+1]==-1)
        {
            break;
        }
        cout<<path[i]<<"->";
    }
    cout<<path[i];
    cout<<"\n\n";
    return 0;
}

void init_graph()
{
    /* Initializing distance to -1 */
    for(int i=0; i<MAX_NODES ; i++)
    {
        for( int j=0; j<MAX_NODES ; j++)
        {
            dist[i][j]= -1;
        }
    }

    cout<<"\n\nINITIALIZING GRAPH . . . .\n";
    for(int i=0; i<MAX_NODES ; i++)
    {
        cout<<"\nSOURCE NODE is : "<<i<<" \n\n";
        for( int j=i; j<MAX_NODES ; j++)
        {
            if(i==j)
            {
                dist[i][j]= dist[j][i]= 0;
            }
            if(dist[i][j]== -1)
            {
                cout<<"Direct-distance from NODE "<<i<<" to NODE "<<j<<" : ";
                cin>>dist[i][j];
                dist[j][i]=dist[i][j];
            }
        }

    }

    cout<<"GRAPH successfully initialized.";
}

void shortest_path(int s, int t, int path[])
{
    int i,k,min;
    struct state *p;

    for(p=&state[0]; p<&state[n]; p++)
    {
        p->predecessor=-1;
        p->length=INFINITY;
        p->label=tentative;
    }

    state[t].length=0;
    state[t].label= permanent;


    k=t;    /* k is the initial working node */
    do
    {
        /* Calculate the length of optimal direct path between 'source node' to any neighbour node*/
        for(i=0; i<n; i++)
        {
            /* If there is a "direct path" between 'k' and all nodes &
            the destination node is tentative */
            if(dist[k][i]!=0 && state[i].label==tentative)
            {
                /* If the length of this new path < the former length of the destination node - INFINITY initially */
                if (state[k].length + dist[k][i] < state[i].length)
                {
                    /* set predecessor and the length to reach this node*/
                    state[i].predecessor = k;
                    state[i].length = state[k].length + dist[k][i];
                }
            }
        }

        /* Find the tentatively labeled node with the smallest label */
        k=0;
        min=INFINITY;
        for(i=0; i<n; i++)
        {
            if(state[i].label==tentative && state[i].length < min)
            {
                min=state[i].length;
                k=i;
            }
        }
        state[k].label=permanent;
    }
    while(k!=s);

    /* copy the path to output array*/
    i=0;
    k=s;
    do
    {
        path[i]=k;
        i++;
        k=state[k].predecessor;
    }
    while(k>=0);

}
