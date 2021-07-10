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
}
