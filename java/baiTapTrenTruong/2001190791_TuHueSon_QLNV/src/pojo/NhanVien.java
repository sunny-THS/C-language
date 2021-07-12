/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pojo;

import java.sql.Date;

/**
 *
 * @author Admin
 */
public class NhanVien {
    private int maNV, phong;
    private String hoTen, phai;
    private Date ngaySinh;
    private float luong;
    private boolean trangThai;

    public NhanVien() {
    }

    public NhanVien(int maNV, int phong, String hoTen, String phai, Date ngaySinh, float luong, boolean trangThai) {
        this.maNV = maNV;
        this.phong = phong;
        this.hoTen = hoTen;
        this.phai = phai;
        this.ngaySinh = ngaySinh;
        this.luong = luong;
        this.trangThai = trangThai;
    }

    /**
     * @return the maNV
     */
    public int getMaNV() {
        return maNV;
    }

    /**
     * @param maNV the maNV to set
     */
    public void setMaNV(int maNV) {
        this.maNV = maNV;
    }

    /**
     * @return the phong
     */
    public int getPhong() {
        return phong;
    }

    /**
     * @param phong the phong to set
     */
    public void setPhong(int phong) {
        this.phong = phong;
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
     * @return the phai
     */
    public String getPhai() {
        return phai;
    }

    /**
     * @param phai the phai to set
     */
    public void setPhai(String phai) {
        this.phai = phai;
    }

    /**
     * @return the ngaySinh
     */
    public Date getNgaySinh() {
        return ngaySinh;
    }

    /**
     * @param ngaySinh the ngaySinh to set
     */
    public void setNgaySinh(Date ngaySinh) {
        this.ngaySinh = ngaySinh;
    }

    /**
     * @return the luong
     */
    public float getLuong() {
        return luong;
    }

    /**
     * @param luong the luong to set
     */
    public void setLuong(float luong) {
        this.luong = luong;
    }

    /**
     * @return the trangThai
     */
    public boolean isTrangThai() {
        return trangThai;
    }

    /**
     * @param trangThai the trangThai to set
     */
    public void setTrangThai(boolean trangThai) {
        this.trangThai = trangThai;
    }
    
}
