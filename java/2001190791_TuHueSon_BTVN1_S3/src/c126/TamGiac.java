/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c126;

import c124.Diem2D;

/**
 *
 * @author Admin
 */
public class TamGiac {
    protected Diem2D a;
    protected Diem2D b;
    protected Diem2D c;

    public TamGiac() {
        this.a = new Diem2D();
        this.b = new Diem2D();
        this.c = new Diem2D();

    }
    
    public TamGiac(Diem2D a, Diem2D b, Diem2D c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    
    public TamGiac(TamGiac tg) {
        this.a = tg.a;
        this.b = tg.b;
        this.c = tg.c;
    }
    
    public void nhap() {
        System.out.println("Nhap điểm a:");
        this.a.nhapDiem();
        System.out.println("Nhap điểm b:");
        this.b.nhapDiem();
        System.out.println("Nhap điểm c:");
        this.c.nhapDiem();
    }
    public void xuat() {
        System.out.print("Toạ độ điểm A: ");
        this.a.hienThi();
        System.out.print("Toạ độ điểm B: ");
        this.b.hienThi();
        System.out.print("Toạ độ điểm C: ");
        this.c.hienThi();
    }
    
    public float khoangCachA() {
        return this.a.khoangCach(b);
    }
    public float khoangCachB() {
        return this.b.khoangCach(c);
    }
    public float khoangCachC() {
        return this.c.khoangCach(a);
    }
    
    public float chuVi() {
        return this.khoangCachA() + this.khoangCachB() + this.khoangCachC();
    }
    
    public float dienTich() {
        float p = this.chuVi()/2;
        return (float) Math.sqrt( p * (p-this.khoangCachA()) * (p-this.khoangCachB()) * (p-this.khoangCachC()) );
    }
    
    /**
     * @return the a
     */
    public Diem2D getA() {
        return a;
    }

    /**
     * @param a the a to set
     */
    public void setA(Diem2D a) {
        this.a = a;
    }

    /**
     * @return the b
     */
    public Diem2D getB() {
        return b;
    }

    /**
     * @param b the b to set
     */
    public void setB(Diem2D b) {
        this.b = b;
    }

    /**
     * @return the c
     */
    public Diem2D getC() {
        return c;
    }

    /**
     * @param c the c to set
     */
    public void setC(Diem2D c) {
        this.c = c;
    }
}
