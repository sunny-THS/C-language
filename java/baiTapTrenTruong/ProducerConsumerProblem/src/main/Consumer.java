/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package main;

/**
 *
 * @author Admin
 */
public class Consumer extends Thread{
    Store store = null;
    public Consumer(Store s) {
        store = s;
    }

    @Override
    public void run() {
        while(true) {
            try {
                long x = store.get();
                if (x>0) System.out.println("-- Product "+ x + " is bought");
                else System.out.println("Consumer is waiting for new product.");
            } catch (Exception e) {
            }
        }
    }
    
}
