#include <stdio.h>
#include <stdlib.h>
///su dung con tro de in mot mang theo thu tu dao nguoc

void vitridao(int mang[],int *pt1)
{
    int *pt2=mang;
    while(*pt2!=NULL)
    {
        *pt1=*pt1+1; //vitri+1, luu y cho nay
        pt2++;
    }
//    printf("%d %d\n",count,*pt1);
}

void inmang(int mang[],int *indx)
{
    int i;
    for(i=*indx-1;i>=0;i--)
    {
        printf("%d\n",mang[i]);
    }
}


int main()
{
    int mang[10]={1,2,3,4,5};
    int vitri=0;
    vitridao(mang,&vitri);

    printf("vitri=%d\n",vitri);

    inmang(mang,&vitri);
    return 0;
}
