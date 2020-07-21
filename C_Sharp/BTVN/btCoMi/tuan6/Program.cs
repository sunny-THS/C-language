using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan6
{
    class Program
    {
        static void Main(string[] args)
        {
            int sel;
            do
            {
                var i = 3;
                for (; i <= 5; i++)
                {
                    Console.WriteLine("{0}. Bai {1}", i - 2, i);
                }
                Console.WriteLine("{0}. Thoat Chuong Trinh", i-2);
                Console.Write("Chon: ");
                Int32.TryParse(Console.ReadLine(), out sel);
                switch (sel)
                {
                    case 1:
                        {
                            HangHoa NuocGiaKhat_ = new NuocGiaiKhat();
                            NuocGiaKhat_.Nhap();
                            NuocGiaKhat_.Xuat();
                        } break;
                    case 2:
                        {
                            NhanVien CB_LanhDao_ = new CBLanhDao();
                            CB_LanhDao_.Nhap();
                            CB_LanhDao_.Xuat();
                        } break;
                    case 3:
                        {
                            Nguoi SinhVien_ = new SinhVien();
                            SinhVien_.Nhap();
                            SinhVien_.Xuat();
                        }  break;
                    case 4: break;
                    default:
                        {
                            Console.WriteLine("moi ban nhap lai\n");
                        } break;
                }
            } while (sel != 4);
        }
    }
}
