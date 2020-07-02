using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan2
{
  public class DanhSach_VanDongVien
  {
    List<VanDongVien> List_VDV;
    int SoLuong;
    public DanhSach_VanDongVien()
    {
      List_VDV = new List<VanDongVien>(20); // toi thieu 20 van dong vien
      this.SoLuong = 0;
    }
    public void Them_VanDongVien(VanDongVien vdv)
    {
      List_VDV.Add(vdv);
    }
    public void Nhap_ThongTin_ListVanDongVien()
    {
      Console.Write("Nhap so luong van dong vien: ");
      this.SoLuong = int.Parse(Console.ReadLine());
      for(var i = 0; i < this.SoLuong; i++)
      {
        VanDongVien vdv = new VanDongVien();
        vdv.Nhap_ThongTin_VanDongVien();
        Them_VanDongVien(vdv);
      }
    }
    public void Xuat_ThongTin_ListVanDongVien()
    {
      Console.WriteLine("Danh sach van dong vien: ");
      List_VDV.ForEach(vdv => vdv.Xuat_ThongTin_VanDongVien());
    }
    public List<VanDongVien> Xet_VanDongVien_Dat()
    {
      return List_VDV.Where(vdv => vdv.Tinh_ThanhTich()<=VanDongVien.ThanhTichChuan).ToList();
    }
  }
}
