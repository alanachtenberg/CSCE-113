//Alan Achtenberg
//CSCE 113-501
//Assignment 3
//Problem 1

//program to find the real roots of ax^2+bx+c


#include "std_lib_facilities_3.h"

struct no_real_roots {};

double compute_error(const double a,const double b, const double c, double& root);

double compute_discriminant(const double a,const double b, const double c);

void double_real_root(const double a,const double b,const double c, double& root);

void two_real_roots(const double a, const double b, const double c, const double discriminant, double& root1, double& root2);

void linear_equation(const double b, const double c, double& root);


double compute_error(const double a,const double b, const double c, double& root)
{
    double err;
    err=(a*root*root)+(b*root)+c;
    return err;
}
double compute_discriminant(const double a,const double b, const double c)
try
{
    double disc=0;
    disc=(b*b-(4*a*c));
    if (disc<0)
        throw no_real_roots();
    return disc;
}
catch (no_real_roots)
{
    cout<< "error no real roots of the equation \n";
    return -1; //return negative number to keep main from calling two real roots
}

void double_real_root(const double a,const double b,const double c, double& root)
{
    root=(-b)/(2*a);
}
void two_real_roots(const double a, const double b, const double c, const double discriminant, double& root1, double& root2)
{
    root1=-b/(2*a);
    root2=root1;
    root1+=(sqrt(discriminant)/(2*a));
    root2-=(sqrt(discriminant)/(2*a));
}
void linear_equation(const double b, const double c, double& root)
{
    root=-c/b;
}



int main()
{
    char t;
    double a,b,c;
    double root1,root2;

    while(1)
    {
        cout<<"input q to quit, any other char to continue \n";
        cin>>t;
        if(t=='q')
            break;
        cout<<"input the coefficients a b c of the form ax^2+bx+c\n";
        cin>>a>>b>>c;
        double discriminant=compute_discriminant(a,b,c);

        if(a==0&&b!=0)
        {
            linear_equation(b,c,root1);
            cout<<"this is a linear equation with the root= "<<root1<<endl;
            cout<<"the computational error is "<<compute_error(a,b,c,root1)<<endl;
        }
        if(a==0&&b==0)
        {
            cout<<"this equation has no real roots\n";
        }

        if(discriminant==0&&(a||b!=0))
        {
            double_real_root(a,b,c,root1);
            cout<<"this is an equation with a double real root= "<<root1<<endl;
            cout<<"the computational error is "<<compute_error(a,b,c,root1)<<endl;
        }
        if(discriminant>0&&a!=0)
        {
            two_real_roots(a,b,c,discriminant,root1,root2);
            cout<<"this equation has two real roots = "<<root1<<" and "<<root2<<endl;
            cout<<"the computational error for root 1 is "<<compute_error(a,b,c,root1)<<endl;
            cout<<"the computational error for root 2 is "<<compute_error(a,b,c,root2)<<endl;
        }
    }





    keep_window_open();
    return 0;

}

