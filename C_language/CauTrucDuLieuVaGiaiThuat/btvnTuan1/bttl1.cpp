#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define YEARNOW 2019
struct Date
{
	int ngay;
	int thang;
	int nam;
};
struct SinhVien
{
	char mssv[50];
	char hoten[50];
	char diaChi[50];
	Date ngaySinh;
	char nganhHoc[50];
	float dtb;
};
void docFile(SinhVien * sv, int &n);
void xuatThongTin(SinhVien sv);
void xuatDSThongTin(SinhVien * sv, int n);
char * TinhDiemChu(SinhVien sv);
char * XepLoai(SinhVien sv);
bool XuatSVCNTT(SinhVien sv);
void XuatDSSVCNTT(SinhVien * sv, int n);
int demSoSVTren22(SinhVien * sv, int n);
SinhVien TimSVDTBMAX(SinhVien * sv, int n);
void Swap(SinhVien &a, SinhVien &b);
void sapXep(SinhVien *sv, int n);

void main()
{
	SinhVien sv[20];
	int n;
	docFile(sv, n);
	xuatDSThongTin(sv, n);
	XuatDSSVCNTT(sv, n);
	printf("\nDs sinh vien tren 22: %d", demSoSVTren22(sv, n));
	getch();
}
void docFile(SinhVien * sv, int &n)
{
	FILE *f;
	char date[40];
	if ((f = fopen("input.txt", "r")) == NULL)
	{
		printf("ERROR");
		exit(1);
	}
	fscanf(f, "%d", &n);
	for (size_t i = 0; i < n; i++)
	{
		fscanf(f, "%s", &sv[i].mssv);
		fscanf(f, "%s", &sv[i].hoten);
		fscanf(f, "%d", &sv[i].ngaySinh.ngay);
		fscanf(f, "%d", &sv[i].ngaySinh.thang);
		fscanf(f, "%d", &sv[i].ngaySinh.nam);
		fscanf(f, "%s", &sv[i].diaChi);
		fscanf(f, "%s", &sv[i].nganhHoc);
		fscanf(f, "%f", &sv[i].dtb);
	}
	fclose(f);
}
void xuatThongTin(SinhVien sv)
{
	printf("%s\t--\t%s\t--\t%d/%d/%d\t--\t%s\t-- %s\t-- %.2f -- ", sv.mssv, sv.hoten, sv.ngaySinh.ngay, sv.ngaySinh.thang, sv.ngaySinh.nam, sv.diaChi, sv.nganhHoc, sv.dtb);
	printf("%s\t", TinhDiemChu(sv));
	printf("%s\n", XepLoai(sv));
}
void xuatDSThongTin(SinhVien * sv, int n)
{
	printf("Danh Sinh vien\n");
	for (size_t i = 0; i < n; i++)
	{
		xuatThongTin(sv[i]);
	}
}
char * TinhDiemChu(SinhVien sv)
{
	if (sv.dtb>=8.5) return "A";
	else if (sv.dtb >= 8) return "B+";
	else if (sv.dtb >= 7) return "B";
	else if (sv.dtb >= 6.5) return "C+";
	else if (sv.dtb >= 5.5) return "C";
	else if (sv.dtb >= 5) return "D+";
	else if (sv.dtb >= 4) return "D";
	else return "F";
}
char * XepLoai(SinhVien sv)
{
	if (sv.dtb>=8.5) return "Gioi";
	else if (sv.dtb >= 7) return "Kha";
	else if (sv.dtb >= 5.5) return "Trung Binh";
	else if (sv.dtb >= 4) return "Trung Binh Yeu";
	else return "Kem";
}
bool XuatSVCNTT(SinhVien sv)
{
	if (strcmpi(sv.nganhHoc, "CNTT") == 0) return true;
	return false;
}
void XuatDSSVCNTT(SinhVien * sv, int n)
{
	printf("\nDs sinh vien cntt\n");
	for (size_t i = 0; i < n; i++)
	{
		if (XuatSVCNTT(sv[i]))
		{
			xuatThongTin(sv[i]);
		}
	}
}
int demSoSVTren22(SinhVien * sv, int n)
{
	int dem = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (YEARNOW - sv[i].ngaySinh.nam>22)
		{
			dem++;
		}
	}
	return dem;
}
// btvn
//SinhVien TimSVDTBMAX(SinhVien * sv, int n)
//{
//	sapXep(sv, )
//}
//void sapXep(SinhVien *sv, int n)
//{
//	for (size_t i = 0; i < n-1; i++)
//	{
//		for (size_t j = i+1; j < n; j++)
//		{
//			if (sv[i].dtb>sv[j].dtb)
//			{
//				Swap(sv[i], sv[j])
//			}
//		}
//	}
//}
//void Swap(SinhVien &a, SinhVien &b)
//{
//	SinhVien t = a;
//	a = b;
//	b = t;
//}