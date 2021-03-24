/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c129;

/**
 *
 * @author Admin
 */
public class NvSanXuat extends NhanVien {
    private int soSP;
    public NvSanXuat() {
    }
    public NvSanXuat(String hoTen, int namVaoLam) {
        super(hoTen, namVaoLam);
        this.soSP = 0;
    }

    public NvSanXuat(int soSP) {
        this.soSP = soSP;
    }

    public NvSanXuat(int soSP, String hoTen, int namVaoLam) {
        super(hoTen, namVaoLam);
        this.soSP = soSP;
    }
    
    @Override
    public void nhap() {
        super.nhap();
        System.out.print("Nhập số sản phẩm: ");
        this.soSP = NhanVien.in.nextInt();
    }
    
    @Override
    public void xuat() {
        super.xuat();
        System.out.printf("Số sản phẩm: %d\n", this.soSP);
        System.out.printf("Tổng lương: %.2f\n", this.tinhLuong());
        System.out.println("\n");
    }

    
    
    @Override
    public double tinhLuong() {
        return super.tinhLuong() + this.soSP * 2000;
    }
    /**
     * @return the soSP
     */
    public int getSoSP() {
        return soSP;
    }

    /**
     * @param soSP the soSP to set
     */
    public void setSoSP(int soSP) {
        this.soSP = soSP;
    }
}
