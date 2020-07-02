using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan2
{
  public class VanDongVien
  {
    public static Time ThanhTichChuan = new Time(1, 30, 00);
    String MaSo, HoTen;
    int SoAo;
    Time ThoiGianBatDau, ThoiGianKetThuc;
    public VanDongVien()
    {
      ThoiGianBatDau = new Time();
      ThoiGianKetThuc = new Time();
    }
    public VanDongVien(String MaSo, String HoTen, int SoAo)
    {
      ThoiGianBatDau = new Time();
      ThoiGianKetThuc = new Time();
      this.MaSo = MaSo;
      this.HoTen = HoTen;
      this.SoAo = SoAo;
    }
    public VanDongVien(VanDongVien vdv)
    {
      this.ThoiGianBatDau = vdv.ThoiGianBatDau;
      this.ThoiGianKetThuc = vdv.ThoiGianKetThuc;
      this.MaSo = vdv.MaSo;
      this.HoTen = vdv.HoTen;
      this.SoAo = vdv.SoAo;
    }
    public void Nhap_ThongTin_VanDongVien()
    {
      bool kt;
      Console.Write("Nhap ma so: ");
      this.MaSo = Console.ReadLine();
      Console.Write("Nhap ho ten: ");
      this.HoTen = Console.ReadLine();
      Console.Write("Nhap so ao: ");
      this.SoAo = int.Parse(Console.ReadLine());
      do {
        Console.Write("Nhap thoi gian bat dau: ");
        this.ThoiGianBatDau.Nhap_Kieu24h();
        Console.Write("Nhap thoi gian ket thuc: ");
        this.ThoiGianKetThuc.Nhap_Kieu24h();
        kt = this.KiemTra_ThoiGianNhap();
        if(!kt)
          Console.WriteLine("Moi Ban Nhap Lai thoi gian");
      } while (!kt);
      Console.WriteLine("---------------------------");
    }
    public void Xuat_ThongTin_VanDongVien()
    {
      Console.WriteLine("Ma So: {0}\nHo va Ten: {1}\nSo ao: {2}", this.MaSo, this.HoTen, this.SoAo);
      Console.Write("Start: ");
      this.ThoiGianBatDau.Xuat_Kieu24h();
      Console.Write("End: ");
      this.ThoiGianKetThuc.Xuat_Kieu24h();
      Console.WriteLine("=============================");
    }
    public Time Tinh_ThanhTich()
    {
      return this.ThoiGianKetThuc - this.ThoiGianBatDau;
    }
    public bool KiemTra_ThoiGianNhap()
    {
      return this.ThoiGianBatDau.KiemTra_GioHopLe() && this.ThoiGianKetThuc.KiemTra_GioHopLe();
    }
  }
}
