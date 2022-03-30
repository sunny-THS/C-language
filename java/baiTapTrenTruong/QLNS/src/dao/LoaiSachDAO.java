/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import dataprovider.SQLServerProvider;
import java.sql.ResultSet;
import java.util.ArrayList;
import pojo.LoaiSach;

/**
 *
 * @author Admin
 */
public class LoaiSachDAO {
    public static int getMa(String strTen) {
        int ma = -1;
        try {
            String strSqlGetMa = "select LS_ID from LoaiSach where ten =N'"+strTen+"'";
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            ResultSet rs = provider.executeQuery(strSqlGetMa);
            if (rs.next()) ma = rs.getInt("LS_ID");
            provider.close();
        } catch (Exception e) {
        }
        return ma;
    }
    public static boolean delLoaiSach(LoaiSach ls) {
        boolean bUD = false;
        try {
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            String strSqlDel = "Delete from loaiSach where LS_ID="+ls.getiMa();
            bUD = provider.executeUpdate(strSqlDel)>0?true:false;
            provider.close();
        } catch (Exception e) {
        }
        return bUD;
    }
    public static boolean insertLoaiSach(LoaiSach ls) {
        boolean bUD = false;
        try {
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            String strSqlInset = "insert loaisach values ("+(ls.getiMa()+1)+", N'"+ls.getStrTen()+"', N'"+ls.getStrMoTa()+"')";
            bUD = provider.executeUpdate(strSqlInset)>0?true:false;
            provider.close();
        } catch (Exception e) {
        }
        return bUD;
    }
    public static boolean udLoaiSach(LoaiSach ls) {
        boolean bUD = false;
        try {
            SQLServerProvider provider = new SQLServerProvider();
            provider.open();
            String strSqlUD = "update loaisach set ten=N'"+ls.getStrTen()+"', mota=N'"+ls.getStrMoTa()+"' where LS_ID="+ls.getiMa();
            bUD = provider.executeUpdate(strSqlUD)>0?true:false;
            provider.close();
        } catch (Exception e) {
        }
        return bUD;
    }
    public static int countLoaiSach () {
        String strSqlCount = "select count(*) dem from loaisach";
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
            String strSqlCheckTen = "select * from LoaiSach where ten=N'"+strTen+"'";
            ResultSet rs = provider.executeQuery(strSqlCheckTen);
            bCkTen = rs.next();
            provider.close();
        } catch (Exception e) {
            bCkTen = false;
        }
        return bCkTen;
    }
    public static ArrayList<LoaiSach> showData() {
        ArrayList<LoaiSach> arrlst = new ArrayList<LoaiSach>();
        SQLServerProvider provider = new SQLServerProvider();
        try {
            provider.open();
            String sql = "Select * from LoaiSach";
            ResultSet rs = provider.executeQuery(sql);
            while(rs.next()) {
                LoaiSach ls = new LoaiSach();
                ls.setiMa(Integer.parseInt(rs.getString("LS_ID")));
                ls.setStrTen(rs.getString("Ten"));
                ls.setStrMoTa(rs.getString("MoTa"));
                arrlst.add(ls);
            }
            provider.close();
        } catch (Exception e) {
        }
        return arrlst;
    }
}
