#include "stdio.h"

#define NGAY_DEFAULT 11
#define THANG_DEFAULT 5
#define NAM_DEFAULT 2019
#define THANG_31 31 //1 3 5 7 8 10 12
#define THANG_30 30 // 4 6 9 11


//3 truong hop tinh do chenh lech thang.
//Truong hop 1: ThangNguoiDungNhap == THANG_DEFAULT && Cung Nam.
//Truong hop 2: ThangNGuoiDUngNhap != THANG_DEFAULT && Khac Nam.
//Truong hop 3: ThangNguoiDungNhap < THANG_DEFAULT && namNguoiDungNhap vao <NAM_DEFAULT.
//Cung Nam. 
//Co nen check qua khu?.

//can 1 function check nam nhuan.

bool checkNamNhuan (int namNguoiDungNhap) //
{
    if(namNguoiDungNhap % 4 == 0 && namNguoiDungNhap % 100 != 0 || namNguoiDungNhap % 400 == 0) //dieu kien de la nam nhuan.
    {
        return true; //la nam nhuan.
    }
    return false; //khong phai la nam nhuan.
}

int doChenhLechThang(int thangNguoiDungNhap,int namNguoiDungNhap)
{
    //Neu la nam nhuan thi co cach tinh khac
    if (checkNamNhuan == true) //nam nhuan thi co 366 ngay va co thang 2 == 29 ngay 
    {
        if(thangNguoiDungNhap > THANG_DEFAULT && namNguoiDungNhap == NAM_DEFAULT)
        {
            

        }
        else if()
        {

        }
    }
    else 
    {
        if

    }
}

int tinhNgayChenhLechGiuaThang(int ngayNguoiDungNhap, int thangNguoiDungNhap, int namNguoiDungNhap)
{   
    int doChenhLechThang = 0;
    if(ngayNguoiDungNhap > NGAY_DEFAULT && thangNguoiDungNhap == THANG_DEFAULT && namNguoiDungNhap == NAM_DEFAULT)
    {
     return THANG_31 - thangNguoiDungNhap;  //Do chenh lech ngay cua cung thang cung nam (ngay > ngay default)
    }
    else if(thangNguoiDungNhap > THANG_DEFAULT && namNguoiDungNhap == NAM_DEFAULT)
    {
       doChenhLechThang = thangNguoiDungNhap - THANG_DEFAULT;
       
    }
    else if()
    {

    }  
}
int main()
{

}
