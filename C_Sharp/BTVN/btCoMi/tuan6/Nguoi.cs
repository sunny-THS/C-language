using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan6
{
    class Nguoi
    {
        protected String HoTen, gioiTinh;
        protected DateTime NgaySinh;

        public String GioiTinh
        {
            get { return gioiTinh; }
            set 
            {
                String[] gt = new String[]{"nam", "nu"};
                if (gt.Contains(value))
                    gioiTinh = value;
                else gioiTinh = "NAM";
            }
        }
        public Nguoi()
        {
            this.HoTen = null;
            this.NgaySinh = new DateTime(2000, 1, 1);
            gioiTinh = "nam";
        }
        public Nguoi(String HoTen, String gioiTinh, DateTime NgaySinh)
        {
            this.HoTen = HoTen;
            this.GioiTinh = gioiTinh;
            this.NgaySinh = NgaySinh;
        }
        public virtual void Nhap()
        {
            try
            {
                Console.Write("Ho Ten: ");
                this.HoTen = Console.ReadLine();
                Console.Write("Gioi Tinh: ");
                this.GioiTinh = Console.ReadLine();
                Console.Write("Ngay Sinh: ");
                this.NgaySinh = DateTime.Parse(Console.ReadLine());
            }
            catch (FormatException err)
            {
                Console.WriteLine("=======> Error: "+ err.Message);
                Console.WriteLine("Ngay sinh dua ve mac dinh: 1/1/2000");
            }
        }
        public virtual void Xuat()
        {
            Console.WriteLine("Ho Ten: {0}\nGioi Tinh: {1}\nNgay Sinh: {2:d}", this.HoTen.ToUpper(), this.gioiTinh.ToUpper(), this.NgaySinh);
        }

    }
}
