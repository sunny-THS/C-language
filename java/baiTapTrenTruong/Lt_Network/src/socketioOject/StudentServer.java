/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package socketioOject;

import java.io.ObjectInputStream;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author Admin
 */
public class StudentServer {
    public static final int DEFAULT_PORT = 3071;
    private static void communicate (Socket connSocket) {
        try {
            ObjectInputStream in = new ObjectInputStream(connSocket.getInputStream());
            Student student;
            try {
                while((student=(Student)in.readObject())!=null)
                    System.out.println("received: "+student.getName());
            } catch (Exception e) {
            }
        } catch (Exception e) {
        }
    }
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(DEFAULT_PORT);
            System.out.println("Server waiting for port: "+ DEFAULT_PORT);
            while (true) {
                Socket connSocket = serverSocket.accept();
                communicate(connSocket);
            }
        } catch (Exception e) {
        }
    }
}
