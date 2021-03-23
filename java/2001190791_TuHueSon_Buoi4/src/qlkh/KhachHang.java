/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package qlkh;

import java.util.Scanner;

/**
 *
 * @author A102PC32
 */
public class KhachHang {

    /**
     * @return the maSo
     */
    public String getMaSo() {
        return maSo;
    }

    /**
     * @param maSo the maSo to set
     */
    public void setMaSo(String maSo) {
        this.maSo = maSo;
    }

    /**
     * @return the hoTen
     */
    public String getHoTen() {
        return hoTen;
    }

    /**
     * @param hoTen the hoTen to set
     */
    public void setHoTen(String hoTen) {
        this.hoTen = hoTen;
    }

    /**
     * @return the namSinh
     */
    public int getNamSinh() {
        return namSinh;
    }

    /**
     * @param namSinh the namSinh to set
     */
    public void setNamSinh(int namSinh) {
        this.namSinh = namSinh;
    }
    private String maSo;
    private String hoTen;
    private int namSinh;

    public KhachHang() {
        this.maSo = null;
        this.hoTen = null;
        this.namSinh = 1999;
    }
    
    public KhachHang(String maSo, String hoTen, int namSinh) {
        this.maSo = maSo;
        this.hoTen = hoTen;
        this.namSinh = namSinh;
    }
    public void nhapThongTin() {
        Scanner in = new Scanner(System.in);
        System.out.print("Nhập mã số: ");
        this.maSo = in.nextLine();
        System.out.print("Nhập Họ Tên: ");
        this.hoTen = in.nextLine();
        System.out.print("Nhập năm sinh: ");
        this.namSinh = in.nextInt();
    }

    @Override
    public String toString() {
        return this.maSo + " - " + this.hoTen + " - " + this.namSinh;
    }
    
}
