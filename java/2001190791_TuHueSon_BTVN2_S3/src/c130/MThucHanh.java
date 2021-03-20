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
public class MThucHanh extends MonHoc {

    /**
     * @return the cot1
     */
    public float getCot1() {
        return cot1;
    }

    /**
     * @param cot1 the cot1 to set
     */
    public void setCot1(float cot1) {
        this.cot1 = cot1;
    }

    /**
     * @return the cot2
     */
    public float getCot2() {
        return cot2;
    }

    /**
     * @param cot2 the cot2 to set
     */
    public void setCot2(float cot2) {
        this.cot2 = cot2;
    }

    /**
     * @return the cot3
     */
    public float getCot3() {
        return cot3;
    }

    /**
     * @param cot3 the cot3 to set
     */
    public void setCot3(float cot3) {
        this.cot3 = cot3;
    }

    /**
     * @return the cot4
     */
    public float getCot4() {
        return cot4;
    }

    /**
     * @param cot4 the cot4 to set
     */
    public void setCot4(float cot4) {
        this.cot4 = cot4;
    }
    private float cot1, cot2, cot3, cot4;

    public MThucHanh() {
    }

    public MThucHanh(float cot1, float cot2, float cot3, float cot4) {
        this.cot1 = cot1;
        this.cot2 = cot2;
        this.cot3 = cot3;
        this.cot4 = cot4;
    }

    public MThucHanh(float cot1, float cot2, float cot3, float cot4, String maMH, String tenMH, int soTC) {
        super(maMH, tenMH, soTC);
        this.cot1 = cot1;
        this.cot2 = cot2;
        this.cot3 = cot3;
        this.cot4 = cot4;
    }
    @Override
    public void nhap() {
        super.nhap();
        System.out.print("Nhập điểm cột 1: ");
        this.cot1 = MonHoc.in.nextFloat();
        System.out.print("Nhập điểm cột 2: ");
        this.cot2 = MonHoc.in.nextFloat();
        System.out.print("Nhập điểm cột 3: ");
        this.cot3 = MonHoc.in.nextFloat();
        System.out.print("Nhập điểm cột 4: ");
        this.cot4 = MonHoc.in.nextFloat();
    }
    
    @Override
    public void xuat() {
        super.xuat();
        System.out.printf("Điểm cột 1: %.2f\n", this.cot1);
        System.out.printf("Điểm cột 2: %.2f\n", this.cot2);
        System.out.printf("Điểm cột 3: %.2f\n", this.cot3);
        System.out.printf("Điểm cột 4: %.2f\n", this.cot4);
        System.out.printf("Điểm trung bình: %.2f\n", this.tinhDTB());
    }
    
    @Override
    public float tinhDTB() {
        return (float) (super.tinhDTB() + (this.cot1+this.cot2+this.cot3+this.cot4)/4);
    }
}
