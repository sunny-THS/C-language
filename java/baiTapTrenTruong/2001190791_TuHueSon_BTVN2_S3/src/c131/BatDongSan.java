/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c131;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class BatDongSan {
    public static Scanner in = new Scanner(System.in);

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
     * @return the chieuDai
     */
    public int getChieuDai() {
        return chieuDai;
    }

    /**
     * @param chieuDai the chieuDai to set
     */
    public void setChieuDai(int chieuDai) {
        this.chieuDai = chieuDai;
    }

    /**
     * @return the chieuRong
     */
    public int getChieuRong() {
        return chieuRong;
    }

    /**
     * @param chieuRong the chieuRong to set
     */
    public void setChieuRong(int chieuRong) {
        this.chieuRong = chieuRong;
    }
    protected String maSo;
    protected int chieuDai, chieuRong;

    public BatDongSan() {
    }

    public BatDongSan(String maSo, int chieuDai, int chieuRong) {
        this.maSo = maSo;
        this.chieuDai = chieuDai;
        this.chieuRong = chieuRong;
    }
    
    public void nhap() {
        in.nextLine();
        System.out.print("\nNhập mã số: ");
        this.maSo = in.nextLine();
        System.out.print("Nhập chiều dài: ");
        this.chieuDai = in.nextInt();
        System.out.print("Nhập chiều rộng: ");
        this.chieuRong = in.nextInt();
    }
    
    public void xuat() {
        System.out.printf("Mã số: %s\nChiều dài: %d\nChiều rộng: %d\n", this.maSo, this.chieuDai, this.chieuRong);
    }
    
    public float tinhGiaTri() {
        return (float) this.chieuDai*this.chieuRong;
    }
}
