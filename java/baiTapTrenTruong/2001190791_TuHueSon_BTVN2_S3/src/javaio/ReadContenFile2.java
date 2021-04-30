/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaio;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

/**
 *
 * @author A102PC33
 */
public class ReadContenFile2 {
    public static void main(String[] args) throws IOException {
        byte[] enconed = Files.readAllBytes(Paths.get("D:\\log.txt"));
        String s = new String(enconed, StandardCharsets.UTF_8);
        System.out.println(s);
    }
}
