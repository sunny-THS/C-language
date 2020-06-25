using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TuHueSon_2001190791
{
  public class DanhSach_NhanVien
  {
    List<NhanVien> List_NhanVien;
    int SiSo;
    public DanhSach_NhanVien()
    {
      List_NhanVien = new List<NhanVien>(50); // toi thieu 50 nhan vien
    }
    public void Them_NhanVien(NhanVien nv)
    {
      List_NhanVien.Add(nv);
    }
    public void Nhap_ThongTin_ListNhanVien()
    {
      NhanVien nv = new NhanVien();
      Console.Write("nhap so luong nhan vien: ");
      this.SiSo = int.Parse(Console.ReadLine());
      for (int i = 0; i < this.SiSo; i++)
      {
        nv.Nhap_ThongTin_NhanVien();
        Them_NhanVien(nv);
      }
    }
    public void Xuat_ThongTin_ListNhanVien()
    {
      Console.WriteLine("Danh sach nhan vien");
      List_NhanVien.ForEach(nv => nv.Xuat_ThongTin_NhanVien());
    }
    public double Tinhtongluong()
    {
      return List_NhanVien.Sum(nv=>nv.Tinhluong());
    }
    public NhanVien Timluongcao()
    {
      return List_NhanVien.OrderByDescending(t => t.Tinhluong()).ToList().First();
    }
    public void SapXep_NhanVien_TheoNamVaoLam()
    {
      this.List_NhanVien = this.List_NhanVien.OrderBy(nv=>nv.Nvl).ToList();
    }
  }
}
