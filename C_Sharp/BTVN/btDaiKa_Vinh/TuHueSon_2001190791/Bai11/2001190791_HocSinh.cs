using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TuHueSon_2001190791
{
  public class HocSinh
  {
    String Mhs, hT, ngaySinh;
    double dT, dL, dH;
    public void Nhap_ThongTin_HocSinh()
    {
      Console.Write("Ma so hoc sinh: ");
      this.Mhs = Console.ReadLine();
      Console.Write("Ho va ten: ");
      this.hT = Console.ReadLine();
      Console.Write("Nhap Ngay Sinh: ");
      this.ngaySinh = Console.ReadLine();
      Console.Write("Nhap diem toan: ");
      DT = double.Parse(Console.ReadLine());
      Console.Write("Nhap diem ly: ");
      DL = double.Parse(Console.ReadLine());
      Console.Write("Nhap diem hoa: ");
      DH = double.Parse(Console.ReadLine());
    }
    public Xuat_ThongTin_HocSinh()
    {
      Console.WriteLine("Mshs: {0}\nHo va ten: {1}\nNgay Sinh: {2}\nDiem toan: {3} -- Diem Ly: {4} -- Diem Hoa: {5}", this.Mhs, this.hT, this.ngaySinh, this.dT, this.dL, this.dH);
      Console.WriteLine("+++++++++++++++++++++++++++++++++++++++++");
    }
    public double DL
    {
      get { return dL; }
      set {
        dL = value;
        if (dL < 0 || dL > 10)
        {
          dL = 0;
          throw new Exception("loi gia tri");
        }
      }
    }

    public double DH
    {
      get { return dH; }
      set {
        dH = value;
        if (dH < 0 || dH > 10)
        {
          dH = 0;
          throw new Exception("loi gia tri");
        }
      }
    }

    public double DT
    {
      get { return dT; }
      set {
        dT = value;
        if (dT < 0 || dT > 10)
        {
          dT = 0;
          throw new Exception("loi gia tri");
        }
      }
    }
    public double TingTongDiem3Mon()
    {
      return this.dT + this.dH + this.dL;
    }
  }
}
