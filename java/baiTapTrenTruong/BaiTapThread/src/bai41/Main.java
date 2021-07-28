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
public class Main {
    
    public static void main(String[] args) {
        MyThread1 t1Runable = new MyThread1();
        MyThread1 t2Runable = new MyThread1();
        
        Thread thread1 = new Thread(t1Runable);
        Thread thread2 = new Thread(t2Runable);
        
        thread1.setPriority(Thread.MAX_PRIORITY);
        thread2.setPriority(Thread.MIN_PRIORITY);
        
        thread1.setName("Luồng 1");
        thread2.setName("Luồng 2");
        
        thread1.start();
        thread2.start();
    }
}
