/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c119;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class C119 {
    public static void veHCNRong(int x, int y) {
        for(int i=0; i<y; i++) {
            for(int j=0; j<x; j++)
                if(i==0 || i==y-1 || j==0 || j==x-1)
                    System.out.print(" * ");
                else
                    System.out.print("   ");
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Nhap m: ");
        int m = in.nextInt();
        System.out.print("Nhap n: ");
        int n = in.nextInt();
        veHCNRong(n, m);
    }
}
