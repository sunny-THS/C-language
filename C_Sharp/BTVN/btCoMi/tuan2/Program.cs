using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan2
{
  public class Program
  {
    static void Main(string[] args)
    {
      int n, SoBai = 6;
      do
      {
        Console.WriteLine("============+=+============");
        for(var i = 1; i <= 6; i++)
        {
          if(i >= 4)
          {
            Console.WriteLine("{0}. bai {0}", i);
          }
        }
        Console.WriteLine("0. Thoat Chuong Trinh");
        Console.Write("Nhap So Bai: ");
        n = int.Parse(Console.ReadLine());
        switch (n)
        {
          case 4:
          {
            String kieu;
            int k;
            HinhChuNhat h1 = new HinhChuNhat();
            h1.Nhap();
            h1.Xuat();
            Console.Write("Nhap kinh thuoc de thay doi: ");
            HinhChuNhat h2 = new HinhChuNhat();
            h2.Nhap();
            Console.Write("Ban muon tang hay giam kich thuoc: ");
            kieu = Console.ReadLine();
            if(kieu.ToLower().Equals("tang"))
              k = 1;
            else if(kieu.ToLower().Equals("giam"))
              k = 0;
            else
            {
              Console.WriteLine("Error"); break;
            }
            h1.ChangeSize(h2, k);
            Console.WriteLine("Chieu dai: {0}\nChieu rong: {1}", h1.CD, h1.CR);
          } break;
          case 5:
          {
            int soGiay;
            String tmp;
            Time t = new Time();
            int chon;
            do {
              Console.WriteLine("------------------------");
              Console.WriteLine("1. Nhap kieu 24h");
              Console.WriteLine("2. Nhap kieu 12h");
              Console.WriteLine("0. Thoat chuc nang");
              Console.WriteLine("Lua chon cua ban: ");
              chon = int.Parse(Console.ReadLine());
              switch (chon)
              {
                case 1:
                {
                  t.Nhap_Kieu24h();
                  if(!t.KiemTra_GioHopLe())
                  {
                    Console.WriteLine("==>> gio khong hop le");
                    break;
                  }
                  t.Xuat_Kieu24h();
                  // t.Giam_Gio(7200);
                  Console.Write("Moi ban Nhap So Giay: ");
                  soGiay = int.Parse(Console.ReadLine());
                  Console.Write("Ban muon tang hay giam thoi gian: ");
                  tmp = Console.ReadLine();
                  if(tmp.ToLower().Equals("tang"))
                    t.Tang_Gio(soGiay);
                  else if(tmp.ToLower().Equals("giam"))
                    t.Giam_Gio(soGiay);
                  t.Xuat_Kieu24h();
                } break;
                case 2:
                {
                  t.Nhap_Kieu12h();
                  if(!t.KiemTra_GioHopLe())
                  {
                    Console.WriteLine("==>> gio khong hop le");
                    break;
                  }
                  t.Xuat_Kieu12h();
                  // t.Giam_Gio(7200, "12");
                  Console.Write("Moi ban Nhap So Giay: ");
                  soGiay = int.Parse(Console.ReadLine());
                  Console.Write("Ban muon tang hay giam thoi gian: ");
                  tmp = Console.ReadLine();
                  if(tmp.ToLower().Equals("tang"))
                    t.Tang_Gio(soGiay, "12");
                  else if(tmp.ToLower().Equals("giam"))
                    t.Giam_Gio(soGiay, "12");
                  t.Xuat_Kieu12h();
                } break;
                case 0: break;
                default:
                {
                  Console.WriteLine("Moi ban nhap lai"); break;
                }
              }
            } while (chon!=0);
          } break;
          case 6:
          {
            DanhSach_VanDongVien ds_VDV = new DanhSach_VanDongVien();
            List<VanDongVien> list_vdv = new List<VanDongVien>();
            ds_VDV.Nhap_ThongTin_ListVanDongVien();
            ds_VDV.Xuat_ThongTin_ListVanDongVien();
            Console.WriteLine();
            Console.WriteLine("Cac van dong vien dat yeu cau: ");
            list_vdv = ds_VDV.Xet_VanDongVien_Dat();
            list_vdv.ForEach(vdv => vdv.Xuat_ThongTin_VanDongVien());
          } break;
        }
      } while (n != 0);
    }
  }
}
