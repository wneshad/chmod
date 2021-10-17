#include <stdio.h>
int main()
{
    int p,r;
    
    printf("Enter number of processes: ");
    scanf("%d",&p);
    
    printf("\nEnter number of resources: ");
    scanf("%d",&r);
    
    //Enter Allocated resources
    int allo_r[p][r];
    printf("\n");
    for(int i=1;i<=p;i++)
    {
        printf("Enter Allocated resources for processes P%d: ",i);
        for(int j=1;j<=r;j++)
        {
            scanf("%d",&allo_r[i][j]);
        }
    }
    
    //Enter Maximum resources 
    printf("\n");
    int max_r[p][r];
    for(int i=1;i<=p;i++)
    {
        printf("Enter Maximum resources for processes P%d: ",i);
        for(int j=1;j<=r;j++)
        {
            scanf("%d",&max_r[i][j]);
        }
    }
    
    //Enter available resources
    int ava_r[r];
    printf("\nEnter available resources: ");
    for(int j=1;j<=r;j++)
        scanf("%d",&ava_r[j]);
    
    //print allocated resource
    printf("\nAllocated Resource Table\nP\t");
    for(int j=1;j<=r;j++)
        printf("R%d\t",j);
        
    printf("\n");
    for(int i=1;i<=p;i++)
    {
        printf("P%d\t",i);
        for(int j=1;j<=r;j++)
        {
            printf("%d\t",allo_r[i][j]);
        }
        printf("\n");
    } 
    
    //print max resource
    printf("\nMaximum Resource Table\nP\t");
    for(int j=1;j<=r;j++)
        printf("R%d\t",j);
        
    printf("\n");
    for(int i=1;i<=p;i++)
    {
        printf("P%d\t",i);
        for(int j=1;j<=r;j++)
        {
            printf("%d\t",max_r[i][j]);
        }
        printf("\n");
    } 
    
    int need[p][r];
    printf("\nNeed Table\nP\t");
    for(int j=1;j<=r;j++)
        printf("R%d\t",j);
        
    printf("\n");
    for(int i=1;i<=p;i++)
    {
        printf("P%d\t",i);
        for(int j=1;j<=r;j++)
        {
            need[i][j] = max_r[i][j] - allo_r[i][j];
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    } 
    
    //check safe
    int safe[p],f=0,k=0,safe_false[p],u=0;
    for(int i=1;i<=p;i++)
    {
        
        f=0;
        for(int j=1;j<=r;j++)
        {
            if(need[i][j]>ava_r[j])
            {
                f=1;
                break;
            }
        }
        
        if(f==0)
        {
            for(int j=1;j<=r;j++)
                ava_r[j] = ava_r[j] + allo_r[i][j];
            safe[++k]=i;
        }
        else
        {
            safe_false[++u]=i;
        }
    }
    
    //for false processes
    for(int i=1;i<=u;i++)
    {
        f=0;
        for(int j=1;j<=r;j++)
        {
            if(need[safe_false[i]][j]>ava_r[j])
            {
                f=1;
                break;
            }    
                
        }
        
        if(f==0)
        {
            for(int j=1;j<=r;j++)
                ava_r[j] = ava_r[j] + allo_r[safe_false[i]][j];
            safe[++k]= safe_false[i];
        }
        else
        {
            safe_false[++u]=i;
        }
    }
    
    //print safe state
    printf("\nSafe Sequence: <");
    for(int i=1;i<=k;i++)
    {
        printf("P%d ",safe[i]);
    }
    printf(">");
    return 0;
}
