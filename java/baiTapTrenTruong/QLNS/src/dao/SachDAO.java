/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import dataprovider.SQLServerProvider;
import java.sql.ResultSet;
import java.util.ArrayList;
import pojo.Sach;

/**
 *
 * @author Admin
 */
public class SachDAO {
    public static boolean insertSach(Sach s) {
        boolean bUD = false;
        try {
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            String strSqlInset = String.format("insert sach "
                                          + "select %d, N'%s', N'%s', %d, %d, N'%s'", 
                                            s.getMa(),
                                            s.getTieuDe(),
                                            s.getTacGia(),
                                            s.getNamXB(),
                                            LoaiSachDAO.getMa(s.getTheLoai()),
                                            s.getMoTa()
            );
            bUD = provider.executeUpdate(strSqlInset)>0?true:false;
            provider.close();
        } catch (Exception e) {
        }
        return bUD;
    }
    public static boolean udSach(Sach s) {
        boolean bUD = false;
        try {
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            String strSqlUD = String.format("update sach "
                                          + "select N'%s', N'%s', %d, %d, N'%s'", 
                                            s.getTieuDe(),
                                            s.getTacGia(),
                                            s.getNamXB(),
                                            LoaiSachDAO.getMa(s.getTheLoai()),
                                            s.getMoTa()
            );
            bUD = provider.executeUpdate(strSqlUD)>0?true:false;
            provider.close();
        } catch (Exception e) {
        }
        return bUD;
    }
    public static int countSach () {
        String strSqlCount = "select count(*) dem from sach";
        int n = 0;
        try {
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            ResultSet rs = provider.executeQuery(strSqlCount);
            rs.next();
            n = rs.getInt("dem");
            provider.close();
        } catch (Exception e) {
            n = 0;
        }
        return n;
    }
    public static boolean bCheckTen(String strTen) {
        boolean bCkTen = false;
        try {
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            String strSqlCheckTen = "select * from sach where tieude=N'"+strTen.trim()+"'";
            ResultSet rs = provider.executeQuery(strSqlCheckTen);
            bCkTen = rs.next();
            provider.close();
        } catch (Exception e) {
            bCkTen = false;
        }
        return bCkTen;
    }
    public static boolean delSach(Sach s) {
        boolean isDel = false;
        try {
            SQLServerProvider provider = new SQLServerProvider();
            String strSqlDel = "delete from sach where S_ID="+s.getMa();
            provider.open();
            int n = provider.executeUpdate(strSqlDel);
            if (n>0) isDel = true;
            provider.close();
        } catch (Exception e) {
        }
        return isDel;
    }
    public static ArrayList<Sach> showLst() {
        ArrayList<Sach> arrlst = new ArrayList<Sach>();
        SQLServerProvider provider = new SQLServerProvider();
        try {
            provider.open();
            String sql = "Select sach.*, ten from LoaiSach join sach on loaisach.LS_ID = sach.theloai";
            ResultSet rs = provider.executeQuery(sql);
            while(rs.next()) {
                Sach s = new Sach();
                s.setMa(Integer.parseInt(rs.getString("S_ID")));
                s.setTieuDe(rs.getString("tieude"));
                s.setTacGia(rs.getString("tacgia"));
                s.setNamXB(Integer.parseInt(rs.getString("namxuatban")));
                s.setTheLoai(rs.getString("ten"));
                s.setMoTa(rs.getString("moTa"));
                arrlst.add(s);
            }
            provider.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return arrlst;
    }
}
