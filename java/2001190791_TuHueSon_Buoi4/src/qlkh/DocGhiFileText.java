/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package qlkh;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

/**
 *
 * @author A102PC32
 */
public class DocGhiFileText {
    public static boolean ghiFile(ArrayList<KhachHang> lkh, String path) {
        try {
            FileOutputStream fos = new FileOutputStream(path);
            OutputStreamWriter osw = new OutputStreamWriter(fos, "UTF-8");
            BufferedWriter bw = new BufferedWriter(osw);
            for (KhachHang kh : lkh) {
                String line = kh.toString();
                bw.write(line);
                bw.newLine();
            }
            bw.close();
            osw.close();
            fos.close();
            return true;            
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }
    public static ArrayList<KhachHang> docFile(String path) {
        ArrayList<KhachHang> lkh = new ArrayList<KhachHang>();
        try {
            FileInputStream fis = new FileInputStream(path);
            InputStreamReader isr = new InputStreamReader(fis);
            BufferedReader br = new BufferedReader(isr);
            String line = br.readLine();
            while (line != null) {
                String arr[] = line.split(" - ");
                lkh.add(new KhachHang(
                        arr[0], 
                        arr[1], 
                        Integer.parseInt(arr[2])
                ));
                line = br.readLine();
            }
            br.close();
            isr.close();
            fis.close();
            return lkh;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}
