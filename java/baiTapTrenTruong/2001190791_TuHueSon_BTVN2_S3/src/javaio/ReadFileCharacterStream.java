/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaio;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;


/**
 *
 * @author A102PC33
 */
public class ReadFileCharacterStream {
    public static void main(String[] args) {
        try{
            FileInputStream fis = new FileInputStream("D:\\log.txt");
            InputStreamReader irs = new InputStreamReader(fis,"UTF-8");
            BufferedReader br = new BufferedReader(irs);
            String s;
            do{
                s = null;
                s = br.readLine();
                System.out.println(s);
            }
            while(s != null);
            br.close();
        }
        catch(Exception ex){
            ex.printStackTrace();
        }
    }
}
