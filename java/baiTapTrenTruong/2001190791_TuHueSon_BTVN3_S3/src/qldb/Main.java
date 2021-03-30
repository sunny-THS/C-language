/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package qldb;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author A102PC32
 */
public class Main {
    public static ArrayList<DanhBa> ldb = new ArrayList<DanhBa>();
    private static String path = "D:/dataDB.obj";
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
        System.out.print("Nhập số lượng danh bạ cần: ");
        int sl = new Scanner(System.in).nextInt();
        for (int i = 0; i < sl; i++) {
            System.out.printf("\nDanh bạ thứ %d\n", i+1);
            DanhBa db = new DanhBa();
            db.nhapThongTin();
            ldb.add(db); 
        }
    }

    private static void xuatThongTinKhachHang() {
        ldb.forEach(kh -> {
            System.out.println(kh);
        });
    }

    private static void ghiThongTinVaoFile() {
        if (DocGhiFileText.ghiFile(ldb, path))
            System.out.println("Ghi file thành công!");
        else System.out.println("Ghi file thất bại!");
    }

    private static void docThongTinTuFile() {
        ldb = DocGhiFileText.docFile(path);
        ldb.forEach(kh -> {
            System.out.println(kh);
        });
    }
}
