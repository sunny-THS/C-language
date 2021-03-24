/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c123;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class Mang2C {
    Scanner in = new Scanner(System.in);

    /**
     * @return the arr
     */
    public int[][] getArr() {
        return arr;
    }

    /**
     * @param arr the arr to set
     */
    public void setArr(int[][] arr) {
        this.arr = arr;
    }

    /**
     * @return the m
     */
    public int getM() {
        return m;
    }

    /**
     * @param m the m to set
     */
    public void setM(int m) {
        this.m = m;
    }

    /**
     * @return the n
     */
    public int getN() {
        return n;
    }

    /**
     * @param n the n to set
     */
    public void setN(int n) {
        this.n = n;
    }
    private int[][] arr;
    private int m, n;
    Mang2C() { }
    
    public void nhapMN() {
        System.out.print("Nhap m: ");
        this.m = in.nextInt();
        System.out.print("Nhap n: ");
        this.n = in.nextInt();
        this.arr = new int[m][n];
    }
    public void nhapBP() {
        for (int i = 0; i < this.m; i++) {
            for (int j = 0; j < this.n; j++) {
                System.out.printf("arr[%d][%d] = ", i, j);
                this.arr[i][j] = in.nextInt();
            }
        }
    }
    public void nhapRandom() {
        for (int i = 0; i < this.m; i++) {
            for (int j = 0; j < this.n; j++) {
                this.arr[i][j] = (int) (-99+Math.random()*(99+1+99));
                System.out.printf("arr[%d][%d] = %4d\n", i, j, arr[i][j]);
            }
        }
    }
    public void xuat() {
        for (int i = 0; i < this.m; i++) {
            for (int j = 0; j < this.n; j++) {
                System.out.printf("%4d", arr[i][j]);
            }
        }
    }
    public int tinhTongGtriLe() {
        int res = 0;
        for (int i = 0; i < this.m; i++)
            for (int j = 0; j < this.n; j++)
               if (arr[i][j]%2!=0) res+=arr[i][j];
        return res;
    }
    public int tinhTongGtriDuong(int k) {
        int res = 0;
        for (int j = 0; j < this.n; j++)
           if (arr[k][j]>0) res+=arr[k][j];
        return res;
    }
    public int demSLDuong() {
        int d = 0;
        for (int i = 0; i < this.m; i++)
            for (int j = 0; j < this.n; j++)
               if (arr[i][j]>=0) d++;
        return d;
    }
    public boolean kTraSNT(int a) {
        if (a<2) return false;
        for (int i=2; i<=Math.sqrt(a); i++)
            if (a%i==0) return false;
        return true;
    }
    public int demSlSNTTren1d(int r) {
        int d = 0;
        for (int j = 0; j < this.n; j++)
           if (kTraSNT(arr[r][j])) d++;
        return d;
    }
    public boolean kTraTTSoAm() {
        for (int i = 0; i < this.m; i++)
            for (int j = 0; j < this.n; j++)
               if (arr[i][j]<0) return true;
        return false;
    }
    public boolean kTraTang(int k) {
        for (int j = 0; j < this.n-1; j++)
           if (arr[k][j]>arr[k][j+1]) return false;
        return true;
    }
    public void lietKeDongSNT() {
        System.out.print("Dòng thứ:");
        for (int i = 0; i < this.m; i++)
            for (int j = 0; j < this.n; j++)
               if (kTraSNT(arr[i][j])) {
                   System.out.printf("%3d", i);
                   break;
               }
    }
    public void lietKeDongTGtriChan() {
        System.out.print("Dòng thứ:");
        for (int i = 0; i < this.m; i++)
            for (int j = 0; j < this.n; j++) {
                if (arr[i][j]%2!=0)
                   break;
                System.out.printf("%3d", i);
            }
    }
}
