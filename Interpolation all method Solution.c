/* 1.Linear Interpolation Method
   2.Lagrange Interpolation Method
   3.Newton's Interpolation Polynomial Method
   4.Newton's Divided Difference Interpolation Method
   5.Newton's Backward interpolation
   6.Newton's Forward interpolation
ID:1705031
Name: Jannatunnaher
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
int fact(int);
int fact1(int);

void LinearInterpolation();
void LagrangeInterpolation();
void NewInterPoly();
void NewDividedDifInterpolation();
void NewBackwardInterpolation();
void NewForwardInterpolation();

int main()
{
    int n;
    printf("select any methods\n");
    printf("Press 1, for Linear Interpolation Method Solution\n");
    printf("Press 2, for Lagrange Interpolation Method Solution\n");
    printf("Press 3, for Newton's Interpolation polynomial Method Solution\n");
    printf("Press 4, for Newton's Divided Difference Interpolation Method Solution\n");
    printf("Press 5, for Newton's Backward interpolation Method Solution\n");
    printf("Press 6, for Newton's Forward interpolation Method Solution\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        LinearInterpolation();
        break;
    case 2:
        LagrangeInterpolation();
        break;
    case 3:
        NewInterPoly();
        break;
    case 4:
        NewDividedDifInterpolation();
        break;
    case 5:
        NewBackwardInterpolation();
        break;
    case 6:
        NewForwardInterpolation();
        break;
    }

    return 0;

}

void LinearInterpolation()
{
 float x0,y0,x1,y1,xx,yy;

 printf("\nWelcome to Linear Interpolation Method\n");
 printf("Enter first point (x0,y0):\n");
 scanf("%f%f",&x0,&y0);
 printf("Enter second point (x1,y1):\n");
 scanf("%f%f",&x1,&y1);
 printf("Enter interpolation point: ");
 scanf("%f", &xx);

 yy = y0+((y1-y0)/(x1-x0))*(xx - x0);
 printf("Interpolated value at %0.3f is %0.3f", xx, yy);
 return 0;
}


void LagrangeInterpolation()
{
	 float x[100], y[100], xx, yy=0, p;
	 int i,j,n;
     printf("\nWelcome to Lagrange Interpolation Method\n");
	 printf("Enter number of data: ");
	 scanf("%d", &n);
	 printf("Enter data:\n");
	 for(i=1; i<=n; i++)
	 {
		  printf("x[%d] = ", i);
		  scanf("%f", &x[i]);
		  printf("y[%d] = ", i);
		  scanf("%f", &y[i]);
	 }
	 printf("Enter interpolation point: ");
	 scanf("%f", &xx);

	 for(i=1; i<=n; i++)
	 {
		  p=1;
		  for(j=1; j<=n; j++)
		  {
			   if(i!=j)
			   {
			    	p=p*(xx-x[j])/(x[i]-x[j]);
			   }
		  }
		  yy=yy+p*y[i];
	 }
	 printf("Interpolated value at %.3f is %.3f.", xx, yy);
}


void NewInterPoly()
    {
        int i,j,n,k;
        float X[10],Y[10],d[10][10],x,t,y=0,s=1;
        printf("\nWelcome to Newton's Interpolation Polynomial Method\n");
        printf("Enter the value of n : ");
        scanf("%d",&n);
        printf("\nEnter the value of X[i] and Y[i] : \n");
        printf("X[i]\tY[i]\n");
        for(i=0; i<n; i++)
        scanf("%f%f",&X[i],&Y[i]);
        printf("Enter the value of x  : ");
        scanf("%f",&x);
        for(j=0; j<n; j++)
            for(i=0; i<n-j; i++)
                d[i][j]=0;
        for(i=0; i<n; i++)
            d[i][0]=Y[i];
        for(j=0; j<n; j++)
            for(i=0; i<n-j; i++)
            {
                if(j==0)    continue;
                d[i][j]=(d[i+1][j-1]-d[i][j-1])/(X[i+j]-X[i]);
            }
        y=Y[0];
        for(k=1;k<n;k++)
        {
            s=s*(x-X[k-1]);
            t=s*d[0][k];
            y=y+t;
        }
        printf("\nInterpolated value is = %f .",y);
    }

void NewDividedDifInterpolation()
{
  float x[10],y[10][10],sum,p,u,temp;
  int i,n,j,k=0,f,m;
  //float f(int);
  printf("\nWelcome to Newton's Divided Interpolation Method\n");
  printf("How many record you will be enter: ");
  scanf("%d",&n);
  for(i=0; i<n; i++)
  {
   printf("\nEnter the value of x%d: ",i);
   scanf("%f",&x[i]);
   printf("\nEnter the value of f(x%d): ",i);
   scanf("%f",&y[k][i]);
  }
  printf("\nEnter X for finding f(x): ");
  scanf("%f",&p);

  for(i=1;i<n;i++)
  {
    k=i;
    for(j=0;j<n-i;j++)
    {
     y[i][j]=(y[i-1][j+1]-y[i-1][j])/(x[k]-x[j]);
     k++;
    }
  }
  printf("\n  x(i)\t   y(i)\t    y1(i)    y2(i)    y3(i)    y4(i)");

  for(i=0; i<n; i++)
  {
    printf("n %.3f",x[i]);
    for(j=0;j<n-i;j++)
    {
     printf("   ");
     printf(" %.3f",y[j][i]);
    }
   printf("\n");
  }

  i=0;
  do
  {
   if(x[i]<p && p<x[i+1])
    k=1;
   else
    i++;
  }while(k != 1);
  f=i;

  sum=0;
  for(i=0;i<n-1;i++)
  {
   k=f;
   temp=1;
   for(j=0;j<i;j++)
   {
    temp = temp * (p - x[k]);
    k++;
   }
    sum = sum + temp*(y[i][f]);
  }
  printf("\nf(%.2f) = %f ",p,sum);
}



void NewBackwardInterpolation()
{
int n,i,j,ch=30;
float arr[10][11],px=1,x,y,p,h;
printf("\nWelcome to Newton's Backward Interpolation Method\n");
printf("Enter the no of data:");
scanf("%d",&n);
printf("\nEnter the data: \n");
for(i=0;i<n;i++)
{
printf("X%d=",i+1);
scanf("%f",&arr[i][0]);
printf("Y%d=",i+1);
scanf("%f",&arr[i][1]);
}

for(j=2; j<=n; j++)
{for(i=0; i<n-1; i++)
arr[i][j]=arr[i+1][j-1]-arr[i][j-1];
}

//printing table
printf("\nThe difference table");
printf("\n\tX  \tY");
for(i=0;i<n-1;i++)
printf("\t%c^%d",ch,i+1);
for(i=0;i<n;i++)
{printf("\n");
for(j=0;j<n+1-i;j++)
printf("\t%.2f",arr[i][j]);
}

printf("\nEnter the value of x for f(x)");
scanf("%f",&x);

h=arr[n-1][0]-arr[n-2][0];
p=(x-arr[n-1][0])/h;
y=arr[n-1][1];
for(i=1;i<n;i++)
{
px=px*(p+(i-1));
y=y+(arr[n-1-i][i+1]*px)/fact(i);
}
printf("Interpolated value at %0.3f is %0.3f",x,y);
}
int fact(int n)
{ int f=1,i;
for(i=1;i<=n;i++)
f=f*i;
return f;
}

void NewForwardInterpolation()
{
float arr[10][11],x,h,p,y,px=1;
int i,j,n,ch=30;
printf("\nWelcome to Newton's Forward Interpolation Method\n");
printf("Enter the number of data: ");
scanf("%d",&n);
for(i=0; i<n; i++)
{ printf("X%d=",i+1);
scanf("%f",&arr[i][0]);
printf("Y%d=",i+1);
scanf("%f",&arr[i][1]);
}

for(j=2; j<=n; j++)
for(i=0; i<n-1; i++)
arr[i][j]=arr[i+1][j-1]-arr[i][j-1];

//printing table
printf("\nThe difference table");
printf("\n\tX  \tY");
for(i=0;i<n-1;i++)
printf("\t%c^%d",ch,i+1);
for(i=0;i<n;i++)
{printf("\n");
for(j=0;j<n+1-i;j++)
printf("\t%.2f",arr[i][j]);
}

printf("\nEnter the value x for function f(x): ");
scanf("%f",&x);

h=arr[1][0]-arr[0][0];
p=(x-arr[0][0])/h;
y=arr[0][1];
for(i=1;i<n;i++)
{ px=px*(p-(i-1));
y=y+(arr[0][i+1]*px)/fact(i);
}
printf("Interpolated value at %0.3f is %0.3f\n",x,y);

int fact1(int n)
{ int i,f=1;
for(i=1;i<=n;i++)
f=f*i;
return f;
}
}
