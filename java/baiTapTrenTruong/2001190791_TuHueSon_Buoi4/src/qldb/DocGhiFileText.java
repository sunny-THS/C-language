/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package qldb;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

/**
 *
 * @author A102PC32
 */
public class DocGhiFileText {
    public static boolean ghiFile(ArrayList<DanhBa> ldb, String path) {
        try {
            FileOutputStream fos = new FileOutputStream(path);
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            
            oos.writeObject(ldb);
            oos.close();
            fos.close();
            return true;            
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }
    public static ArrayList<DanhBa> docFile(String path) {
        ArrayList<DanhBa> ldb = new ArrayList<DanhBa>();
        try {
            FileInputStream fis = new FileInputStream(path);
            ObjectInputStream ois = new ObjectInputStream(fis);
            
            ldb = (ArrayList<DanhBa>)ois.readObject();
            ois.close();
            fis.close();
            return ldb;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}
