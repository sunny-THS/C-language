/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c126;


/**
 *
 * @author Admin
 */
public class Main {
    public static void main(String[] args) {
        TamGiac tg = new TamGiac();
        System.out.println("Nhập các điểm trong tam giác");
        tg.nhap();
        System.out.printf("Chu vi tam giác: %.2f\n", tg.chuVi());
        System.out.printf("Diện tích tam giác: %f\n", tg.dienTich());

    }
}
