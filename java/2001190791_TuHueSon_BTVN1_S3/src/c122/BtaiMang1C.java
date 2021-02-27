/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c122;

import java.util.Scanner;
/**
 *
 * @author Admin
 */
public class BtaiMang1C {    
    public static void menu() {
        String q[] = {
            "Nhập giá trị cho n phần tử mảng từ bàn phím (n <= 500)",
            "Phát sinh giá trị ngẫu nhiên từ -199 đến 199 cho n phần tử mảng (n <= 500)",
            "Xuất mảng ra màn hình",
            "Liệt kê các giá trị âm có trong mảng",
            "Liệt kê các số nguyên tố có trong mảng",
            "Liệt kê các phần tử có giá trị nằm trong đoạn [a, b] cho trước",
            "Tính tổng giá trị các phần tử là số nguyên tố",
            "Tính trung bình cộng của các phần tử dương có trong mảng",
            "Đếm số phần tử có giá trị lớn hơn x cho trước",
            "Đếm số phần tử có giá trị là số nguyên tố trong mảng",
            "Kiểm tra mảng có phải là mảng chứa toàn số nguyên tố",
            "Kiểm tra mảng có phải là mảng tăng dần",
            "Tìm giá trị lớn nhất trong mảng",
            "Tìm giá trị nhỏ nhất trong mảng",
            "Tìm số âm lớn nhất trong mảng",
            "Đảo ngược mảng",
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
        Mang1C arr = new Mang1C();
        Scanner in = new Scanner(System.in);
        int chon;
        int n=0;
        do {
            menu();
            chon = in.nextInt();
            switch(chon) {
                case 1: {
                    arr.nhapN();
                    arr.nhapBP();
                }break;
                case 2: {
                    arr.nhapN();
                    arr.nhapRandom();
                }break;
                case 3: {
                    System.out.println("Mảng vừa nhập là: ");
                    arr.xuat();
                }break;
                case 4: {
                    System.out.println("Các giá trị âm trong mảng: ");
                    arr.lietKeSoAm();
                }break;
                case 5: {
                    System.out.println("Các giá trị là số nguyên tố trong mảng: ");
                    arr.lietKeSNT();
                }break;
                case 6: {
                    System.out.println("Các giá trị trong khoảng [a, b]: ");
                    int a, b;
                    do {
                        System.out.print("Nhap a: ");
                        a = in.nextInt();
                        System.out.print("Nhap b: ");
                        b = in.nextInt();
                    } while (a>b);
                    arr.lietKeTKhoang(a, b);
                }break;
                case 7: {
                    System.out.println("Tổng các giá trị là số nguyên tố: " + arr.tinhTongSNT());
                }break;
                case 8: {
                    System.out.println("Trung bình cộng các phần tử dương: " + arr.tinhTBCDuong());
                }break;
                case 9: {
                    System.out.println("Đếm số phần tử có giá trị lớn hơn x: ");
                    System.out.print("Nhap x: ");
                    int x = in.nextInt();
                    System.out.println("Số phần tử lớn hơn x: " + arr.demSoPtLonHon(x));
                }break;
                case 10: {
                    System.out.println("Đếm số phần tử có giá trị là số nguyên tố: "); System.out.print("Nhap x: ");
                    System.out.println("Số phần tử có giá trị là số nguyên tố: " + arr.demSNT());
                }break;
                case 11: {
                    String answer = arr.kTraToanSNT()?"Có":"Không";
                    System.out.println("mảng có phải là mảng chứa toàn số nguyên tố: " + answer);
                }break;
                case 12: {
                    String answer = arr.kTraMangTang()?"Có":"Không";
                    System.out.println("mảng có phải là mảng tăng dần: " + answer);
                }break;
                case 13: {
                    System.out.printf("Giá trị lớn nhất: %d\n", arr.timGtriMax());
                }break;
                case 14: {
                    System.out.printf("Giá trị nhỏ nhất: %d\n", arr.timGtriMin());
                }break;
                case 15: {
                    int res = arr.timGtriAmMax();
                    if (res==0) 
                        System.out.println("Không có giá trị âm nào");
                    else 
                        System.out.printf("Giá trị âm lớn nhất: %d\n", res);
                }break;
                case 16: {
                    System.out.println("Mảng cũ");
                    arr.xuat();
                    arr.daoMang();
                    System.out.println("\nMảng mới");
                    arr.xuat();
                }break;
            }
        } while (chon!=0);
    }
            
}
