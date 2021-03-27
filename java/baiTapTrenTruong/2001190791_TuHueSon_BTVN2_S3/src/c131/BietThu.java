/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c131;

/**
 *
 * @author Admin
 */
public class BietThu extends BatDongSan implements PhiKD {

    public BietThu() {
    }

    public BietThu(String maSo, int chieuDai, int chieuRong) {
        super(maSo, chieuDai, chieuRong);
    }

    @Override
    public void nhap() {
        super.nhap();
    }
    
    @Override
    public void xuat() {
        super.xuat();
        System.out.printf("Giá bán: %.2f\n", this.tinhGiaTri());
        System.out.println();
    }
    
    @Override
    public float tinhGiaTri() {
        return super.tinhGiaTri()*400000 + this.tinhPhiKD();
    }

    @Override
    public float tinhPhiKD() {
        return super.tinhGiaTri()*1000;
    }
    
}
