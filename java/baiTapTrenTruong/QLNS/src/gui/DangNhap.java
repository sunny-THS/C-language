/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package gui;

import dataprovider.SQLServerProvider;
import java.sql.ResultSet;
import javax.swing.JOptionPane;

/**
 *
 * @author Admin
 */
public class DangNhap extends javax.swing.JDialog {
    
    private String strTenDN, strTenND, strMK;
    private boolean kqDN;

    /** Creates new form DangNhap */
    public DangNhap(java.awt.Frame parent, boolean modal) {
        super(parent, modal);
        initComponents();
        this.setSize(420, 230);
        this.setTitle("Đăng nhập");
        this.setLocationRelativeTo(parent);
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        lbDN = new javax.swing.JLabel();
        lbPW = new javax.swing.JLabel();
        tfDN = new javax.swing.JTextField();
        tfPW = new javax.swing.JPasswordField();
        btnDN = new javax.swing.JButton();
        btnDK = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        jPanel1.setBorder(javax.swing.BorderFactory.createTitledBorder(null, "Thông tin đăng nhập", javax.swing.border.TitledBorder.DEFAULT_JUSTIFICATION, javax.swing.border.TitledBorder.TOP));

        lbDN.setText("Tên đăng nhập: ");

        lbPW.setText("Mật khẩu: ");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(lbDN)
                    .addComponent(lbPW))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(tfDN, javax.swing.GroupLayout.DEFAULT_SIZE, 190, Short.MAX_VALUE)
                    .addComponent(tfPW))
                .addContainerGap(29, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(lbDN)
                    .addComponent(tfDN, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(lbPW)
                    .addComponent(tfPW, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        btnDN.setText("Đăng nhập");
        btnDN.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnDNActionPerformed(evt);
            }
        });

        btnDK.setText("Đăng ký");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(29, 29, 29)
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(33, Short.MAX_VALUE))
            .addGroup(layout.createSequentialGroup()
                .addGap(54, 54, 54)
                .addComponent(btnDN)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(btnDK)
                .addGap(61, 61, 61))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(24, 24, 24)
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnDN)
                    .addComponent(btnDK))
                .addContainerGap(46, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnDNActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnDNActionPerformed
        try {
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            String sql = String.format("Select * from NguoiDung where TenDangNhap='%s' And MatKhau='%s'", 
                    this.getTfDN().getText(),
                    this.getTfPW().getText()
            );
            ResultSet rs = provider.executeQuery(sql);
            while (rs.next()) {
                this.setStrTenDN(rs.getString("TenDangNhap"));
                this.setStrTenND(rs.getString("HoTen"));
                this.setStrMK(rs.getString("MatKhau"));
                this.setKqDN(true);
            }
            provider.close();
            if (this.isKqDN()) 
                this.setVisible(false);
            else
                JOptionPane.showConfirmDialog(lbDN, "Tên đăng nhập hoặc mật khẩu không đúng");
        } catch (Exception e) {
            JOptionPane.showConfirmDialog(lbDN, e.getMessage());
        }
    }//GEN-LAST:event_btnDNActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(DangNhap.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(DangNhap.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(DangNhap.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(DangNhap.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the dialog */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                DangNhap dialog = new DangNhap(new javax.swing.JFrame(), true);
                dialog.addWindowListener(new java.awt.event.WindowAdapter() {
                    @Override
                    public void windowClosing(java.awt.event.WindowEvent e) {
                        System.exit(0);
                    }
                });
                dialog.setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnDK;
    private javax.swing.JButton btnDN;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JLabel lbDN;
    private javax.swing.JLabel lbPW;
    private javax.swing.JTextField tfDN;
    private javax.swing.JPasswordField tfPW;
    // End of variables declaration//GEN-END:variables

    /**
     * @return the strTenDN
     */
    public String getStrTenDN() {
        return strTenDN;
    }

    /**
     * @param strTenDN the strTenDN to set
     */
    public void setStrTenDN(String strTenDN) {
        this.strTenDN = strTenDN;
    }

    /**
     * @return the strTenND
     */
    public String getStrTenND() {
        return strTenND;
    }

    /**
     * @param strTenND the strTenND to set
     */
    public void setStrTenND(String strTenND) {
        this.strTenND = strTenND;
    }

    /**
     * @return the strMK
     */
    public String getStrMK() {
        return strMK;
    }

    /**
     * @param strMK the strMK to set
     */
    public void setStrMK(String strMK) {
        this.strMK = strMK;
    }

    /**
     * @return the kqDN
     */
    public boolean isKqDN() {
        return kqDN;
    }

    /**
     * @param kqDN the kqDN to set
     */
    public void setKqDN(boolean kqDN) {
        this.kqDN = kqDN;
    }

    /**
     * @return the btnDK
     */
    public javax.swing.JButton getBtnDK() {
        return btnDK;
    }

    /**
     * @param btnDK the btnDK to set
     */
    public void setBtnDK(javax.swing.JButton btnDK) {
        this.btnDK = btnDK;
    }

    /**
     * @return the btnDN
     */
    public javax.swing.JButton getBtnDN() {
        return btnDN;
    }

    /**
     * @param btnDN the btnDN to set
     */
    public void setBtnDN(javax.swing.JButton btnDN) {
        this.btnDN = btnDN;
    }

    /**
     * @return the jPanel1
     */
    public javax.swing.JPanel getjPanel1() {
        return jPanel1;
    }

    /**
     * @param jPanel1 the jPanel1 to set
     */
    public void setjPanel1(javax.swing.JPanel jPanel1) {
        this.jPanel1 = jPanel1;
    }

    /**
     * @return the lbDN
     */
    public javax.swing.JLabel getLbDN() {
        return lbDN;
    }

    /**
     * @param lbDN the lbDN to set
     */
    public void setLbDN(javax.swing.JLabel lbDN) {
        this.lbDN = lbDN;
    }

    /**
     * @return the lbPW
     */
    public javax.swing.JLabel getLbPW() {
        return lbPW;
    }

    /**
     * @param lbPW the lbPW to set
     */
    public void setLbPW(javax.swing.JLabel lbPW) {
        this.lbPW = lbPW;
    }

    /**
     * @return the tfDN
     */
    public javax.swing.JTextField getTfDN() {
        return tfDN;
    }

    /**
     * @param tfDN the tfDN to set
     */
    public void setTfDN(javax.swing.JTextField tfDN) {
        this.tfDN = tfDN;
    }

    /**
     * @return the tfPW
     */
    public javax.swing.JPasswordField getTfPW() {
        return tfPW;
    }

    /**
     * @param tfPW the tfPW to set
     */
    public void setTfPW(javax.swing.JPasswordField tfPW) {
        this.tfPW = tfPW;
    }

}
