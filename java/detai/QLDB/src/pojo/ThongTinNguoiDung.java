/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pojo;

import java.util.Date;

/**
 *
 * @author Admin
 */
public class ThongTinNguoiDung extends DangNhap {
    private String maND, tenND, email;
    private Date ngaySinh;

    public ThongTinNguoiDung() {
    }

    public ThongTinNguoiDung(String maND, String tenND, String email, Date ngaySinh) {
        this.maND = maND;
        this.tenND = tenND;
        this.email = email;
        this.ngaySinh = ngaySinh;
    }

    public ThongTinNguoiDung(String maND, String tenND, String email, Date ngaySinh, String maNDN, String tenDN) {
        super(maNDN, tenDN);
        this.maND = maND;
        this.tenND = tenND;
        this.email = email;
        this.ngaySinh = ngaySinh;
    }

    /**
     * @return the maND
     */
    public String getMaND() {
        return maND;
    }

    /**
     * @param maND the maND to set
     */
    public void setMaND(String maND) {
        this.maND = maND;
    }

    /**
     * @return the tenND
     */
    public String getTenND() {
        return tenND;
    }

    /**
     * @param tenND the tenND to set
     */
    public void setTenND(String tenND) {
        this.tenND = tenND;
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
     * @return the email
     */
    public String getEmail() {
        return email;
    }

    /**
     * @param email the email to set
     */
    public void setEmail(String email) {
        this.email = email;
    }
}
