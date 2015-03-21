
/*
 * File:   140401064.c
 * Author: ufuk doğan
 * Number: 140401064
 *
 * Created on March 14, 2015, 2:38 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int istenenSayi1,istenenSayi2,istenenSayi3,istenenSayi4;  // rastgele üretilecek 4 global değişken
int girilenSayi1,girilenSayi2,girilenSayi3,girilenSayi4;  // klavyeden girilecek 4 global değişken
int puan=250,carkDurum;  // diğer global değişkenler

void sayi_uret();  // rasgele üretilen sayıları global değişkenlere atayan fonksiyon.
int tahmin_gir();  // kullanıcıdan 4 sayı isteyerek, üretilen rasgele sayılar ile karşılaştırarak doğru sayısını dönderen fonksiyon.
int cark_cevir();  // 1-6 arası rasgele sayı üreten fonksiyon.

int main()
{
    printf("Cark Cevirme Oyununa Hosgeldiniz. \n");
    printf("Baslangic Puaniniz = %d \n",puan);
    char islem;
    int sayac;
    while(islem!='s' && puan>0){ // islem 's' ve puan 1 den küçük olmadığı sürece döngüye girmesini sağlar.
        islem='d'; // islemi tekrar c ve s haricinde belirleyerek döngüye girmesini sağlar.
        while(islem!='s' && islem != 'c'){
            printf("#### Carki Dondur (c)  ####\n");
            printf("#### Oyunu Sonlandir (s) ### \n");
            printf("islem seciniz: ");
            scanf(" %c",&islem);  // klavyeden girilen değeri islem değişkenine atar.
        }

        carkDurum= cark_cevir();  // rastgele üretilen 1-6 arası sayiyi tutacak olan değişken.
        if(islem=='s') carkDurum=7; // islem 's' seçildiğinde programı bitirmeyi sağlar.
        switch(carkDurum){
            case 1:  // rastgele üretilen sayı 1 olduğunda 50 puanlık işlemleri yapmayı sağlar.
                printf("\n50 Puan Geldi. Puani kazanmak icin en az 1 dogru tahmin gerekiyor. \n");
                sayac = tahmin_gir();
                if(sayac>=1){
                    printf("\nTebrikler! 50 Puan Kazandiniz. \n");
                    puan +=50;
                }
                else printf("\nUzgunum puan alamadiniz. Bilmeniz geren sayilar sunlardi: %d %d %d %d \n",istenenSayi1,istenenSayi2,istenenSayi3,istenenSayi4);
                printf("Guncel Puaniniz : %d \n",puan);

                break;

            case 2:   // rastgele üretilen sayı 2 olduğunda 100 puanlık işlemleri yapmayı sağlar.
                printf("\n100 Puan Geldi. Puani kazanmak icin en az 2 dogru tahmin gerekiyor. \n");
                sayac = tahmin_gir();
                if(sayac>=2){
                    printf("\nTebrikler! 100 Puan Kazandiniz. \n");
                    puan +=100;
                }
                else printf("\nUzgunum puan alamadiniz. Bilmeniz geren sayilar sunlardi: %d %d %d %d \n",istenenSayi1,istenenSayi2,istenenSayi3,istenenSayi4);
                printf("Guncel Puaniniz : %d \n",puan);
                break;
            case 3:  // rastgele üretilen sayı 3 olduğunda 250 puanlık işlemleri yapmayı sağlar.
                printf("\n250 Puan Geldi. Puani kazanmak icin en az 3 dogru tahmin gerekiyor. \n");
                sayac = tahmin_gir();
                if(sayac>=3){
                    printf("\nTebrikler! 250 Puan Kazandiniz. \n");
                    puan +=250;
                }
                else printf("\nUzgunum puan alamadiniz. Bilmeniz geren sayilar sunlardi: %d %d %d %d \n",istenenSayi1,istenenSayi2,istenenSayi3,istenenSayi4);
                printf("Guncel Puaniniz : %d \n",puan);
                break;
            case 4:   // rastgele üretilen sayı 4 olduğunda pas işlemini yapmayı sağlar.
                printf("\nPas geldi. Puaniniz degismedi. \n");
                printf("Guncel Puaniniz : %d \n",puan);
                break;
            case 5:   // rastgele üretilen sayı 5 olduğunda puan azaltma işlemini yapmayı sağlar.
                printf("\nPuan azaltma geldi. Puaninizin 1/4 unu kaybettiniz. \n");
                puan = puan-(puan*0.25);
                printf("Guncel Puaniniz : %d \n",puan);
                break;
            case 6:   // rastgele üretilen sayı 6 olduğunda iflas işlemini yapmayı sağlar.
                printf("\nIflas geldi. \n");
                islem='s';
                puan = 0;
                break;
            case 7: // kullanıcı 's' tuşuna bastığında programı sonlandırmayı sağlar.
                islem='s';
                break;
        }
    }
    printf("\n######### Oyun %d puanla sonlandi ######### \n\n",puan);
    return 0;
}

void sayi_uret(){
    srand(time(NULL));

    istenenSayi1 = 1+rand()%10;

    istenenSayi2 = 1+rand()%10;
    while(istenenSayi2==istenenSayi1){
        istenenSayi2 = 1+rand()%10;
    }

    istenenSayi3 = 1+rand()%10;
    while(istenenSayi3==istenenSayi1 || istenenSayi3==istenenSayi2){
        istenenSayi3 = 1+rand()%10;
    }

    istenenSayi4 = 1+rand()%10;
    while(istenenSayi4==istenenSayi1 || istenenSayi4==istenenSayi2 || istenenSayi4==istenenSayi3){
        istenenSayi4 = 1+rand()%10;
    }
}

int tahmin_gir(){

    int toplam=0;

    printf("1.sayiyi giriniz >  ");
    scanf("%d",&girilenSayi1);
    while(girilenSayi1<1 || girilenSayi1>10){
        printf("1.sayiyi giriniz (Lutfen 1-10 arasida sayi giriniz) > ");
        scanf("%d",&girilenSayi1);
    }

    printf("2.sayiyi giriniz >  ");
    scanf("%d",&girilenSayi2);
    while(girilenSayi2<1 || girilenSayi2>10){
        printf("2.sayiyi giriniz (Lutfen 1-10 arasida sayi giriniz) >  ");
        scanf("%d",&girilenSayi2);
    }

    printf("3.sayiyi giriniz >  ");
    scanf("%d",&girilenSayi3);
    while(girilenSayi3<1 || girilenSayi3>10){
        printf("3.sayiyi giriniz (Lutfen 1-10 arasida sayi giriniz) >  ");
        scanf("%d",&girilenSayi3);
    }

    printf("4.sayiyi giriniz >  ");
    scanf("%d",&girilenSayi4);
    while(girilenSayi4<1 || girilenSayi4>10){
        printf("4.sayiyi giriniz (Lutfen 1-10 arasida sayi giriniz)  >  ");
        scanf("%d",&girilenSayi4);
    }

    if(girilenSayi1==istenenSayi1 || girilenSayi1==istenenSayi2 || girilenSayi1==istenenSayi3 || girilenSayi1==istenenSayi4){
        toplam = toplam+1;
    }

    if(girilenSayi2==istenenSayi1 || girilenSayi2==istenenSayi2 || girilenSayi2==istenenSayi3 || girilenSayi2==istenenSayi4){
        if(girilenSayi2!=girilenSayi1) toplam = toplam+1;
    }

    if(girilenSayi3==istenenSayi1 || girilenSayi3==istenenSayi2 || girilenSayi3==istenenSayi3 || girilenSayi3==istenenSayi4){
        if(girilenSayi3!=girilenSayi2 && girilenSayi3!=girilenSayi1) toplam = toplam+1;
    }

    if(girilenSayi4==istenenSayi1 || girilenSayi4==istenenSayi2 || girilenSayi4==istenenSayi3 || girilenSayi4==istenenSayi4){
        if(girilenSayi4!=girilenSayi1 && girilenSayi4!=girilenSayi2 && girilenSayi4!=girilenSayi3) toplam = toplam+1;
    }
    return toplam;
}

int cark_cevir(){
    srand(time(NULL));
    sayi_uret();
    return 1+rand()%6;
}




