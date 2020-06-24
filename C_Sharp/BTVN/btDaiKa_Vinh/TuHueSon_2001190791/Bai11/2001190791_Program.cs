using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TuHueSon_2001190791
{
  public class Program
  {
    static void Main(string[] args)
    {
      LopHoc lopHoc = new LopHoc();
      HocSinh hocSinh = new HocSinh();
      String tt;

      lopHoc.Nhap_ThongTin_ListHocSinh();
      lopHoc.Xuat_ThongTin_ListHocSinh();

      hocSinh = lopHoc.HocSinh_CoTongDiem_Max();
      hocSinh.Xuat_ThongTin_HocSinh();

      Console.Write("Nhap thong tin can tim (Ho va ten hoac ma so hoc sinh): ");
      tt = Console.ReadLine();
      hocSinh = lopHoc.Tim_ThongTin_HocSinh(tt);
      hocSinh.Xuat_ThongTin_HocSinh();
      Console.ReadKey();
    }
  }
}
