using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace _48_TuHueSon_Tuan3
{
  class DanhSach_GiaoVien
  {
      String Khoa, DiaDiem;
    List<GiaoVien> list_GV;
    public DanhSach_GiaoVien()
    {
      list_GV = new List<GiaoVien>(10);
    }
    //public void Nhap_ThongTin_ListGiaoVien()
    //{
    //  int SoGV;
    //  do {
    //    try
    //    {
    //      Console.Write("Nhap so giao vien: ");
    //      SoGV = int.Parse(Console.ReadLine());
    //    }
    //    catch
    //    {
    //      Console.WriteLine("Moi ban nhap lai");
    //      SoGV = -1;
    //    }
    //  } while (SoGV < 0);
    //  for(var i = 0; i < SoGV; i++)
    //  {
    //    GiaoVien gv = new GiaoVien();
    //    gv.Nhap_ThongTin_GiaoVien();
    //    list_GV.Add(gv);
    //  }
    //}
    public void DocFileXML(String file)
    {
        XmlDocument xml = new XmlDocument();
        xml.Load(file);
        //cach 1
        //XmlNode root = xml.SelectSingleNode("/DHCNTP");
        //this.Khoa = root.FirstChild.InnerText;
        //this.DiaDiem = root.FirstChild.NextSibling.InnerText;
        //foreach (XmlNode node in root.ChildNodes[2])
        //{
        //    list_GV.Add(new GiaoVien(node["HoTen"].InnerText, int.Parse(node["SoNhom"].InnerText)));
        //}
        //canh 2
        this.Khoa = xml.DocumentElement["Khoa"].InnerText;
        this.DiaDiem = xml.DocumentElement["DiaDiem"].InnerText;
        foreach (XmlNode node in xml.DocumentElement["DanhSach"])
        {
            var loai = int.Parse(node.Attributes["Loai"].Value);
            list_GV.Add(new GiaoVien(node["HoTen"].InnerText, int.Parse(node["SoNhom"].InnerText)));
        }

        // example
        //XmlDocument xmlDoc = new XmlDocument();
        //xmlDoc.LoadXml("<users><user>InnerText/InnerXml is here</user></users>");
        //Console.WriteLine("InnerXml: " + xmlDoc.DocumentElement.InnerXml);
        //Console.WriteLine("InnerText: " + xmlDoc.DocumentElement.InnerText);
    }
    public void Xuat_ThongTin_ListGiaoVien()
    {
      Console.WriteLine("Thong Tin Giao Vien");
      list_GV.ForEach(gv => gv.Xuat_ThongTin_GiaoVien());
    }
    public int TongSoNhom()
    {
      return list_GV.Sum(gv => gv.SONHOM);
    }
    public void SapXep_TangDan_TheoHoTen()
    {
      list_GV = list_GV.OrderBy(gv => gv.HOTEN).ToList();
    }
    public void SapXep_GiamDan_TheoSoNhom()
    {
      list_GV = list_GV.OrderByDescending(gv => gv.SONHOM).ToList();
    }
    public List<GiaoVien> Loc_SoNhom_LonHon1()
    {
      return list_GV.Where(gv => gv.SONHOM > 1).ToList();
    }
    public GiaoVien Tim(String x)
    {
        return list_GV.Find(ds => ds.HOTEN.Equals(x));
    }
  }
}
