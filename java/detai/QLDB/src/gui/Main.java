/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui;

import dao.DangNhapDAO;

/**
 *
 * @author Admin
 */
public class Main {

    public static String iconImage = "image/icon.png";
    public static String personImage = "image/person.png";
    public static String saoLuuDangNhap = "saoLuuDangNhap.txt";
    public static String imageVCard = "image/vcard.png";

    public static void main(String[] args) {
        try {
            java.io.FileInputStream fis = new java.io.FileInputStream(Main.saoLuuDangNhap);
            java.io.InputStreamReader isr = new java.io.InputStreamReader(fis, "UTF-8");
            java.io.BufferedReader br = new java.io.BufferedReader(isr);
            String thongTinDangNhap = br.readLine();
            br.close();
            isr.close();
            fis.close();
            if (thongTinDangNhap == "") {
                new gui.auth.Login().setVisible(true);
            } 
            else {
                String[] splitThongTin = thongTinDangNhap.split("-");
                DangNhapDAO.setInfoUser(splitThongTin[0]);
                new gui.mainframe.DanhBa_GUI().setVisible(true);
            }

        } catch (Exception e) {
            new gui.auth.Login().setVisible(true);
            // e.printStackTrace();
        }
    }

    // debug sql
//    public static void main(String[] args) {
//        VCard vCard = new VCard();
//        vCard.setName("Believe in the eternal");
//        vCard.setAddress("street 1, xxxx address");
//        vCard.setCompany("company Inc.");
//        vCard.setPhoneNumber("+xx/xx.xx.xx");
//        vCard.setTitle("title");
//        vCard.setEmail("info@gmail.com");
//        vCard.setWebsite("https://google.com");
//
//        ByteArrayOutputStream bout =
//                QRCode.from(vCard)
//                        .withCharset("utf-8")
//                        .withSize(250, 250)
//                        .to(ImageType.PNG)
//                        .stream();
//
//        try {
//            OutputStream out = new FileOutputStream("qr-code-vcard.png");
//            bout.writeTo(out);
//            out.flush();
//            out.close();
//
//        } catch (FileNotFoundException e){
//            e.printStackTrace();
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//    }
}
