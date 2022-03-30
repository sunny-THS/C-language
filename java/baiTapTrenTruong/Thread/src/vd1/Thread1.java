/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vd1;

/**
 *
 * @author Admin
 */
public class Thread1 extends Thread{

    public Thread1() {
        super();
    }

    @Override
    public void run() {
        System.out.println("vd1.Thread1.run()");
    }
    
}
