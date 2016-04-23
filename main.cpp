#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool ifSimple(int n)
{
    int c=0;
    int d=0;
    for(int i=2;i<=sqrt(n);++i)
    {
        c=n%i;
        d=n/i;
        if(c==0) return false;
    }
    return true;
}

bool ifCircularPrime(int n,int *mass)
{
    int n2=n;
    int num=0;
    int numMove=0;
    int base=1;
    while(n2)
    {
        num++;
        n2/=10;
    }
    for(int i=0;i<num-1;++i)
        base*=10;

    int lastAlpha=0;
    for(int i=0;i<num-1;++i)
    {
        lastAlpha=n%10;
        n/=10;
        n=lastAlpha*base+n;
        if(mass[n]==1) numMove++;
    }
    if(numMove==num-1) return true;
        else
    return false;
}

int main()
{
    int n;
    int ans=0;
    cout<<"Input n=";
    cin>>n;
    vector<int> simple;
    int *mass=new int[1000001];
    for(int i=0;i<1000001;++i)
        mass[i]=0;
    for(int i=2;i<n;++i)
    {
        if(ifSimple(i))
        {
            mass[i]=1;
            simple.push_back(i);
        }
    }

    for(vector<int>::iterator i=simple.begin();i!=simple.end();++i)
        if(ifCircularPrime(*i,mass))
        {
            ans++;
            //cout<<*i<<" ";
        }

    cout<<"ans="<<ans;
}
