//
//  main.c
//  [20111208] cpsf_sosu2_kai
//  CPSF 素数のアルゴリズム
//
//  Created by 土屋 貴裕 on 11/12/09.
//  Copyright (c) 2011年 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/* macros */
//#define DEBUG

/* prototypes */
unsigned int *alloc_prime_tab(unsigned int n);
void make_prime_tab(unsigned int n, unsigned int ip[]);
void print_primes(unsigned int n, unsigned int ip[]);
void print_primes_select(unsigned int n, unsigned int ip[], unsigned int select);
unsigned int count_primes(unsigned int n, unsigned int ip[]);

/* variables */


/* main */
#ifdef DEBUG
int main (int argc, const char * argv[]) {
    unsigned int n, *ip;
    
    printf("検索範囲の上限を入力(MAX:65535)\n >");
    scanf("%d", &n);
    ip = alloc_prime_tab(n);
    make_prime_tab(n, ip); //素数以外をフィルタリング
    
    print_primes(n, ip);
    printf ("%d Primes found.\n", count_primes(n, ip));
    
    //print_primes_select(n, ip, sel);
    
    free(ip);
}
#endif


/* ------------------------------------------------
 unsigned int *alloc_prime_tab(unsigned int n)
    メモリ領域を確保する関数
    input  >> unsigned int n: 素数をサーチする数字の上限
    return >> unsigned int ip: 確保したメモリ番地？
 ------------------------------------------------- */
unsigned int *alloc_prime_tab(unsigned int n) {
    unsigned int nh, j, ibit, *ip;
    
    nh = n >> 1; //nは正だからnh = n/2;
    ibit = 0;
    for (j = 8 * sizeof(unsigned int); j > 1; j >>= 1) ibit++;
        //j/=2; unsigned-intは4バイトなので32→16→8→4→2と回り、ibit=5
    
    ip = (unsigned int *)malloc(((nh >> ibit) + 1) << (ibit - 3)); // (n/2/32+1)*4=nh/8+4のメモリを確保
    return ip;
}


/* ------------------------------------------------
 void make_prime_tab(unsigned int n, unsigned int ip[])
    素数以外を削る関数
    input   >> unsigned int n: 素数
            >> unsigned int ip[]: 素数の一覧表
  ------------------------------------------------- */
void make_prime_tab(unsigned int n, unsigned int ip[]) {
    unsigned int nh, j, k, ibit, imask;
    
    nh = n >> 1;
    ibit = 0;
    for (j = 8 * sizeof(unsigned int); j > 1; j >>= 1) ibit++;
    
    imask = ~((-1) << ibit);
    
    for (j = 0; j <= (nh >> ibit); j++)
        ip[j] = 0;
    
    for (k = 1; k <= nh / 3; k++) {
        if ((~ip[k >> ibit]) & (1 << (k & imask))) {
            for (j = k + (k + k + 1); j < nh; j += k + k + 1) {
                ip[j >> ibit] |= (1 << (j & imask));
            }
        }
    }
}


/* ------------------------------------------------
 void print_primes(unsigned int n, unsigned int ip[])
    上限の数nまでに含まれる素数を出力する関数
    input   >> unsigned int n: 素数
            >> unsigned int ip[]: 素数の一覧表
 ------------------------------------------------- */
void print_primes(unsigned int n, unsigned int ip[]) {
    unsigned int nh, j, ibit, imask, count;
    
    nh = n >> 1; //nh=n/2
    ibit = 0;
    for (j = 8 * sizeof(unsigned int); j > 1; j >>= 1) ibit++;
    
    imask = ~((-1) << ibit); //imask = ~( - 2^(ibit=5) ) = ~(-32) = ~(0b00100000) = 0b11011111
    
    //出力
    if (n > 2) {
        printf ("%d番目の素数: %d\n", 1, 2); //2を出力
    }
    count = 1;
    for (j = 1; j < nh; j++) { //nh = n/2;
        if ((~ip[j >> ibit]) & (1 << (j & imask))) {
            count++;
            printf ("%d番目の素数: %d\n", count, j + j + 1); //素数(2j+1)を出力 3~
        }
    }
}

/* ------------------------------------------------
 void print_primes_select(unsigned int n, unsigned int ip[], unsigned int sel)
    n番目の素数を出力する関数
    input   >> unsigned int n: 素数
            >> unsigned int ip[]: 素数の一覧表
            >> unsigned int sel: 指定された素数の個数目
 ------------------------------------------------- */
void print_primes_select(unsigned int n, unsigned int ip[], unsigned int sel) {
    unsigned int nh, j, ibit, imask, count;
    
    nh = n >> 1; //nh=n/2
    ibit = 0;
    for (j = 8 * sizeof(unsigned int); j > 1; j >>= 1) ibit++;
    
    imask = ~((-1) << ibit);
    
    //出力
    if (n > 2) {
        if (count == sel) printf ("[1]: %d\n", 2);
    }
    count = 1;
    for (j = 1; j < nh; j++) {
        if ((~ip[j >> ibit]) & (1 << (j & imask))) {
            count++;
            if (count == sel) printf ("[%d]: %d\n", count, j + j + 1);
        }
    }
}


/* ------------------------------------------------
 unsigned int count_primes(unsigned int n, unsigned int ip[])
    上限の数nまでに含まれる素数を出力する関数
    input   >> unsigned int n: 素数
            >> unsigned int ip[]: 素数の一覧表
    return  >> unsigned int k: 素数の個数
 ------------------------------------------------- */
unsigned int count_primes(unsigned int n, unsigned int ip[]) {
    unsigned int nh, j, k, ibit, imask;
    
    nh = n >> 1;
    ibit = 0;
    for (j = 8 * sizeof(unsigned int); j > 1; j >>= 1) ibit++;
    
    imask = ~((-1) << ibit);
    
    k = 0;
    if (n > 2) {
        k++;
    }
    for (j = 1; j < nh; j++) {
        if ((~ip[j >> ibit]) & (1 << (j & imask))) {
            k++;
        }
    }
    return k;
}

