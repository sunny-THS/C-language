using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan7
{
    class Program
    {
        static void Main(string[] args)
        {
            CongTy_ABC cty_ABC = new CongTy_ABC();
            cty_ABC.docFilexml();
            cty_ABC.xuat();
            Console.WriteLine();
            Console.WriteLine("Tong Thu Nhap {0:.0}", cty_ABC.TongThuNhap());

            Console.ReadLine();
        }
    }
}
