/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c125;

import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class SDPhanSo {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
//        PhanSo psA = new PhanSo(3, 7);
//        PhanSo psB = new PhanSo(4, 9);
//        System.out.print("Phân số a: ");
//        psA.hienThi();
//        System.out.print("Phân số b: ");
//        psB.hienThi();
//        System.out.println("Phân số x: ");
//        PhanSo x = new PhanSo();
//        x.nhapPS();
//        System.out.println("Phân số y: ");
//        PhanSo y = new PhanSo();
//        y.nhapPS();
//        PhanSo nghichDaoX = x.giaTriNghichDao();
//        System.out.print("Giá trị nghịch đảo của x: ");
//        nghichDaoX.hienThi();
//        System.out.print("Giá trị x: ");
//        x.hienThi();
//        System.out.print("Tổng x+y: ");
//        x.cong(y).hienThi();
//        System.out.println();
        System.out.println("Danh Sách gồm n phân số");
        System.out.print("Nhập n: ");
        int n = in.nextInt();
        PhanSo[] dsps = new PhanSo[n];
        for (int i = 0; i < n; i++) {
            PhanSo ps = new PhanSo();
            System.out.printf("Nhập phân số %d\n", i+1);
            ps.nhapPS();
            dsps[i] = new PhanSo(ps);
        }
        PhanSo resSum = new PhanSo();
        for (PhanSo ps : dsps)
            resSum = resSum.cong(ps);
        System.out.print("Tổng của n phân số: ");
        resSum.hienThi();
        PhanSo maxPs = dsps[0];
        for (PhanSo ps : dsps) {
            if (maxPs.ketQua()<ps.ketQua())
                maxPs = ps;
        }
        System.out.print("Phân số lớn nhất: ");
        maxPs.hienThi();
        for (int i = 0; i < dsps.length-1; i++) {
            for (int j = i+1; j < dsps.length; j++) {
                if (dsps[i].ketQua() > dsps[j].ketQua()) {
                    PhanSo t = dsps[i];
                    dsps[i] = dsps[j];
                    dsps[j] = t;
                }
            }
        }
        System.out.println("Danh được sắp xếp tăng dần:");
        for (PhanSo ps : dsps) {
            ps.hienThi();
        }
    }
}
