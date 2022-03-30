#ifndef BIG_FIVE_H
  #define BIG_FIVE_H
  #include <iostream>
  #include <string>
  #include "DCSTC.h"
  using namespace std;

  class BigFive {
    private:
      float chiSoTinhCach[5] = {};
    protected:
      const string thongTinCacTinhCach[5][2] = { \
        {"Nguoi co diem cao o yeu to nay thuong la nguoi thich nhung y tuong moi, thich hieu biet nhieu linh vuc dong thoi cung thich tu do, khong thich bi rang buoc...", "Nguoi co diem thap o yeu to nay thuong kha bao thu, kho tiep nhan nhung y thuong moi, la. Ho thich su on dinh, quen thuoc va thuc te"}, \
        {"chi so cao cua C", "chi so thap cua C"}, \
        {"chi so cao cua E", "chi so thap cua E"}, \
        {"chi so cao cua A", "chi so thap cua A"}, \
        {"chi so cao cua N", "chi so thap cua N"}, \
      };

    public:
      BigFive() { }
      void nhapTTDG() {

      }
  };
#endif //BIG_FIVE_H
