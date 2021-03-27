/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c124;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class SDDiem {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Diem2D A = new Diem2D(3, 4);
        System.out.print("A");
        A.hienThi();
        System.out.println();
        System.out.print("Nhập x: ");
        int x = in.nextInt();
        System.out.print("Nhập y: ");
        int y = in.nextInt();
        Diem2D B = new Diem2D(x, y);
        System.out.print("B");
        B.hienThi();
        System.out.println();
        Diem2D C = new Diem2D();
        C.setX(-B.giaTriX());
        C.setY(-B.giaTriY());
        System.out.print("C");
        C.hienThi();    
        System.out.println();
        System.out.printf("\nKhoảng cách từ điểm B đến điểm O: %.2f\n", B.khoangCach());
        System.out.printf("\nKhoảng cách từ điểm A đến điểm B: %.2f\n", A.khoangCach(B));
    }
}
