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
public class GetFileInfor {
    public static void main(String[] args) {
        File f = new File("D:\\log.txt");
        if(f.isDirectory())
            System.out.println("Is folder");
        if(f.isFile())
            System.out.println("Is file");
        if(f.exists())
            System.out.println("File is exists");
        else
            System.out.println("File does not exists");
        System.out.println("Absolute: " +f.getAbsolutePath());
        System.out.println("Get path: " +f.getPath());
        System.out.println("Get name: " +f.getName());
        System.out.println("Get parent: " + f.getParent());
    }
}
