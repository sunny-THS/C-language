package main;

import java.awt.*;
import javax.swing.*;

public class TaoFrame extends JFrame {
  public TaoFrame(String title) {
    this.setTitle(title);
    this.setSize(300, 200);
    this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    this.setLocationRelativeTo(null);
    JButton btnThoat = new JButton("Thoát");
    getContentPane().add(btnThoat);
  }
  public static void main(String[] args) {
      sqlserverprovider.SQLServerProvider provider = new sqlserverprovider.SQLServerProvider();
      provider.open();
      provider.close();
      new TaoFrame("vd tạo cửa sổ 1").setVisible(true);
  }
}
