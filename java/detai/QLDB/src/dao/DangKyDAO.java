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
    // kiểm tra xem username đã tồn tại hay chưa
    public static boolean ckUserName(String username) {
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        boolean ck = provider.isUId(username.trim());
        provider.close();
        return ck;
    }
    // cập nhật thông tin đăng ký của người dùng
    public static boolean capNhatThongTin(String ten, String email, String ngaySinh, String tenDN, String mk) {
        SQLServerProvider provider = new SQLServerProvider();
        try {
            provider.open();
            String insertThongTinCaNhan = "SET DATEFORMAT DMY INSERT INTO THONGTIN_NGUOIDUNG(TENND,EMAIL,NGAYSINH)"
                                    + "VALUES(N'" + ten.trim() + "','" + email.trim() + "','" + ngaySinh.trim() + "')";
            String insertDN = "INSERT INTO DANGNHAP(TENDANGNHAP,MATKHAU)"
                            + "VALUES('" + tenDN.trim() + "','" + MD5.getMD5(mk.trim()) + "')"; // chuyển mật khẩu thành mã MD5 để bảo mật hơn

            provider.executeUpdate(insertThongTinCaNhan); // cập nhật thông tin cá nhân
            provider.executeUpdate(insertDN); // cập nhật thông tin đăng nhập

            String updateMaNDN_CaNhan = "UPDATE THONGTIN_NGUOIDUNG SET MANDN='" + provider.getMaNDN(tenDN.trim()) + "'"
                    + " WHERE MAND=(SELECT TOP(1) MAND FROM THONGTIN_NGUOIDUNG ORDER BY MAND DESC)";
            provider.executeUpdate(updateMaNDN_CaNhan);
            provider.close();
        } catch (Exception e) { // khi gặp lỗi sẽ xóa thông tin đăng ký đó
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
