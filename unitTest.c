
#include <stdio.h>
#include "hafta9.c"

//Lab icin hafta8_fonksiyon prototipleri
void hafta9_fonksiyon(int *dizi,int elemanSayisi, void *isareciDizi[], int *TekElemanSayisi, int *ciftElemanSayisi, int tekSayiDizisi[], int ciftSayiDizisi[]);

/*
Fonksiyon icerisinde yapilacak islemler
Dizi degerlerinin orjinalini degistirmeden
İşaretçi Dizisi kullanarak
Tek degerler küçükten buyüğe
Cift degerler büyükten küçüğe
siralayarak ilgili diziye atayiniz
Tek ve cift eleman sayisini hesaplattirarak isaretcilerle bu degerleri ilgili adreslere atayiniz
öncelikli çift değerler olmak üzere cift-tek-cift-tek-... olacak sekilde isaretci dizisinde orjinal dizi adreslerine gore adres degerleri atanmali
Ornegin en buyuk cift deger 42 ise orjinal dizideki 42 sayisini barindiran adres isaretci dizisinin ilk indisine atanarak burada tutulmali
sonrasinda ise en kucuk olan ilk deger seklinde sirayla cift degerlerin dizideki adresleri ve tek degerlerin dizideki adresleri isaretci dizisine atanmalidir.
Bu atamada tek degerlerin kucukten buyuge, cift degerlerin buyukten kucuge oldugunu unutmayiniz.
Sistemsel hata disindeki sorularinizi lutfen derste sorunuz.A
*/


int main()
{
    FILE *fp;
    fp = fopen("not.txt", "w");
    int dogrutestsayisi=0;

    //create a .txt file
    if (fp == NULL) {
        printf("File Pointer Null. Dosya acilamadi.\n");
        return -1;
    }

    //Degiskenler
    void *ptrArray[18]; //Void Pointer Array
    int i; 
    for(i=0;i<18;i++) ptrArray[i]=NULL;
    //Isaretci Dizisi ile erisilen adreslerdeki verilerin turleri
    int Dizi[18]={21,8,7,5,22,1,3,18,6,9,36,2,13,15,45,28,42,44};
    int Hedef[18]={44,1,42,3,36,5,28,7,22,9,18,13,8,15,6,21,2,45};
    int Kontrol_Tek[9]={1, 3, 5, 7, 9, 13, 15, 21, 45};
    int Kontrol_Cift[9]={44, 42, 36, 28, 22, 18, 8, 6, 2};
    int tekElemanSayisi=0, ciftElemanSayisi=0;
    int *PtrTelElemanSayisi=&tekElemanSayisi, *PtrCiftElemanSayisi=&ciftElemanSayisi;
    //Gecici Diziler (Islemlerde kullanilmasi icin)
    int tekSayiDizisi[9]={0};
    int ciftSayiDizisi[9]={0};

    printf("\n");
    //Fonksiyon Cagirma
    hafta9_fonksiyon(Dizi,18, ptrArray, PtrTelElemanSayisi, PtrCiftElemanSayisi, tekSayiDizisi, ciftSayiDizisi);
    printf("\n");
    printf("Fonksiyon Sonrasi Degerler:\n");
    printf("\nDizi:"); 
    for(i=0; i<18; i++) printf("- %d ", Dizi[i]);
    printf("\nTekSayilar:"); 
    for(i=0; i<9; i++) printf("- %d ", tekSayiDizisi[i]);
    printf("\nCiftSayilar:");
    for(i=0; i<9; i++) printf("- %d ", ciftSayiDizisi[i]);
    printf("\nIsaretci Dizisi Gosterdigi Degerler:");
    for(i=0; i<18; i++) if(ptrArray[i]!=NULL) printf("- %d ", *((int*)ptrArray[i])); else{printf("-NULL");}
    printf("\n");

    //TEST - 1:
    printf("\nTEST - 1\n");
    printf("Tek Cift Eleman Sayisi Kontrolu: \n");
    if(tekElemanSayisi==9 && ciftElemanSayisi==9)
    {
        printf("DOGRU\n");
        dogrutestsayisi++;
    }else{printf("YANLIS\n");}

    //TEST - 2:
    printf("\nTEST - 2\n");
    printf("Tek ve Cift Siralama Kontrolu: \n");
    int diziDogrulamaKontrol=1;
    for(i=0; i<9; i++){ if(tekSayiDizisi[i]!=Kontrol_Tek[i] || ciftSayiDizisi[i]!=Kontrol_Cift[i]) diziDogrulamaKontrol=0;}
    if(diziDogrulamaKontrol==1)
    {
        printf("DOGRU\n");
        dogrutestsayisi+=2;
    }else{printf("YANLIS\n");}

    //TEST - 3:
    printf("\nTEST - 3\n");
    printf("Isaretci Dizisi Kontrolu -1: \n");
    int nullKontrol=1;
    for(i=0; i<18; i++){ if(ptrArray[i]==NULL) nullKontrol=0;}
    if(nullKontrol==1)
    {
        printf("DOGRU\n");
        dogrutestsayisi+=2;
    }else{printf("YANLIS\n");}

    //TEST - 4:
    printf("\nTEST - 4\n");
    printf("Isaretci Dizisi Kontrolu -2: \n");
    int degerKontrol=1;
    for(i=0; i<18; i++){ if( *((int*)ptrArray[i]) != Hedef[i]) nullKontrol=0;}
    if(degerKontrol==1)
    {
        printf("DOGRU\n");
        dogrutestsayisi+=5;
    }else{printf("YANLIS\n");}

    printf("\n");
    //Son Yapilan İslemler
    int puan=dogrutestsayisi*10;
    printf("Puan: %d", puan);
    fprintf(fp, "Puan: %d", puan);
    fclose(fp);

    return 0;
}
