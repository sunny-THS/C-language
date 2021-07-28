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
public class ThreadInSoLe extends Thread{

    public ThreadInSoLe() {
    }

    @Override
    public void run() {
        for (int i = 1; i < 10; i+=2) {
            System.out.println("i = " +i + " --- " + Thread.currentThread().getName());
        }
    }
    
}
