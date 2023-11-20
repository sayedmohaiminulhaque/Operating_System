#include<bits/stdc++.h>
using namespace std;
int main()
{
    int req[5][3],aloc[5][3],ava[7][3],need[5][3],x,cnt=0;
    int sum1=0,sum2=0, sum3=0,r[]= {10, 5, 7};
    int arr[1000];
    string s[10000];
    int n=5;


    ifstream file("B.txt");

    while(file >> x)
    {
        if(cnt<n*3)
        {
            req[cnt/3][cnt%3]=x;
            cnt++;
        }

        else if(cnt<6*n)
        {
            aloc[(cnt-3*n)/3][(cnt-3*n)%3]=x;
            cnt++;
        }
    }

   
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
        //cout<<req[i][j]<<"\n";
            need[i][j]=req[i][j]-aloc[i][j];
           // cout<<aloc[i][j]<<"\n";
        }

    }

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
                    need[j][0]=INT_MAX;
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


