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
public class PhongBan {
    private int maPh;
    private String tenPh;

    public PhongBan() {
    }

    public PhongBan(int maPh, String tenPh) {
        this.maPh = maPh;
        this.tenPh = tenPh;
    }
    

    /**
     * @return the maPh
     */
    public int getMaPh() {
        return maPh;
    }

    /**
     * @param maPh the maPh to set
     */
    public void setMaPh(int maPh) {
        this.maPh = maPh;
    }

    /**
     * @return the tenPh
     */
    public String getTenPh() {
        return tenPh;
    }

    /**
     * @param tenPh the tenPh to set
     */
    public void setTenPh(String tenPh) {
        this.tenPh = tenPh;
    }
}
