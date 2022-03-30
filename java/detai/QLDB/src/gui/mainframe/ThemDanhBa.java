/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui.mainframe;

import dao.DanhBaDAO;
import static gui.util.Utils.*;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.MenuItem;
import java.awt.PopupMenu;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import static javax.swing.WindowConstants.DISPOSE_ON_CLOSE;
import pojo.NhomLienHe;

/**
 *
 * @author pc
 * Thêm một danh bạ
 */
public class ThemDanhBa extends JDialog {

    private JTextField tfHoTen, tfSDT, tfEmail, tfGhiChu, tfNhomLh;
    private JButton btnXacNhan, btnNhapLai, btnQuayLai;
    private JLabel lbErrHoten, lbErrSDT, lbErrGhiChu, lbErrEmail, lbErrNhomLH;
    private boolean ckAdd = false;
    private PopupMenu lstLH;

    public ThemDanhBa(JFrame parent, boolean modal) {
        super(parent, modal);
        initComponents();
        handle();
    }

    private void initComponents() {
        Dimension sizeBoxInput = new Dimension(200, 30);
        tfHoTen = new JTextField("Nhập họ tên");
        tfEmail = new JTextField("Nhập email: abc@example.com");
        tfSDT = new JTextField("ex: 093249113");
        tfGhiChu = new JTextField("Ghi chú");
        tfNhomLh = new JTextField("Nhóm liên hệ");

        tfHoTen.setForeground(Color.LIGHT_GRAY);
        tfEmail.setForeground(Color.LIGHT_GRAY);
        tfSDT.setForeground(Color.LIGHT_GRAY);
        tfGhiChu.setForeground(Color.LIGHT_GRAY);
        tfNhomLh.setForeground(Color.LIGHT_GRAY);

        btnXacNhan = new JButton("Xác nhận");
        btnNhapLai = new JButton("Nhập lại");
        btnQuayLai = new JButton("Quay lại");

        btnXacNhan.setCursor(new Cursor(Cursor.HAND_CURSOR));
        btnNhapLai.setCursor(new Cursor(Cursor.HAND_CURSOR));
        btnQuayLai.setCursor(new Cursor(Cursor.HAND_CURSOR));

        tfHoTen.setPreferredSize(sizeBoxInput);
        tfEmail.setPreferredSize(sizeBoxInput);
        tfSDT.setPreferredSize(sizeBoxInput);
        tfGhiChu.setPreferredSize(sizeBoxInput);
        tfNhomLh.setPreferredSize(sizeBoxInput);

        this.setSize(450, 360);
        this.setTitle("Đăng Ký");
        this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        this.setLocationRelativeTo(this);

        Container con = getContentPane();
        con.setLayout(new BorderLayout());

        JPanel pnTitle = new JPanel(new FlowLayout(FlowLayout.CENTER));
        pnTitle.setPreferredSize(new Dimension(0, 50));
        JLabel lbTitle = new JLabel("Đăng ký thông tin");
        lbTitle.setFont(new Font("Arial", Font.BOLD, 22));
        pnTitle.add(lbTitle);

        Font fontThongTin = new Font("Arial", Font.BOLD, 16);
        JPanel pnThongTin = new JPanel();
        JPanel pnDienThongTin = new JPanel(new GridLayout(5, 2, 0, 5));
        JLabel lbHoten = new JLabel("Họ và tên: ");
        JLabel lbSDT = new JLabel("SDT");
        JLabel lbEmail = new JLabel("Email: ");
        JLabel lbGhiChu = new JLabel("Ghi chú: ");
        JLabel lbNhomLienHe = new JLabel("Nhóm liên hệ: ");
        lbHoten.setFont(fontThongTin);
        lbSDT.setFont(fontThongTin);
        lbGhiChu.setFont(fontThongTin);
        lbEmail.setFont(fontThongTin);
        lbNhomLienHe.setFont(fontThongTin);

        Font fontErr = new Font("Arial", Font.PLAIN, 9);
        Dimension sizePInfoAndErr = new Dimension(200, 35);
        JPanel pnHoTen = new JPanel();
        pnHoTen.setLayout(new BoxLayout(pnHoTen, BoxLayout.Y_AXIS));
        pnHoTen.setPreferredSize(sizePInfoAndErr);
        lbErrHoten = new JLabel(" ");
        lbErrHoten.setForeground(Color.RED);
        lbErrHoten.setFont(fontErr);
        pnHoTen.add(tfHoTen);
        pnHoTen.add(lbErrHoten);

        JPanel pnEmail = new JPanel();
        pnEmail.setLayout(new BoxLayout(pnEmail, BoxLayout.Y_AXIS));
        pnEmail.setPreferredSize(sizePInfoAndErr);
        lbErrEmail = new JLabel(" ");
        lbErrEmail.setForeground(Color.RED);
        lbErrEmail.setFont(fontErr);
        pnEmail.add(tfEmail);
        pnEmail.add(lbErrEmail);

        JPanel pnSDT = new JPanel();
        pnSDT.setLayout(new BoxLayout(pnSDT, BoxLayout.Y_AXIS));
        pnSDT.setPreferredSize(sizePInfoAndErr);
        lbErrSDT = new JLabel(" ");
        lbErrSDT.setForeground(Color.RED);
        lbErrSDT.setFont(fontErr);
        pnSDT.add(tfSDT);
        pnSDT.add(lbErrSDT);

        JPanel pnGhiChu = new JPanel();
        pnGhiChu.setLayout(new BoxLayout(pnGhiChu, BoxLayout.Y_AXIS));
        pnGhiChu.setPreferredSize(sizePInfoAndErr);
        lbErrGhiChu = new JLabel(" ");
        lbErrGhiChu.setForeground(Color.RED);
        lbErrGhiChu.setFont(fontErr);
        pnGhiChu.add(tfGhiChu);
        pnGhiChu.add(lbErrGhiChu);

        JPanel pnNhomLH = new JPanel();
        pnNhomLH.setLayout(new BoxLayout(pnNhomLH, BoxLayout.Y_AXIS));
        pnNhomLH.setPreferredSize(sizePInfoAndErr);
        lbErrNhomLH = new JLabel(" ");
        lbErrNhomLH.setForeground(Color.RED);
        lbErrNhomLH.setFont(fontErr);
        pnNhomLH.add(tfNhomLh);
        pnNhomLH.add(lbErrNhomLH);

        pnDienThongTin.add(lbHoten);
        pnDienThongTin.add(pnHoTen);
        pnDienThongTin.add(lbSDT);
        pnDienThongTin.add(pnSDT);
        pnDienThongTin.add(lbEmail);
        pnDienThongTin.add(pnEmail);
        pnDienThongTin.add(lbGhiChu);
        pnDienThongTin.add(pnGhiChu);
        pnDienThongTin.add(lbNhomLienHe);
        pnDienThongTin.add(pnNhomLH);

        pnThongTin.add(pnDienThongTin);

        JPanel pnControl = new JPanel(new FlowLayout(FlowLayout.CENTER));
        pnControl.setPreferredSize(new Dimension(0, 50));
        pnControl.add(btnXacNhan);
        pnControl.add(btnNhapLai);
        pnControl.add(btnQuayLai);

        lstLH = new PopupMenu();
        
        ArrayList<NhomLienHe> nhomLH = new ArrayList<NhomLienHe>();
        nhomLH = DanhBaDAO.getNhomLh();
        
        nhomLH.forEach(i -> {
            String nhom = i.getTenNhom();
            MenuItem mnuI = new MenuItem(nhom);
            mnuI.addActionListener(e -> {
                tfNhomLh.setText(nhom);
            });
            lstLH.add(mnuI);
        });
        
        con.add(pnTitle, BorderLayout.PAGE_START);
        con.add(pnThongTin, BorderLayout.CENTER);
        con.add(pnControl, BorderLayout.PAGE_END);
        con.add(lstLH);
    }

    private void handle() {
        tfNhomLh.addMouseListener(new MouseAdapter() {
            public void mouseReleased(MouseEvent me) {
                if (me.isPopupTrigger()) {
                    lstLH.show(tfNhomLh, 0, 22);
                }
            }
        });
        tfHoTen.addFocusListener(new FocusListener() {
            @Override
            public void focusLost(FocusEvent e) {
                if (tfHoTen.getText().equals("")) {
                    tfHoTen.setText("Nhập họ tên");
                    tfHoTen.setForeground(Color.LIGHT_GRAY);
                }
            }

            @Override
            public void focusGained(FocusEvent e) {
                if (tfHoTen.getText().equals("Nhập họ tên")) {
                    tfHoTen.setText("");
                    tfHoTen.setForeground(Color.BLACK);
                }
            }
        });
        tfEmail.addFocusListener(new FocusListener() {
            @Override
            public void focusLost(FocusEvent e) {
                if (tfEmail.getText().equals("")) {
                    tfEmail.setText("Nhập email: abc@example.com");
                    tfEmail.setForeground(Color.LIGHT_GRAY);
                }
            }

            @Override
            public void focusGained(FocusEvent e) {
                if (tfEmail.getText().equals("Nhập email: abc@example.com")) {
                    tfEmail.setText("");
                    tfEmail.setForeground(Color.BLACK);
                }
            }
        });
        tfSDT.addFocusListener(new FocusListener() {
            @Override
            public void focusLost(FocusEvent e) {
                if (tfSDT.getText().equals("")) {
                    tfSDT.setText("ex: 093249113");
                    tfSDT.setForeground(Color.LIGHT_GRAY);
                }
            }

            @Override
            public void focusGained(FocusEvent e) {
                if (tfSDT.getText().equals("ex: 093249113")) {
                    tfSDT.setText("");
                    tfSDT.setForeground(Color.BLACK);
                }
            }
        });
        tfGhiChu.addFocusListener(new FocusListener() {
            @Override
            public void focusLost(FocusEvent e) {
                if (tfGhiChu.getText().equals("")) {
                    tfGhiChu.setText("Ghi chú");
                    tfGhiChu.setForeground(Color.LIGHT_GRAY);
                }
            }

            @Override
            public void focusGained(FocusEvent e) {
                if (tfGhiChu.getText().equals("Ghi chú")) {
                    tfGhiChu.setText("");
                    tfGhiChu.setForeground(Color.BLACK);
                }
            }
        });
        tfNhomLh.addFocusListener(new FocusListener() {
            @Override
            public void focusLost(FocusEvent e) {
                if (tfNhomLh.getText().equals("")) {
                    tfNhomLh.setText("Nhóm liên hệ");
                    tfNhomLh.setForeground(Color.LIGHT_GRAY);
                }
            }

            @Override
            public void focusGained(FocusEvent e) {
                if (tfNhomLh.getText().equals("Nhóm liên hệ")) {
                    tfNhomLh.setText("");
                    tfNhomLh.setForeground(Color.BLACK);
                }
            }
        });
        btnNhapLai.addActionListener(ae -> {
            tfHoTen.setText("");
            tfEmail.setText("");
            tfGhiChu.setText("");
            tfNhomLh.setText("");
            tfSDT.setText("");

            lbErrEmail.setText(" ");
            lbErrSDT.setText(" ");
            lbErrGhiChu.setText(" ");
            lbErrHoten.setText(" ");
            lbErrNhomLH.setText(" ");

            tfHoTen.requestFocus();
        });
        btnQuayLai.addActionListener(ae -> {
            this.dispose();
        });

        btnXacNhan.addActionListener(ae -> {
            boolean kt = true;

            // kiểm tra nhập họ tên
            if (tfNhomLh.getText().trim().equals("") || tfNhomLh.getText().equals("Nhóm liên hệ")) {
                kt = false;
                lbErrNhomLH.setText("Vui lòng điền nhóm liên hệ");
                tfNhomLh.selectAll();
                tfNhomLh.requestFocus();
            } else {
                lbErrNhomLH.setText(" ");
            }

            // kiểm tra nhập email
            if (!isValidEmail(tfEmail.getText())) {
                kt = false;
                lbErrEmail.setText("Email không hợp lệ");
                tfEmail.selectAll();
                tfEmail.requestFocus();
            } else {
                lbErrEmail.setText(" ");
            }

            if (!isValidPhoneNumber(tfSDT.getText())) {
                kt = false;
                lbErrSDT.setText("Số điện thoại không hợp lệ");
                tfSDT.selectAll();
                tfSDT.requestFocus();
            } else {
                lbErrSDT.setText(" ");
                if (DanhBaDAO.isSDT(tfSDT.getText())) {
                    kt = false;
                    lbErrSDT.setText("Số điện thoại đã tồn tại");
                    tfSDT.selectAll();
                    tfSDT.requestFocus();
                }
            }

            // kiểm tra nhập họ tên
            if (tfHoTen.getText().trim().equals("") || tfHoTen.getText().equals("Nhập họ tên")) {
                kt = false;
                lbErrHoten.setText("Vui lòng điền họ tên");
                tfHoTen.selectAll();
                tfHoTen.requestFocus();
            } else {
                lbErrHoten.setText(" ");
            }

            if (kt == true) { // thêm danh bạ vào db
                if (DanhBaDAO.add(tfSDT.getText(), tfHoTen.getText(), tfEmail.getText(), tfGhiChu.getText(), tfNhomLh.getText())) {
                    JOptionPane.showMessageDialog(null, "Thêm danh bạ thành công");
                    ckAdd = true;
                    this.dispose();
                }
                else 
                    JOptionPane.showMessageDialog(null, "Thêm danh bạ thất bại, vui lòng thử lại");
            }

        });
    }

    /**
     * @return the ckAdd
     */
    public boolean isCkAdd() {
        return ckAdd;
    }
}
