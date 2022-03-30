/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package socketioOject;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

/**
 *
 * @author Admin
 */
public class StudentClient {
    public static void main(String[] args) {
        try {
            Socket clientSocket = new Socket("localhost", 3071);
            BufferedReader user = new BufferedReader(new InputStreamReader(System.in));
            ObjectOutputStream out = new ObjectOutputStream(clientSocket.getOutputStream());
            String message;
            while (true) {
                String id;
                System.out.print("Student id: ");
                id = user.readLine();
                if (id.length() == 0) {
                    System.out.println("Stoped sending to server");
                    break;
                }
                String name;
                System.out.println("Student name: ");
                name = user.readLine();
                Student st = new Student(id, name);
                out.writeObject(st);
                out.flush();
            }
            clientSocket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
