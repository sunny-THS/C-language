/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import dataprovider.SQLServerProvider;
import gui.auth.MD5;

/**
 *
 * @author Admin
 */
public class DangKyDAO {
    public static boolean ckUserName(String username) {
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        boolean ck = provider.isUId(username.trim());
        provider.close();
        return ck;
    }
    public static boolean capNhatThongTin(String ten, String email, String ngaySinh, String tenDN, String mk) {
        SQLServerProvider provider = new SQLServerProvider();
        try {
            provider.open();
            String insertThongTinCaNhan = "SET DATEFORMAT DMY INSERT INTO THONGTIN_NGUOIDUNG(TENND,EMAIL,NGAYSINH)"
                                    + "VALUES(N'" + ten.trim() + "','" + email.trim() + "','" + ngaySinh.trim() + "')";
            String insertDN = "INSERT INTO DANGNHAP(TENDANGNHAP,MATKHAU)"
                            + "VALUES('" + tenDN.trim() + "','" + MD5.getMD5(mk.trim()) + "')";

            provider.executeUpdate(insertThongTinCaNhan);
            provider.executeUpdate(insertDN);

            String updateMaNDN_CaNhan = "UPDATE THONGTIN_NGUOIDUNG SET MANDN='" + provider.getMaNDN(tenDN.trim()) + "'"
                    + " WHERE MAND=(SELECT TOP(1) MAND FROM THONGTIN_NGUOIDUNG ORDER BY MAND DESC)";
            provider.executeUpdate(updateMaNDN_CaNhan);
            provider.close();
        } catch (Exception e) {
            e.printStackTrace();
            String sqlDelDN = "delete from DANGNHAP where TENDANGNHAP = '" + tenDN.trim() + "'";
            String sqlDelTTND = "delete from THONGTIN_NGUOIDUNG where MANDN='" + provider.getMaNDN(tenDN.trim()) + "'";
            provider.open();
            provider.executeUpdate(sqlDelTTND);
            provider.executeUpdate(sqlDelDN);
            provider.close();
            return false;
        }
        return true;
    }
}
