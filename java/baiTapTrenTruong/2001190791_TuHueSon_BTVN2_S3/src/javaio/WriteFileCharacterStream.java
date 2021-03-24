/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaio;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;

/**
 *
 * @author A102PC33
 */
public class WriteFileCharacterStream {
    public static void main(String[] args) {
        try{
            FileOutputStream fos = new FileOutputStream("D:\\log.txt");
            OutputStreamWriter os = new OutputStreamWriter(fos,"UTF-8");
            BufferedWriter bw = new BufferedWriter(os);
            String []str = new String[]{"aaa"};
            for(String s: str ){
                bw.write(s);
                bw.write("\n");
            }
            bw.close();
        }
        catch(Exception ex){
            ex.printStackTrace();
        }
    }
}
