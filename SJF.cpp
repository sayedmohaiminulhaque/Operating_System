#include<bits/stdc++.h>
using namespace std;

int main()
{
    int wt[10000],temp;
    double avg,sum=0;
    string b[10000];
    for(int i=0; i<10000; i++)
    //string b;
    {
        wt[i]=-1;
        //scanf("%s",&b);
        //printf("%s",b);
    }

    map<int,string>mp;

    mp.insert({7,"P0"});
    mp.insert({12,"P1"});
    mp.insert({2,"P3"});
    mp.insert({15,"P4"});
    mp.insert({3,"P5"});
    mp.insert({6,"P6"});
    mp.insert({25,"P7"});
    mp.insert({10,"P8"});
    mp.insert({9,"P9"});
    mp.insert({14,"P10"});
    mp.insert({17,"P11"});
    mp.insert({27,"P12"});


    for(int i=0; i<10000; i++)
    {
        if(mp.count(i)!=0)
        {
            if(i==0)
            {
                wt[i]=0;
                temp=0;
                sum=sum+wt[i];
            }
            else
            {
                wt[i]=wt[temp]+i;
                temp=i;
                sum=sum+wt[i];
            }
            /*cout<<b[i]<<"   "<<wt[i]<<"  ";
            for(int j=0; j<a[i]; j++)
            {
                cout<<"* ";
            }
            cout<<"\n";*/
        }
    }
    avg=sum/12;
    cout<<"Process  "<<"Waiting_Time      "<<"Average    "<<"Working\n";
     for(int i=0; i<10000; i++)
    {
        if(mp.count(i)!=0)
        {
            cout<<mp.at(i)<<"           "<<wt[i]<<"             "<<avg<<"       ";

            for(int j=0; j<i; j++)
            {
                cout<<"*";
            }
            cout<<"\n";
        }
    }


    return 0;
}

