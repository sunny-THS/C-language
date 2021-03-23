/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package qlkh;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author A102PC32
 */
public class Main {
    public static ArrayList<KhachHang> lkh = new ArrayList<KhachHang>();
    private static String path = "D:/dataKH.txt";
    public static void main(String[] args) {
        while(true) {
            menu();
        }
    }
    private static void menu() {
        System.out.println("1. Nhập thông tin từ bàn phím");
        System.out.println("2. Xuất thông tin");
        System.out.println("3. Ghi thông vào file");
        System.out.println("4. Xuất thông từ file");
        System.out.println("5. Thoát");
        System.out.print("Chọn: ");
        int chon = new Scanner(System.in).nextInt();
        switch(chon) {
            case 1:
                nhapThongTinKhachHang();
                break;
            case 2: 
                xuatThongTinKhachHang();
                break;
            case 3:
                ghiThongTinVaoFile();
                break;
            case 4:
                docThongTinTuFile();
                break;
            case 5:
                System.exit(0);
        }
    }

    private static void nhapThongTinKhachHang() {
        System.out.print("Nhập số lượng khách hàng cần: ");
        int sl = new Scanner(System.in).nextInt();
        for (int i = 0; i < sl; i++) {
            System.out.printf("\nKhách hàng thứ %d\n1"
                    + "", i+1);
            KhachHang kh = new KhachHang();
            kh.nhapThongTin();
            lkh.add(kh); 
        }
    }

    private static void xuatThongTinKhachHang() {
        lkh.forEach(kh -> {
            System.out.println(kh);
        });
    }

    private static void ghiThongTinVaoFile() {
        if (DocGhiFileText.ghiFile(lkh, path))
            System.out.println("Ghi file thành công!");
        else System.out.println("Ghi file thất bại!");
    }

    private static void docThongTinTuFile() {
        lkh = DocGhiFileText.docFile(path);
        lkh.forEach(kh -> {
            System.out.println(kh);
        });
    }
}
