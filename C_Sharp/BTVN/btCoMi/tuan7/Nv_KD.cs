using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan7
{
    public class Nv_KD : NhanVien
    {
        float doanhThuTT, doanhThu;

        public float DoanhThu
        {
            get { return doanhThu; }
            set { doanhThu = value; }
        }

        public float DoanhThuTT
        {
            get { return doanhThuTT; }
            set { doanhThuTT = value; }
        }
        public Nv_KD()
        {
            this.DoanhThu = 0;
            this.DoanhThuTT = 0;
        }
        public Nv_KD(String ma, String HoTen, int namSinh, float hsl, int namVaoLam, String gioiTinh, float doanhThuTT, float doanhThu)
            : base(ma, HoTen, namSinh, hsl, namVaoLam, gioiTinh)
        {
            this.DoanhThu = doanhThu;
            this.DoanhThuTT = doanhThuTT;
        }
        public override char XepLoai()
        {
            if (this.doanhThu < this.doanhThuTT)
                return 'C';
            else if (this.doanhThu < this.doanhThuTT * 0.5)
                return 'D';
            else if (this.doanhThu < this.doanhThuTT * 2)
                return 'B';
            else return 'A';
        }
        public override double TinhLuong()
        {
            return this.Hsl * NhanVien.LCB + HoaHong();
        }
        public double HoaHong()
        {
            if (this.doanhThuTT < this.doanhThu)
                return 0.15 * (this.doanhThu - this.doanhThuTT);
            return 0;
        }
        public override void Nhap()
        {
            base.Nhap();
            Console.Write("Doanh thu ban hang toi thieu: ");
            this.DoanhThuTT = float.Parse(Console.ReadLine());
            Console.Write("Doanh thu ban hang theo thang: ");
            this.DoanhThu = float.Parse(Console.ReadLine());
        }
        public override void Xuat()
        {
            base.Xuat();
            Console.Write("Doanh thu ban hang toi thieu: {0}\n", this.DoanhThuTT);
            Console.Write("Doanh thu ban hang theo thang: {0}\n\n", this.DoanhThu);
        }
    }
}
