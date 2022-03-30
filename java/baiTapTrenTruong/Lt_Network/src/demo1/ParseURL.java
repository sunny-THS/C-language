/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package demo1;

import java.net.MalformedURLException;
import java.net.URL;

/**
 *
 * @author Admin
 */
public class ParseURL {
    public static void main(String[] args) throws MalformedURLException {
        String url = "http://example.com:80/docs/book/tutorial"
                   + "/index.html?name=networking#DOWNLOADING";
        URL aURL = new URL(url);
        System.out.println("protocol: " + aURL.getProtocol());
        System.out.println("authority: " + aURL.getAuthority());
        System.out.println("host: " + aURL.getHost());
        System.out.println("port: " + aURL.getPort());
        System.out.println("path: " + aURL.getPath());
        System.out.println("query: " + aURL.getQuery());
        System.out.println("filename: " + aURL.getFile());
        System.out.println("ref: " + aURL.getRef());
    }
}
