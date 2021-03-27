/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c130;

/**
 *
 * @author Admin
 */
public class MLyThuyet extends MonHoc {
    private float dTL, dGK, dCK;

    public MLyThuyet() {
    }

    public MLyThuyet(float dTL, float dGK, float dCK) {
        this.dTL = dTL;
        this.dGK = dGK;
        this.dCK = dCK;
    }

    public MLyThuyet(float dTL, float dGK, float dCK, String maMH, String tenMH, int soTC) {
        super(maMH, tenMH, soTC);
        this.dTL = dTL;
        this.dGK = dGK;
        this.dCK = dCK;
    }
    
    @Override
    public void nhap() {
        super.nhap();
        System.out.print("Nhập điểm tiểu luận: ");
        this.dTL = MonHoc.in.nextFloat();
        System.out.print("Nhập điểm giữa kì: ");
        this.dGK = MonHoc.in.nextFloat();
        System.out.print("Nhập điểm cuối kì: ");
        this.dCK = MonHoc.in.nextFloat();
    }
    
    @Override
    public void xuat() {
        super.xuat();
        System.out.printf("Điểm tiểu luận: %.2f\n", this.dTL);
        System.out.printf("Điểm giữa kì: %.2f\n", this.dGK);
        System.out.printf("Điểm cuối kì: %.2f\n", this.dCK);
        System.out.printf("Điểm trung bình: %.2f\n", this.tinhDTB());
    }
    
    @Override
    public float tinhDTB() {
        return (float) (super.tinhDTB() + this.dTL*0.2 + this.dGK*0.3 + this.dCK*0.5);
    }
    
    public float getdTL() {
        return dTL;
    }

    /**
     * @param dTL the dTL to set
     */
    public void setdTL(float dTL) {
        this.dTL = dTL;
    }

    /**
     * @return the dGK
     */
    public float getdGK() {
        return dGK;
    }

    /**
     * @param dGK the dGK to set
     */
    public void setdGK(float dGK) {
        this.dGK = dGK;
    }

    /**
     * @return the dCK
     */
    public float getdCK() {
        return dCK;
    }

    /**
     * @param dCK the dCK to set
     */
    public void setdCK(float dCK) {
        this.dCK = dCK;
    }
    
}
