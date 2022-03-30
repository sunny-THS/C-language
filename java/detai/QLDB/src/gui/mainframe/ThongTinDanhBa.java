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
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.text.SimpleDateFormat;
import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.KeyStroke;
import pojo.*;
import static gui.util.Utils.*;

/**
 *
 * @author pc
 * hiển thị thông tin của liên hệ
 */
public class ThongTinDanhBa extends JDialog {

    private JTextField tfSDT, tfTenLH, tfEmail, tfNgayLuu;
    private JTextArea taGhiChu;
    private JMenuItem mniLuu, mniCS, mniQL, mniDel;
    private DanhBa danhBa;
    private JLabel lbImageVcard;
    String kieuDinhDang = "dd/MM/yyyy";
    SimpleDateFormat df = new SimpleDateFormat(kieuDinhDang);
    private boolean ckUpdate = false;

    public ThongTinDanhBa(JFrame parent, boolean modal, DanhBa db) {
        super(parent, modal);
        danhBa = db;
        initComponents();
        loadData();
        xuLiSuKien();
    }

    public ThongTinDanhBa(JDialog parent, boolean modal, DanhBa db) {
        super(parent, modal);
        danhBa = db;
        initComponents();
        loadData();
        xuLiSuKien();
    }

    private void initComponents() {
        this.setSize(400, 490);
        this.setTitle("Thông tin danh bạ");
        this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        this.setLocationRelativeTo(this);

        Container con = getContentPane();
        con.setLayout(new BorderLayout());

        JMenuBar menuBar = new JMenuBar();
        JMenu menuTool = new JMenu("Tools");
        menuTool.setPreferredSize(new Dimension(50, 15));
        menuTool.setMnemonic(KeyEvent.VK_T); // Tạo phím tắt alt_T, Tổ hợp phím sẽ hiện cửa sổ lên và không cần bấm vào menu

        Dimension sizeMenu = new Dimension(160, 30);
        mniLuu = new JMenuItem("Lưu");
        mniLuu.setPreferredSize(sizeMenu);
        mniLuu.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, ActionEvent.CTRL_MASK));
        mniLuu.setEnabled(false);
        menuTool.add(mniLuu);
        menuTool.addSeparator();

        mniCS = new JMenuItem("Chỉmh sửa");
        mniCS.setPreferredSize(sizeMenu);
        mniCS.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_C, ActionEvent.CTRL_MASK | ActionEvent.ALT_MASK));
        menuTool.add(mniCS);
        menuTool.addSeparator();

        mniDel = new JMenuItem("Xóa");
        mniDel.setPreferredSize(sizeMenu);
        mniDel.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_D, ActionEvent.CTRL_MASK | ActionEvent.ALT_MASK));
        menuTool.add(mniDel);
        menuTool.addSeparator();

        mniQL = new JMenuItem("Quay Lại");
        mniQL.setPreferredSize(sizeMenu);
        mniQL.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_Q, ActionEvent.CTRL_MASK));
        menuTool.add(mniQL);

        menuBar.add(menuTool);
        setJMenuBar(menuBar);

        JPanel pnTitle = new JPanel(new FlowLayout(FlowLayout.CENTER));
        pnTitle.setPreferredSize(new Dimension(0, 40));
        pnTitle.setBackground(Color.WHITE);
        JLabel lbTitle = new JLabel("Thông Tin Danh Bạ");
        lbTitle.setForeground(Color.blue);
        lbTitle.setFont(new Font("Arial", Font.BOLD, 20));
        pnTitle.add(lbTitle);

        Font fontThongTin = new Font("Arial", Font.PLAIN, 14);
        JPanel pnThongTin = new JPanel();
        pnThongTin.setBackground(Color.WHITE);
        JPanel pnHienThiThongTin = new JPanel(new GridLayout(5, 2, 0, 15));
        pnHienThiThongTin.setBackground(Color.WHITE);
        pnThongTin.add(pnHienThiThongTin);

        JLabel lbSDT = new JLabel("Số điện thoại: ");
        JLabel lbTenLH = new JLabel("Tên liên hệ: ");
        JLabel lbGhiChu = new JLabel("Ghi chú: ");
        JLabel lbNgayLuu = new JLabel("Ngày lưu: ");
        JLabel lbEmail = new JLabel("Email: ");

        lbSDT.setFont(fontThongTin);
        lbTenLH.setFont(fontThongTin);
        lbGhiChu.setFont(fontThongTin);
        lbNgayLuu.setFont(fontThongTin);
        lbEmail.setFont(fontThongTin);

        Dimension sizeBoxInput = new Dimension(180, 25);

        JPanel pnSDT = new JPanel();
        pnSDT.setLayout(new BoxLayout(pnSDT, BoxLayout.Y_AXIS));
        tfSDT = new JTextField();
        tfSDT.setPreferredSize(sizeBoxInput);
        pnSDT.add(tfSDT);

        JPanel pnTenLH = new JPanel();
        pnTenLH.setLayout(new BoxLayout(pnTenLH, BoxLayout.Y_AXIS));
        tfTenLH = new JTextField();
        tfTenLH.setPreferredSize(sizeBoxInput);
        pnTenLH.add(tfTenLH);

        JPanel pnGC = new JPanel();
        pnGC.setLayout(new BoxLayout(pnGC, BoxLayout.Y_AXIS));
        taGhiChu = new JTextArea();
        taGhiChu.setPreferredSize(sizeBoxInput);
        taGhiChu.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        pnGC.add(taGhiChu);

        JPanel pnEmail = new JPanel();
        pnEmail.setLayout(new BoxLayout(pnEmail, BoxLayout.Y_AXIS));
        tfEmail = new JTextField();
        tfEmail.setPreferredSize(sizeBoxInput);
        pnEmail.add(tfEmail);

        JPanel pnNgayLuu = new JPanel();
        pnNgayLuu.setLayout(new BoxLayout(pnNgayLuu, BoxLayout.Y_AXIS));
        tfNgayLuu = new JTextField();
        tfNgayLuu.setPreferredSize(sizeBoxInput);
        pnNgayLuu.add(tfNgayLuu);

        pnHienThiThongTin.add(lbSDT);
        pnHienThiThongTin.add(pnSDT);
        pnHienThiThongTin.add(lbTenLH);
        pnHienThiThongTin.add(pnTenLH);
        pnHienThiThongTin.add(lbNgayLuu);
        pnHienThiThongTin.add(pnNgayLuu);
        pnHienThiThongTin.add(lbEmail);
        pnHienThiThongTin.add(pnEmail);
        pnHienThiThongTin.add(lbGhiChu);
        pnHienThiThongTin.add(pnGC);

        JPanel pnFooter = new JPanel();
        pnFooter.setBackground(Color.WHITE);
        lbImageVcard = new JLabel();
        pnFooter.add(lbImageVcard);

        con.add(pnTitle, BorderLayout.PAGE_START);
        con.add(pnThongTin, BorderLayout.CENTER);
        con.add(pnFooter, BorderLayout.PAGE_END);
    }

    private void xuLiSuKien() {
        mniLuu.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                boolean kt = true;

                if (!isValidPhoneNumber(tfSDT.getText())) {
                    kt = false;
                    tfSDT.selectAll();
                    tfSDT.requestFocus();
                } else {
                    if (!tfSDT.getText().equals(danhBa.getSdt()) && DanhBaDAO.isSDT(tfSDT.getText())) {
                        kt = false;
                        tfSDT.selectAll();
                        tfSDT.requestFocus();
                    }
                }
                // kiểm tra nhập họ tên
                if (tfTenLH.getText().trim().equals("") || tfTenLH.getText().equals("Nhập họ tên")) {
                    kt = false;
                    tfTenLH.selectAll();
                    tfTenLH.requestFocus();
                }

                // kiểm tra nhập email
                if (!isValidEmail(tfEmail.getText())) {
                    kt = false;
                    tfEmail.selectAll();
                    tfEmail.requestFocus();
                }
                
                try {
                    danhBa.setNgayLuu(df.parse(tfNgayLuu.getText()));
                } catch (Exception e) {
                    e.printStackTrace();
                }

                danhBa.setTenLH(tfTenLH.getText());
                danhBa.setGhiChu(taGhiChu.getText());
                danhBa.setSdt(tfSDT.getText());
                danhBa.setEmail(tfEmail.getText());
                
                if (kt) {
                    mniLuu.setEnabled(false);
                    try {
                        if (DanhBaDAO.capNhat(danhBa)) {
                            loadData();
                            ckUpdate = true;
                            JOptionPane.showMessageDialog(null, "Lưu thông tin danh bạ thành công");
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                        JOptionPane.showMessageDialog(null, "Lưu thông tin danh bạ thất bại");
                    }
                }
            }
        });
        mniDel.addActionListener(ae -> {
            try {
                int c = JOptionPane.showConfirmDialog(
                        null,
                        "Bạn có muốn xóa danh bạ này không",
                        "Thông Báo",
                        JOptionPane.YES_NO_OPTION,
                        JOptionPane.QUESTION_MESSAGE
                );
                if (c == JOptionPane.YES_OPTION) {
                    if (DanhBaDAO.xoa(danhBa)) {
                        this.ckUpdate = true;
                        JOptionPane.showMessageDialog(null, "Xóa thông tin danh bạ thành công");
                        dispose();
                    }
                }
            } catch (Exception e) {
                JOptionPane.showMessageDialog(null, "Xóa danh bạ thất bại");
            }
        });
        mniCS.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                mniLuu.setEnabled(true);
                tfSDT.setEditable(true);
                tfEmail.setEditable(true);
                tfTenLH.setEditable(true);
                taGhiChu.setEditable(true);
                tfSDT.requestFocus();
                tfSDT.selectAll();
            }
        });

        mniQL.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                dispose();
            }
        });
    }

    private void loadData() {
        VCardDanhBa vcard = new VCardDanhBa(danhBa); // tạo mã QR dựa trên thông tin của liên hệ
        vcard.createVCart();// tạo mã
        lbImageVcard.setIcon(new ImageIcon(vcard.getImageVCard())); // hiển thị mã qr

        df.setLenient(false); // set false để kiểm tra tính hợp lệ của date. VD: tháng 2 phải có 28-29 ngày, năm có 12 tháng,....

        tfEmail.setEditable(false);
        tfNgayLuu.setEditable(false);
        tfSDT.setEditable(false);
        tfTenLH.setEditable(false);
        taGhiChu.setEditable(false);

        tfEmail.setText(danhBa.getEmail());
        tfNgayLuu.setText(df.format(danhBa.getNgayLuu()));
        tfSDT.setText(danhBa.getSdt());
        tfTenLH.setText(danhBa.getTenLH());
        taGhiChu.setText(danhBa.getGhiChu());
    }

    /**
     * @return the ckUpdate
     */
    public boolean isCkUpdate() {
        return ckUpdate;
    }
}
