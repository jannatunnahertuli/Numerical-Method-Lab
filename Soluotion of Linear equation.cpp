/* 1. Gauss Elimination Method
2.Gauss Jordan Elimination Method
ID:1705031
Name: Jannatunnaher
*/
#include<bits/stdc++.h>

using namespace std;
void GaussElimination();
void GaussJordanElimination();
int main()
{
    int n;
    cout<<"Select any Methods: "<<endl;
    cout<<"Press 1, for Gauss Elimination Method Solution in linear equations"<<endl;
    cout<<"Press 2, for Gauss Jordan Elimination Method Solution in linear equation"<<endl;
    cin>>n;
    switch(n)
    {
    case 1:
        GaussElimination();
        break;
    case 2:
        GaussJordanElimination();
        break;
    }
    return 0;
}


void GaussElimination()
{
	 float arr[15][15], x[15], r;
	 int i,j,k,n;
     cout<<"Welcome to Gauss Elimination Solution"<<endl;
	 cout<<"\nEnter number of unknown value: ";
	 cin>>n;

	 cout<<"Enter Coefficients of Augmented Matrix: "<< endl;
	 for(i=1; i<=n; i++)
	 {
		  for(j=1; j<=n+1; j++)
		  {
			   cout<<"arr["<< i<<"]"<<"["<<j<<"]= ";
			   cin>>arr[i][j];
		  }
	 }

	 for(i=1; i<=n-1; i++)
	 {
		  if(arr[i][i] == 0.0)
		  {
			   cout<<"Error"<<endl;
			   exit(0);
		  }
		  for(j=i+1; j<=n; j++)
		  {
			   r=arr[j][i]/arr[i][i];

			   for(k=1;k<=n+1; k++)
			   {
			  		arr[j][k]=arr[j][k]-r*arr[i][k];
			   }
		  }
	 }

	 x[n] = arr[n][n+1]/arr[n][n];

	 for(i=n-1; i>=1; i--)
	 {
		  x[i] = arr[i][n+1];
		  for(j=i+1; j<=n; j++)
		  {
		  		x[i]=x[i]-arr[i][j]*x[j];
		  }
		  x[i] = x[i]/arr[i][i];
	 }


	 cout<< endl<<"Required Solution: "<< endl;
	 for(i=1; i<=n; i++)
	 {
	  	cout<<"x["<< i<<"] = "<< x[i]<< endl;
	 }

	 }

void GaussJordanElimination()
{
	 float arr[15][15], x[15], r;
	 int i,j,k,n;

     cout<<"Welcome to Gauss Jordan Elimination Solution"<<endl;
	 cout<<"\nEnter number of unknowns values: ";
	 cin>>n;

	 cout<<"Enter Coefficients of Augmented Matrix: "<< endl;
	 for(i=1; i<=n; i++)
	 {
		  for(j=1; j<=n+1; j++)
		  {
			   cout<<"arr["<< i<<"]"<<"["<<j<<"]= ";
			   cin>>arr[i][j];
		  }
	 }

     for(i=1; i<=n; i++)
     {
          if(arr[i][i] == 0.0)
          {
               cout<<"Mathematical Error!";
               exit(0);
          }
          for(j=1; j<=n; j++)
          {
               if(i!=j)
               {
                    r=arr[j][i]/arr[i][i];
                    for(k=1; k<=n+1; k++)
                    {
                        arr[j][k]=arr[j][k]-r*arr[i][k];
                    }
               }
          }
     }

     for(i=1; i<=n; i++)
     {
        x[i]=arr[i][n+1]/arr[i][i];
     }


	 cout<<"Required Solution: "<< endl;
	 for(i=1; i<=n; i++)
	 {
	  	cout<<"x["<< i<<"] = "<< x[i]<< endl;
	 }

}

