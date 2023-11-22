#include <iostream>
#include <string>
using namespace std;


void findNwHostId(string s,int k){
    int c=0;string nw="",host="";
    for(int i=0;i<s.length();i++){
        
        if(c == k){
            host = host+s.substr(i);
            break;
        }
        else{
            if(s[i] == '.')
            c++;
            
            if(c==k)continue;
            
            nw = nw+s[i];
        }
        
    }
    cout<<"Network Id is : "<<nw<<endl;
    cout<<"Host Id is : "<<host<<endl;

}

int main()
{
  string s; 
  cout<<"Enter a IP address:"<<endl;
  cin>>s;
  string cll = "";
  for(int i=0;i<3;i++){
      cll = cll+s[i];
  }
  int cl = stoi(cll);
  int k;
  

  if(cl >=1 and cl <= 126){
    cout<<"Class A"<<endl; 
    k=1;
    findNwHostId(s,k);  
  }
  else if(cl >= 128 && cl <= 191){
      cout<<"Class B"<<endl;
      k=2;
      findNwHostId(s,k); 
  }
  else if(cl >= 192 && cl <= 223){
      cout<<"Class C"<<endl;
      k=3;
      findNwHostId(s,k); 
  }
  else if(cl >= 224 and cl <= 239){
      cout<<"Class D"<<endl;
  }
  else{
      cout<<"Class E"<<endl;
  }

  return 0;
}