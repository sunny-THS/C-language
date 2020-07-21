using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan6
{
    class SinhVien : Nguoi
    {
        String mssv, heDaoTao;

        public int Tong_TC
        {
            get 
            {
                return this.heDaoTao.Equals("dai hoc") ? 150 : this.heDaoTao.Equals("cao dang") ? 100 : 130;
            }
        }

        public String HeDaoTao
        {
            get { return heDaoTao; }
            set 
            {
                String[] HDT = new String[] { "dai hoc", "cao dang", "cao dang nghe" };
                if (HDT.Contains(value))
                    heDaoTao = value;
                else heDaoTao = HDT[0];
            }
        }
        public SinhVien(String HoTen, String GioiTinh, DateTime NgaySinh, String mssv, String heDaoTao)
            : base(HoTen, GioiTinh, NgaySinh)
        {
            this.mssv = mssv;
            this.HeDaoTao = heDaoTao;
        }

        public SinhVien()
        {
            // TODO: Complete member initialization
        }
        public override void Nhap()
        {
            base.Nhap();
            Console.Write("MSSV: ");
            this.mssv = Console.ReadLine();
            Console.Write("He Dao Tao: ");
            this.HeDaoTao = Console.ReadLine();
            Console.WriteLine("=====================================");
        }

        public override void Xuat()
        {
            Console.WriteLine("Thong tin sinh vien");
            base.Xuat();
            Console.WriteLine("MSSV: {0}\nHe Dao Tao: {1}\nTong So Tin Chi: {2}\nTong hoc phi: {3:.0}", this.mssv, this.heDaoTao, this.Tong_TC, this.Tinh_TongHocPhi());
            Console.WriteLine("=====================================");
        }
        public double Tinh_TongHocPhi()
        {
            return this.Tong_TC * (this.heDaoTao.Equals("dai hoc") ? 200000 : this.heDaoTao.Equals("cao dang") ? 150000 : 12000);
        }
    }
}
