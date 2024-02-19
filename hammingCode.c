#include<stdio.h>

int main()
{
    int data[7], rec[7], c1, c2, c3, c;
    printf("Enter four bits of data : \n");
    scanf("%d%d%d%d", &data[0], &data[1], &data[2], &data[4]);
    data[6] = data[0] ^ data[2] ^ data[4];
    data[5] = data[0] ^ data[1] ^ data[4];
    data[3] = data[0] ^ data[1] ^ data[2];

    printf("The encoded bits are : \n");
    for(int i=0;i<7;i++)
    {
        printf("%d ", data[i]);
    }

    printf("\nEnter the received bits : \n");
    for(int i=0;i<7;i++)
    {
        scanf("%d", &rec[i]);
    }

    c1 = rec[0] ^ rec[2] ^ rec[4] ^ rec[6];
    c2 = rec[0] ^ rec[1] ^ rec[4] ^ rec[5];
    c3 = rec[0] ^ rec[1] ^ rec[2] ^ rec[3];
    c = c3 * 4 + c2 * 2 + c1;

    if(c == 0)
    {
        printf("\nCongratulations there is no error!!\n");
    }
    else{
        printf("\nError at the position : %d\n", c);
        if(rec[7 - c] == 0)
        {
            rec[7 - c] = 1;
        }
        else{
            rec[7 - c] = 0;
        }

        printf("The correct message is : ");
        for(int i=0;i<7;i++)
        {
            printf("%d ", rec[i]);
        }
    }
    return 0;
}