#include <stdio.h>
#include <stdlib.h>
#include <string.h>

volatile int key_menu;

void menu(void);


typedef struct {
    char id;
    char ten[30];
    float toan;
    float ly;
    float hoa;
    float tb;
    char xeploai[30];
}info_sv;

enum key{NHAP=1,IN=2, XEP_LOAI,DIEM_TB};
enum rank_student{EXCELLENT =8, GOOD=7, AVERAGE=5};
void fill_student(info_sv ds[30],int *number);
void list(info_sv ds[30], int *number);
void calc_average(info_sv *pt_ds);
void xeploai_f(info_sv ds[30], int *number);
void sapxep_f(info_sv ds[30], int *number);

int main()
{
    //menu(enum): 1.nhap ten, diem toan, ly, hoa ->tu tinh diem trung binh va id
    //      2. in danh sach
    //      3. xep loai
    //      4. sap xep theo diem tb

    info_sv ds[20];
    int number;

    while(1)
    {
        while(key_menu==0 ||key_menu>4) menu();

        switch(key_menu){
        case NHAP:
            printf("-----Fill Student-----\n");
            fill_student(ds,&number);
            printf("\n!!!Select number to continuous!\n");
            scanf("%d",&key_menu);
            //printf("key= %d -----\n",key_menu);
            break;
        case IN:
            printf("-----Student List-----\n");
            list(ds, &number);
            printf("\n!!!Select number to continuous!\n");
            scanf("%d",&key_menu);
            //printf("key= %d -----\n",key_menu);
        case XEP_LOAI:
            printf("-----Student Rank-----\n");
            printf("Ranked Academic!\n");
            xeploai_f(ds, &number);
            printf("\n!!!Select number to continuous!\n");
            scanf("%d",&key_menu);
            //printf("key= %d -----\n",key_menu);
        case DIEM_TB:
            printf("-----Arrange Rank-----\n");
            sapxep_f(ds, &number);
            printf("\n!!!Select number to continuous!\n");
            scanf("%d",&key_menu);
            //printf("key= %d -----\n",key_menu);
        }
    }
    return 0;
}
/*------------------------------------------*/

void menu(void){
    printf("-----------MENU--------------\n");
    printf("1. Nhap n sinh vien\n");
    printf("2. In danh sach\n");
    printf("3. Xep loai sinh vien\n");
    printf("4. Sap xep theo diem trung binh\n");
    scanf("%d",&key_menu);
    //printf("key= %d -----\n",key_menu);
}

void calc_average(info_sv *pt_ds){
    pt_ds->tb = pt_ds->toan + pt_ds->ly + pt_ds->hoa;
    pt_ds->tb = pt_ds->tb  /3.0;
}

void fill_student(info_sv ds[30],int *number){
    printf("so luong sinh vien: ");
    scanf("%d", number);
    int i;
    for(i=0; i<*number ; i++)
    {
        printf("--sinh vien thu %d--\n",i+1);
        ds[i].id=i+1;
        printf("Ten: ");
        fflush(stdin); gets(ds[i].ten);
        //printf("filled: %s\n", pt_ds->ten);
        printf("Diem Toan: ");  scanf("%f",&ds[i].toan);
        printf("Diem Ly: ");  scanf("%f",&ds[i].ly);
        printf("Diem Hoa: ");  scanf("%f",&ds[i].hoa);
        calc_average(&ds[i]);
        printf("filled: %s %.2f %.2f %.2f %.2f\n",ds[i].ten, ds[i].toan, ds[i].ly, ds[i].hoa, ds[i].tb);

    }
    key_menu=0;
}

void list(info_sv ds[30], int *number){
    int i;
    for(i=0; i<*number; i++)
    {
        printf("Sinh vien thu %d: ",i+1);
        printf("Ten: %s", ds[i].ten);
        printf("\nDiem toan: %f", ds[i].toan);
        printf("\nDiem ly:   %f", ds[i].ly);
        printf("\nDiem hoa:  %f", ds[i].hoa);
        printf("\nDiem TB:   %.2f", ds[i].tb);
        printf("\nXep loai:  %s\n", ds[i].xeploai);
        printf("---\n");
    }
}
void xeploai_f(info_sv ds[30], int *number){
    int i;
    for(i=0; i<*number;i++)
    {
        if(ds[i].tb>=EXCELLENT)     strcpy(ds[i].xeploai,"Excellent");
        else if(ds[i].tb<GOOD &&ds[i].tb>GOOD)  strcpy(ds[i].xeploai,"Good");
        else strcpy(ds[i].xeploai,"Average");
    }
}

void sapxep_f(info_sv ds[30], int *number){
    info_sv temp_ds[30];
    int i,j;
    for(i=0; i<*number-1; i++)
    {
        for(j=i+1;j<*number; j++)
        {
            if( ds[j].tb > ds[i].tb)
            {
                temp_ds[0]=ds[i];
                ds[i]=ds[j];
                ds[j]=temp_ds[0];
            }
        }
    }
}

