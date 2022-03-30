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
public class RunableThread implements Runnable{

    public RunableThread() {
    }

    @Override
    public void run() {
        System.out.println("vd2.RunableThread.run()");
    }
    
}
