/* 1.Polynomial
2.Bisection
3.False Position Method
4.Newton Raphson Method
5.Secant Method
ID:1705031
Name: Jannatunnaher
*/

#include<bits/stdc++.h>

/* Defining equation to be solved.
   Change this equation to solve another problem. */

#define    f(x)    x*x - x - 2
#define   g(x)   2*x -1 //Derivative of the function


using namespace std;

void Polynomial();
void Bisection();
void False();
void Newton();
void Secant();

int main()
{

    int n;
    cout<<"      Select any method  "<<endl;
    cout<<"Press 1, for Polynomial Method Solution"<<endl;
    cout<<"Press 2, for Bisection Method Solution"<<endl;
    cout<<"Press 3, for False Position Method Solution"<<endl;
    cout<<"Press 4, for Newton Raphson Method Solution"<<endl;
    cout<<"Press 5, for Secant Method Solution "<<endl<<endl;
    cin>>n;
    switch(n)
    {
    case 1:
        Polynomial();
        break;
    case 2:
        Bisection();
        break;
    case 3:
        False();
        break;
    case 4:
        Newton();
        break;
    case 5:
        Secant();
        break;
    }

    return 0;
}

void Polynomial()
{
    float a[100],sum=0,x;
    int n,i;
    cout<<"Welcome to Polynomial solution"<<endl;
    cout<<"Enter degree of the polynomial X  "<<endl;
    cin>>n;
    cout<<"Enter coefficient's of the polynomial X  "<<endl;
    for(i=n; i>=0; i--)
    {
        cout<<"Enter Coefficient of [ X^"<<i<<" ]  "<<endl;
        cin>>a[i];
    }

    cout<<"Enter the value of X  "<<endl;
    cin>>x;

    for(i=n; i>0; i--)
    {
        sum=(sum+a[i])*x;
    }

    sum=sum+a[0];

    cout<<"Value of the polynomial is = "<< sum<<endl;
}

void Bisection()
{
    float x0, x1, x, f0, f1, f, e;
    int step = 1;

    cout<<"Welcome to Bisection Method Solution"<< endl;

    cout<<"Enter first guess: ";
    cin>>x0;
    cout<<"Enter second guess: ";
    cin>>x1;
    cout<<"Enter tolerable error: ";
    cin>>e;

    f0 = f(x0);
    f1 = f(x1);

    if( f0 * f1 > 0.0)
    {
        cout<<"Incorrect"<< endl;
    }


    do
    {

        x = (x0 + x1)/2;
        f = f(x);

        cout<<"Iteration-"<< step<<":\t x = "<< setw(10)<< x<<" and f(x) = "<< setw(10)<< f(x)<< endl;

        if( f0 * f < 0)
        {
            x1 = x;
        }
        else
        {
            x0 = x;
        }
        step = step + 1;
    }
    while(fabs(f)>e);

    cout<<endl<< "Root is: "<<  x<<endl;
}

void False()
{
    float x0, x1, x, f0, f1, f, e;
    int step = 1;
    cout<<"Welcome to False Position Method Solution"<< endl;

    cout<<"Enter first guess: ";
    cin>>x0;
    cout<<"Enter second guess: ";
    cin>>x1;
    cout<<"Enter tolerable error: ";
    cin>>e;
    f0 = f(x0);
    f1 = f(x1);

    if( f0 * f1 > 0.0)
    {
        cout<<"Incorrect "<< endl;

    }


    do
    {
        x = x0 - (x0-x1) * f0/ (f0-f1);
        f = f(x);

        cout<<"Iteration-"<< step<<":\t x = "<< setw(10)<< x<<" and f(x) = "<< setw(10)<< f(x)<< endl;

        if( f0 * f < 0)
        {
            x1 = x;
            f1 = f;
        }
        else
        {
            x0 = x;
            f0 = f;
        }
        step = step + 1;
    }
    while(fabs(f)>e);

    cout<< endl<<"Root is: "<< x<< endl;

}

void Newton()
{
    float x0, x1, f0, f1, g0, e;
    int step = 1, N;

    cout<<"Welcome to Newton Raphson Method"<< endl;
    cout<<"Enter initial guess: ";
    cin>>x0;
    cout<<"Enter tolerable error: ";
    cin>>e;
    do
    {
        g0 = g(x0);
        f0 = f(x0);
        if(g0 == 0.0)
        {
            cout<<"Mathematical Error.";
            exit(0);
        }


        x1 = x0 - f0/g0;


        cout<<"Iteration-"<< step<<":\t x = "<< setw(10)<< x1<<" and f(x) = "<< setw(10)<< f(x1)<< endl;
        x0 = x1;

        step = step+1;

        f1 = f(x1);

    }
    while(fabs(f1)>e);

    cout<< endl<<"Root is: "<< x1;

}
void Secant()
{
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1, N;
    cout<<"Welcome to Secant Method Solution"<< endl;
    cout<<"Enter first guess: ";
    cin>>x0;
    cout<<"Enter second guess: ";
    cin>>x1;
    cout<<"Enter tolerable error: ";
    cin>>e;

    do
    {
        f0 = f(x0);
        f1 = f(x1);
        if(f0 == f1)
        {
            cout<<"Mathematical Error.";
            exit(0);
        }

        x2 = x1 - (x1 - x0) * f1/(f1-f0);
        f2 = f(x2);

        cout<<"Iteration-"<< step<<":\t x2 = "<< setw(10)<< x2<<" and f(x2) = "<< setw(10)<< f(x2)<< endl;

        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;

        step = step + 1;


    }
    while(fabs(f2)>e);

    cout<< endl<<"Root is: "<< x2;
}
