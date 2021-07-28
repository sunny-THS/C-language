/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bai41;


/**
 *
 * @author Admin
 */
public class MyThread1 implements Runnable{
    public MyThread1() {
    }   

    @Override
    public void run() {
        for (int i = 1; i <= 10; i++) {
            try {
                System.out.println("i = " +i + " --- " + Thread.currentThread().getName());
                Thread.sleep(500);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
    
}
