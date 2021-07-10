/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pojo;

import java.awt.Image;
import java.io.*;
import javax.swing.ImageIcon;
import net.glxn.qrgen.core.image.ImageType;
import net.glxn.qrgen.javase.QRCode;

/**
 *
 * @author Admin
 */
public class VCardDanhBa {

    private String tenND, email, sdt;

    public VCardDanhBa(String tenND, String email, String sdt) {
        this.tenND = tenND;
        this.email = email;
        this.sdt = sdt;
    }

    public VCardDanhBa() {
    }

    public Image getImageVCard() {
        ImageIcon img = new ImageIcon(gui.Main.imageVCard);
        Image designImage = img.getImage();
        Image imageVcard = designImage.getScaledInstance(180, 180, Image.SCALE_SMOOTH);// điều chỉnh size ảnh
        return imageVcard;
    }

    public void createVCart() {
        String[] splitName = this.tenND.split(" ");
        String ten = "", dem = "", ho = "";

        int len = splitName.length;
        if (len > 1) {
            ten = splitName[len - 1].trim();
            dem = splitName[len - 2].trim();
            ho = this.tenND.split(dem)[0].trim();
        }

        String vCard = "BEGIN:VCARD\n"
                + "VERSION:3.0\n"
                + "FN:" + this.tenND + "\n"
                + "N:" + ten + ";" + dem + ";" + ho + ";;\n"
                + "TEL;TYPE=CELL:" + this.sdt + "\n"
                + "EMAIL:" + this.email + "\n"
                + "END:VCARD";
        
        ByteArrayOutputStream bout = QRCode.from(vCard)
                .withCharset("UTF-8")
                .withSize(250, 250)
                .to(ImageType.PNG)
                .stream();

        try {
            OutputStream out = new FileOutputStream(gui.Main.imageVCard);
            bout.writeTo(out);
            out.flush();
            out.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * @return the tenND
     */
    public String getTenND() {
        return tenND;
    }

    /**
     * @param tenND the tenND to set
     */
    public void setTenND(String tenND) {
        this.tenND = tenND;
    }

    /**
     * @return the email
     */
    public String getEmail() {
        return email;
    }

    /**
     * @param email the email to set
     */
    public void setEmail(String email) {
        this.email = email;
    }

    /**
     * @return the sdt
     */
    public String getSdt() {
        return sdt;
    }

    /**
     * @param sdt the sdt to set
     */
    public void setSdt(String sdt) {
        this.sdt = sdt;
    }
}
