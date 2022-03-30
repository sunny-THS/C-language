/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bai42;

/**
 *
 * @author Admin
 */
public class ThreadInSoChan extends Thread{

    public ThreadInSoChan() {
    }

    @Override
    public void run() {
        for (int i = 2; i <= 10; i+=2) {
            System.out.println("i = " +i + " --- " + Thread.currentThread().getName());
        }
    }
    
    
}
