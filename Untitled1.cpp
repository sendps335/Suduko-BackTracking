#include<bits/stdc++.h>
using namespace std;
#define N 9
void print_f(int grid[N][N])
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool valid_space(int grid[N][N],int row,int col,int ll)
{
	int i,j;
	bool b1,b2,b3;
	b1=false;
	b2=false;
	b3=false;
	//Checking for the row
	for(i=0;i<9;i++)
	{
		if(grid[row][i]==ll)
		{
			b1=true;
			break;
		}
	}
	for(i=0;i<9;i++)
	{
		if(grid[i][col]==ll)
		{
			b2=true;
			break;
		}
	}
	int roww=row-row%3;
	int coll=col-col%3;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(grid[i+roww][j+coll]==ll)
			{
				b3=true;
				break;
			}
		}
	}
	if((not b1)and (not b2) and (not b3) and grid[row][col]==0)
	{
		return true;
	}
	return false;
}
bool find_empty(int grid[N][N],int &row,int &col)
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(grid[i][j]==0)
			{
				row=i;
				col=j;
				return true;
			}
		}
	}
	return false;
}
bool solver(int grid[N][N])
{
	int l[2];
	int row,col;
	l[1]=0;
	l[0]=0;
	row=l[0];
	col=l[1];
	if(find_empty(grid,row,col)==false)
	{
		return true;
	}
	int ll;
	for(ll=1;ll<=9;ll++)
	{
		if(valid_space(grid,row,col,ll)==true)
		{
			grid[row][col]=ll;
			if(solver(grid)==true)
			{
			    return true;
			}
			grid[row][col]=0;
		}
	}
	return false;
}
int main()
{
	cout<<"Enter the Context of the Suduko Grid"<<endl;
	int t;
	cin>>t;
	while(t--){
	int grid[9][9];
	int i,j,h;
	bool k=true;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cin>>grid[i][j];
		}
		cout<<"Enter the New Row!!!"<<endl;
	}
	  k=solver(grid);
	  cout<<"The Result is"<<endl;
	  if(k==true)
	  {
	      print_f(grid);
      }
	}
	return 0;
}
