/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui.mainframe;

import dao.DanhBaDAO;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.sql.ResultSet;
import java.util.Vector;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;
import pojo.DanhBa;

/**
 *
 * @author Admin
 */
public class FindPhoneBook extends JDialog {

    private JTextField tfFind;
    private JButton btnFind, btnExit;
    private JList<DanhBa> lstDanhBa;
    private ResultSet res;
    DanhBa selectedDB;

    public FindPhoneBook(JFrame parent, boolean modal) {
        super(parent, modal);
        initComponents();
        xuLiSuKien();
    }

    private void initComponents() {
        this.setSize(400, 400);
        this.setTitle("Tìm danh bạ");
        this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        this.setLocationRelativeTo(this);

        Container con = getContentPane();
        con.setLayout(new BorderLayout());

        JPanel pnFind = new JPanel(new FlowLayout());
        pnFind.setBackground(Color.WHITE);
        JLabel lbFind = new JLabel("Tên danh bạ:");
        lbFind.setBackground(Color.WHITE);
        tfFind = new JTextField(20);
        btnFind = new JButton("Find");
        btnFind.setCursor(new Cursor(Cursor.HAND_CURSOR));

        pnFind.add(lbFind);
        pnFind.add(tfFind);
        pnFind.add(btnFind);

        JPanel pnContent = new JPanel();
        pnContent.setBackground(Color.WHITE);
        lstDanhBa = new JList<>();
        lstDanhBa.setCellRenderer(new PhoneBookListRenderer());
        JScrollPane scrollLstDanhBa = new JScrollPane(lstDanhBa, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        scrollLstDanhBa.setPreferredSize(new Dimension(392, 270));
        scrollLstDanhBa.setBorder(new EmptyBorder(0, 5, 0, 5));
        pnContent.add(scrollLstDanhBa);

        JPanel pnFooter = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        pnFooter.setBackground(Color.WHITE);
        btnExit = new JButton("Quay lại");
        pnFooter.add(btnExit);

        con.add(pnFind, BorderLayout.PAGE_START);
        con.add(pnContent, BorderLayout.CENTER);
        con.add(pnFooter, BorderLayout.PAGE_END);
    }

    private void loadData() {
        String timTen = tfFind.getText().trim();
        if (timTen.equals("")) {
            JOptionPane.showMessageDialog(this, "Vui lòng nhập tên danh bạ này", "Thông báo", JOptionPane.WARNING_MESSAGE);
            tfFind.selectAll();
            return;
        }
        try {
            Vector<DanhBa> nhomDB = new Vector<DanhBa>();
            nhomDB = DanhBaDAO.timDanhBa(timTen);
            
            if (nhomDB == null) {
                JOptionPane.showMessageDialog(this, "Không tìm thấy tên danh bạ này", "Thông báo", JOptionPane.WARNING_MESSAGE);
                tfFind.selectAll();
            }

            lstDanhBa.setListData(nhomDB);
            lstDanhBa.setSelectedIndex(0);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void xuLiSuKien() {
        JDialog thisFrame = this;
        tfFind.addKeyListener(new KeyListener() {

            @Override
            public void keyTyped(KeyEvent e) {

            }

            @Override
            public void keyReleased(KeyEvent e) {

            }

            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyChar() == KeyEvent.VK_ENTER) {
                    loadData();
                }
            }
        });
        btnFind.addActionListener(ae -> {
            loadData();
        });
        btnExit.addActionListener(ae -> {
            this.dispose();
        });
        lstDanhBa.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent evt) {
                if (evt.getClickCount() == 2) {
                    selectedDB = lstDanhBa.getSelectedValue();
                    new ThongTinDanhBa(thisFrame, true, selectedDB).setVisible(true);
                }
            }
        });
    }
}
