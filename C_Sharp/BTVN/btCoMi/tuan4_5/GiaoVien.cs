using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan3
{
  class GiaoVien
  {
    String HoTen;
    int SoNhom;
    public String HOTEN
    {
      get { return HoTen; }
      set { HoTen = value; }
    }
    public int SONHOM
    {
      get { return SoNhom; }
      set
      {
        if(value < 0)
          throw new Exception("So nhom >= 1");
        SoNhom = value;
      }
    }
    public GiaoVien()
    {
        this.HoTen = String.Empty;
        this.SoNhom = 0;
    }
    public GiaoVien(String HoTen, int SoNhom)
    {
        this.HoTen = HoTen;
        this.SoNhom = SoNhom;
    }
    public void Nhap_ThongTin_GiaoVien()
    {
      Console.Write("Nhap ho ten: ");
      this.HoTen = Console.ReadLine();
      Console.Write("Nhap so nhom: ");
      this.SONHOM = int.Parse(Console.ReadLine());
      Console.WriteLine("---------------------------------");
    }
    public void Xuat_ThongTin_GiaoVien()
    {
      Console.WriteLine("Ho ten: {0}\nSo nhom: {1}", this.HoTen, this.SoNhom);
      Console.WriteLine("====================================");
    }
  }
}
