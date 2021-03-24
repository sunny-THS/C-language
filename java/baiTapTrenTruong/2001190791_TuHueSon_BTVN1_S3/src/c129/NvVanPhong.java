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
public class NvVanPhong extends NhanVien {

    /**
     * @return the soNgayLV
     */
    public int getSoNgayLV() {
        return soNgayLV;
    }

    /**
     * @param soNgayLV the soNgayLV to set
     */
    public void setSoNgayLV(int soNgayLV) {
        this.soNgayLV = soNgayLV;
    }

    /**
     * @return the troCap
     */
    public double getTroCap() {
        return troCap;
    }

    /**
     * @param troCap the troCap to set
     */
    public void setTroCap(double troCap) {
        this.troCap = troCap;
    }
    private int soNgayLV;
    private double troCap;

    public NvVanPhong() {
    }
    
    public NvVanPhong(String hoTen, int namVaoLam) {
        super(hoTen, namVaoLam);
        this.soNgayLV = 0;
        this.troCap = 0;
    }

    public NvVanPhong(int soNgayLV, double troCap) {
        this.soNgayLV = soNgayLV;
        this.troCap = troCap;
    }

    public NvVanPhong(int soNgayLV, double troCap, String hoTen, int namVaoLam) {
        super(hoTen, namVaoLam);
        this.soNgayLV = soNgayLV;
        this.troCap = troCap;
    }
    
    @Override
    public void nhap() {
        super.nhap();
        System.out.print("Nhập số ngày làm việc: ");
        this.soNgayLV = NhanVien.in.nextInt();
        System.out.print("Nhập trợ cấp: ");
        this.troCap = NhanVien.in.nextDouble();
    }
    
    @Override
    public void xuat() {
        super.xuat();
        System.out.printf("Số ngày làm việc: %d\nTrợ cấp: %f\n", this.soNgayLV, this.troCap);
        System.out.printf("Tổng lương: %.2f\n", this.tinhLuong());
        System.out.println("\n");
    }
    
    @Override
    public double tinhLuong() {
        return super.tinhLuong() + this.getSoNgayLV() * 100000 + this.getTroCap();
    }
}
