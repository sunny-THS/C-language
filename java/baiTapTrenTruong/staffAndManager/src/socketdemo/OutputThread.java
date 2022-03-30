/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package socketdemo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.Socket;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;

/**
 *
 * @author Admin
 */
public class OutputThread extends  Thread{
    Socket socket;
    JTextArea txt;
    BufferedReader bf;
    String sender;
    String receiver;

    public OutputThread(Socket socket, JTextArea txt, String sender, String receiver) {
        super();
        try {
            this.socket = socket;
            this.txt = txt;
            this.bf = new BufferedReader(new InputStreamReader(socket.getInputStream())); // nhận dữ liệu
            this.sender = sender;
            this.receiver = receiver;
        } catch (Exception e) {
            JOptionPane.showInputDialog(null, "Network error!");
            System.exit(0);
        }
    }

    @Override
    public void run() {
        while (true) {
            try {
                if (socket != null) { // kiểm tra xem có staff nào không
                    String msg = "";
                    if ((msg=bf.readLine()) != null && msg.length()>0) // lấy tin nhắn của staff và chk xem có tin nhắn không
                        txt.append("\n" + receiver + ": " + msg); // tin nhắn của staff
                }
                sleep(1000);
            } catch (Exception e) {
            }
        }
    }
    
}
