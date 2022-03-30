/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vd2;

/**
 *
 * @author Admin
 */
public class Main {
    public static void main(String[] args) {
        RunableThread rt = new RunableThread();
        Thread t = new Thread(rt);
        System.out.println("vd2.Main.main()");
        t.start();
        System.out.println("Hello");
    }
}
