/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package multithread;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

/**
 *
 * @author Admin
 */
public class TCPEchoServer implements Runnable {

    private Socket socket;

    public TCPEchoServer(Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));

            String message;
            while ((message = in.readLine()) != null) {
                System.out.println("Recive from client: " + message);
                out.println(message);
                out.flush();
            }
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }
}
