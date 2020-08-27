using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan7
{
    public abstract class NhanVien
    {
        protected String MaNv, HoTen, gioiTinh;
        protected int namSinh;
        private float hsl;
        private int namVaoLam;

        protected int NamVaoLam
        {
            get { return namVaoLam; }
            set { namVaoLam = value; }
        }

        protected float Hsl
        {
            get { return hsl; }
            set { hsl = value; }
        }


        public String GioiTinh
        {
            get { return gioiTinh; }
            set { gioiTinh = value; }
        }

        public int NamSinh
        {
            get { return namSinh; }
            set {
                if (value > 0)
                    namSinh = value;
                else throw new Exception("err");
            }
        }

        public String HOTEN
        {
            get { return HoTen; }
            set { HoTen = value; }
        }

        public String MA
        {
            get { return MaNv; }
            set 
            {
                if (value.Length == 5 && value.StartsWith("CT") && value.Substring(2).All(Char.IsDigit))
                    MaNv = value;
                else MaNv = "Ma khong phu hop xin kiem tra lai \t--\tError";
            }
        }
        public NhanVien()
        {
            this.MA = null;
            this.HOTEN = null;
            this.NamSinh = 2000;
            this.Hsl = 1f;
            this.NamVaoLam = DateTime.Today.Year;
        }
        public NhanVien(String ma, String HoTen, int namSinh, float hsl, int namVaoLam, String gioiTinh)
        {
            this.MA = ma;
            this.HOTEN = HoTen;
            this.NamSinh = namSinh;
            this.NamVaoLam = namVaoLam;
            this.Hsl = hsl;
            this.gioiTinh = gioiTinh;
        }
        public double Tinh_ThuNhap()
        {
            float tienThuong;
            char xl = XepLoai();
            if (xl == 'A')
                tienThuong = 1f;
            else if (xl == 'B')
                tienThuong = 0.75f;
            else if (xl == 'C')
                tienThuong = 0.5f;
            else tienThuong = 0f;
            return tienThuong * TinhLuong() + PCTN();
        }
        public static int LCB = 1150;
        public int PCTN()
        {
            int thoiGianLamViec = DateTime.Today.Year - this.namVaoLam;
            if(thoiGianLamViec >=5)
                return thoiGianLamViec * LCB /100;
            return 0;
        }
        public abstract char XepLoai();
        public abstract double TinhLuong();
        public virtual void Nhap()
        {
            Console.Write("Ma: ");
            this.MA = Console.ReadLine();
            Console.Write("Ho ten: ");
            this.HOTEN = Console.ReadLine();
            Console.Write("Gioi Tinh: ");
            this.GioiTinh = Console.ReadLine();
            Console.Write("Nam sinh: ");
            this.NamSinh = int.Parse(Console.ReadLine());
            Console.Write("He So Luong: ");
            this.Hsl = float.Parse(Console.ReadLine());
            Console.Write("Nam vao lam: ");
            this.NamVaoLam = int.Parse(Console.ReadLine());
        }
        public virtual void Xuat()
        {
            Console.WriteLine("Ma: {0}\nHo ten: {1}\nGioi tinh: {2}\nNam sinh: {3}\nHe so luong: {4}\nNam vao lam: {5}\nXep loai: {6}\nLuong: {7:.0}", this.MA, this.HoTen.ToUpper(), this.gioiTinh.ToUpper(), this.namSinh, this.hsl, this.namVaoLam, this.XepLoai(), this.TinhLuong());
        }
    }
}
