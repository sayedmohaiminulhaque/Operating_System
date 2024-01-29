#include<bits/stdc++.h>
using namespace std;
int main()
{
    string p[200];
    int a[200],b[200],n=5,c[200],t[200],w[200];

    for(int i=0; i<n; i++)
    {
        cin>>p[i]>>a[i]>>b[i];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {

            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
                swap(p[i],p[j]);
                swap(b[i],b[j]);
            }
        }

    }

    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            c[i]=b[i];
        }

        else if(a[i]>c[i-1])
        {
            c[i]=a[i]+b[i];
        }

        else
        {
            c[i]=c[i-1]+b[i];
        }

    }
    for(int i=0; i<n; i++)
    {
        t[i]=c[i]-a[i];
        w[i]=t[i]-b[i];

    }

    cout<<"\n";
    cout<<"\n";
    cout<<"PN\t AT\t BT\t CT\t TAT\t WT\n";
    for(int i=0; i<n; i++)
    {
        cout<<p[i]<<"\t"<<a[i]<<"\t"<<b[i]<<"\t"<<c[i]<<"\t"<<t[i]<<"\t"<<w[i]<<"\n";
    }



}


/*

p1 3 1
p2 4 5
p3 0 2
p4 3 7
p5 5 5

*/
