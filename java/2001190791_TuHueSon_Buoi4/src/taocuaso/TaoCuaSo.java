/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package taocuaso;

import java.awt.Color;
import java.awt.Cursor;
import javax.swing.JButton;
import javax.swing.JFrame;

/**
 *
 * @author A102PC32
 */
public class TaoCuaSo extends JFrame{
    public TaoCuaSo(String title) {
        this.setBackground(Color.DARK_GRAY);
        this.setTitle(title);
        this.setSize(300, 200);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        JButton btnThoat = new JButton("Thoát");
        getContentPane().add(btnThoat);
    }
    public static void main(String[] args) {
        TaoCuaSo taocuaso1 = new TaoCuaSo("vd tạo cửa sổ 1");
        taocuaso1.setVisible(true);
    }
}
