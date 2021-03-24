/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package qldb;

import java.io.Serializable;
import java.util.Scanner;

/**
 *
 * @author A102PC32
 */
public class DanhBa implements Serializable{

    /**
     * @return the ten
     */
    public String getTen() {
        return ten;
    }

    /**
     * @param ten the ten to set
     */
    public void setTen(String ten) {
        this.ten = ten;
    }

    /**
     * @return the sdt
     */
    public String getSdt() {
        return sdt;
    }

    /**
     * @param sdt the sdt to set
     */
    public void setSdt(String sdt) {
        this.sdt = sdt;
    }
    private String ten, sdt;

    public DanhBa() {
    }

    public DanhBa(String ten, String sdt) {
        this.ten = ten;
        this.sdt = sdt;
    }
    public void nhapThongTin() {
        Scanner in = new Scanner(System.in); 
        System.out.print("Nhập tên: ");
        this.ten = in.nextLine();
        System.out.print("Nhập số điện thoại: ");
        this.sdt = in.nextLine();
    }

    @Override
    public String toString() {
        return this.ten + " - " + this.sdt;
    }
    
}
