/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c123;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class BtapMang2C {
    public static void menu() {
        String q[] = {
            "Nhập giá trị cho mxn phần tử của mảng từ bàn phím (m <= 50, n <= 100)",
            "Phát sinh giá trị ngẫu nhiên từ -99 đến 99 cho mxn phần tử của mảng (n <= 100)",
            "Xuất giá trị các phần tử ra màn hình",
            "Tính tổng giá trị các số lẻ",
            "Tính tổng các giá trị dương trên dòng k cho trước",
            "Đếm số lượng số dương",
            "Đếm số lượng số nguyên tố trên một dòng của ma trận",
            "Kiểm tra ma trận có tồn tại số âm hay không",
            "Kiểm tra các phần tử trên dòng k cho trước có tăng dần từ trái qua phải hay không",
            "Liệt kê dòng có chứa số nguyên tố",
            "Liệt kê dòng chứa toàn giá trị chẵn",
            "Thoát!"
        };
        int len = q.length;
        System.out.printf("\n\n");
        for(int i=0; i<len; i++) {
            System.out.printf("%d. %s\n", i==len-1?0:i+1, q[i]);
        }
        System.out.print("Chọn: ");
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Mang2C arr = new Mang2C();
        int chon;
        int n=0;
        do {
            menu();
            chon = in.nextInt();
            switch(chon) {
                case 1: {
                    arr.nhapMN();
                    arr.nhapBP();
                }break;
                case 2: {
                    arr.nhapMN();
                    arr.nhapRandom();
                }break;
                case 3: {
                    System.out.println("Mảng vừa nhập là: ");
                    arr.xuat();
                }break;
                case 4: {
                    System.out.printf("Tổng giá trị các số lẻ: %d\n", arr.tinhTongGtriLe());
                }break;
                case 5: {
                    System.out.println("Tổng các giá trị dương trên dòng k");
                    System.out.print("Nhập k: ");
                    int k = in.nextInt();
                    System.out.printf("Tổng: %3d", arr.tinhTongGtriDuong(k));
                }break;
                case 6: {
                    System.out.printf("Số lượng số dương: %d", arr.demSLDuong());
                }break;
                case 7: {
                    System.out.println("Số lượng số nguyên tó trên 1 dòng của ma trận");
                    for (int i = 0; i < arr.getM(); i++) {
                        System.out.printf("số lượng của dòng %d: %d\n", i+1, arr.demSlSNTTren1d(i));
                    }
                }break;
                case 8: {
                    System.out.println("Kiểm tra ma trận có tồn tại số âm hay không");
                    System.out.printf("Ma trận %s tồn tại số âm", arr.kTraTTSoAm()?"Có":"Không");
                }break;
                case 9: {
                    System.out.println("Kiểm tra các phần tử trên dòng k cho trước có tăng dần từ trái qua phải hay không");
                    System.out.print("Nhập k: ");
                    int k = in.nextInt();
                    System.out.printf("Các phần tử trên dòng k cho trước %s tăng dần từ trái qua phải", arr.kTraTang(k)?"Có":"Không");
                }break;
                case 10: {
                    System.out.println("Liệt kê dòng có chứa số nguyên tố");
                    arr.lietKeDongSNT();
                }break;
                case 11: {
                    System.out.println("Liệt kê dòng chứa toàn giá trị chẵn");
                    arr.lietKeDongTGtriChan();
                }break;
            }
        } while (chon!=0);
    }
}
