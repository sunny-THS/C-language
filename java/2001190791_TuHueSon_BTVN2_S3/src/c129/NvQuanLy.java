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
public class NvQuanLy extends NhanVien {

    /**
     * @return the hscv
     */
    public float getHscv() {
        return hscv;
    }

    /**
     * @param hscv the hscv to set
     */
    public void setHscv(float hscv) {
        this.hscv = hscv;
    }

    /**
     * @return the thuong
     */
    public double getThuong() {
        return thuong;
    }

    /**
     * @param thuong the thuong to set
     */
    public void setThuong(double thuong) {
        this.thuong = thuong;
    }
    private float hscv;
    private double thuong;

    public NvQuanLy() {
    }
    
    public NvQuanLy(String hoTen, int namVaoLam) {
        super(hoTen, namVaoLam);
        this.hscv = 0;
        this.thuong = 0;
    }

    public NvQuanLy(float hscv, double thuong) {
        this.hscv = hscv;
        this.thuong = thuong;
    }

    public NvQuanLy(float hscv, double thuong, String hoTen, int namVaoLam) {
        super(hoTen, namVaoLam);
        this.hscv = hscv;
        this.thuong = thuong;
    }
    
    @Override
    public void nhap() {
        super.nhap();
        System.out.print("Nhập hệ số chức vụ: ");
        this.hscv = NhanVien.in.nextFloat();
        System.out.print("Nhập tiền thưởng: ");
        this.thuong = NhanVien.in.nextDouble();
    }
    
    @Override
    public void xuat() {
        super.xuat();
        System.out.printf("Hệ số chức vụ: %f\nTrợ cấp: %f\n", this.hscv, this.thuong);
        System.out.printf("Tổng lương: %.2f\n", this.tinhLuong());
        System.out.println("\n");
    }
    
    @Override
    public double tinhLuong() {
        return super.tinhLuong()*this.hscv+this.thuong;
    }
}
