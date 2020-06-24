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
      DanhSach_NhanVien danhsach_NhanVien = new DanhSach_NhanVien();
      NhanVien nhanVien = new NhanVien();

      danhsach_NhanVien.Nhap_ThongTin_ListNhanVien();
      danhsach_NhanVien.Xuat_ThongTin_ListNhanVien();

      if (danhsach_NhanVien.Tinhtongluong() == 0)
        Console.Write("khong co nhan vien\n");
      else
      {
        Console.Write("Tong luong la: {0}\n", danhsach_NhanVien.Tinhtongluong());

        nhanVien = danhsach_NhanVien.Timluongcao();
        Console.Write("\nthong tin can tim la:\n ");
        nhanVien.Xuat_ThongTin_NhanVien();

        danhsach_NhanVien.SapXep_NhanVien_TheoNamVaoLam();
        Console.WriteLine("List duoc sap xep:");
        danhsach_NhanVien.Xuat_ThongTin_ListNhanVien();
      }
      Console.ReadLine();
    }
  }
}
