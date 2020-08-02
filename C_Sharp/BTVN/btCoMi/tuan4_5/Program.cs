using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan3
{
  class Program
  {
    static void Main(string[] args)
    {
      DanhSach_GiaoVien ds_gv = new DanhSach_GiaoVien();
      //ds_gv.Nhap_ThongTin_ListGiaoVien();
      ds_gv.DocFileXML("../../xml.xml");
      ds_gv.Xuat_ThongTin_ListGiaoVien();
      //Console.WriteLine();
      //Console.Write("Tong so nhom huong dan thuc hanh: {0}", ds_gv.TongSoNhom());
      //Console.WriteLine();
      //Console.WriteLine("Sap xep tang dan danh sach giao vien theo ten");
      //ds_gv.SapXep_TangDan_TheoHoTen();
      //ds_gv.Xuat_ThongTin_ListGiaoVien();
      //Console.WriteLine();
      //Console.WriteLine("Sap xep giam dan danh sach giao vien theo so nhom huong dan");
      //ds_gv.SapXep_GiamDan_TheoSoNhom();
      //ds_gv.Xuat_ThongTin_ListGiaoVien();
      //Console.WriteLine();
      //Console.WriteLine("Danh sach giao vien co so nhom huong dan thuc hanh lon hon 1");
      //ds_gv.Loc_SoNhom_LonHon1().ForEach(gv => gv.Xuat_ThongTin_GiaoVien());
      Console.Write("Nhap ten: ");
      ds_gv.Tim(Console.ReadLine()).Xuat_ThongTin_GiaoVien();
      Console.ReadLine();
    }
  }
}
