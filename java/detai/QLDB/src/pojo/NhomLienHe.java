/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pojo;

import java.util.Vector;

/**
 *
 * @author pc
 */
public class NhomLienHe {

    private String msNhom, tenNhom;
    private Vector<DanhBa> lstDanhBa = new Vector<>();

    /**
     * @return the msNhom
     */
    public String getMsNhom() {
        return msNhom;
    }

    /**
     * @param msNhom the msNhom to set
     */
    public void setMsNhom(String msNhom) {
        this.msNhom = msNhom;
    }

    /**
     * @return the tenNhom
     */
    public String getTenNhom() {
        return tenNhom;
    }

    /**
     * @param tenNhom the tenNhom to set
     */
    public void setTenNhom(String tenNhom) {
        this.tenNhom = tenNhom;
    }

    public NhomLienHe() {
    }

    public NhomLienHe(String msNhom, String tenNhom) {
        this.msNhom = msNhom;
        this.tenNhom = tenNhom;
    }

    @Override
    public String toString() {
        return this.tenNhom; //To change body of generated methods, choose Tools | Templates.
    }

    /**
     * @return the lstDanhBa
     */
    public Vector<DanhBa> getLstDanhBa() {
        return lstDanhBa;
    }

    /**
     * @param lstDanhBa the lstDanhBa to set
     */
    public void setLstDanhBa(Vector<DanhBa> lstDanhBa) {
        this.lstDanhBa = lstDanhBa;
    }

    public void themDanhBa(DanhBa db) {
        lstDanhBa.add(db);
        db.setNlh(this);
    }
}
