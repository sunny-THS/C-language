/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c124;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class Diem2D {
    Scanner in = new Scanner(System.in);

    /**
     * @return the x
     */
    public int giaTriX() {
        return x;
    }

    /**
     * @param x the x to set
     */
    public void setX(int x) {
        this.x = x;
    }

    /**
     * @return the y
     */
    public int giaTriY() {
        return y;
    }

    /**
     * @param y the y to set
     */
    public void setY(int y) {
        this.y = y;
    }
    protected int x, y;
    public Diem2D() {
        this.x = this.y = 0;
    }
    public Diem2D  (int x, int y) {
        this.x = x;
        this.y = y;
    }
    public void nhapDiem() {
        System.out.print("x= ");
        this.x = in.nextInt();
        System.out.print("y= ");
        this.y = in.nextInt();
    }
    public void hienThi() {
        System.out.printf("{ %d, %d }\n", this.x, this.y);
    }
    public void doiDiem(int dx, int dy) {
        this.x = dx;
        this.y = dy;
    }
    public float khoangCach() {
        return (float) Math.sqrt(x*x + y*y);
    }
    public float khoangCach(Diem2D d) {
        return (float) Math.sqrt(Math.pow(this.x-d.x, 2) + Math.pow(this.y-d.y, 2));
    }
}
