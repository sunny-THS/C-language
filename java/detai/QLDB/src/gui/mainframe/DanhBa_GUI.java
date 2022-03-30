/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui.mainframe;

import dao.DangNhapDAO;
import dao.DanhBaDAO;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Container;
import java.awt.Font;
import java.awt.Dimension;
import java.awt.event.*;
import java.awt.Event;
import java.awt.Color;
import java.awt.Cursor;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.ArrayList;
import java.util.Vector;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JSeparator;
import javax.swing.JList;
import javax.swing.JComboBox;
import javax.swing.BoxLayout;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.border.EmptyBorder;
import javax.swing.KeyStroke;
import pojo.*;

/**
 *
 * @author Admin
 */
public class DanhBa_GUI extends JFrame {

    private JComboBox<NhomLienHe> cboNhomLH;
    private JList<DanhBa> lstDanhBa;
    private JMenu mnuLogout;
    private JMenuItem mnuISaoLuu, mnuIKhoiPhuc, mnuIThemDanhBa, mnuIFindPhoneBook;
    private JLabel lbFooter;
    public static String username;
    DanhBa selectedDB;
    NhomLienHe selectedNLH;

    public DanhBa_GUI() {
        super("Chương trình quản lý danh bạ");
        username = DangNhapDAO.getInfoUser().getTenDN();
        initComponents();
        handle();
        loadData();
    }

    private void initComponents() {
        this.setSize(400, 450);
        this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setIconImage(java.awt.Toolkit.getDefaultToolkit().getImage(gui.Main.iconImage));
        this.setResizable(false);

        Container con = this.getContentPane();
        con.setLayout(new BorderLayout());

        JMenuBar mnuBar = new JMenuBar();

        JMenu mnuTools = new JMenu("Tools");

        mnuLogout = new JMenu("Logout");

        Dimension sizeMenu = new Dimension(200, 30);
        mnuISaoLuu = new JMenuItem("Sao Lưu");
        mnuISaoLuu.setPreferredSize(sizeMenu);
        mnuISaoLuu.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, ActionEvent.CTRL_MASK | Event.SHIFT_MASK));

        mnuIKhoiPhuc = new JMenuItem("Khôi Phục");
        mnuIKhoiPhuc.setPreferredSize(sizeMenu);
        mnuIKhoiPhuc.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_R, ActionEvent.CTRL_MASK | Event.SHIFT_MASK));

        mnuIThemDanhBa = new JMenuItem("Thêm danh bạ");
        mnuIThemDanhBa.setPreferredSize(sizeMenu);
        mnuIThemDanhBa.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_N, ActionEvent.CTRL_MASK));

        mnuIFindPhoneBook = new JMenuItem("Find");
        mnuIFindPhoneBook.setPreferredSize(sizeMenu);
        mnuIFindPhoneBook.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_F, ActionEvent.CTRL_MASK));

        mnuTools.add(mnuIThemDanhBa);
        mnuTools.add(new JSeparator());
        mnuTools.add(mnuISaoLuu);
        mnuTools.add(new JSeparator());
        mnuTools.add(mnuIKhoiPhuc);
        mnuTools.add(new JSeparator());
        mnuTools.add(mnuIFindPhoneBook);

        mnuBar.add(mnuTools);
        mnuBar.add(mnuLogout);

        this.setJMenuBar(mnuBar);

        JPanel pnTitle = new JPanel();
        pnTitle.setLayout(new BoxLayout(pnTitle, BoxLayout.Y_AXIS));
        pnTitle.setPreferredSize(new Dimension(0, 75));
        pnTitle.setBackground(Color.WHITE);

        JLabel lbTitle = new JLabel("Danh Bạ");
        lbTitle.setFont(new Font("Arial", Font.BOLD, 35));
        lbTitle.setAlignmentX(CENTER_ALIGNMENT);
        lbTitle.setAlignmentY(CENTER_ALIGNMENT);

        JPanel pnNhomLH = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        pnNhomLH.setBackground(Color.WHITE);
        cboNhomLH = new JComboBox<>();
        pnNhomLH.add(getCboNhomLH());

        pnTitle.add(lbTitle);
        pnTitle.add(pnNhomLH);

        JPanel pnContent = new JPanel();
        pnContent.setBackground(Color.WHITE);
        lstDanhBa = new JList<>();
        getLstDanhBa().setCellRenderer(new PhoneBookListRenderer()); // thiết kê cho các phần tử trong jlist
        JScrollPane scrollLstDanhBa = new JScrollPane(getLstDanhBa(), JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED); // scroll bar
        scrollLstDanhBa.setPreferredSize(new Dimension(392, 270));
        scrollLstDanhBa.setBorder(new EmptyBorder(0, 5, 0, 5));
        pnContent.add(scrollLstDanhBa);

        JPanel pnFooter = new JPanel(new FlowLayout(FlowLayout.LEFT));
        lbFooter = new JLabel(username + " |");
        lbFooter.setCursor(new Cursor(Cursor.HAND_CURSOR));
        pnFooter.add(lbFooter);

        con.add(pnTitle, BorderLayout.PAGE_START);
        con.add(pnContent, BorderLayout.CENTER);
        con.add(pnFooter, BorderLayout.PAGE_END);
    }

    private void handle() {
        JFrame thisFrame = this;

        mnuIFindPhoneBook.addActionListener(ae -> {
            new FindPhoneBook(thisFrame, true).setVisible(true);
        });

        mnuLogout.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent evt) {
                try {
                    int c = JOptionPane.showConfirmDialog(
                            null,
                            "Bạn có muốn đăng xuất không?",
                            "Thông báo", JOptionPane.YES_NO_OPTION,
                            JOptionPane.QUESTION_MESSAGE
                    );
                    if (c == JOptionPane.YES_OPTION) {
                        if (DangNhapDAO.dangXuat()) {
                            FileOutputStream fos = new FileOutputStream(gui.Main.saoLuuDangNhap);
                            OutputStreamWriter osw = new OutputStreamWriter(fos, "UTF-8");
                            BufferedWriter bw = new BufferedWriter(osw);
                            bw.write("");
                            bw.close();
                            osw.close();
                            fos.close();
                            
                            new gui.auth.Login().setVisible(true);
                            thisFrame.dispose();
                        }
                        else 
                            JOptionPane.showMessageDialog(thisFrame, "Đăng xuất thất bại vui lòng thử lại");   
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });

        mnuIThemDanhBa.addActionListener(ae -> {
            ThemDanhBa themDanhBa = new ThemDanhBa(thisFrame, true);
            themDanhBa.setVisible(true);
            if (themDanhBa.isCkAdd()) {
                getCboNhomLH().removeAllItems();
                loadData();
            }
        });

        getCboNhomLH().addActionListener(ae -> {
            showDanhBa(); // show thông tin của từng danh bạ
        });

        getLstDanhBa().addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent evt) {
                if (evt.getClickCount() == 2) { // khi click double vào 1 liên hệ nào đó
                    selectedDB = getLstDanhBa().getSelectedValue();
                    ThongTinDanhBa ttdb = new ThongTinDanhBa(thisFrame, true, selectedDB);
                    ttdb.setVisible(true); // hiễn thị thông tin của liên hệ
                    if (ttdb.isCkUpdate()) {
                        getCboNhomLH().removeAllItems();
                        loadData();
                    }
                }

            }
        });
        // ở footer chứa username của người dùng
        lbFooter.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent evt) {
                new ThongTinCaNhan(thisFrame, true).setVisible(true); // hiển thị thông tin của người dùng
            }
        });
        mnuISaoLuu.addActionListener(ae -> { // tính năng sao lưu danh bạ
            if (DanhBaDAO.saoLuu()) {
                mnuIKhoiPhuc.setEnabled(true);
                JOptionPane.showMessageDialog(this, "Sao lưu thành công");
            }
            else
                JOptionPane.showMessageDialog(this, "Sao lưu thất bại");
            
        });
        mnuIKhoiPhuc.addActionListener(ae -> { // tính năng khôi phục của danh bạ
            if (DanhBaDAO.khoiPhuc()) {
                getCboNhomLH().removeAllItems();
                loadData();
                JOptionPane.showMessageDialog(this, "Danh bạ đã được khôi phục");
            }
            else 
                JOptionPane.showMessageDialog(this, "Khôi phục thất bại");
           
        });
    }
    // hiển thị các liên hệ
    private void showDanhBa() {
        Vector<DanhBa> v = new Vector<DanhBa>();
        if (getCboNhomLH().getModel().getSize() < 1) {
            getLstDanhBa().setListData(v);
            return;
        }
        selectedNLH = (NhomLienHe) getCboNhomLH().getSelectedItem();
        v = selectedNLH.getLstDanhBa();
        getLstDanhBa().setListData(v);
        getLstDanhBa().setSelectedIndex(0);
    }

    private void loadData() {
        if (!DanhBaDAO.isSaoLuu()) {
            mnuIKhoiPhuc.setEnabled(false);
        }
        ArrayList<NhomLienHe> nhomLH = new ArrayList<NhomLienHe>();
        nhomLH = DanhBaDAO.getNhomLh();

        nhomLH.forEach(el -> {
            getCboNhomLH().addItem(el);
        });

        Vector<DanhBa> nhomDB = new Vector<DanhBa>();
        nhomDB = DanhBaDAO.getDanhBa();

        for (NhomLienHe lh : nhomLH) {
            for (DanhBa db : nhomDB) {
                if (lh.getMsNhom().equals(db.getMalh())) {
                    lh.themDanhBa(db);
                }
            }
        }

        showDanhBa();
    }

    /**
     * @return the cboNhomLH
     */
    public JComboBox<NhomLienHe> getCboNhomLH() {
        return cboNhomLH;
    }

    /**
     * @return the lstDanhBa
     */
    public JList<DanhBa> getLstDanhBa() {
        return lstDanhBa;
    }
}
