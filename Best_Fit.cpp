#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=5;
    int a[n],b[n],x,cnt=0,cmp=INT_MAX,t,sum=0,k=0;
    vector<int>v;

    ifstream file("c.txt");

    while(file >> x)
    {
        if(cnt<n)
        {
            a[cnt]=x;
            cnt++;
        }
        else if(cnt<2*n)
        {
            b[cnt-n]=x;
            cnt++;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(b[j]>=a[i])
            {
                if(b[j]<cmp)
                {
                    cmp=b[j];
                    t=j;
                }
            }
        }
        if(cmp!=INT_MAX)
        {
            cout<<a[i]<<" "<<cmp<<" "<<cmp-a[i]<<"\n";
            sum+=cmp-a[i];
            b[t]=0;
            cmp=INT_MAX;
        }
        else
        {
            cout<<a[i]<<" "<<"Waiting.....\n";
            v.push_back(a[i]);
        }

    }
    cout<<"The total internal Fragmentation is: "<<sum<<"\n";
    for(int i=0; i<n; i++)
    {
        if(b[i]!=0)
        {
            sum+=b[i];
        }

    }
    for(int i=0; i<v.size(); i++)
    {
        if(sum>=v[i])
        {
            cout<<"External Fragmentation is present for: "<<v[i]<<"\n";
        }
        else
        {
            k++;
        }
    }
    if(k==v.size())
    {
        cout<<"External Fragmentation is not present.\n";

    }


    return 0;

}
