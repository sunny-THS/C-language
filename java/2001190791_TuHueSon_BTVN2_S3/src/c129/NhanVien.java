/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c129;

import java.time.Year;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class NhanVien {
    public static Scanner in = new Scanner(System.in);
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
     * @return the namVaoLam
     */
    public int getNamVaoLam() {
        return namVaoLam;
    }

    /**
     * @param namVaoLam the namVaoLam to set
     */
    public void setNamVaoLam(int namVaoLam) {
        this.namVaoLam = namVaoLam;
    }

    /**
     * @return the Luong
     */
    public double getLuong() {
        return Luong;
    }

    /**
     * @param Luong the Luong to set
     */
    public void setLuong(double Luong) {
        this.Luong = Luong;
    }

    /**
     * @return the LCB
     */
    public static int getLCB() {
        return LCB;
    }

    /**
     * @param aLCB the LCB to set
     */
    public static void setLCB(int aLCB) {
        LCB = aLCB;
    }
    protected String hoTen;
    protected int namVaoLam;
    protected double Luong;
    protected static int LCB = 1490000;
    public NhanVien() {
        this.hoTen = "";
        this.namVaoLam = Year.now().getValue();
        this.Luong = 0;
    }

    public NhanVien(String hoTen, int namVaoLam) {
        this.hoTen = hoTen;
        this.namVaoLam = namVaoLam;
    }
    
    public void nhap() {
        in.nextLine();
        System.out.print("Nhập họ tên: ");
        this.hoTen = in.nextLine();
        System.out.print("Năm vào làm: ");
        this.namVaoLam = in.nextInt();
    }
    
    public void xuat() {
        System.out.printf("Họ tên: %s\nNăm vào làm: %d\n", this.hoTen, this.namVaoLam);
    }
    
    public double tinhLuong() {
        return NhanVien.LCB;
    }
    
}
