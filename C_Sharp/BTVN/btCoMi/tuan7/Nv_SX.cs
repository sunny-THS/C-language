using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan7
{
    public class Nv_SX : NhanVien
    {
        static float HSPCR = 0.1f;
        uint soNgayNghi;
        public Nv_SX()
        {
            soNgayNghi = 0;
        }
        public Nv_SX(String ma, String HoTen, int namSinh, float hsl, int namVaoLam, String gioiTinh, uint soNgayNghi)
            : base(ma, HoTen, namSinh, hsl, namVaoLam, gioiTinh)
        {
            this.soNgayNghi = soNgayNghi;
        }
        public override char XepLoai()
        {
            if (soNgayNghi <= 1)
                return 'A';
            else if (soNgayNghi <= 3)
                return 'B';
            else if (soNgayNghi <= 5)
                return 'C';
            return 'D';
        }
        public override double TinhLuong()
        {
            return this.Hsl * NhanVien.LCB * (1 + Nv_SX.HSPCR);
        }
        public override void Nhap()
        {
            base.Nhap();
            Console.Write("So Ngay Nghi: ");
            this.soNgayNghi = uint.Parse(Console.ReadLine());
        }
        public override void Xuat()
        {
            base.Xuat();
            Console.WriteLine("So ngay nghi: {0}\n", this.soNgayNghi);
        }
    }
}
