#include "stdio.h"

#define NGAY_DEFAULT 11
#define THANG_DEFAULT 5
#define NAM_DEFAULT 2019
#define THANG_31 31 //1 3 5 7 8 10 12
#define THANG_30 30 // 4 6 9 11
#define MAX_THANG 12
typedef enum {false, true} bool; //bool type false = 0, true = 1


//3 truong hop tinh do chenh lech thang.
//Truong hop 1: ThangNguoiDungNhap == THANG_DEFAULT && Cung Nam.
//Truong hop 2: ThangNGuoiDUngNhap != THANG_DEFAULT && Khac Nam.
//Truong hop 3: ThangNguoiDungNhap < THANG_DEFAULT && namNguoiDungNhap vao <NAM_DEFAULT.
//Cung Nam. 
//Co nen check qua khu?.

//can 1 function check nam nhuan.

bool checkNamNhuan (int nam) // ----GOOD TO GO
{
    if(nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) //dieu kien de la nam nhuan.
    {
        return true; //la nam nhuan.
    }
    return false; //khong phai la nam nhuan.
}

int tinhCachBietThang(int thang, int nam)
{
    int soThangChenhLech = 0; //thang default 5 la thang co 31 ngay
    int soCachBietNam = nam - NAM_DEFAULT;
    if (nam == NAM_DEFAULT)
    {
        soThangChenhLech = thang - THANG_DEFAULT;
        return soThangChenhLech;
    }
    else
    {
        for (int i = 0; i <= soCachBietNam; i++)
        {
            if (soCachBietNam == 1)
            {
                soThangChenhLech = (MAX_THANG - THANG_DEFAULT) + thang;
            }
            else
            {
                soThangChenhLech = (MAX_THANG - THANG_DEFAULT) + (MAX_THANG * (soCachBietNam -1)) + thang;
            }
        }
        return soThangChenhLech;
    }
}
/*
int tinhSoNgayChenhLech(int ngay, int thang,int nam) //
{
    //Neu la nam nhuan thi co cach tinh khac
    int soNgayChenhLech = 0
    if (checkNamNhuan == true) //nam nhuan thi co 66 ngay va co thang 2 == 29 ngay 
    {
        if(ngay > NGAY_DEFAULT && thang == THANG_DEFAULT && nam == NAM_DEFAULT)
        {
            soNgayChenhLech += ngay - NGAY_DEFAULT;
            return soNgayChenhLech;
        }
        else if(thang > THANG_DEFAULT)
        {
            //cach nhau bao nhieu thang 
           soNgayChenhLech =  tinhCachBietThang(thang, nam)

        }
    }
    else 
    {
        if

    }
}
*/


int main()
{
  int ngay,thang,nam;
  printf("Xin moi nhap ngay: ");
  scanf("%d",&ngay);
  printf("Xin moi nhap thang: ");
  scanf("%d",&thang);
  printf("Xin moi nhap nam: ");
  scanf("%d",&nam);
//Test
  int doChenhLech = tinhCachBietThang(thang, nam);
  printf("do chenh lenh giua thang 5 va thang %d nam %d: %d\n ",thang, nam, doChenhLech);
}
