#include<bits/stdc++.h>
using namespace std;
int main()
{
    int req[3],aloc[3],ava,need[3],x,cnt=0;
    int sum=0,r=12;
    int arr[1000];
    string s[10000];
    int n=3;
// data read from file.. and data must need to be in this format
    /*

    7
    10
    5
    3
    4
    3

    */
    ifstream file("a.txt");

    while(file >> x)
    {
        if(cnt<n)
        {
            req[cnt]=x;
            cnt++;
        }
        else if(cnt<2*n)
        {
            aloc[cnt-n]=x;
            cnt++;
        }
        /*
        else
        {
            need[cnt-6]=x;
            cnt++;
        }
        */

    }
    // to calculate the need

    for(int i=0; i<n; i++)
    {
        need[i]=req[i]-aloc[i];
    }

    //map<int,string>mp;
    /*
        req[0]=7;
        req[1]=10;
        req[2]=5;



        aloc[0]=3;
        aloc[1]=4;
        aloc[2]=3;


        need[0]=4;
        need[1]=6;
        need[2]=2;

        */
    // define the proces name
    s[0]="p1";
    s[1]="p2";
    s[2]="p3";

    //calculate the sum and initial available
    for(int i=0; i<n; i++)
    {
        sum=sum+aloc[i];
        //cout<<sum<<endl;
    }
    ava=r-sum;
    /*
            mp.insert({4,"p1"});
            mp.insert({6,"p2"});
            mp.insert({2,"p3"});
    */



    int cnt1=0,k=0;
    cout<<ava<<endl;
    while(cnt1!=(n-1))
    {
loop:
        for(int i=0; i<n; i++)
        {

            if(ava>=need[i] && need[i]>=0)
            {
                // cout<<s[i]<<endl;
                ava=ava+aloc[i];
                cout<<s[i]<<" "<<ava<<endl;
                need[i]=-1;
                cnt1++;
                goto loop;
            }
        }
        k++;
        if(k>2)
        {
            break;
        }


    }

    if(ava==r)
    {
        cout<<"This Process is safe\n";
    }

    else
    {
        cout<<"This Process is not safe.\n";
        cout<<"The unsafe states are: ";
        for(int i=0; i<n; i++)
        {
            if(need[i]!=-1)
            {
                cout<<s[i]<<" ";
            }
        }
    }
    return 0;
}

