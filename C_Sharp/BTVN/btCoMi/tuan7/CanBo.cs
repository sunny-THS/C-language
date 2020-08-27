using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan7
{
    public class CanBo : NhanVien
    {
        String chucVu;
        float hsCv;

        public float HsCv
        {
            get { return hsCv; }
            set { hsCv = value; }
        }

        public String ChucVu
        {
            get { return chucVu; }
            set { chucVu = value; }
        }
        public CanBo()
        {
            chucVu = null;
            hsCv = 0;
        }
        public CanBo(String ma, String HoTen, int namSinh, float hsl, int namVaoLam, String gioiTinh, String chucVu, float hsCv)
            : base(ma, HoTen, namSinh, hsl, namVaoLam, gioiTinh)
        {
            this.ChucVu = chucVu;
            this.hsCv = hsCv;
        }
        public override char XepLoai()
        {
            return 'A';
        }
        public override double TinhLuong()
        {
            return NhanVien.LCB * this.Hsl + pccv();
        }
        public float pccv()
        {
            return this.hsCv * 1100;
        }
        public override void Nhap()
        {
            base.Nhap();
            Console.Write("Chuc vu: ");
            this.ChucVu = Console.ReadLine();
            Console.Write("He So pc Chuc vu: ");
            this.hsCv = float.Parse(Console.ReadLine());
        }
        public override void Xuat()
        {
            base.Xuat();
            Console.Write("Chuc vu: {0}\n", this.chucVu.ToUpper());
            Console.Write("He So pc Chuc vu: {0}\n\n", this.hsCv);
        }
    }
}
