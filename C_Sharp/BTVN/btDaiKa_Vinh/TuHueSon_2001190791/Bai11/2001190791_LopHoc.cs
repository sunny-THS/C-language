using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TuHueSon_2001190791
{
  public class LopHoc
  {
    List<HocSinh> List_hs_;
    int SiSo;
    // String MaLop, Tenlop; // tuy bai
    public LopHoc()
    {
      List_hs_ = new List<HocSinh>(30); // toi thieu 30 hs
      this.SiSo = 0;
    }
    public void Them_HocSinh(HocSinh hs)
    {
      List_hs_.Add(hs);
    }
    public void Nhap_ThongTin_ListHocSinh()
    {
      Console.Write("Nhap so luong hoc sinh: ");
      SiSo = int.Parse(Console.ReadLine());
      for(var i = 0; i < this.SiSo; i++)
      {
        HocSinh hs = new HocSinh();
        hs.Nhap_ThongTin_HocSinh();
        Them_HocSinh(hs);
      }
    }
    public void Xuat_ThongTin_ListHocSinh()
    {
      Console.WriteLine("Danh Sach Hoc Sinh");
      List_hs_.ForEach(hs=>hs.Xuat_ThongTin_HocSinh());
    }
    public HocSinh HocSinh_CoTongDiem_Max()
    {
      if(List_hs_.Count == 0)
        return null;
      HocSinh max = List_hs_.OrderByDescending(hs=>hs.TinhTongDiem3Mon()).ToList().First();
      return max;
    }
    public HocSinh Tim_ThongTin_HocSinh(String tt)
    {
      try
      {
        if(List_hs_.Count == 0)
          return null;
        HocSinh hs = List_hs_.Find(hs=>hs.MHS.ToUpper().Equals(tt.ToUpper()) || hs.HT.ToUpper().Equals(tt.ToUpper()));
        return hs;
      }
      catch (ArgumentNullException e)
      {
        Console.Write("Exception Thrown: ");
        Console.Write("{0}", e.GetType(), e.Message);
      }
    }
  }
}
