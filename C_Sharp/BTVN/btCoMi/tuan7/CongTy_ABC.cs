using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace _48_TuHueSon_Tuan7
{
    class CongTy_ABC
    {
        String tenCT, diaChi;
        List<NhanVien> list;
        public CongTy_ABC()
        {
            list = new List<NhanVien>();
            this.tenCT = null;
            this.diaChi = null;
        }
        public void docFilexml()
        {
            XmlDocument root = new XmlDocument();
            root.Load("../../CongTy_ABC.xml");
            this.tenCT = root.DocumentElement["TenCongTy"].InnerText;
            this.diaChi = root.DocumentElement["DiaChi"].InnerText;
            //<ma>nv1</ma>
            //<hoTen>tu hue son</hoTen>
            //<gioiTinh>Nam</gioiTinh>
            //<namSinh>2001</namSinh>
            //<hsl>1.0</hsl>
            //<namVaoLam>2020</namVaoLam>
            foreach (XmlNode node in root.DocumentElement["DanhSach"])
            {
                NhanVien nv;
                var ma = node["ma"].InnerText;
                var hoTen = node["hoTen"].InnerText;
                var gioiTinh = node["gioiTinh"].InnerText;
                var hsl = float.Parse(node["hsl"].InnerText);
                var namSinh = int.Parse(node["namSinh"].InnerText);
                var namVaoLam = int.Parse(node["namVaoLam"].InnerText);

                var loai = int.Parse(node.Attributes["loai"].Value);
                if (loai == 1)
                    nv = new Nv_SX(ma, hoTen, namSinh, hsl, namVaoLam, gioiTinh, uint.Parse(node["soNgayNghi"].InnerText));
                else if (loai == 2)
                    nv = new Nv_KD(ma, hoTen, namSinh, hsl, namVaoLam, gioiTinh, float.Parse(node["doanhThu"].InnerText), float.Parse(node["doanhThuTT"].InnerText));
                else nv = new CanBo(ma, hoTen, namSinh, hsl, namVaoLam, gioiTinh, node["chucVu"].InnerText, float.Parse(node["hsCv"].InnerText));
                list.Add(nv);
            }
        }
        public void xuat()
        {
            Console.WriteLine("\nThong tin nhan vien");

            list.ForEach(nv => nv.Xuat());
        }
        public double TongThuNhap()
        {
            return list.Sum(nv => nv.TinhLuong());
        }
    }
}
