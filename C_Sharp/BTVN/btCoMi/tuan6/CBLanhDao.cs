using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _48_TuHueSon_Tuan6
{
    class CBLanhDao : NhanVien
    {
        String ChucVu;
        uint ThamNien;
        public CBLanhDao() : base("NV009", "Dieu Hien", 4.67f)
        {
            this.ChucVu = "giam doc";
            this.ThamNien = 10;
        }
        public override double thunhap()
        {
            return base.thunhap() + 1500 * Tinh_HeSoLD();
        }
        public float Tinh_HeSoLD()
        {
            if (this.ChucVu.ToLower().Equals("giam doc"))
                return 7f;
            else if (this.ChucVu.ToLower().Equals("truong phong"))
                return 6f;
            else if (this.ChucVu.ToLower().Equals("pho phong"))
                return 4.5f;
            else return 1f;
        }
        public override void Nhap()
        {
            base.Nhap();
            Console.Write("Chuc Vu: ");
            this.ChucVu = Console.ReadLine();
            Console.Write("Tham Nien: ");
            this.ThamNien = uint.Parse(Console.ReadLine());
            Console.WriteLine("=====================================");
        }
        public override void Xuat()
        {
            Console.WriteLine("Thong tin can bo lanh dao");
            base.Xuat();
            Console.WriteLine("Chuc vu: {0}", this.ChucVu.ToUpper());
            Console.WriteLine("=====================================");
        }
    }
}
