using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan6
{
    class NuocGiaiKhat : HangHoa
    {
        String DonViTinh;
        uint sl;
        double donGia;
        static float ChietKhau = 2.5f;

        public String DVT
        {
            get { return DonViTinh; }
            set 
            {
                String[] dvt = new String[] { "ket", "thung", "chai", "lon" }; 
                if (dvt.Contains(value.ToLower()))
                    DonViTinh = value;
                else DonViTinh = dvt[3];
            }
        }
        public NuocGiaiKhat(String MaHang, String TenHang, String DonViTinh, uint sl, double donGia)
            : base(MaHang, TenHang)
        {
            this.DVT = DonViTinh;
            this.donGia = donGia;
            this.sl = sl;
        }

        public NuocGiaiKhat()
        {
            // TODO: Complete member initialization
        }
        public override void Xuat()
        {
            Console.WriteLine("Thong tin nuoc giai khat");
            base.Xuat();
            Console.WriteLine("Don Vi Tinh: {0}\nSo Luong: {1}\nDon Gia: {2}\nThanh Tien: {3:.0}", this.DVT, this.sl, this.donGia, this.TongTien());
            Console.WriteLine("=====================================");
        }
        public double TinhThanhTien()
        {
            var tmp = this.sl * this.donGia;
            if (this.DVT.ToLower().Equals("ket") || this.DVT.ToLower().Equals("thung"))
                return tmp;
            else if (this.DVT.ToLower().Equals("chai"))
                return tmp / 20;
            else return tmp / 24;
        }
        public override void Nhap()
        {
            base.Nhap();
            Console.Write("Don Vi Tinh: ");
            this.DVT = Console.ReadLine();
            Console.Write("Don gia: ");
            this.donGia = double.Parse(Console.ReadLine());
            Console.Write("So luong: ");
            this.sl = uint.Parse(Console.ReadLine());
            Console.WriteLine("=====================================");
        }
        public double TongTien()
        {
            return this.TinhThanhTien() * NuocGiaiKhat.ChietKhau;
        }
    }
}
