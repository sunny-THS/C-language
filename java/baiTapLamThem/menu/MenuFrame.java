package menu;

import javax.swing.*;

public class MenuFrame extends JFrame {

  public MenuFrame() {
    super("ví dụ menu");
    initCompanents();
  }

  public static void main(String[] args) {
    new MenuFrame().setVisible(true);
  }
  void initCompanents() {
    this.setSize(500, 350);
    this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
    this.setLocationRelativeTo(null);

    JMenuBar mnuBar = new JMenuBar();
    this.setJMenuBar(mnuBar);

    JMenu mnuFile = new JMenu("File");
    JMenuItem mnuIExit = new JMenuItem("Exit");
    mnuIExit.addActionListener(ae -> {
      int a = JOptionPane.showConfirmDialog(
        null,
        "Bạn có muốn thoát không?",
        "Thoát",
        JOptionPane.YES_NO_CANCEL_OPTION,
        JOptionPane.QUESTION_MESSAGE
      );
      if (a == JOptionPane.YES_OPTION)
        System.exit(0);
    });
    mnuFile.add(mnuIExit);
    mnuBar.add(mnuFile);
  }
}
