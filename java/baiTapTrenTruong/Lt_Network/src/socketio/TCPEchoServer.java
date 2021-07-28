/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package socketio;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author Admin
 */
public class TCPEchoServer {
    public  static final int DEFAULT_PORT = 3071;
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(DEFAULT_PORT);
            System.out.println("Server waiting for port: " + DEFAULT_PORT);
            while (true) {                
                Socket connSocket = serverSocket.accept();
                System.out.println("Accepted client: " + connSocket.getInetAddress().getHostAddress());
                try {
                    BufferedReader in = new BufferedReader(new InputStreamReader(connSocket.getInputStream()));
                    PrintWriter out = new PrintWriter(new OutputStreamWriter(connSocket.getOutputStream()));
                    
                    String message;
                    while ((message=in.readLine()) != null) {
                        System.out.println("Recive from client: " + message);
                        out.println(message);
                        out.flush();
                    }
                } catch (Exception e) {
                    System.err.println(e.getMessage());
                }
            }
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }
}
 