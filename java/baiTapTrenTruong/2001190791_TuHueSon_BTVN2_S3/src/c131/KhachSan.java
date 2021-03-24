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
public class KhachSan extends BatDongSan implements PhiKD{

    /**
     * @return the soSao
     */
    public int getSoSao() {
        return soSao;
    }

    /**
     * @param soSao the soSao to set
     */
    public void setSoSao(int soSao) {
        this.soSao = soSao;
    }
    private int soSao;

    public KhachSan() {
    }
    
    public KhachSan(int soSao) {
        this.soSao = soSao;
    }

    public KhachSan(int soSao, String maSo, int chieuDai, int chieuRong) {
        super(maSo, chieuDai, chieuRong);
        this.soSao = soSao;
    }
    
    @Override
    public void nhap() {
        super.nhap();
        System.out.print("Nhập số sao: ");
        this.soSao = BatDongSan.in.nextInt();
    }
    
    @Override
    public void xuat() {
        super.xuat();
        System.out.printf("Số lâu: %d\n", this.soSao);
        System.out.printf("Giá bán: %.2f\n", this.tinhGiaTri());
        System.out.println();
    }
    
    @Override
    public float tinhGiaTri() {
        return 100000 + this.soSao*50000 + this.tinhPhiKD();
    }

    @Override
    public float tinhPhiKD() {
        return super.chieuRong*5000;
    }
}
