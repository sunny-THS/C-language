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
import java.util.List;

/**
 *
 * @author pc
 */
public class ReadContenFile {
    public static void main(String[] args) throws IOException {
        List<String> list = Files.readAllLines(Paths.get("D:\\log.txt"), StandardCharsets.UTF_8);
        for(String s: list){
            System.out.println(s);
        }
    }
}
