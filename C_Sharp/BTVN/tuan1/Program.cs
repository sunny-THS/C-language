using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan1
{
  public class NgayThang //bai 9
  {
      int ngay, thang, nam;
      public NgayThang()
      {
          this.ngay = 1;
          this.thang = 1;
          this.nam = 2000;
      }
      public NgayThang(int d, int m, int y)
      {
          this.ngay = d;
          this.thang = m;
          this.nam = y;
      }
      public void XuatDate()
      {
        Console.WriteLine("{0}/{1}/{2}", this.ngay, this.thang, this.nam);
      }
      public NgayThang Tinh_Ngay_Hom_Sau()
      {
          int[] days = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
          var d = this.ngay;
          var m = this.thang;
          var y = this.nam;
          d++;
          if(m==2 && ((y%4==0&&y%100!=0)||y%400==0))
          {
              if(d>29)
              {
                  d = days[0];
                  m++;
              }
          }else if(d>days[m])
          {
              d = days[0];
              m++;
          }
          if(m>12)
          {
              m = 1;
              y++;
          }
          return new NgayThang(d, m, y);
      }
      public NgayThang Tinh_Ngay_Truoc_Do()
      {
          int[] days = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
          var d = this.ngay;
          var m = this.thang;
          var y = this.nam;
          d--;
          if(d<days[0])
          {
              m--;
              if(m<1)
              {
                  y--;
                  m = 12;
              }
              if(m==2 && ((y%4==0&&y%100!=0)||y%400==0))
                  d = 29;
              else d = days[m];
          }
          return new NgayThang(d, m, y);
      }
  }
  class Program
  {
    static void Phan_Tich_Thua_SNT(int n) // Phan tich thua so nguyen to
    {
      int d;
      Console.Write("Thua so nguyen to cua {0}: ", n);
      for (var i = 2; i <= n; i++)
      {
        d = 0;
        while(n%i==0)
        {
          d++;
          n/=i;
        }
        if(d!=0)
        {
          Console.Write(i);
          if(d>1)
            Console.Write("^{0}", d);
          if (n>i)
          {
            Console.Write("*");
          }
        }
      }
    }
    static int Dem_Chu_So(int n) // n co bao nhieu chu so?
    {
      var d = 0;
      while(n!=0)
      {
        d++;
        n/=10;
      }
      return d;
    }
    static void Bai7()
    {
      int n;
      Console.Write("Nhap so nguyen n: ");
      n = Convert.ToInt32(Console.ReadLine());
      Phan_Tich_Thua_SNT(n);
      Console.WriteLine("\nn co {0} chu so", Dem_Chu_So(n));
    }
    static bool Xet_SCP(int n)
    {
      var bl = true;
      int sqrt_ = (int)Math.Sqrt(n);
      if(sqrt_*sqrt_ != n)
      {
        bl = !bl;
      }
      return bl;
    }
    static void Bai8()
    {
      int n;
      bool bl;
      do
      {
        Console.Write("Nhap so chinh phuong n: ");
        n = Convert.ToInt32(Console.ReadLine());
        bl = Xet_SCP(n);
        if(!bl)
          Console.WriteLine("Xin moi ban nhap lai");
      } while (!bl);
      Console.WriteLine("So chinh phuong vua nhap: {0}",  n);
    }
    static int XetThang(int m)
    {
      switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return 28;
      }
      return -1;
    }
    static bool XetNgay(int d, int m, int y)
    {
      var bl = true;
      if (d<1 || d>31 || m<1 || m>12) {
        bl = !bl;
      }else if(y%4==0&&y%100!=0||y%400==0){ // nam nhuan
        if (m==2 && d>29 || d>XetThang(m)) {
          bl = !bl;
        }
      }else if(d>XetThang(m)){
        bl = !bl;
      }
      return bl;
    }
    static void Bai9() {
      int d, m, y;
      do {
        Console.Write("Nhap ngay: ");
        d = Convert.ToInt32(Console.ReadLine());
        Console.Write("Nhap thang: ");
        m = Convert.ToInt32(Console.ReadLine());
        Console.Write("Nhap nam: ");
        y = Convert.ToInt32(Console.ReadLine());
      } while (!XetNgay(d, m, y));
      NgayThang date = new NgayThang(d, m, y);
      NgayThang nextDay = new NgayThang();
      NgayThang preDay = new NgayThang();
      nextDay = date.Tinh_Ngay_Hom_Sau();
      preDay = date.Tinh_Ngay_Truoc_Do();

      Console.Write("Ngay Truoc do: ");
      preDay.XuatDate();
      Console.Write("Ngay Sau do: ");
      nextDay.XuatDate();
    }
    static void Xuat(List<int> list)
    {
      Console.Write("Cac Phan tu trong list: ");
      list.ForEach(item =>Console.Write(item + " "));
      Console.WriteLine();
    }
    static void xuat_list_CoDK(bool dk, int item)
    {
      if (dk) {
        Console.Write(item + " ");
      }
    }
    static bool Xet_So_Luon_Chan(int n) // XET SO LUON CHAN
    {
      while(n!=0){
        if (n%10%2!=0) {
          return false;
        }
        n/=10;
      }
      return true;
    }
    static bool XetSNT(int n) // XET SO NGUYEN TO
    {
      if(n < 2)
        return false;
      for (var i = 2; i <= Math.Sqrt(n); i++) {
        if(n%i==0)
          return false;
      }
      return true;
    }
    static void Bai10()
    {
      const int len = 20;
      int x;
      List<int> list= new List<int>(len);
      Random rand = new Random();
      for (var i = 0; i < list.Capacity; i++) { // gan gia tri
        var k = rand.Next(1000);
        list.Add(k);
      }
      Console.WriteLine();
      Xuat(list); // xuat gia tri
      Console.WriteLine();
      list.Reverse(); // dao list
      Console.WriteLine("Dao day so");
      Xuat(list);
      Console.WriteLine();
      Console.Write("Nhap x: ");
      x = Convert.ToInt32(Console.ReadLine());
      if (list.Contains(x)) { // xet xem co chua gia tri x khong (x Nhap tu ban phim)
        Console.WriteLine("Co chua gia tri x={0}", x);
      }else {
        Console.WriteLine("Khong co chua gia tri x");
      }
      Console.WriteLine();
      Console.Write("Cac phan tu co 2 chu so: ");// xuat cac phan tu co 2 chu so
      list.ForEach(item=>xuat_list_CoDK(item/100==0&&item!=0, item));
      Console.WriteLine();
      Console.WriteLine();
      Console.Write("Cac so co cac chu so deu la so chan: "); // tim so luon chan
      list.ForEach(item=>xuat_list_CoDK(Xet_So_Luon_Chan(item), item));
      Console.WriteLine();
      Console.WriteLine();
      Console.Write("Cac so nguyen to trong day: "); // tim so nguyen to
      list.ForEach(item=>xuat_list_CoDK(XetSNT(item), item));
      Console.WriteLine();
      Console.WriteLine();
      Console.WriteLine("Xoa day so cac so le va la bo cua 3"); // xoa phan tu theo dieu kien
      list.RemoveAll(item=>(item%2!=0 && item%3==0));
      Xuat(list);
      Console.WriteLine();
      for (var i = 1; i < list.Count-1; i++) {
        if (list[i]<list[i-1] && list[i]<list[i+1]) {
          list[i]++;
        }
      }
      Console.WriteLine("Cau hoi gan cuoi");
      Xuat(list); // cau gan cuoi
      Console.WriteLine();
      Console.WriteLine("Sap xep tang"); // XEP TANG DAN
      list.Sort();
      Xuat(list);
      Console.WriteLine();
      Console.WriteLine("Sap xep giam"); // XEP GIAM DAM
      list.Reverse();
      Xuat(list);
    }
    static void Main(string[] args)
    {
      Console.WriteLine("CAU 7");
      Bai7();
      Console.WriteLine("=============================");
      Console.WriteLine();
      Console.WriteLine("CAU 8");
      Bai8();
      Console.WriteLine("=============================");
      Console.WriteLine();
      Console.WriteLine("CAU 9");
      Bai9();
      Console.WriteLine("=============================");
      Console.WriteLine();
      Console.WriteLine("CAU 10");
      Bai10();
      Console.ReadKey();
    }
  }
}
