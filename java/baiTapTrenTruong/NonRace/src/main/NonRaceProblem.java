/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package main;

import java.util.Date;

/**
 *
 * @author Admin
 */
public class NonRaceProblem {
    Date d = null;
    long num1=0, num2=0;
    
    TimeThread t1 = new TimeThread();
    AddThread t2 = new AddThread();

    public NonRaceProblem() {
        d = new Date(System.currentTimeMillis());
        randomNumber();
        t1.start();
        t2.start();
    }

    private void randomNumber() {
        num1 = Math.round(Math.random()*10000000);
        num2 = Math.round(Math.random()*10000000);
    }
    
    private class TimeThread extends Thread{

        public TimeThread() {
            super();
        }
        @Override
        public void run() {
            while(true)  {
                try {
                    System.out.println(d);
                    this.sleep(1000); //1s
                    d = new Date(System.currentTimeMillis());
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }

    private class AddThread extends Thread{

        public AddThread() {
            super();
        }
        @Override
        public void run() {
            while(true)  {
                try {
                    System.out.println(num1 + num2);
                    randomNumber();
                    this.sleep(500); //500ms
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
