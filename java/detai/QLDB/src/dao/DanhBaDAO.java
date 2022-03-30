/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import dataprovider.SQLServerProvider;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.Vector;
import pojo.DanhBa;
import pojo.NhomLienHe;

/**
 *
 * @author Admin
 */
public class DanhBaDAO {
    public static boolean xoa(DanhBa danhBa) {
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        String delDanhBa = "DELETE THONGTINDANHBA WHERE MADB='" + danhBa.getMadb() + "' AND MANDN='" + provider.getMaNDN(DangNhapDAO.getInfoUser().getTenDN()) + "'";
        int ud = provider.executeUpdate(delDanhBa);
        provider.close();
        return ud > 0 ? true : false;
    }
    
    public static boolean capNhat(DanhBa danhBa) {
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        String updateDanhBa = "UPDATE DANHBA SET SDT="
                            + "'" + danhBa.getSdt().trim() + "', EMAIL='" + danhBa.getEmail().trim() + "', TENDANHBA=N'" + danhBa.getTenLH().trim() + "', GHICHU=N'" + danhBa.getGhiChu().trim() + "' "
                            + "WHERE MADB='" + danhBa.getMadb() + "'";

        int ud = provider.executeUpdate(updateDanhBa);
        provider.close();
        return ud > 0 ? true : false;
    }
    
    public static boolean isSDT(String sdt) {
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        boolean ck = provider.isSDT(provider.getMaNDN(DangNhapDAO.getInfoUser().getTenDN()), sdt);
        provider.close();
        return ck;
    }
    
    public static boolean add(String sdt, String tenDB, String email, String ghiChu, String nhomLH) {
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        try {
            String insertDanhBa = "INSERT INTO DANHBA(SDT, TENDANHBA, EMAIL, GHICHU) "
                                + "VALUES('" + sdt.trim() + "',N'" + tenDB.trim() + "','" + email.trim() + "',N'" + ghiChu.trim() + "')";
            String insertThongTinDanhBa = "INSERT INTO THONGTINDANHBA(MANDN)"
                                        + " VALUES('" + provider.getMaNDN(DangNhapDAO.getInfoUser().getTenDN()) + "')";
            String insertNhomLienHe = "INSERT INTO NHOMLIENHE(TENNHOMLH) VALUES(N'" + nhomLH.trim() + "')";

            String updateDanhBaWhenNhomIsNull = "UPDATE DANHBA SET MANHOMLH=(SELECT TOP(1) MANHOM FROM NHOMLIENHE ORDER BY MANHOM DESC) WHERE MADB=(SELECT TOP(1)MADB FROM DANHBA ORDER BY MADB DESC)";

            provider.executeUpdate(insertDanhBa); // thêm một liên hệ mới
            provider.executeUpdate(insertThongTinDanhBa); // cập nhật thông tin của liên hệ đó

            // check xem đã có nhóm liên hệ đó chưa
            if (!provider.isNhomLienHe(provider.getMaNDN(DangNhapDAO.getInfoUser().getTenDN()), nhomLH.trim())) { // chưa nhóm lh này
                provider.executeUpdate(insertNhomLienHe); // thêm nhóm lh đó
                provider.executeUpdate(updateDanhBaWhenNhomIsNull); // update nhóm lh cho danh bạ
            } else {
                String updatePhoneBookWhenGroupIsNotNull = "UPDATE DANHBA SET MANHOMLH='" + provider.getMaNLH(provider.getMaNDN(DangNhapDAO.getInfoUser().getTenDN()), nhomLH.trim()) + "' WHERE MADB=(SELECT TOP(1)MADB FROM DANHBA ORDER BY MADB DESC)";
                provider.executeUpdate(updatePhoneBookWhenGroupIsNotNull);
            }
            provider.close();
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            provider.close();
            return false;
        }
    }
    // tìm thông tin danh bạ
    public static Vector<DanhBa> timDanhBa(String tenDB) {
        Vector<DanhBa> nhomDB = new Vector<DanhBa>();
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        try {
            String selectDB = "SELECT DANHBA.*, NGAYLUU FROM NHOMLIENHE INNER JOIN DANHBA ON NHOMLIENHE.MANHOM=DANHBA.MANHOMLH INNER JOIN THONGTINDANHBA ON DANHBA.MADB=THONGTINDANHBA.MADB WHERE LOWER(TENDANHBA)LIKE N'" + tenDB.toLowerCase() + "%' AND MANDN='" + provider.getMaNDN(DangNhapDAO.getInfoUser().getTenDN()) + "'";
            ResultSet res = provider.executeQuery(selectDB);
            while (res.next()) {
                nhomDB.add(new DanhBa(res.getString("SDT"), res.getNString("TENDANHBA"), res.getString("EMAIL"), res.getNString("GHICHU"), res.getString("MANHOMLH"), res.getDate("NGAYLUU"), res.getString("MADB")));
            }
            provider.close();
            return nhomDB;
        } catch (Exception e) {
            provider.close();
            return null;
        }
    }
    // khôi phục danh bạ được xóa sau khi sao lưu
    public static boolean khoiPhuc() {
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        try {
            String selectSaoLuu = "SELECT * FROM SAOLUUDANHBA WHERE MANDN='" + provider.getMaNDN(DangNhapDAO.getInfoUser().getTenDN()) + "'";
            ResultSet res = provider.executeQuery(selectSaoLuu);
            while (res.next()) {
                String ma = res.getString("MADB");
                if (!provider.isMaDanhBa(provider.getMaNDN(DangNhapDAO.getInfoUser().getTenDN()), ma)) {
                    String khoiPhuc = "INSERT INTO THONGTINDANHBA VALUES('" + res.getString("MANDN") + "', '" + ma + "', GETDATE())";
                    provider.executeUpdate(khoiPhuc);
                }
            }
            provider.close();
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            provider.close();
            return false;
        }
    }
    // sao lưu danh bạ
    public static boolean saoLuu() {
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        try {
            String delSaoLuu = "DELETE SAOLUUDANHBA WHERE MANDN='" + provider.getMaNDN(DangNhapDAO.getInfoUser().getTenDN()) + "'";
            String selectDanhBa = "SELECT THONGTINDANHBA.* FROM NHOMLIENHE INNER JOIN DANHBA ON NHOMLIENHE.MANHOM=DANHBA.MANHOMLH INNER JOIN THONGTINDANHBA ON DANHBA.MADB=THONGTINDANHBA.MADB WHERE MANDN='" + provider.getMaNDN(DangNhapDAO.getInfoUser().getTenDN()) + "'";
            ResultSet res = provider.executeQuery(selectDanhBa);
            provider.executeUpdate(delSaoLuu);
            while (res.next()) {
                String insertSaoLuu = "INSERT INTO SAOLUUDANHBA VALUES('" + res.getString("MANDN") + "', '" + res.getString("MADB") + "', GETDATE())";
                provider.executeUpdate(insertSaoLuu);
            }
            provider.close();
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            provider.close();
            return false;
        }
    }
    // lấy thông tin của danh bạ
    public static Vector<DanhBa> getDanhBa() {
        Vector<DanhBa> nhomDB = new Vector<DanhBa>();
        
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        
        try {
            String selectDB = "SELECT DANHBA.*, NGAYLUU FROM NHOMLIENHE INNER JOIN DANHBA ON NHOMLIENHE.MANHOM=DANHBA.MANHOMLH INNER JOIN THONGTINDANHBA ON DANHBA.MADB=THONGTINDANHBA.MADB WHERE MANDN='" + provider.getMaNDN(DangNhapDAO.getInfoUser().getTenDN()) + "'";
            ResultSet res = provider.executeQuery(selectDB);
            while (res.next()) {
                nhomDB.add(new DanhBa(res.getString("SDT"), res.getNString("TENDANHBA"), res.getString("EMAIL"), res.getNString("GHICHU"), res.getString("MANHOMLH"), res.getDate("NGAYLUU"), res.getString("MADB")));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        
        provider.close();
        return nhomDB;
    }
    // lấy thông tin của các nhóm liên hệ
    public static ArrayList<NhomLienHe> getNhomLh () {
        ArrayList<NhomLienHe> nhomLH = new ArrayList<NhomLienHe>();
        
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        try {
            String selectNhLH = "SELECT DISTINCT NHOMLIENHE.* FROM NHOMLIENHE INNER JOIN DANHBA ON NHOMLIENHE.MANHOM=DANHBA.MANHOMLH INNER JOIN THONGTINDANHBA ON DANHBA.MADB=THONGTINDANHBA.MADB WHERE MANDN='" + provider.getMaNDN(DangNhapDAO.getInfoUser().getTenDN()) + "'";
            ResultSet res = provider.executeQuery(selectNhLH);
            while (res.next()) {
                nhomLH.add(new NhomLienHe(res.getString("MANHOM"), res.getNString("TENNHOMLH")));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        
        provider.close();
        return nhomLH;
    }
    
    public static boolean isSaoLuu() {
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        String selectSaoLuu = "SELECT * FROM SAOLUUDANHBA WHERE MANDN='" + provider.getMaNDN(DangNhapDAO.getInfoUser().getTenDN()) + "'";
        try {
            ResultSet res = provider.executeQuery(selectSaoLuu);
            boolean ck = res.next();
            provider.close();
            return ck;
        } catch (Exception e) {
            e.printStackTrace();
            provider.close();
            return true;
        }
    }
}
