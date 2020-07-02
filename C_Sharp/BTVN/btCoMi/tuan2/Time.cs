using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan2
{
  public class Time
  {
    int gio, phut, giay;
    bool buoi;
    bool type; // true is 24h and false is 12h
    public int Hour
    {
      set
      {
        // if(value >= 0 && value <= 23)
        //   this.gio = value;
        // else
        // {
        //   this.gio = 0;
        //   throw new Exception("Du lieu nhap bi loi");
        // }
        this.gio = value;
      }
      get{ return this.gio; }
    }
    public int Minute
    {
      set
      {
        // if(value >= 0 && value <= 59)
        //   this.phut = value;
        // else
        // {
        //   this.phut = 0;
        //   throw new Exception("Du lieu nhap bi loi"); // phat hien loi
        // }
        this.phut = value;
      }
      get{ return this.phut; }
    }
    public int Second
    {
      set
      {
        // if(value >= 0 && value <= 59)
        //   this.giay = value;
        // else
        // {
        //   this.giay = 0;
        //   throw new Exception("Du lieu nhap bi loi"); // phat hien loi
        // }
        this.giay = value;
      }
      get{ return this.giay; }
    }
    public Time()
    {
      this.giay = 0;
      this.phut = 0;
      this.gio = 0;
    }
    public Time(int gio, int phut, int giay)
    {
      this.giay = giay;
      this.phut = phut;
      this.gio = gio;
    }
    public Time(Time t)
    {
      this.giay = t.giay;
      this.phut = t.phut;
      this.gio = t.gio;
    }
    public bool KiemTra_GioHopLe()
    {
      if(this.type)
      {
        if(this.gio>23 || this.gio<0 || this.phut<0 || this.phut>59 || this.giay<0 || this.giay>59)
          return false;
      }
      else
        if(this.gio>12 || this.gio<1 || this.phut<0 || this.phut>59 || this.giay<0 || this.giay>59)
          return false;
      return true;
    }
    public void Nhap_Kieu24h()
    {
      // Console.WriteLine("Nhap Kieu 24h");
      this.type = true;
      Console.Write("Nhap gio: ");
      Hour = int.Parse(Console.ReadLine());
      Console.Write("Nhap phut: ");
      Minute = int.Parse(Console.ReadLine());
      Console.Write("Nhap giay: ");
      Second = int.Parse(Console.ReadLine());
    }
    public void Xuat_Kieu24h()
    {
      Console.WriteLine("{0:00}:{1:00}:{2:00}", this.gio, this.phut, this.giay);
    }
    public void Nhap_Kieu12h()
    {
      String tmp;
      this.type = false;
      // Console.WriteLine("Nhap Kieu 12h");
      Console.Write("Nhap gio: "); // 1-12
      Hour = int.Parse(Console.ReadLine());
      Console.Write("Nhap phut: ");
      Minute = int.Parse(Console.ReadLine());
      Console.Write("Nhap giay: ");
      Second = int.Parse(Console.ReadLine());
      do {
        Console.Write("Nhap AM/PM: ");
        tmp = Console.ReadLine();
        if(tmp.ToUpper().Equals("AM"))
          this.buoi = true;
        else if(tmp.ToUpper().Equals("PM"))
          this.buoi = false;
      } while (!(tmp.ToUpper().Equals("PM") || tmp.ToUpper().Equals("AM")));
    }
    public void Xuat_Kieu12h()
    {
      String tmp;
      if(this.buoi)
        tmp = "AM";
      else tmp = "PM";
      Console.WriteLine("{0:00}:{1:00}:{2:00} {3}", this.gio, this.phut, this.giay, tmp);
    }
    // tang gio
    public void Tang_Gio(int soGiay)
    {
      var tmp = this.gio*3600 + this.phut*60 + this.giay;
      tmp += soGiay;
      this.gio = tmp/3600;
      this.phut = tmp%3600/60;
      this.giay = tmp%3600%60;
      if(this.gio>23)
        this.gio -= 24;
    }
    public void Tang_Gio(int soGiay, String KieuGio)
    {
      if(KieuGio.Equals("24"))
        Tang_Gio(soGiay);
      else if(KieuGio.Equals("12"))
      {
        var tmp = this.gio*3600 + this.phut*60 + this.giay;
        tmp += soGiay;
        this.gio = tmp/3600;
        this.phut = tmp%3600/60;
        this.giay = tmp%3600%60;
        if(this.gio>12)
        {
          this.gio -= 12;
          this.buoi = !this.buoi;
        }
      }
    }
    // giam gio
    public void Giam_Gio(int soGiay)
    {
      var tmp = this.gio*3600 + this.phut*60 + this.giay;
      tmp -= soGiay;
      if(tmp<0)
        tmp = 23*3600 + 59*60 + 60 + tmp;
      this.gio = tmp/3600;
      this.phut = tmp%3600/60;
      this.giay = tmp%3600%60;
    }
    public void Giam_Gio(int soGiay, String KieuGio)
    {
      if(KieuGio.Equals("24"))
        Tang_Gio(soGiay);
      else if(KieuGio.Equals("12"))
      {
        var tmp = this.gio*3600 + this.phut*60 + this.giay;
        tmp -= soGiay;
        if(tmp<0)
        {
          tmp = 23*3600 + 59*60 + 60 + tmp;
          this.buoi = !this.buoi;
        }
        this.gio = tmp/3600;
        this.phut = tmp%3600/60;
        this.giay = tmp%3600%60;
      }
    }

    // operator(-)
    public static Time operator-(Time t1, Time t2)
    {
        int s1 = t1.gio*3600 + t1.phut*60 + t1.giay;
        int s2 = t2.gio*3600 + t2.phut*60 + t2.giay;
        if(s1<s2)
          s1 += 86400;
        int res = s1 - s2;
        return new Time(res/3600, res%3600/60, res%3600%60);
    }
    // operator(<=)
    public static bool operator<=(Time t1, Time t2)
    {
      int s1 = t1.gio*3600 + t1.phut*60 + t1.giay;
      int s2 = t2.gio*3600 + t2.phut*60 + t2.giay;
      return s1<=s2;
    }
    // operator(>=)
    public static bool operator>=(Time t1, Time t2)
    {
      int s1 = t1.gio*3600 + t1.phut*60 + t1.giay;
      int s2 = t2.gio*3600 + t2.phut*60 + t2.giay;
      return s1>=s2;
    }
  }
}
