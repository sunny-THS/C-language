/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package multithread;

import java.net.ServerSocket;

/**
 *
 * @author Admin
 */
public class TCPEchoServerMultiThread {

    public static final int DEFAULT_PORT = 3071;

    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(DEFAULT_PORT);
            System.out.println("Server waiting for port: " + DEFAULT_PORT);
            while (true) {
                Runnable t = new TCPEchoServer(serverSocket.accept());
                new Thread(t).start();
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

    }

}
