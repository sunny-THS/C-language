/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import dataprovider.SQLServerProvider;
import java.sql.ResultSet;
import java.text.SimpleDateFormat;
import pojo.ThongTinNguoiDung;


/**
 *
 * @author Admin
 */
public class DangNhapDAO {
    private static ThongTinNguoiDung infoUser = new ThongTinNguoiDung();
    
    // cập nhật trạng thái hoạt động của người dùng
    public static boolean dangXuat() {
        String updateTT = "UPDATE DANGNHAP SET TRANGTHAI='DISCONNECT' WHERE TENDANGNHAP='" + infoUser.getTenDN() + "'";
        SQLServerProvider provider = new SQLServerProvider();
        try {
            provider.open();
            provider.executeUpdate(updateTT); // cập nhật trạng thái
            provider.close();
        } catch (Exception e) {
            return false;
        }
        
        return true;
    }
    
    // kiểm tra thông tin đăng nhập có chính xác không
    public static boolean isDangNhap(String uid, String pwd) {
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        boolean ckDN = provider.isDangNhap(uid, pwd);
        infoUser.setTenDN(uid);
        provider.close();
        return ckDN;
    }

    /**
     * @return the infoUser
     */
    public static ThongTinNguoiDung getInfoUser() {
        return infoUser;
    }

    /**
     * @param aInfoUser the infoUser to set
     */
    public static void setInfoUser(String username) {
        ThongTinNguoiDung aInfoUser = new ThongTinNguoiDung();
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        String sql = "select * from DANGNHAP join THONGTIN_NGUOIDUNG\n" +
                     "on DANGNHAP.MANDN=THONGTIN_NGUOIDUNG.MANDN\n" +
                     "where TENDANGNHAP = '"+ username +"'";
        ResultSet res = provider.executeQuery(sql);
        try {
            if(res.next()) {
                aInfoUser.setMaNDN(res.getString("MANDN"));
                aInfoUser.setMaND(res.getString("MAND"));
                aInfoUser.setTenND(res.getNString("TENND"));
                aInfoUser.setTenDN(res.getString("TENDANGNHAP"));
                aInfoUser.setEmail(res.getString("EMAIL"));
                aInfoUser.setNgaySinh(res.getDate("NGAYSINH"));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        provider.close();
        infoUser = aInfoUser;
    }
    // cập nhật thông tin của người dùng
    public static void setInfoUser(ThongTinNguoiDung ttnd) {
        String kieuDinhDang = "dd/MM/yyyy";
        SimpleDateFormat df = new SimpleDateFormat(kieuDinhDang);
        df.setLenient(false); // set false để kiểm tra tính hợp lệ của date. VD: tháng 2 phải có 28-29 ngày, năm có 12 tháng,....
        
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        String updateThongTinCaNhan = "SET DATEFORMAT DMY UPDATE THONGTIN_NGUOIDUNG SET TENND="
                                    + "N'" + ttnd.getTenND().trim() + "', EMAIL='" + ttnd.getEmail().trim() + "', NGAYSINH='" + df.format(ttnd.getNgaySinh()) + "' "
                                    + "WHERE MANDN='" + provider.getMaNDN(DangNhapDAO.getInfoUser().getTenDN()) + "'";

        provider.executeUpdate(updateThongTinCaNhan);
        provider.close();
        infoUser = ttnd;
    }
}
