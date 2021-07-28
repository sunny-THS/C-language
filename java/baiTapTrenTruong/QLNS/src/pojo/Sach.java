/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pojo;

/**
 *
 * @author Admin
 */
public class Sach {
    private String tieuDe, tacGia, moTa, theLoai;
    private int namXB, ma;


    public Sach() {
    }

    public Sach(String tieuDe, String tacGia, String moTa, int namXB, String theLoai, int ma) {
        this.tieuDe = tieuDe;
        this.tacGia = tacGia;
        this.moTa = moTa;
        this.namXB = namXB;
        this.theLoai = theLoai;
        this.ma = ma;
    }

    /**
     * @return the tieuDe
     */
    public String getTieuDe() {
        return tieuDe;
    }

    /**
     * @param tieuDe the tieuDe to set
     */
    public void setTieuDe(String tieuDe) {
        this.tieuDe = tieuDe;
    }

    /**
     * @return the tacGia
     */
    public String getTacGia() {
        return tacGia;
    }

    /**
     * @param tacGia the tacGia to set
     */
    public void setTacGia(String tacGia) {
        this.tacGia = tacGia;
    }

    /**
     * @return the moTa
     */
    public String getMoTa() {
        return moTa;
    }

    /**
     * @param moTa the moTa to set
     */
    public void setMoTa(String moTa) {
        this.moTa = moTa;
    }

    /**
     * @return the namXB
     */
    public int getNamXB() {
        return namXB;
    }

    /**
     * @param namXB the namXB to set
     */
    public void setNamXB(int namXB) {
        this.namXB = namXB;
    }

    /**
     * @return the theLoai
     */
    public String getTheLoai() {
        return theLoai;
    }

    /**
     * @param theLoai the theLoai to set
     */
    public void setTheLoai(String theLoai) {
        this.theLoai = theLoai;
    }

    /**
     * @return the ma
     */
    public int getMa() {
        return ma;
    }

    /**
     * @param ma the ma to set
     */
    public void setMa(int ma) {
        this.ma = ma;
    }

   
}
