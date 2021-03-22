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
public class MDoAn extends MonHoc {

    /**
     * @return the dGVHD
     */
    public float getdGVHD() {
        return dGVHD;
    }

    /**
     * @param dGVHD the dGVHD to set
     */
    public void setdGVHD(float dGVHD) {
        this.dGVHD = dGVHD;
    }

    /**
     * @return the dGVPB
     */
    public float getdGVPB() {
        return dGVPB;
    }

    /**
     * @param dGVPB the dGVPB to set
     */
    public void setdGVPB(float dGVPB) {
        this.dGVPB = dGVPB;
    }
    private float dGVHD, dGVPB;

    public MDoAn() {
    }

    public MDoAn(float dGVHD, float dGVPB) {
        this.dGVHD = dGVHD;
        this.dGVPB = dGVPB;
    }

    public MDoAn(float dGVHD, float dGVPB, String maMH, String tenMH, int soTC) {
        super(maMH, tenMH, soTC);
        this.dGVHD = dGVHD;
        this.dGVPB = dGVPB;
    }
    @Override
    public void nhap() {
        super.nhap();
        System.out.print("Nhập điểm giáo viên hướng dẫn: ");
        this.dGVHD = MonHoc.in.nextFloat();
        System.out.print("Nhập điểm giáo viên phản biện: ");
        this.dGVPB = MonHoc.in.nextFloat();
    }
    
    @Override
    public void xuat() {
        super.xuat();
        System.out.printf("Điểm giáo viên hướng dẫn: %.2f\n", this.dGVHD);
        System.out.printf("Điểm giáo viên phản biện: %.2f\n", this.dGVPB);
        System.out.printf("Điểm trung bình: %.2f\n", this.tinhDTB());
    }
    
    @Override
    public float tinhDTB() {
        return (float) (super.tinhDTB() + (this.dGVHD+this.dGVPB)/2);
    }
}
