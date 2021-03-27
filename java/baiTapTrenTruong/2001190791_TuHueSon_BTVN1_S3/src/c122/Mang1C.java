/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c122;

import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class Mang1C {
    Scanner in = new Scanner(System.in);
    private int[] arr;
    private int n;
    Mang1C() { }
    public void nhapN() {
        do {
            System.out.print("Nhập n: ");
            setN(in.nextInt());
        } while (getN()<=0 || getN()>500);
        arr = new int[n];
    }
    public void nhapBP() {
        // nhập giá trị từ bàn phím
        for(int i=0; i<getN(); i++) {
            System.out.printf("arr[%d]= ", i);
            getArr()[i] = in.nextInt();
        }
    }
    public void nhapRandom() {
        // nhập giá trị random
        for(int i=0; i<getN(); i++) {
            getArr()[i] = (int) (-199+Math.random()*(199+1+199));
            System.out.printf("arr[%d]= %d\n", i, getArr()[i]);
        }
    }
    public void xuat() {
        for (int i : arr) {
            System.out.printf("%-5d", i);
        }
    }
    public void xuat(int i) {
        System.out.printf("%-5d", i);
    }
    
    public boolean kTraGtriAm(int a) {
        if (a>=0) return false;
        return true;
    }
    
    public boolean kTraSNT(int a) {
        if (a<2) return false;
        for (int i=2; i<=Math.sqrt(a); i++)         
            if (a%i==0) return false;
        return true;
    }
    
    public void lietKeSoAm() {
        for (int i=0; i<arr.length; i++) 
            if (kTraGtriAm(arr[i]))
                xuat(arr[i]);
    }
    
    public void lietKeSNT() {
        for (int i=0; i<arr.length; i++) 
            if (kTraSNT(arr[i]))
                xuat(arr[i]);
    }
    
    public void lietKeTKhoang(int a, int b) {
        for (int i=0; i<arr.length; i++) 
            if (arr[i]>=a && arr[i]<=b)
                xuat(arr[i]);
    }
    
    public int tinhTongSNT() {
        int s=0;
        for (int i=0; i<arr.length; i++) 
            if (kTraSNT(arr[i]))
                s += arr[i];
        return s;
    }
    
    public float tinhTBCDuong() {
        int s=0;
        int d=0;
        for (int i=0; i<arr.length; i++) 
            if (!kTraGtriAm(arr[i])) {
                d++;
                s += arr[i];
            }
        return s/d;
    }
    
    public int demSoPtLonHon(int x) {
        int d=0;
        for (int i=0; i<arr.length; i++) 
            if (arr[i]>x) {
                d++;
            }
        return d;
    }
    
    public int demSNT() {
        int d=0;
        for (int i=0; i<arr.length; i++) 
            if (kTraSNT(arr[i]))
                d++;
        return d;
    }
    
    public boolean kTraToanSNT() {
        for (int i=0; i<arr.length; i++) 
            if (!kTraSNT(arr[i])) return false;
        return true;
    }
    
    public boolean kTraMangTang() {
        for (int i=0; i<arr.length-1; i++) 
            if (arr[i]>arr[i+1]) return false;
        return true;
    }
    
    public int timGtriMax() {
        int max = arr[0];
        for (int i : arr) {
            if (max<i) max = i;
        }
        return max;
    }
    
    public int timGtriMin() {
        int min = arr[0];
        for (int i : arr) {
            if (min>i) min = i;
        }
        return min;
    }
    
    public int timGtriAmMax() {
        int aMax = 0; // số âm lớn nhất
        for (int i : arr) {
            if (i<0) {
                aMax = i;
                break;
            }
        }
        if (aMax==0) return aMax;
        for (int i : arr) {
            if (aMax<i && i<0) aMax = i;
        }
        return aMax;
    }
    
    public void daoMang() {
        for (int i = 0; i < arr.length/2; i++) {
            int t = arr[i];
            arr[i] = arr[n-i-1];
            arr[n-i-1] = t;
        }
    }
            
    /**
     * @return the arr
     */
    public int[] getArr() {
        return arr;
    }

    /**
     * @param arr the arr to set
     */
    public void setArr(int[] arr) {
        this.arr = arr;
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
}
