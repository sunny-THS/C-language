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
public class LoaiSach {
    private String strTen, strMoTa;
    private int iMa;

    public LoaiSach() {
    }

    public LoaiSach(String strTen, String strMoTa, int iMa) {
        this.strTen = strTen;
        this.strMoTa = strMoTa;
        this.iMa = iMa;
    }

    /**
     * @return the strTen
     */
    public String getStrTen() {
        return strTen;
    }

    /**
     * @param strTen the strTen to set
     */
    public void setStrTen(String strTen) {
        this.strTen = strTen;
    }

    /**
     * @return the strMoTa
     */
    public String getStrMoTa() {
        return strMoTa;
    }

    /**
     * @param strMoTa the strMoTa to set
     */
    public void setStrMoTa(String strMoTa) {
        this.strMoTa = strMoTa;
    }

    /**
     * @return the iMa
     */
    public int getiMa() {
        return iMa;
    }

    /**
     * @param iMa the iMa to set
     */
    public void setiMa(int iMa) {
        this.iMa = iMa;
    }
    
}
