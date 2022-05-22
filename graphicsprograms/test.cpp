#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
//#include<math.h>

#define EKRAN_X 750
#define EKRAN_Y 750

//using namespace std;

struct nokta//KOORDİNAT
{
    float x;
    float y;
} koordinatlar[50];//DİZİ NESNESİ

int main()
{
    int nokta_sayisi=0;//DOSYADAKİ NOKTA SAYISI
    FILE *dosyaptr;//DOSYA OKUMA POİNTER
    char karakter;//KARAKTER KARAKTER OKUMA
    int virgul_sayi=0;//.txt VİRGUL SAYISI

    if((dosyaptr=fopen("koordinat.txt","r"))==NULL)//DOSYA OKUNMAZ İSE
    {
        printf("Dosya Bulunamadi!!");
        exit(1);
    }
    else//DOSYA OKUNMAYA BAŞLANDI
    {
        printf("Koordinatlar Aliniyor..\n\n");
        karakter=fgetc(dosyaptr);//İLK KARAKTER OKUNUYOR

        while(!feof(dosyaptr))//DOSYA SONUNA KADAR KARAKTER KARAKTER OKUMA İŞLEMİ
        {
            printf("%c",karakter);
            if(karakter==',')
            {
                virgul_sayi++;
            }
            karakter=fgetc(dosyaptr);//KARAKTER KARAKTER OKUMA İŞLEMİ
        }

        nokta_sayisi=(virgul_sayi+1)/2;//NOKTA SAYISI VİRGÜL SAYISINA GÖRE BELİRLENDİ
        fclose(dosyaptr);//DOSYAYI KAPAT

        dosyaptr=fopen("koordinat.txt","r");//DOSYAYI AÇ
        karakter=fgetc(dosyaptr);//{} ALMAK İÇİN

        for(int i=0;i<nokta_sayisi;i++)//NOKTA SAYISI KADAR STRUCH DİZİSİ OLUŞTURACAĞIZ
        {
            fscanf(dosyaptr,"{%f,%f}, ",&koordinatlar[i].x,&koordinatlar[i].y);//FORMATLI OKUMA
        }

        printf("\n \n ---**Koordinatlar Alindi**---\n");
        fclose(dosyaptr);

    }//OKUMA SONU

    printf("Koordinat Sayisi= %d\n",nokta_sayisi);//.txt KOORDİNAT SAYISI

    for(int i=0;i<nokta_sayisi;i++)
    {
        printf("%d. Noktanin x= %0.f y= %0.f \n",i+1,koordinatlar[i].x,koordinatlar[i].y);
    }


    //GRAFİK İŞLEMLERİ
    initwindow(EKRAN_X,EKRAN_Y);//GRAFİK İÇİN YENİ KONSOL PENCERESİ
    setcolor(GREEN);//KOORDİNAT ÇİZGİ RENGİ
    line(EKRAN_X/2,0,EKRAN_X/2,EKRAN_Y);//X EKSENİ
    line(0,EKRAN_Y/2,EKRAN_X,EKRAN_Y/2);//Y EKSENİ

    //X VE Y EKSENİ NUMARALANDIRMASI
    char str[2];//MAX 2 HANELİ SAYI KULLANILACAK
    int x_olcek_sayilari=-30;//X EKSENİ ÖLÇEKLENDİRME ARALIĞI
    int y_olcek_sayilari=30;//Y EKSENİ ÖLÇEKLENDİRME ARALIĞI
    settextstyle(0,0,1);//OUT TEXT X-Y AYARLARI FONT YÖN ve BÜYÜKLÜK

    //X EKSENİ NUMARALANDIRMA
    for(int i=-EKRAN_X/2;i<EKRAN_X;i=i+25)//30 EŞİT PARÇA
    {
        sprintf(str,"%d",x_olcek_sayilari);//SAYİ BELİRTME İÇİN
        outtextxy(i,EKRAN_X/2,str);//SAYIYI KOORDİNAT DÜZLEMİNE YAZMA
        x_olcek_sayilari++;
    }

    //Y EKSENİ NUMARALANDIRMA
    for(int i=-EKRAN_Y/2;i<EKRAN_Y;i=i+25)//30 EŞİT PARÇA
    {
        sprintf(str,"%d",y_olcek_sayilari);
        outtextxy(EKRAN_Y/2,i,str);
        y_olcek_sayilari--;
    }

    //KARELERE BÖLME 
    for(int i=0;i<EKRAN_X;i=i+25)
    {
        line(EKRAN_X/2,0+i,EKRAN_X/2,0+i);
        line(0+i,EKRAN_Y/2,0+i,EKRAN_Y/2);
        line(0+i,0,0+i,EKRAN_Y);
        line(0,0+i,EKRAN_X,0+i);
    }

    //NOKTALARIN KOORDİNAT GÖSTERİMİ
    for(int i=0;i<nokta_sayisi;i++)
    {
        char str[4];//(X,Y) BELİRTMEK İÇİN
        setcolor(WHITE);//NOKTALAR BEYAZ OLSUN

        //KOORDİNAT BÖLGE AYRIMI
        if((koordinatlar[i].x<=0)&&(koordinatlar[i].y<=0))//3.BÖLGE
        {
            sprintf(str,"'(%0.f,%0.f)",koordinatlar[i].x,koordinatlar[i].y);//(X,Y) BELİRTMEK İÇİN
            outtextxy((koordinatlar[i].x+15)*25,(abs(koordinatlar[i].y)+15)*25,str);//Y EKSİ OLDUĞUNDA MUTLAK DEĞER
        }

        if((koordinatlar[i].x<=0)&&(koordinatlar[i].y>=0))//2.BÖLGE
        {
            sprintf(str,"'(%0.f,%0.f)",koordinatlar[i].x,koordinatlar[i].y);
            outtextxy((koordinatlar[i].x+15)*25,(15-koordinatlar[i].y)*25,str);
        }

        if((koordinatlar[i].x>=0)&&(koordinatlar[i].y<=0))//4.BÖLGE
        {
            sprintf(str,"'(%0.f,%0.f)",koordinatlar[i].x,koordinatlar[i].y);
            outtextxy((koordinatlar[i].x+15)*25,(abs(koordinatlar[i].y)+15)*25,str);
        }

        if((koordinatlar[i].x>=0)&&(koordinatlar[i].y>=0))//1.BÖLGE
        {
            sprintf(str,"'(%0.f,%0.f)",koordinatlar[i].x,koordinatlar[i].y);
            outtextxy((koordinatlar[i].x+15)*25,(15-koordinatlar[i].y)*25,str);
        }

    }

    getch();//Grafik konsolu ekranda kalmasý için
    closegraph();
    return 0;
}

