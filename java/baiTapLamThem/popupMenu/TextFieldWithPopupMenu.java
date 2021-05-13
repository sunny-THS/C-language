package popupMenu;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class TextFieldWithPopupMenu extends JFrame {
  JTextField textField;
  public TextFieldWithPopupMenu() {
    super("ví dụ TextFieldWithPopupMenu");
    initComponents();
  }
  public void initComponents() {
    this.setSize(500, 350);
    this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
    this.setLocationRelativeTo(null);

    Container con = getContentPane();
    con.setLayout(new FlowLayout());
    // 1. Let's add the initial popup to the text field.
    textField = new JTextField(20);

    JPopupMenu popup = new JPopupMenu();
    popup.setPreferredSize(new Dimension(220, 100));
    JScrollPane 
    textField.add(popup);
    String[] a = {
      "aaaaaaaaaaaa",
      "dddddddddddd",
      "bbbbbbbbbbbb"
    };

    for(String i : a) {
      JMenuItem mnuItem = new JMenuItem(i);
      mnuItem.addActionListener(ae -> {
        textField.setText(i);
      });
      popup.add(mnuItem);
    }

    con.add(textField);
    con.add(popup);

    textField.addMouseListener(new MouseListener(){

      @Override
      public void mouseReleased(MouseEvent e) {
        if (e.isPopupTrigger())
          popup.show(textField, 0, 20);
      }

      @Override
      public void mousePressed(MouseEvent e) {

      }

      @Override
      public void mouseExited(MouseEvent e) {

      }

      @Override
      public void mouseEntered(MouseEvent e) {

      }

      @Override
      public void mouseClicked(MouseEvent e) {

      }
    });
  }
  public static void main(String[] args) {
    new TextFieldWithPopupMenu().setVisible(true);
  }
}
