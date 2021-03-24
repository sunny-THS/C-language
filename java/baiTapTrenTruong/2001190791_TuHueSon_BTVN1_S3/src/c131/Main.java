/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c131;

import java.util.ArrayList;

/**
 *
 * @author Admin
 */
public class Main {
    public static void main(String[] args) {
        ArrayList<BatDongSan> list = new ArrayList<>();
        int chon; 
        do {
            System.out.println("\n\nNhập thông tin Bất động sản");
            System.out.println("1. Đất trồng");
            System.out.println("2. Nhà ở");
            System.out.println("3. Khách Sạn");
            System.out.println("4. Biệt thự");
            System.out.println("0. Thoát!");
            System.out.print("Chon: ");
            chon = BatDongSan.in.nextInt();
            switch (chon) {
                case 1:
                    BatDongSan dt = new DatTrong();
                    dt.nhap();
                    list.add(dt);
                    break;
                case 2:
                    BatDongSan no = new NhaO();
                    no.nhap();
                    list.add(no);
                    break;
                case 3: 
                    BatDongSan ks = new KhachSan();
                    ks.nhap();
                    list.add(ks);
                    break;
                case 4: 
                    BatDongSan bt = new BietThu();
                    bt.nhap();
                    list.add(bt);
                    break;
            }
        } while (chon!=0);
        System.out.println("\nThông tin các bất động sản\n");
        list.forEach(i -> i.xuat());   
        System.out.print("\nGiá bản của tất cả bất động sản: ");
        float gia = 0;
        gia = list.stream().map((bds) -> bds.tinhGiaTri()).reduce(gia, (accumulator, _item) -> accumulator + _item);
        System.out.println(gia);
    }
}
