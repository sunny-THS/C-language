/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c121;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class C121 {
    public static void veHTGRong(int h) {
        for(int i=0; i<h; i++) {
            for(int j=1; j<2*h; j++)
                if(j==h+i || j==h-i || i==h-1)
                    System.out.print(" * ");
                else System.out.print("   ");
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Nhap h: ");
        int h = in.nextInt();
        veHTGRong(h);
    }
}
