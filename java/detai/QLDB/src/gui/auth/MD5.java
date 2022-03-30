/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui.auth;

import java.math.BigInteger;
import java.security.MessageDigest;

/**
 *
 * @author Admin
 * Dùng MD5 để mã hóa mật khẩu của người dùng
 * Để tăng tinh bảo mật cho tài khoản
 */
public class MD5 {

    public static String getMD5(String pwd) {
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            
            byte[] msgDigest = md.digest(pwd.getBytes()); // băm chuỗi
            
            BigInteger no = new BigInteger(1, msgDigest); // chuyển mảng băm
            
            String hashText = no.toString(16); // chuyển thành chuỗi hex
            while (hashText.length() < 32) {
                hashText = '0' + hashText;
            }
            return hashText;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}
