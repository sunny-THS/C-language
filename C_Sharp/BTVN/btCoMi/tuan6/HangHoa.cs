using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan6
{
    class HangHoa
    {
        protected String MaHang, TenHang;

        public String TENHANG
        {
            get { return TenHang; }
            set { TenHang = value; }
        }

        public String MAHANG
        {
            get { return MaHang; }
            set 
            { 
                int tmp;
                if (value.Length == 5 && value.StartsWith("HH") && Int32.TryParse(value.Substring(2, 3), out tmp))
                    MaHang = value;
                else MaHang = "HH001";
            }
        }

        public HangHoa()
        {
            this.MaHang = null;
            this.TenHang = null;
        }
        public HangHoa(String MaHang, String TenHang)
        {
            this.TENHANG = TenHang;
            this.MAHANG= MaHang;
        }
        public virtual void Nhap()
        {
            Console.Write("Ma hang: ");
            this.MAHANG = Console.ReadLine();
            Console.Write("Ten hang: ");
            this.TENHANG = Console.ReadLine();
        }
        public virtual void Xuat()
        {
            Console.WriteLine("Ma hang: {0} -- Ten hang: {1}", this.MaHang, this.TenHang);
        }
    }
}
