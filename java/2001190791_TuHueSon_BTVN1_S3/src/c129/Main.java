/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c129;

import java.util.ArrayList;


/**
 *
 * @author Admin
 */
public class Main {
    public static void main(String[] args) {
        ArrayList<NhanVien> list = new ArrayList<>();
        int chon;
        do {
            System.out.println("\n\nNhập thông tin nhân viên");
            System.out.println("1. Nhân viên văn phòng");
            System.out.println("2. Nhân viên sản xuất");
            System.out.println("3. Nhân viên quản lí");
            System.out.println("0. Thoát!");
            System.out.print("Chon: ");
            chon = NhanVien.in.nextInt();
            switch (chon) {
                case 1:
                    NhanVien nvvp = new NvVanPhong();
                    nvvp.nhap();
                    list.add(nvvp);
                    break;
                case 2:
                    NhanVien nvsx = new NvSanXuat();
                    nvsx.nhap();
                    list.add(nvsx);
                    break;
                case 3: 
                    NhanVien nvql = new NvQuanLy();
                    nvql.nhap();
                    list.add(nvql);
                    break;
            }
        } while (chon!=0);
        System.out.println("\nThông tin nhân viên\n");
        list.forEach(i -> i.xuat());
        double s = 0;
        for (NhanVien nv : list)
            s += nv.tinhLuong();
        System.out.printf("Tổng tiền lương của công ty: %.2f", s);
    }
}
