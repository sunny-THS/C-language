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
public class DangNhap {
    protected String maNDN, tenDN;

    /**
     * @return the maNDN
     */
    public String getMaNDN() {
        return maNDN;
    }

    /**
     * @param maNDN the maNDN to set
     */
    public void setMaNDN(String maNDN) {
        this.maNDN = maNDN;
    }

    /**
     * @return the tenDN
     */
    public String getTenDN() {
        return tenDN;
    }

    /**
     * @param tenDN the tenDN to set
     */
    public void setTenDN(String tenDN) {
        this.tenDN = tenDN;
    }

    public DangNhap() {
    }

    public DangNhap(String maNDN, String tenDN) {
        this.maNDN = maNDN;
        this.tenDN = tenDN;
    }
    
}
