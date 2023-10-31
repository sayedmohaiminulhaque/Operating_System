#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[10000],wt[10000],temp;
    double avg,sum=0;
    string b[10000];
    for(int i=0; i<10000; i++)
    //string b;
    {
        a[i]=-1;
        wt[i]=-1;
        //scanf("%s",&b);
        //printf("%s",b);
    }
    a[2]=7;
    a[5]=12;
    a[1]=2;
    a[0]=15;
    a[7]=3;
    a[3]=6;
    a[9]=25;
    a[4]=10;
    a[6]=9;
    a[11]=14;
    a[10]=17;
    a[8]=27;

    b[2]="P0";
    b[5]="P1";
    b[1]="P3";
    b[0]="P4";
    b[7]="P5";
    b[3]="P6";
    b[9]="P7";
    b[4]="P8";
    b[6]="P9";
    b[11]="P10";
    b[10]="P11";
    b[8]="P12";

    for(int i=0; i<10000; i++)
    {
        if(a[i]!=-1)
        {
            if(i==0)
            {
                wt[i]=0;
                temp=0;
                sum=sum+wt[i];
            }
            else
            {
                wt[i]=wt[temp]+a[temp];
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
        if(a[i]!=-1)
        {
            cout<<b[i]<<"           "<<wt[i]<<"             "<<avg<<"       ";
            for(int j=0; j<a[i]; j++)
            {
                cout<<"*";
            }
            cout<<"\n";
        }
    }


    return 0;
}
