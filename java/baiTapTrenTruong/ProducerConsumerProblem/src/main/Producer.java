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
public class Producer extends Thread{
    Store store = null;
    long index = 1;
    public Producer(Store s) {
        store = s;
    } 

    @Override
    public void run() {
        while(true) {
            try {
                boolean rs = store.put(index);
                if (rs) System.out.println("** Product " + (index++) + "is made.");
                else System.out.println("Store is full");
            } catch (Exception e) {
            }
        }
    }
    
}
