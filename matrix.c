#include<stdio.h>
#define MAX 20
typedef struct
{
	int col;
	int row;
	int value;
}term;

term
a[MAX],b[MAX],b1[MAX],b2[MAX],B1[MAX],B2[MAX],b3[MAX];
void printsparse(term a[MAX]);
void readsparse(term a[MAX]);
void transpose(term b1[MAX], term b2[MAX]);
void fast_transpose(term B1[MAX], term B2[MAX]);
void addsparse(term b1[MAX],term b2[MAX],term b3[MAX]);
int main()
{
int m,n,ch;
do{
printf("\n1.enter sparse matrix A\n2.enter sparse matrix B\n3.disply sparse matarix A\n4.display sparse matrix B\n5.simple transpose of A\n6.fast transepose B \n7.addition of sparse");
printf("\nenter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: readsparse(b1);
break;
case 2: readsparse(b2);
break;
case 3: printsparse(b1);
break;
case 4: printsparse(b2);
break;
case 5: transpose(b1,b2);
printsparse(b2);
break;
case 6: fast_transpose(b1,b2);
printsparse(b2);
break;
case 7:addsparse(b1,b2,b3);
printsparse(b3);
break;
    }
}while(ch!=8);

}

void readsparse(term a[])
{
int i,j,t,m,n,k;
printf("\nEnter the size of matrix (rows,columns):");
scanf("%d%d",&m,&n);
printf("\nEnter the data:");
    k=1;
for(i=0;i<m;i++)
    {
for(j=0;j<n;j++)
        {
scanf("%d",&t);
if(t!=0)
                {
a[k].row=i;
a[k].col=j;
a[k].value=t;
k++;
                }
        }
    }
a[0].row=m;
a[0].col=n;
a[0].value=k-1;
return;
}
void printsparse(term a[MAX])
{
int i,n;
   n=a[0].value;
printf("\nRow column value");
printf("\n%d\t%d\t%d",a[0].row,a[0].col,n);
printf("\n");
for(i=1;i<=n;i++)
   {
printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].value);
   }
}
void transpose(term b1[],term b2[])
{
int i,j,k,n;
b2[0].row=b1[0].col;
b2[0].col=b1[0].row;
b2[0].value=b1[0].value;
   k=1;
   n=b1[0].value;
for(i=0;i<b1[0].col;i++)
   {
for(j=1;j<=n;j++)
      {
if(i==b1[j].col)
        {
b2[k].row=i;
b2[k].col=b1[j].row;
b2[k].value=b1[j].value;
k++;
        }
      }
   }
}
void fast_transpose(term B1[MAX],term B2[MAX])
{
int m,n,t,i,col_num,location;
int total[MAX],index[MAX];
  m=B1[0].row;
  n=B1[0].col;
  t=B1[0].value;
B2[0].row=n;
B2[0].col=m;
B2[0].value=t;
for(i=0;i<n;i++)
total[i]=0;
for(i=1;i<=t;i++)
    {
col_num=B1[i].col;
total[col_num]++;
    }
index[0]=1;
for(i=1;i<n;i++)
index[i]=index[i-1]+total[i-1];
for(i=1;i<=t;i++)
  {
col_num=B1[i].col;
location=index[col_num];
index[col_num]++;
B2[location].row=B1[i].col;
B2[location].col=B1[i].row;
B2[location].value=B1[i].value;
  }
}
void addsparse(term b1[MAX],term b2[MAX],term b3[MAX])
{
int t1,t2,i,j,k;
   t1=b1[0].value;
   t2=b2[0].value;
   i=j=k=0;
b3[0].row=b1[0].row;
b3[0].col=b1[0].col;
while(i<=t1 && j<=t2)
  {
if(b1[i].row<b2[j].row)
    {
b3[k].row=b1[i].row;
b3[k].col=b1[i].col;
b3[k].value=b1[i].value;
k++;
i++;
continue;
    }
if(b2[i].col<b1[j].col)
    {
b3[k].row=b1[j].row;
b3[k].col=b1[j].col;
b3[k].value=b1[j].value;
k++;
j++;
continue;
    }
if(b2[j].col<b1[i].col)
    {
b3[k].row=b2[j].row;
b3[k].col=b2[j].col;
b3[k].value=b2[j].value;
k++;
i++;
    }
if(b2[j].col<b1[i].col)
   {
b3[k].row=b2[j].row;
b3[k].col=b2[j].col;
b3[k].value=b2[j].value;
k++;
j++;
continue;
   }
b3[k].row=b1[i].row;
b3[k].col=b1[i].col;
b3[k].value=b1[i].value+b2[j].value;
k++;
i++;
j++;
 }
while(i<=t1)
    {
b3[k].row=b1[i].row;
b3[k].col=b1[i].col;
b3[k].value=b1[i].value;
i++;
k++;
    }
while(j<=t2)
    {
b3[k].row=b2[j].row;
b3[k].col=b2[j].col;
b3[k].value=b2[j].value;
i++;
k++;
    }
b3[0].value=k-1;
}
