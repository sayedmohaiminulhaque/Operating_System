#include<bits/stdc++.h>
using namespace std;
int main()
{
    int req[5][3],aloc[5][3],ava[7][3],need[5][3],x,cnt=0;
    int sum1=0,sum2=0, sum3=0,r[]= {10, 5, 7};
    int arr[1000];
    string s[10000];
    int n=5;
// data read from file.. and data must need to be in this format
    /*

    7
    10
    5
    3
    4
    3


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


    }
    */
    // to calculate the need



    //map<int,string>mp;

    req[0][0]=7;
    req[0][1]=5;
    req[0][2]=3;

    req[1][0]=3;
    req[1][1]=2;
    req[1][2]=2;

    req[2][0]=9;
    req[2][1]=0;
    req[2][2]=2;

    req[3][0]=2;
    req[3][1]=2;
    req[3][2]=2;

    req[4][0]=4;
    req[4][1]=3;
    req[4][2]=3;


    aloc[0][0]=0;
    aloc[0][1]=1;
    aloc[0][2]=0;

    aloc[1][0]=2;
    aloc[1][1]=0;
    aloc[1][2]=0;

    aloc[2][0]=3;
    aloc[2][1]=0;
    aloc[2][2]=2;

    aloc[3][0]=2;
    aloc[3][1]=1;
    aloc[3][2]=1;

    aloc[4][0]=0;
    aloc[4][1]=0;
    aloc[4][2]=2;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            need[i][j]=req[i][j]-aloc[i][j];
        }

    }


    /*
            need[0]=4;
            need[1]=6;
            need[2]=2;

            */
    // define the proces name
    s[0]="p0";
    s[1]="p1";
    s[2]="p2";
    s[3]="p3";
    s[4]="p4";

    //calculate the sum and initial available

    for(int j=0; j<5; j++)
    {

        sum1=sum1+aloc[j][0];

        sum2=sum2+aloc[j][1];

        sum3=sum3+aloc[j][2];


    }
    ava[0][0]=r[0]-sum1;
    ava[0][1]=r[1]-sum2;
    ava[0][2]=r[2]-sum3;
    /*
            mp.insert({4,"p1"});
            mp.insert({6,"p2"});
            mp.insert({2,"p3"});
    */



    int cnt1=0,k=0;
    cout<<ava[0][0]<<" "<<ava[0][1]<<" "<<ava[0][2]<<endl;


    while(cnt1!=(n-1))
    {
        for(int i=0; i<n;)
        {
        loop:

            for(int j=0; j<5; j++)
            {
                if(ava[i][0]>=need[j][0] && ava[i][1]>= need[j][1] && ava[i][2]>= need[j][2])
                {
                    // cout<<s[i]<<endl;
                    ava[i+1][0]=ava[i][0]+aloc[i][0];
                    ava[i+1][1]=ava[i][1]+aloc[i][1];
                    ava[i+1][2]=ava[i][2]+aloc[i][2];

                    cout<<s[j]<<" "<<ava[i+1][0]<<" "<<ava[i+1][1]<<" "<<ava[i+1][2]<<endl;
                    need[j][0]=100000;
                    cnt1++;
                    i++;
                    goto loop;
                }

            }

        }
        k++;
        if(k>(n-1))
        {
            break;
        }


    }


    return 0;
}

