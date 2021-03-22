/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaio;

import java.io.File;

/**
 *
 * @author pc
 */
public class ListFilesInFolder {
    public static void main(String[] args) {
        File f = new File("C:\\windows");
        if(f.isAbsolute()){
            File [] list = f.listFiles();
            for(File item : list)
                System.out.println(item.getPath());
        }
    }
}
