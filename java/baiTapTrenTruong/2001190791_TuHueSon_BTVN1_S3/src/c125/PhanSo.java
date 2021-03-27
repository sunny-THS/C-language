/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c125;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class PhanSo {
    Scanner in = new Scanner(System.in);
    protected int tu;
    protected int mau;
    public PhanSo() {
        this.tu = 0;
        this.mau = 1;
    }

    public PhanSo(int tu, int mau) {
        this.tu = tu;
        this.mau = mau;
    }
    
    public PhanSo(PhanSo ps) {
        this.tu = ps.tu;
        this.mau = ps.mau;
    }
    
    public void nhapPS() {
        do {
            System.out.print("Nhập tử: ");
            this.tu = in.nextInt();
            System.out.print("Nhập mẫu: ");
            this.mau = in.nextInt();
            if (this.mau == 0)
                System.out.println("\nMời bạn nhập lại!\n");
        } while (this.mau==0);
    }
    
    public void hienThi() {
        this.rutGon();
        if (this.tu==0)
            System.out.println(0);
        else if (this.mau==1)
            System.out.println(this.tu);
        else
            System.out.printf("%d/%d\n", this.mau<0?-this.tu:this.tu, Math.abs(this.mau));
    }
    
    public void nghichDao() {
        int t = this.tu;
        this.tu = this.mau;
        this.mau = t;
    }
    
    public PhanSo giaTriNghichDao() {
        PhanSo ps = new PhanSo(this);
        ps.nghichDao();
        return ps;
    }
    
    public float ketQua() {
        try {
            float res = (float) this.tu/this.mau;
            return res;
        } catch(Exception e) {
            System.out.println("Error: Mẫu số bằng 0!");
        }
        return -1;
    }
    
    public boolean lonHon(PhanSo ps) {
        float ps1 = (float)  this.tu/this.mau;
        float ps2 = (float)  ps.tu/ps.mau;
        return ps1>ps2;
    }
    
    public int nhanTuChung() {
        int x = this.tu;
        int y = this. mau;
        if (x == 0 || y == 0) {
            return x+y;
          }
        while (x != y) {
            if (x < y) {
                y-=x;
            }else {
                x-=y;
            }
        }
        return x;
    }
    
    public void rutGon() {
        int ntc = this.nhanTuChung();
        this.tu /= ntc;
        this.mau /= ntc;
    }
    
    public PhanSo cong(PhanSo ps) {
        PhanSo res = new PhanSo();
        res.tu = this.tu*ps.mau + this.mau*ps.tu;
        //      ---------------------------------
        res.mau =       this.mau*ps.mau;
        return res;
    }
    public PhanSo cong(int a) {
        PhanSo res = new PhanSo();
        res.tu = this.tu*1 + this.mau*a;
        //     --------------------------
        res.mau =     this.mau*1;
        return res;
    }
    
    public PhanSo tru(PhanSo ps) {
        PhanSo res = new PhanSo();
        res.tu = this.tu*ps.mau - this.mau*ps.tu;
        //      ---------------------------------
        res.mau =       this.mau*ps.mau;
        return res;
    }
    public PhanSo tru(int a) {
        PhanSo res = new PhanSo();
        res.tu = this.tu*1 - this.mau*a;
        //     --------------------------
        res.mau =     this.mau*1;
        return res;
    }
    
    public PhanSo nhan(PhanSo ps) {
        PhanSo res = new PhanSo();
        res.tu =   this.tu*ps.tu;
        //      -------------------
        res.mau = this.mau*ps.mau;
        return res;
    }
    public PhanSo nhan(int a) {
        PhanSo res = new PhanSo();
        res.tu =  this.tu*a;
        //     ----------------
        res.mau = this.mau;
        return res;
    }
    
    public PhanSo chia(PhanSo ps) {
        PhanSo res = new PhanSo();
        res.tu =   this.tu*ps.mau;
        //      -------------------
        res.mau = this.mau*ps.tu;
        return res;
    }
    public PhanSo chia(int a) {
        PhanSo res = new PhanSo();
        res.tu =    this.tu;
        //     ----------------
        res.mau =  this.mau*a;
        return res;
    }

    /**
     * @return the tu
     */
    public int getTu() {
        return tu;
    }

    /**
     * @param tu the tu to set
     */
    public void setTu(int tu) {
        this.tu = tu;
    }

    /**
     * @return the mau
     */
    public int getMau() {
        return mau;
    }

    /**
     * @param mau the mau to set
     */
    public void setMau(int mau) {
        this.mau = mau;
    }
    
}
