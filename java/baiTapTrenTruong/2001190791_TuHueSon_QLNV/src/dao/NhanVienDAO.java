/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import dataprovider.SQLServerProvider;
import java.sql.ResultSet;
import java.util.ArrayList;
import pojo.NhanVien;

/**
 *
 * @author Admin
 */
public class NhanVienDAO {
    public static ArrayList<NhanVien> getListNV() {
        ArrayList<NhanVien> ds = new ArrayList<NhanVien>();
        try {
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            String sql = "select * from nhanvien";
            ResultSet rs = provider.executeQuery(sql);
            while (rs.next()) {
                ds.add(new NhanVien(
                        rs.getInt("MaNV"),
                        rs.getInt("Phong"),
                        rs.getString("HoTen"),
                        rs.getString("Phai"),
                        rs.getDate("NgaySinh"),
                        rs.getFloat("Luong"),
                        rs.getBoolean("TrangThai")
                ));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return ds;
    }
    public static NhanVien getNhanVien(String maNV) {
        NhanVien nv = null;
        try {
            String sql = String.format("Select * from NhanVien where MaNV='%s'", maNV);
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            ResultSet rs = provider.executeQuery(sql);
            if (rs.next())
                nv = new NhanVien(
                        rs.getInt("MaNV"),
                        rs.getInt("Phong"),
                        rs.getString("HoTen"),
                        rs.getString("Phai"),
                        rs.getDate("NgaySinh"),
                        rs.getFloat("Luong"),
                        rs.getBoolean("TrangThai")
                );
            provider.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return nv;
    }
    public static boolean ckNhanVien(String hoTen) {
        try {
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            String sql = String.format("Select * from NhanVien where HoTen='%s'", hoTen);
            ResultSet rs = provider.executeQuery(sql);
            provider.close();
            return rs.next();
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }
    public static boolean themNhanVien(NhanVien nv) {
        boolean b = false;
        try {
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            String sql = String.format(
                    "insert NhanVien(Hoten, Luong, Manv, NgaySinh, Phai, Phong) "
                  + "values('%s','%f','%s','%s','%s','%d')",
                    nv.getHoTen(),
                    nv.getLuong(),
                    nv.getMaNV(),
                    nv.getNgaySinh(),
                    nv.getPhai(),
                    nv.getPhong()
            );
            int n = provider.executeUpdate(sql);
            if (n>0) 
                b = true;
            provider.close();
        } catch (Exception e) {
        }
        return b;
    }
    public static boolean xoaNhanVien(String maNV) {
        boolean b = false;
        try {
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            String sql = String.format(
                    "delete from NhanVien where maNV='%s'",
                    maNV
            );
            int n = provider.executeUpdate(sql);
            if (n>0) 
                b = true;
            provider.close();
        } catch (Exception e) {
        }
        return b;
    }
    public static boolean capNhatNhanVien(NhanVien nv) {
        boolean b = false;
        try {
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            String sql = String.format(
                    "update NhanVien "
                  + "set Hoten    = '%s' , "
                      + "Luong    = %f   , "
                      + "NgaySinh = '%s' , "
                      + "Phai     = '%s' , "
                      + "Phong    = %d    "
                  + "Where MaNV = '%s'",
                    nv.getHoTen(),
                    nv.getLuong(),
                    nv.getNgaySinh(),
                    nv.getPhai(),
                    nv.getPhong(),
                    nv.getMaNV()
            );
            int n = provider.executeUpdate(sql);
            if (n>0) 
                b = true;
            provider.close();
        } catch (Exception e) {
        }
        return b;
    }
}
