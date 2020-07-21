using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan6
{
    class NhanVien
    {
        protected String MaNhanVien, TenNhanVien;
        protected float heSoLuong;
        static uint LCB = 1150;

        public String MNV
        {
            get { return MaNhanVien; }
            set 
            { 
                if(value.StartsWith("NV"))
                    MaNhanVien = value; 
                else MaNhanVien = "NV001";
            }
        }
        public NhanVien()
        {
            this.MaNhanVien = "NV001";
            this.TenNhanVien = "Tu Hue Son";
            this.heSoLuong = 2.34f;
        }
        public NhanVien(String MaNhanVien, String TenNhanVien, float heSoLuong)
        {
            this.MNV = MaNhanVien;
            this.TenNhanVien = TenNhanVien;
            this.heSoLuong = heSoLuong;
        }
        public virtual double thunhap()
        {
            return this.heSoLuong * NhanVien.LCB;
        }
        public virtual void Nhap()
        {
            Console.Write("Ma Nhan Vien: ");
            this.MNV = Console.ReadLine();
            Console.Write("Ten nhan vien: ");
            this.TenNhanVien = Console.ReadLine();
            Console.Write("He So Luong: ");
            this.heSoLuong = float.Parse(Console.ReadLine());
        }
        public virtual void Xuat()
        {
            Console.WriteLine("Ma nhan vien: {0}\nHo ten: {1}\nHe So Luong: {2}\nThu Nhap: {3:.0}", this.MaNhanVien, this.TenNhanVien.ToUpper(), this.heSoLuong, this.thunhap());
        }
    }
}
