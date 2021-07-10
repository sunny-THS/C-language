/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui.mainframe;

import java.awt.Component;
import java.awt.Font;
import java.awt.Image;
import javax.swing.DefaultListCellRenderer;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.border.EmptyBorder;

class PhoneBookListRenderer extends DefaultListCellRenderer {

    Font font = new Font("Arial", Font.BOLD, 20);

    // format for jlist
    @Override
    public Component getListCellRendererComponent(JList list, Object value, int index, boolean isSelected, boolean cellHasFocus) {
        JLabel label = (JLabel) super.getListCellRendererComponent(list, value, index, isSelected, cellHasFocus);

        label.setHorizontalTextPosition(JLabel.RIGHT);
        label.setFont(font);
        label.setBorder(new EmptyBorder(5, 5, 0, 5));

        Image imageIcon = new ImageIcon(gui.Main.personImage).getImage();
        Image icon = imageIcon.getScaledInstance(35, 35, Image.SCALE_SMOOTH);
        label.setIcon(new ImageIcon(icon));

        return label;
    }
}
