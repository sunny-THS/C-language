using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TuHueSon_2001190791
{
  public class NhanVien
  {
    Double hsl;
    String mnv;
    String hoten;
    int nvl;
    public static double mltt = 2000;

    public String Mnv
    {
      get { return mnv; }
      set { mnv = value; }
    }

    public String Hoten
    {
      get { return hoten; }
      set { hoten = value; }
    }

    public double Hsl
    {
      get { return hsl; }
      set { hsl = value; }
    }

    public int Nvl
    {
      get { return nvl; }
      set { nvl = value; }
    }
    public NhanVien()
    {
      this.mnv = "001";
      this.hoten = "le van a";
      this.hsl = 1;
      this.nvl = 2000;
    }
    public NhanVien(String mnv, String hoten, double hsl, int nvl)
    {
      this.mnv = mnv;
      this.hoten = hoten;
      this.hsl = hsl;
      this.nvl = nvl;
    }
    public NhanVien(NhanVien nv)
    {
      this.mnv = nv.mnv;
      this.hoten = nv.hoten;
      this.hsl = nv.hsl;
      this.nvl = nv.nvl;
    }
    public void Nhap_ThongTin_NhanVien()
    {
      Console.Write("Nhap ma nhan vien: ");
      Mnv = Console.ReadLine();
      Console.Write("Nhap ho ten: ");
      Hoten = Console.ReadLine();
      Console.Write("Nhap he so luong: ");
      Hsl = double.Parse(Console.ReadLine());
      Console.Write("Nhap nam vao lam: ");
      Nvl = int.Parse(Console.ReadLine());
      Console.WriteLine("==================================");
    }
    public void Xuat_ThongTin_NhanVien()
    {
      Console.WriteLine(" Thong tin nhan Vien:\n Ma nhan vien: {0}\n Ho ten: {1}\n He so luong: {2}\n Nam vao lam: {3}\n Luong: {4}\n", mnv, hoten, hsl, nvl, Tinhluong());
      Console.WriteLine("-----------------------------------");
    }
    public double Tinhluongcoban()
    {
      return hsl * mltt;
    }
    public double Tinhluongphucap()
    {
      DateTime Nam_HienTai = DateTime.Today;
      return mltt * (Nam_HienTai.Year - nvl) / 100;
    }
    public double Tinhluong()
    {
      return Tinhluongcoban() + Tinhluongphucap();
    }
  }
}
