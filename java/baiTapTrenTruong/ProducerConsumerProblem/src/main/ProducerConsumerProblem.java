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
public class ProducerConsumerProblem {
    Store store;
    Producer pro;
    Consumer con;
    public ProducerConsumerProblem() {
        store = new Store();
        pro = new Producer(store);
        con = new Consumer(store);
        pro.start();
        con.start();
    }
    public static void main(String[] args) {
        new ProducerConsumerProblem();
    }
}
