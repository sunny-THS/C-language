/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pojo;

import java.util.Date;

/**
 *
 * @author pc
 */
public class DanhBa {

    private String sdt, tenLH, ghiChu, Email, malh, madb;
    private NhomLienHe nlh;
    private Date ngayLuu;

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

    /**
     * @return the tenLH
     */
    public String getTenLH() {
        return tenLH;
    }

    /**
     * @param tenLH the tenLH to set
     */
    public void setTenLH(String tenLH) {
        this.tenLH = tenLH;
    }

    /**
     * @return the ghiChu
     */
    public String getGhiChu() {
        return ghiChu;
    }

    /**
     * @param ghiChu the ghiChu to set
     */
    public void setGhiChu(String ghiChu) {
        this.ghiChu = ghiChu;
    }

    /**
     * @return the Email
     */
    public String getEmail() {
        return Email;
    }

    /**
     * @param Email the Email to set
     */
    public void setEmail(String Email) {
        this.Email = Email;
    }

    public DanhBa() {
    }

    public DanhBa(String sdt, String tenLH, String Email, String ghiChu, String malh, Date ngayLuu, String madb) {
        this.sdt = sdt;
        this.tenLH = tenLH;
        this.ghiChu = ghiChu;
        this.Email = Email;
        this.malh = malh;
        this.ngayLuu = ngayLuu;
        this.madb = madb;
    }

    @Override
    public String toString() {
        return this.tenLH; //To change body of generated methods, choose Tools | Templates.
    }

    /**
     * @return the nlh
     */
    public NhomLienHe getNlh() {
        return nlh;
    }

    /**
     * @param nlh the nlh to set
     */
    public void setNlh(NhomLienHe nlh) {
        this.nlh = nlh;
    }

    /**
     * @return the malh
     */
    public String getMalh() {
        return malh;
    }

    /**
     * @param malh the malh to set
     */
    public void setMalh(String malh) {
        this.malh = malh;
    }

    /**
     * @return the ngayLuu
     */
    public Date getNgayLuu() {
        return ngayLuu;
    }

    /**
     * @param ngayLuu the ngayLuu to set
     */
    public void setNgayLuu(Date ngayLuu) {
        this.ngayLuu = ngayLuu;
    }

    /**
     * @return the madb
     */
    public String getMadb() {
        return madb;
    }

    /**
     * @param madb the madb to set
     */
    public void setMadb(String madb) {
        this.madb = madb;
    }

}
