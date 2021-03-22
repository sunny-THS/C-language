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
public class NhaO extends BatDongSan {

    /**
     * @return the soLau
     */
    public int getSoLau() {
        return soLau;
    }

    /**
     * @param soLau the soLau to set
     */
    public void setSoLau(int soLau) {
        this.soLau = soLau;
    }
    private int soLau;

    public NhaO() {
    }

    public NhaO(String maSo, int chieuDai, int chieuRong) {
        super(maSo, chieuDai, chieuRong);
    }
    
    @Override
    public void nhap() {
        super.nhap();
        System.out.print("Nhập số lâu: ");
        this.soLau = BatDongSan.in.nextInt();
    }
    
    @Override
    public void xuat() {
        super.xuat();
        System.out.printf("Số lâu: %d\n", this.soLau);
        System.out.printf("Giá bán: %.2f\n", this.tinhGiaTri());
        System.out.println();
    }
    
    @Override
    public float tinhGiaTri() {
        return super.tinhGiaTri()*10000 + this.soLau*100000;
    }
}
