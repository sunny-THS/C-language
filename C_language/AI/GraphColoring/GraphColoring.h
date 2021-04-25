#ifndef GRAPHCOLORING_H_
  #define GRAPHCOLORING_H_
  #include <stdio.h>
  #include <string>
  #define MAX 100
  class GraphColoring {
    private:
      int arr[MAX][MAX], mauCam[MAX][MAX], bacDinh[MAX], mauDinh[MAX], n;
    public:
      GraphColoring() { }
      ~GraphColoring() { }
      void docFile(std::string fileName) {
        FILE *fp;
        if (!(fp=fopen(fileName.c_str(), "r"))) {
          printf("File %s khong ton tai", fileName);
          exit(1);
        }
        fscanf(fp, "%d", &n);
        for(size_t i=1; i<=n; i++)
          for(size_t j=1; j<=n; j++)
            fscanf(fp, "%d", &arr[i][j]);
      }
      void initMauDinh() {
        for (size_t i=1; i<=n; i++) {
          mauDinh[i] = -1; // chua dinh nao dc to mau
        }
      }
      void xacDinhBacCacDinh() {
        for(size_t i=1; i<=n; i++) {
          bacDinh[i] = 0;
          for(size_t j=1; j<=n; j++)
            bacDinh[i] += arr[i][j];
        }
      }
      int timDinhBacMax() {
        int v = 1;
        int max = bacDinh[v];
        for (size_t i=v+1; i<=n; i++) {
          if (max < bacDinh[i]) {
            v = i;
            max = bacDinh[i];
          }
        }
        return v;
      }
      int checkMau(int v, int m) {
        /*
          return 1 trung mau voi dinh ke
          return 0 khong bi trung mau voi dinh ke
        */
        for (size_t i=1; i<=n; i++)
          if (mauCam[v][i] == m)
            return 1;
        return 0;
      }
      int chonMau(int v) {
        int m = 1;
        do {
          if (!checkMau(v, m)) // return 1 or 0
            break;
          else m++;
        } while(1);
        return m;
      }
      void initMauCam() {
        for(size_t i=1; i<=n; i++)
          for(size_t j=1; j<=n; j++)
            mauCam[i][j] = -1; // chua co mau nao cam
      }
      void toMau() {
        int dinhMax;
        int dinh = 1;
        int dinhDaXet[MAX];
        for (size_t i=1; i<=n; i++)
          dinhDaXet[i] = -1; // chua xet dinh nao
        initMauCam();
        do {
          dinhMax = timDinhBacMax(); // dinh bac cao nhat
          mauDinh[dinhMax] = chonMau(dinhMax); // chon mau cho dinh bac cao nhat
          dinhDaXet[dinhMax] = 1; // danh dau dinh da xet
          dinh++;

          for (size_t i=1; i<=n; i++) {
            if (arr[dinhMax][i]==1 && dinhDaXet[i]!=1) { // gan mau da chon cho cac dinh ke
              mauCam[i][dinhMax] = mauDinh[dinhMax];
              bacDinh[i]--;
            }
            if (bacDinh[i]==0 && dinhDaXet[i]!=1) {
              mauDinh[i] = chonMau(i);
              dinhDaXet[i] = 1;
              dinh++;
            }
          }
          bacDinh[dinhMax] = 0;
        } while(dinh<=n);
      }
      void showRes() {
        for (size_t i=1; i<=n; i++) {
          printf("%d ", mauDinh[i]);
        }
      }
      void xuat() {
        for(size_t i=1; i<=n; i++) {
          for(size_t j=1; j<=n; j++)
            printf("%d ", arr[i][j]);
          printf("\n");
        }
      }
  };
#endif // GRAPHCOLORING_H_
