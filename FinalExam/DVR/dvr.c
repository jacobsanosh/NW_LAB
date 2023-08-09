#include <stdio.h>
struct node
{
        int dist[20], from[20];
} rt[10];
int main()
{
        int dmat[20][20], n, i, j, k, count = 0;
        printf("\nenter the no of node");
        scanf("%d", &n);
        printf("\nenter the cost matrix\t");
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        scanf("%d", &dmat[i][j]);
                        dmat[i][i] = 0;
                        rt[i].dist[j] = dmat[i][j];
                        rt[i].from[j] = j;
                }
        }
        do
        {
                count = 0;
                for (int i = 0; i < n; i++)
                {
                        for (int j = 0; j < n; j++)
                        {
                                for (int k = 0; k < n; k++)
                                {
                                        if (rt[i].dist[j] > dmat[i][k] + rt[k].dist[j])
                                        {
                                                rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                                                rt[i].from[j] = k;
                                                count++;
                                        }
                                }
                        }
                }
        } while (count != 0);
        for (int i = 0; i < n; i++)
        {
                printf("\n\nstate value is %d\n", i + 1);
                for (int j = 0; j < n; j++)
                {
                        printf("\nnode %d via router %d distance is %d ", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
                }
        }
}
