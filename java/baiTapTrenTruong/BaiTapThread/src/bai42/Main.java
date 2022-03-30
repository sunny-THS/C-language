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
public class Main {
    public static void main(String[] args) throws InterruptedException {
        ThreadInSoChan t1 = new ThreadInSoChan();
        ThreadInSoLe t2 = new ThreadInSoLe();
        
        t1.setName("Thread chẵn");
        t2.setName("Thread lẻ");
        
        t1.start();
        t1.join();
        t2.start();
    }
}
