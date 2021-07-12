/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import dataprovider.SQLServerProvider;
import java.sql.ResultSet;
import java.util.ArrayList;
import pojo.PhongBan;

/**
 *
 * @author Admin
 */
public class PhongBanDAO {
    
    public static ArrayList<PhongBan> layDanhSachPhongBan() {
        ArrayList<PhongBan> dsPB = new ArrayList<PhongBan>();
        try {
            String sql = "select * from PhongBan";
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            ResultSet rs = provider.executeQuery(sql);
            while(rs.next()) {
                PhongBan pb = new PhongBan();
                pb.setMaPh(rs.getInt("MaPHG"));
                pb.setTenPh(rs.getString("TenPHG"));
                dsPB.add(pb);
            }
            provider.close();
        } catch (Exception e) {
        }
        return dsPB;
    }
    public static  ArrayList<PhongBan> timKiemPhongBanTheoTen(String tenPB) {
        ArrayList<PhongBan> dsPB = new ArrayList<PhongBan>();
        try {
            String sql = "select * from PhongBan where tenphg like '%" + tenPB + "%'";
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            ResultSet rs = provider.executeQuery(sql);
            while (rs.next()) {
                PhongBan pb = new PhongBan();
                pb.setMaPh(rs.getInt("MaPHG"));
                pb.setTenPh(rs.getString("TenPHG"));
                dsPB.add(pb);
            }
            provider.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return dsPB;
    }
    public static boolean themPhongBan(PhongBan pb) {
        boolean kq = false;
        String sql = String.format("Insert PhongBan(TenPHG) values('%s')", pb.getTenPh());
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        int n = provider.executeUpdate(sql);
        if (n>0)
            kq = true;
        provider.close();
        return kq;
    }
    public static boolean xoaPhongBan(String maPB) {
        boolean kq = false;
        String sql = String.format("Delete from PhongBan Where MaPHG=%d", maPB);
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        int n = provider.executeUpdate(sql);
        if (n>0)
            kq = true;
        provider.close();
        return kq;
    }
    public static boolean capNhatPhongBan(PhongBan pb) {
        boolean kq = false;
        String sql = String.format("Update PhongBan set TenPHG='%s' "
                                   + "where MaPHG=%d", pb.getTenPh(), pb.getMaPh());
        SQLServerProvider provider = new SQLServerProvider();
        provider.open();
        int n = provider.executeUpdate(sql);
        if (n>0)
            kq = true;
        provider.close();
        return kq;
    }
    public static PhongBan layPhongBan(int maPB) {
        PhongBan pb = null;
        try {
            String sql = "Select * from PhongBan where MaPHG=" + maPB;
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            ResultSet rs = provider.executeQuery(sql);
            if (rs.next()) {
                pb = new PhongBan();
                pb.setMaPh(rs.getInt("MaPHG"));
                pb.setTenPh(rs.getString("TenPHG"));
            }
            provider.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return pb;
    }
}
