/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c130;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class MonHoc {

    /**
     * @return the maMH
     */
    public String getMaMH() {
        return maMH;
    }

    /**
     * @param maMH the maMH to set
     */
    public void setMaMH(String maMH) {
        this.maMH = maMH;
    }

    /**
     * @return the tenMH
     */
    public String getTenMH() {
        return tenMH;
    }

    /**
     * @param tenMH the tenMH to set
     */
    public void setTenMH(String tenMH) {
        this.tenMH = tenMH;
    }

    /**
     * @return the soTC
     */
    public int getSoTC() {
        return soTC;
    }

    /**
     * @param soTC the soTC to set
     */
    public void setSoTC(int soTC) {
        this.soTC = soTC;
    }
    public static Scanner in = new Scanner(System.in);
    private String maMH;
    private String tenMH;
    private int soTC;

    public MonHoc() {
    }

    public MonHoc(String maMH, String tenMH, int soTC) {
        this.maMH = maMH;
        this.tenMH = tenMH;
        this.soTC = soTC;
    }
    public void nhap() {
        in.nextLine();
        System.out.print("Nhập mã môn học: ");
        this.maMH = in.nextLine();
        System.out.print("Nhập tên môn học: ");
        this.tenMH = in.nextLine();
        System.out.print("Nhập số tín chỉ: ");
        this.soTC = in.nextInt();
    }
    public void xuat() {
        System.out.println("\nMã môn học: " + this.maMH);
        System.out.println("Tên môn học: " + this.tenMH);
        System.out.println("Số tín chỉ: " + this.soTC);
    }
    public float tinhDTB() {
        return 0;
    }
}
