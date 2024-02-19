#include <stdio.h>

void getNetworkHostId(int a,int b,int c,int d){
    if(a<128){
        printf("Class A\n");
        printf("NetWork Id: %d.0.0.0",a);
        printf("Host Id: %d.%d.%d",b,c,d);
    }
    else if(a<192){
        printf("Class B\n");
        printf("NetWork Id: %d.%d.0.0\n",a,b);
        printf("Host Id: % %d.%d\n",c,d);
    }
    else if(a<224){
        printf("Class C\n");
        printf("NetWork Id: %d.%d.%d.0\n",a,b,c);
        printf("Host Id: % %d\n",d);
    }
    else if(a<240){
        printf("CLASS D\n");
    }
    else if(a<256){
        printf("CLASS E\n");
    }
    else {
        printf("INVALID");
    }
}

int main()
{   char s[16];
    scanf("%s",s);
    int a,b,c,d;
    sscanf(s,"%d.%d.%d.%d",&a,&b,&c,&d);
    getNetworkHostId(a,b,c,d);
    return 0;
}