/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c130;

import java.util.ArrayList;

/**
 *
 * @author Admin
 */
public class Main {
    public static void main(String[] args) {
        ArrayList<MonHoc> list = new ArrayList<>();
        int chon;
        do {
            System.out.println("\n\nNhập thông tin môn học");
            System.out.println("1. Môn lý thuyết");
            System.out.println("2. Môn thực hành");
            System.out.println("3. Môn đồ án");
            System.out.println("0. Thoát!");
            System.out.print("Chon: ");
            chon = MonHoc.in.nextInt();
            switch (chon) {
                case 1:
                    MonHoc mlt = new MLyThuyet();
                    mlt.nhap();
                    list.add(mlt);
                    break;
                case 2:
                    MonHoc mth = new MThucHanh();
                    mth.nhap();
                    list.add(mth);
                    break;
                case 3: 
                    MonHoc mda = new MDoAn();
                    mda.nhap();
                    list.add(mda);
                    break;
            }
        } while (chon!=0);
        System.out.println("\nThông tin các môn học\n");
        list.forEach(i -> i.xuat());
    }
}
