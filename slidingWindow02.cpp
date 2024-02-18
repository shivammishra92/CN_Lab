#include <stdio.h> 
#include <stdlib.h>
#include<iostream>
using namespace std;

void printing(int x , int y, int a[])
{
    for(int i=x;i<=y;i++)
    {
    cout<<a[i]<<" ";
    }
}

int main()
{
        int choice , count = 1,n,w; 
        cout<<"\nEnter total data length "; 
        cin>>n;
        cout<<"\nEnter window size "; 
        cin>>w;
        int a[100];
        cout<<"\nEnter the data packet "; 
        for(int i=0;i<w;i++)
        cin>>a[i];

        int s=0,e=w-1;
        cout<<"\n The current sliding window is "; 
        printing(s,e,a);

        while(count<=n)
        {
            choice = rand() % 3; 
            if(choice==0)
            {
                if (count>n-w)
                {
                        cout<<"\n Acknowledge received for data packet " << a[s]; 
                        s++;

                    if(a[s-1]==n)
                    {
                        cout<<"\n Data transmission successful using selective-repeat sliding window protocol"; 
                        cout<<"\n USN: 4NI21IS095";
                        break;
                    }
                    else
                    {
                        cout<<"\n The current sliding window is ";
                        printing(s,e,a);
                        count++;
                    }
                    //cout<<"Count in spcl if loop "<<count;
                }
                else
                {
                    cout<<"\n Acknowledge received for data packet " << a[s]; 
                    s++;
                    e++;

                    cout<<"\n Enter the data packet ";
                    cin>>a[e];
                    cout<<"\n The current sliding window is "; 
                    printing(s,e,a);
                    count++;
                //cout<<"Count in if loop "<<count;
                }


            }
            else if(choice == 1)
            {
                cout<<"\n Timed out";
                cout<<"\n The current sliding window is ";
                printing(s,e,a);
            }
            else
            {
                cout<<"\n Error in transmission"; 
                cout<<"\n The current sliding window is "; 
                printing(s,e,a);

            }
        }


        return 0;

}



