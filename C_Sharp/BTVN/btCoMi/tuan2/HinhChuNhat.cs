using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan2
{
  public class HinhChuNhat
  {
    int cd, cr;
    public int CD
    {
      get { return cd; }
      set
      {
        if(value > 0)
          this.cd = value;
        else
        {
          this.cd = 0;
          throw new Exception("Du lieu nhap bi loi");
        }
      }
    }
    public int CR
    {
      get { return cr; }
      set
      {
        if(value > 0)
          this.cr = value;
        else
        {
          this.cr = 0;
          throw new Exception("Du lieu nhap bi loi");
        }
      }
    }
    // constructor
    public HinhChuNhat()
    {
      this.cd = 0;
      this.cr = 0;
    }
    public HinhChuNhat(int cd, int cr)
    {
      this.cr = cr;
      this.cd = cd;
    }
    public HinhChuNhat(HinhChuNhat hcn)
    {
      this.cr = hcn.cr;
      this.cd = hcn.cd;
    }
    public int Tinh_ChuVi()
    {
      return (this.cd + this.cr)*2;
    }
    public int Tinh_DienTich()
    {
      return this.cd * this.cr;
    }
    public double Tinh_DuongCheo()
    {
      return Math.Sqrt(this.cd*this.cd + this.cr*this.cr);
    }
    public void Nhap()
    {
      Console.Write("Nhap chieu dai: ");
      this.cd = int.Parse(Console.ReadLine());
      Console.Write("Nhap chieu rong: ");
      this.cr = int.Parse(Console.ReadLine());
    }
    public void Xuat()
    {
      Console.WriteLine("Chu vi: {0}m\nDien tich: {1}m^2\nDuong cheo: {2}m", Tinh_ChuVi(), Tinh_DienTich(), Tinh_DuongCheo());
    }
    // change size
    public void ChangeSize(int tx, int ty, int kieu)
    {
      if(kieu==1)
      {
        this.cd += tx;
        this.cr += ty;
      }
      else
      {
        this.cd -= tx;
        this.cr -= ty;
      }
    }
    public void ChangeSize(HinhChuNhat a, int kieu)
    {
      if(kieu==1)
      {
        this.cd += a.cd;
        this.cr += a.cr;
      }
      else
      {
        this.cd -= a.cd;
        this.cr -= a.cr;
      }
    }
  }
}
