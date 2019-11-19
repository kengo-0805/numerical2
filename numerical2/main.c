//
//  main.c
//  numerical2
//
//  Created by 堀井健吾 on 2019/11/18.
//  Copyright © 2019 kengohorii. All rights reserved.
//
#include <stdio.h>
//#include <stdlib.h> //勝手に消してみた
#include <math.h>

/* 一次方程式の元の個数 */
   

/*収束確認のための定数*/
#define EPS 10e-6
#define maxvalue 90000000000
 int main(void) {
   int i,j,k,z = 0; //z:行列サイズ
     #define DIM 4  //４行４列の指定

//スキャンfで行列のサイズを選択
    printf("行列のサイズを2~10で選択して下さい \n");
    scanf("%d", &z);
    printf("行列のサイズ:%d\n", z);

     
//  箱用意する？
     if(z == 3){
         double a[DIM][DIM] = {{3,2,1},{1,4,1},{2,2,5}}; //DIM 3 の時
         double b[DIM] = {10,12,21}; //DIM 3 の時
     }else if(z == 4){
         double a[DIM][DIM] = {{9,2,1,1},{2,8,-2,1},{-1,-2,7,-2},{1,-1,-2,6}}; //DIM 4 の時
         double b[DIM] = {20,16,8,17}; //DIM 4 の時
     }
     
   double x[DIM] = {0}; //更新前のx
   double x_new[DIM] = {0}; //更新後のx

  do {
    /* 値の更新 */
    for (i=0; i<DIM; i++){
      x[i] = x_new[i];
    }

    /* 演算処理 */
    for (i=0; i<DIM; i++) {
      x_new[i] = b[i];
      for (j=0; j<i; j++) {
        x_new[i] -= a[i][j] * x_new[j];
      }
      for (j=i+1; j<DIM; j++) {
        x_new[i] -= a[i][j] * x[j];
      }
      x_new[i] /= a[i][i];
    }

    /* 途中経過の表示 */
    printf("%2d:", k);
    for (i=0; i<DIM; i++) printf("x[%d]= %.5f ", i, x_new[i]);
    printf("\n");
      if(k >= maxvalue){
          break;
      }
    k++;
  } while (fabs(x_new[0]-x[0]) >= EPS && fabs(x_new[1]-x[1]) >= EPS && fabs(x_new[2]-x[2]) >= EPS);

/* 最終結果の表示 */
  printf("\nAns\n");
  for (i=0; i<DIM; i++) printf("x[%d]= %.5f \n", i, x_new[i]);
  printf("\n");

  return 0;
}
