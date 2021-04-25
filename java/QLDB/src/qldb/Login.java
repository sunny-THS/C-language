/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package qldb;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
/**
 *
 * @author Admin
 */
public class Login extends JFrame{
    
    private JTextField tfUsername;
    private JPasswordField tfPassword;
    private JButton btnDN, btnDK;
    private JCheckBox showPassword;

    public Login() {
        super("Chương trình quản lý danh bạ");
        initComponents();
        handle();
    }

    private void initComponents() {
        tfUsername = new JTextField(20);
        tfPassword = new JPasswordField(20);
        btnDN = new JButton("Đăng Nhập");
        btnDK = new JButton("Đăng Ký");
        showPassword = new JCheckBox("Show Password");
        
        this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        this.setSize(450, 300);
        this.setLocationRelativeTo(null);
        this.setResizable(false);
        
        Container con = getContentPane();
        con.setLayout(new BorderLayout());
        
        
        JPanel pnTitle = new JPanel(new FlowLayout());
        JLabel lbTitle = new JLabel("Login");
        lbTitle.setFont(new Font("Tahoma", Font.BOLD, 46));
        lbTitle.setForeground(Color.CYAN);
        pnTitle.add(lbTitle);
        pnTitle.setPreferredSize(new Dimension(0, 90));
        
        JPanel pnContent = new JPanel();
        pnContent.setLayout(new BoxLayout(pnContent, BoxLayout.Y_AXIS));
        
        JPanel pnUsername = new JPanel(new FlowLayout());
        JLabel lbUsername = new JLabel("Username:   ");
        pnUsername.add(lbUsername);
        pnUsername.add(tfUsername);
        
        JPanel pnPassword = new JPanel(new FlowLayout());
        JLabel lbPassword = new JLabel("Password:   ");
        pnPassword.add(lbPassword);
        pnPassword.add(tfPassword);
        
        JPanel pnResPass = new JPanel(new FlowLayout());
        showPassword.setCursor(new Cursor(Cursor.HAND_CURSOR));
        pnResPass.add(showPassword);
        
        pnContent.add(pnUsername);
        pnContent.add(pnPassword);
        pnContent.add(pnResPass);
        
        JPanel pnFooter = new JPanel(new FlowLayout());
        btnDK.setCursor(new Cursor(Cursor.HAND_CURSOR));
        btnDN.setCursor(new Cursor(Cursor.HAND_CURSOR));
        pnFooter.add(btnDN);
        pnFooter.add(btnDK);
        pnFooter.setPreferredSize(new Dimension(0, 60));
        
        // set background
        pnTitle.setBackground(Color.WHITE);
        pnUsername.setBackground(Color.WHITE);
        pnPassword.setBackground(Color.WHITE);
        pnFooter.setBackground(Color.WHITE);
        pnResPass.setBackground(Color.WHITE);
        showPassword.setBackground(Color.WHITE);
        
        con.add(pnTitle, BorderLayout.PAGE_START);
        con.add(pnContent, BorderLayout.CENTER);
        con.add(pnFooter, BorderLayout.PAGE_END);
    }

    private void handle() {
        btnDN.addActionListener(ae -> {
            
        });
        btnDK.addActionListener(ae -> {
            new DangKy(this, true).setVisible(true);
            this.tfPassword.setText("");
            this.tfUsername.setText("");
            this.tfUsername.requestFocus();
        });
        showPassword.addActionListener(ae -> {
            if (showPassword.isSelected())
                tfPassword.setEchoChar((char)0);
            else tfPassword.setEchoChar('•');
            
        });
    }
    
}
