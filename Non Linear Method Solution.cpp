/* 1.Polynomial Method
   2.Bisection Method
   3.False Position Method
   4.Newton's Raphson Method
   5.Secant Method
ID:1705031
Name: Jannatunnaher
*/
#include<stdio.h>
#include<math.h>
int fact(int);
int fact1(int);

void polymonial();
void bisection();
void falseposition();
void newtonraphson();
void secant();

int main()
{
    int n;
    printf("select any methods\n");
    printf("Press 1, for Polynomial methos Solution\n");
    printf("Press 2, for Bisection Method Solution\n");
    printf("Press 3, for False Poisition Method Solution\n");
    printf("Press 4, for Newton Raphson Method Solution\n");
    printf("Press 5, for Secant Method Solution\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        polymonial();
        break;
    case 2:
        bisection();
        break;
    case 3:
        falseposition();
        break;
    case 4:
        newtonraphson();
        break;
    case 5:
        secant();
        break;
    }

    return 0;

}

void polymonial(){
     float a[50000], POLY=0,x;
     int n,i;

     printf("Enter degree of the polynomial X :: ");
     scanf("%d",&n);
     printf("Enter coefficient's of the polynomial X :: \n");
     for(i=n; i>=0; i--)
     {
            printf("Enter Coefficient of [ X^%d ] :: ",i);
            scanf("%f",&a[i]);
     }

     printf("Enter the value of X :: ");
     scanf("%f",&x);

     for(i=n; i>0; i--)
     {
        POLY =(POLY+a[i])*x;
     }

     POLY=POLY+a[0];

     printf("Value of the polynomial is = %f\n",POLY);

}
void bisection(){
	 float x0,x1,x,f0,f1,f,e;
	 int t=1;
	 cout<<"1st iteration: ";
     cin>>x0;
     cout<<"2nd iteration: ";
     cin>>x1;
     cout<<"Error percentage: ";
     cin>>e;
     f0=f(x0);
	 f1=f(x1);


	 if(f0*f1>0.0)
	 {
		  cout<<"Incorrect iteration."<< endl;
     }
	 do
	 {
		  x=(x0+x1)/2;
		  f=f(x);

       cout<<"Iteration no, "<<t<<" for x = "<<x<<" and f(x) = "<<f(x)<< endl;

		  if(f0*f<0)
		  {
			   x1=x;
		  }
		  else
		  {
			   x0=x;
		  }
		  t=t+1;
	 }while(fabs(f)>e);

	 cout<< endl<<"Approximate root is: "<<x<< endl;

}
void falseposition()
