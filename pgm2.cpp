#include<iostream>
#include<vector>
using namespace std;

int main(){
    int w,f;
    cout<<"Enter the window size:"<<endl;
    cin>>w;
    cout<<"Enter number of frames to transmit:"<<endl;
    cin>>f;
    vector<int>frames(f);
    cout<<"Enter "<<f<<" frames:"<<endl;
    for(int i=0;i<f;i++){
        cin>>frames[i];
    }

    cout<< "With sliding window protocol the frames will be sent in the following manner (assuming no corruption of data) :\n "<<endl;
    cout<<"After sending "<<w<<" frames at each stage sender waits for acknowledgement sent by the receiver ...\n"<<endl;

    for(int i=1;i<=f;i++){
        if(i%w == 0){
            cout<<frames[i-1]<<" ";
            cout<<"\nAcknowledgement of above frames sent is received by sender\n"<<endl;
        }
        else{
            cout<<frames[i-1]<<" ";
        }
    }

    if(f%w != 0){
        cout<<"\nAcknowledgement of above frames sent is received by sender\n"<<endl;
    }

    return 0;
}