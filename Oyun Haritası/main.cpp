#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


/*
İsim: Ahmet
Soyisim: Ekti
Öğrenci Numarası: 151601010


  - UBUNTU ÜZERİNDEN -> CLion IDE ile yazilmistir.

*/


char xox_dizisi[3][3];

struct sayisalLoto{ // SAYISAL LOTONUN YAPILARI

    int girilenDeger[6];
    int verilenDeger[6];
    int geciciDeger_verilen;
    int geciciDeger_girilen;
    int geciciDeger_butunVeriler;
    int tutulan_deger;
    int butunElamanlar[50][2];

    int tumSayilar[255];
    int sayiDizisi[50] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24
            ,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49};
}loto;


struct sayiBulma { //SAYI BULMA KISMININ STRUCT YAPISI
    int rastgaleSayi_girilenDeger =0;
    int rastgaleSayi_degeri =0;
    int sayiBulma_hafiza = 0;
    int toplamGirilen_deneme =0;
    char cevap[8];
}sayi;

int sayisalLoto_Ekrani();
int hosgeldinEkrani();
int sayiBulma_Ekrani();
int xox_Ekrani();
int rastgaleSayi_uret(int rastgaleSayi_gelenDeger)
{
    if(sayi.sayiBulma_hafiza == 0) //Sayı bulma hafizasi kontrol ediliyor.
    {
        sayi.sayiBulma_hafiza = sayi.sayiBulma_hafiza + 1;
        srand(time(NULL));
        sayi.rastgaleSayi_degeri=rand()%98+1; //Rastgale deger olusturuluyor.

        if(rastgaleSayi_gelenDeger == sayi.rastgaleSayi_degeri)
        {
            printf("Tebrikler doğru bildiniz.\n");
            printf("Toplam girilen deneme = 1\n");

            printf("Tekrar oynamak ister misiniz: ");

            if(strcmp(sayi.cevap,"evet")==0) //cevabin tekrar oynamaksa degerler sifirlaniyor.
            {
                sayi.cevap;
                sayi.toplamGirilen_deneme =0;
                sayi.sayiBulma_hafiza =0;
                sayi.rastgaleSayi_degeri = 0;
                sayi.rastgaleSayi_girilenDeger =0;
                sayiBulma_Ekrani();
            }
            else if(strcmp(sayi.cevap,"hayır")==0)
            {
                sayi.cevap;
                sayi.toplamGirilen_deneme =0;
                sayi.sayiBulma_hafiza =0;
                sayi.rastgaleSayi_degeri = 0;
                sayi.rastgaleSayi_girilenDeger =0;
                hosgeldinEkrani();
            }
            else
            {
                sayi.cevap;
                sayi.toplamGirilen_deneme =0;
                sayi.sayiBulma_hafiza =0;
                sayi.rastgaleSayi_degeri = 0;
                sayi.rastgaleSayi_girilenDeger =0;
                printf("Lutfen evet veya hayır yazınız.\n");
            }


        }
        else if(rastgaleSayi_gelenDeger > sayi.rastgaleSayi_degeri)
        {
            //printf("Rastgale olusturulan sayi: %d\n",sayi.rastgaleSayi_degeri);
            printf("ASAGI\n");
            sayiBulma_Ekrani();
        }
        else if(rastgaleSayi_gelenDeger < sayi.rastgaleSayi_degeri)
        {
           // printf("Rastgale olusturulan sayi: %d\n",sayi.rastgaleSayi_degeri);
            printf("YUKARI\n");
            sayiBulma_Ekrani();
        }
        else
        {
            //printf("Rastgale olusturulan sayi: %d\n",sayi.rastgaleSayi_degeri);
            printf("Lutfen rakam giriniz.!\n");
            sayiBulma_Ekrani();
        }
    }
    else
    {

        if(rastgaleSayi_gelenDeger == sayi.rastgaleSayi_degeri)
        {

            printf("Tebrikler doğru bildiniz.\n");
            printf("Toplam girilen deneme %d\n",sayi.toplamGirilen_deneme);

            printf("Tekrar oynamak ister misiniz: ");
            scanf("%s",&sayi.cevap);

            if(strcmp(sayi.cevap,"evet")==0)
            {
                sayi.cevap;
                sayi.toplamGirilen_deneme =0;
                sayi.sayiBulma_hafiza =0;
                sayi.rastgaleSayi_degeri = 0;
                sayi.rastgaleSayi_girilenDeger =0;

                sayiBulma_Ekrani();
            }
            else if(strcmp(sayi.cevap,"hayır")==0)
            {
                sayi.cevap;
                sayi.toplamGirilen_deneme =0;
                sayi.sayiBulma_hafiza =0;
                sayi.rastgaleSayi_degeri = 0;
                sayi.rastgaleSayi_girilenDeger =0;

                hosgeldinEkrani();
            }
            else
            {
                sayi.cevap;
                sayi.toplamGirilen_deneme =0;
                sayi.sayiBulma_hafiza =0;
                sayi.rastgaleSayi_degeri = 0;
                sayi.rastgaleSayi_girilenDeger =0;

                printf("Lutfen evet veya hayır yazınız: ");
                scanf("%s",&sayi.cevap);
                printf("OYUN KAPATILDI. LUTFEN BİRDAHAKI SEFERE DOGRU YANIT VERINIZ \n");
            }
        }
        else if(rastgaleSayi_gelenDeger > sayi.rastgaleSayi_degeri)
        {
           // printf("Rastgale olusturulan sayi: %d\n",sayi.rastgaleSayi_degeri);
            printf("ASAGI\n");
            sayiBulma_Ekrani();
        }
        else if(rastgaleSayi_gelenDeger < sayi.rastgaleSayi_degeri)
        {
          //  printf("Rastgale olusturulan sayi: %d\n",sayi.rastgaleSayi_degeri);
            printf("YUKARI\n");
            sayiBulma_Ekrani();
        }
        else
        {
          //  printf("Rastgale olusturulan sayi: %d\n",sayi.rastgaleSayi_degeri);
            printf("Lutfen rakam giriniz.!\n");
            sayiBulma_Ekrani();
        }
    }
}

int sayiBulma_Ekrani() // -> Sayı Bulma Ekranı Burada Başlıyor.
{
    printf("Lutfen tutulan sayiyi tahmin ediniz: ");
    scanf("%d",&sayi.rastgaleSayi_girilenDeger);

    sayi.toplamGirilen_deneme = sayi.toplamGirilen_deneme +1;
    rastgaleSayi_uret(sayi.rastgaleSayi_girilenDeger);
}

int xox_tekrarOyna() // XOX oyununu tekrar başlatacaktır.
{
    for(int i=1; i<10; i++)
    {
        for(int j=1;j<10;j++)
        {
            xox_dizisi[i][j] = NULL;
        }
    }

    char cevap[10];
    printf("Tekrar oynamak ister misin:");

    scanf("%s",&cevap);

    if(strcmp(cevap,"evet") == 0     or strcmp(cevap,"EVET") == 0)
    {
        printf("\n\nOyuna tekrar basliyorsunuz.");
        xox_Ekrani();
    }
    else if(strcmp(cevap,"hayır") == 0 or strcmp(cevap,"HAYIR") == 0)
    {
        printf("\n\nOyun Sonlandırıldı");
        hosgeldinEkrani();
    }
    else
    {
        printf("Hatali sozcuk girdiniz.!\nLutfen tekrar deneyiniz.!\n\n");
        cevap[10] = NULL;
        xox_tekrarOyna();
    }

}

int xox_Ekrani() //XOX oyununa başlatacaktır.
{
    printf("\n\n  XOX OYUNU TABLOSU\n\n");
    for(int l=1;l<4;l++)
    {
        printf("\t");
        for(int m=1;m<4;m++)
        {
            printf("-\t");
        }
        printf("\n");
    }

    for(int k=1;k<10;k++)
    {
        int i,j;

        if(k%2 == 1)
        {
            printf("\nLutfen hangi satır ve sutuna yerlestirmeniz gerektigini seciniz.\n");
            printf("Sıra 'X' tarafinda.\n");
            printf("Satır: ");
            scanf("%d",&i);

            if((i >= 1 and i<= 3) != 1)
            {
                printf("\n\nGirdiginiz degerin: 0 - 4 arasinda olmasi gerekiyor! \n\n");
                xox_tekrarOyna();
            }

            printf("\nSütun: ");
            scanf("%d",&j);

            if((j >= 1 and j<= 3) != 1)
            {
                printf("\n\nGirdiginiz degerin: 0 - 4 arasinda olmasi gerekiyor! \n\n");
                xox_tekrarOyna();
            }


            if(xox_dizisi[i][j] == NULL)
            {
                xox_dizisi[i][j] = 'X';
                //Kontroller buradan yapmaya başlıyor.
                if(xox_dizisi[1][1] == 'X' and xox_dizisi[1][2] == 'X' and xox_dizisi[1][3] == 'X')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (X) \n");
                    xox_tekrarOyna();
                    k = 10;
                }
                else if(xox_dizisi[2][1] == 'X' and xox_dizisi[2][2] == 'X' and xox_dizisi[2][3] == 'X')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (X) \n");
                    xox_tekrarOyna();
                    k = 10;
                }
                else if(xox_dizisi[3][1] == 'X' and xox_dizisi[3][2] == 'X' and xox_dizisi[3][3] == 'X')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (X) \n");
                    xox_tekrarOyna();
                    k = 10;
                }
                else if(xox_dizisi[1][1] == 'X' and xox_dizisi[2][1] == 'X' and xox_dizisi[3][1] == 'X')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (X) \n");
                    xox_tekrarOyna();
                    k = 10;
                }
                else if(xox_dizisi[1][2] == 'X' and xox_dizisi[2][2] == 'X' and xox_dizisi[3][2] == 'X')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (X) \n");
                    xox_tekrarOyna();
                    k = 10;
                }
                else if(xox_dizisi[1][3] == 'X' and xox_dizisi[2][3] == 'X' and xox_dizisi[3][3] == 'X')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (X) \n");
                    xox_tekrarOyna();
                    k = 10;
                }
                else if(xox_dizisi[1][1] == 'X' and xox_dizisi[2][2] == 'X' and xox_dizisi[3][3] == 'X')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (X) \n");
                    xox_tekrarOyna();
                    k = 10;
                }
                else if(xox_dizisi[1][3] == 'X' and xox_dizisi[2][2] == 'X' and xox_dizisi[3][1] == 'X')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (X) \n");
                    xox_tekrarOyna();
                    k = 10;
                }
            }
            else
            {
                printf("Girdiginiz deger onceden doldurulmustur. \n");
                printf("Lutfen tekrar deneyin.\n");
                k = k -1;
            }
        }
        else if(k%2 == 0)
        {
            printf("\nLutfen hangi satır ve sutuna yerlestirmeniz gerektigini seciniz\n");
            printf("Sıra 'O' tarafinda.\n");
            printf("Satır: ");
            scanf("%d",&i);
            if((i >= 1 and i<= 3) != 1)
            {
                printf("\n\nGirdiginiz degerin: 0 - 4 arasinda olmasi gerekiyor! \n\n");
                xox_tekrarOyna();
            }

            printf("\nSütun: ");
            scanf("%d",&j);

            if((j >= 1 and j<= 3) != 1)
            {
                printf("\n\nGirdiginiz degerin: 0 - 4 arasinda olmasi gerekiyor! \n\n");
                xox_tekrarOyna();
            }

            if(xox_dizisi[i][j] == NULL)
            {
                xox_dizisi[i][j] = 'O';

                if(xox_dizisi[1][1] == 'O' and xox_dizisi[1][2] == 'O' and xox_dizisi[1][3] == 'O')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (O) \n");
                    xox_tekrarOyna();
                    k = 10;
                }
                else if(xox_dizisi[2][1] == 'O' and xox_dizisi[2][2] == 'O' and xox_dizisi[2][3] == 'O')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (O) \n");
                    xox_tekrarOyna();
                    k = 10;
                }
                else if(xox_dizisi[3][1] == 'O' and xox_dizisi[3][2] == 'O' and xox_dizisi[3][3] == 'O')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (O) \n");
                    xox_tekrarOyna();
                    k = 10;
                }
                else if(xox_dizisi[1][1] == 'O' and xox_dizisi[2][1] == 'O' and xox_dizisi[3][1] == 'O')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (O) \n");
                    xox_tekrarOyna();

                    k = 10;
                }
                else if(xox_dizisi[2][1] == 'O' and xox_dizisi[2][2] == 'O' and xox_dizisi[3][2] == 'O')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (O) \n");
                    xox_tekrarOyna();

                    k = 10;
                }
                else if(xox_dizisi[1][3] == 'O' and xox_dizisi[2][3] == 'O' and xox_dizisi[3][3] == 'O')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (O) \n");
                    xox_tekrarOyna();

                    k = 10;
                }
                else if(xox_dizisi[1][1] == 'O' and xox_dizisi[2][2] == 'O' and xox_dizisi[3][3] == 'O')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (O) \n");
                    xox_tekrarOyna();

                    k = 10;
                }
                else if(xox_dizisi[1][3] == 'O' and xox_dizisi[2][2] == 'O' and xox_dizisi[3][1] == 'O')
                {
                    printf("OYUN BİTTİ.\n");
                    printf("KAZANAN SENSİN. (O) \n");
                    xox_tekrarOyna();

                    k = 10;
                }
            }
            else //Eğer daha önceden değer doluysa böyle bir hata verecektir.
            {
                printf("Girdiginiz deger onceden doldurulmustur.\n");
                printf("Lutfen tekrar deneyin.\n");
                k = k-1;
            }
        }
        else // 1,2,3 değerleri haricinde değer girilemeyecektir.
        {
            printf("Lutfen 1-2-3 değerini giriniz.");
            k = k -1;
        }
        printf("\n");
        for(int l=1;l<4;l++)
        {
            for(int m=1;m<4;m++)
            {
                if(xox_dizisi[l][m] == NULL)
                {
                    printf("-\t");
                }
                else if(xox_dizisi[l][m] != NULL)
                {
                    printf("%c\t",xox_dizisi[l][m]);
                }
            }
            printf("\n");
        }

        if(k == 9) //9 olduğunda bitecektir.
        {
            printf("\nOyun Berabere Bitmistir. \n");
            xox_tekrarOyna();
        }
    }

}

int sayisalLoto_tekrarOyna() //Sayısal loto oyununu tekrar başlatacaktır.
{

    for(int i=1; i<10; i++)
    {
        for(int j=1;j<10;j++)
        {
            xox_dizisi[i][j] = NULL;
        }
    }

    char cevap[10];
    printf("Tekrar oynamak ister misin:");

    scanf("%s",&cevap);

    if(strcmp(cevap,"evet") == 0     or strcmp(cevap,"EVET") == 0)
    {
        printf("\n\nOyuna tekrar basliyorsunuz.");
        sayisalLoto_Ekrani();
    }
    else if(strcmp(cevap,"hayır") == 0 or strcmp(cevap,"HAYIR") == 0)
    {
        printf("\n\nOyun Sonlandırıldı");
        hosgeldinEkrani();
    }
    else
    {
        printf("Hatali sozcuk girdiniz.!\nLutfen tekrar deneyiniz.!\n\n");
        cevap[10] = NULL;
        sayisalLoto_tekrarOyna();
    }

}

int sayisalLoto_Ekrani()  //SAYISAL LOTO OYUNUN ANA KISMIDIR.!
{
    int secimYap;
    printf("\n************************************\n");
    printf("*                                  *\n");
    printf("*           Sayısal Loto           *\n");
    printf("*                                  *\n");
    printf("************************************\n");

    printf("1-) Kullanici Loto Cekilisi\n");
    printf("2-) Istatistikler\n");
    printf("3-) Ana Menuye dön\n");

    printf("\n->Lutfen secim yapiniz: ");
    scanf("%d",&secimYap);

    if(secimYap == 1) //Kullanıcı Loto Çekilişi
    {
        int toplamSayi=0;
        while( loto.tumSayilar[toplamSayi] != '\0' )
            toplamSayi++;

        srand(time(NULL));

        for (int j=0;j<6;j++) //Rastgale sayıları üretiyor.
        {
            loto.verilenDeger[j] = 1+rand()%49;

            loto.tumSayilar[toplamSayi] = loto.verilenDeger[j];
            toplamSayi = toplamSayi +1;
        }
        for (int i =0; i<6; i++) // Sayı girilme ekranıdır.
        {
            printf("%d.sayiyi giriniz: ",i+1);
            scanf("%d",&loto.girilenDeger[i]);

            if((loto.girilenDeger[i] > 0 and loto.girilenDeger[i] < 50) != 1)
            {
                printf("\nLutfen 1-49 arasinda bir deger giriniz.\n");
                i = i -1;
            }
        }

        for (int i = 0; i <6; ++i)  //Seçtiğim Sonuçları Küçükten büyüğe sıraladık.
        {
            for(int j=0; j<6; j++)
            {
                if(loto.girilenDeger[i] < loto.girilenDeger[j])
                {
                    loto.geciciDeger_girilen = loto.girilenDeger[i];
                    loto.girilenDeger[i] = loto.girilenDeger[j];
                    loto.girilenDeger[j] = loto.geciciDeger_girilen;
                }
            }
        }

        for (int i = 0; i <6; ++i)  //Sayısal Loto Sonuçlarını Küçükten büyüğe sıraladık.
        {
            for(int j=0; j<6; j++)
            {
                if(loto.verilenDeger[i] < loto.verilenDeger[j])
                {
                    loto.geciciDeger_verilen = loto.verilenDeger[i];
                    loto.verilenDeger[i] = loto.verilenDeger[j];
                    loto.verilenDeger[j] = loto.geciciDeger_verilen;
                }
            }
        }
        for(int i=0;i<6;i++) //Tutan sayıları kontrol ediyor.
        {
            for(int j=0; j<6;j++)
            {
                if(loto.girilenDeger[i] == loto.verilenDeger[j]) //Eğer sayılar eşitse +1 liyoruz.
                {
                    loto.tutulan_deger = loto.tutulan_deger + 1;
                }
            }
        }
        printf("\nTahmin Ettiklerim\t-\tSayısal Loto Sonuclari \n"); //Tahmin ettiğin sayıların grafiği

        for (int i =0; i<6; i++) // Sayısal Loto sonuçlarını göster.
        {
            printf("\t%d\t\t\t\t\t\t\t%d\n",loto.girilenDeger[i],loto.verilenDeger[i]);
        }
        printf("\n%d rakam tutturdunuz.\n\n",loto.tutulan_deger);

        sayisalLoto_tekrarOyna();

    }
    else if(secimYap == 2) //Grafikleri cagirir.
    {
        printf("\n\n1-) Tüm sayıların tekrarı ve istatistiklerinin grafigi");
        printf("\n2-) En az 1 kere cikan sayilar ve istatiskler grafigi\n");
        printf("3-) Geri cik\n");
        int cevap;
        printf("Tercih Et: ");
        scanf("%d",&cevap);

        if(cevap == 1) //- 1.Grafiği seç
        {
            printf("\n\n\tSayı\t\tKez\t\tÇubuk Grafik");
            printf("\n----------------------------------------");

            for(int i=0;i<49;i++)
            {
                loto.butunElamanlar[i][1] = loto.sayiDizisi[i]; //butunElamanlara sayidizisini eklesin.

                for(int j=0;j<6;j++)
                {
                    if(loto.sayiDizisi[i] == loto.verilenDeger[j]) //sayidizisinde verilen deger var mı diye baksın.
                    {
                        loto.butunElamanlar[i][2] = loto.butunElamanlar[i][2] + 1; // varsa eger indisi 1 arttırsın.
                    }
                }

                printf("\n\t%d\t\t\t%d\t\t",loto.butunElamanlar[i][1],loto.butunElamanlar[i][2]);

                for (int k = 0; k < loto.butunElamanlar[i][2]; k++) // butunelamanların hafızada tuttugu deger kadar yıldız koyuyoruz.
                {
                    printf("*");
                }

                if(i==48)
                {
                    for (int j = 0; j < 6; j++)
                    {
                        loto.verilenDeger[j] = NULL;
                    }
                }

            }

            int geridon;
            printf("\n\nAna menuye donmek icin: '0' tusuna basiniz: ");
            scanf("%d",&geridon);

            if(geridon == 0)
            {
                hosgeldinEkrani();
            }
            else
            {
                printf("Hatali tus girdiniz.!\n");
                printf("Ana menuye yonlendiriliyorsunuz.! \n");
            }

        }
        else if(cevap == 2) //2.Grafikleri olusturur.
        {

            printf("\n\n\tSayı\t\tKez\t\tÇubuk Grafik");
            printf("\n----------------------------------------");

            for(int i=0;i<49;i++)
            {
                loto.butunElamanlar[i][1] = loto.sayiDizisi[i]; //Sayi dizilerini butun elamanlar dizisine aktarır.

                for(int j=0;j<6;j++)
                {
                    if(loto.sayiDizisi[i] == loto.verilenDeger[j]) //Eger sayi dizisiyle verilen deger eşitse
                    {
                        loto.butunElamanlar[i][2] = loto.butunElamanlar[i][2] + 1; //butunElemanların 2.indisini bir arttır.
                    }
                }

                for (int l = 0; l <loto.butunElamanlar[l][2]; ++i)  //Sayısal Loto Sonuçlarını Küçükten büyüğe sıraladık.
                {
                    for(int m=0; m<loto.butunElamanlar[m][2]; m++)
                    {
                        if(loto.butunElamanlar[l][2] < loto.butunElamanlar[m][2])
                        {
                            loto.geciciDeger_butunVeriler = loto.butunElamanlar[l][2];
                            loto.butunElamanlar[l][2] = loto.verilenDeger[m];
                            loto.butunElamanlar[m][2] = loto.geciciDeger_butunVeriler;
                        }
                    }
                }

                if(i != 48) //48 olunca durdursun ki birdahaki sefere hafizada tutulan sayilari eklemesin.
                {
                    if(loto.butunElamanlar[i][2] != 0)
                    {
                        printf("\n\t%d\t\t\t%d\t\t",loto.butunElamanlar[i][1],loto.butunElamanlar[i][2]);
                    }

                    for (int k = 0; k < loto.butunElamanlar[i][2]; k++)
                    {
                        printf("*");
                    }
                }
                else{

                    for (int j = 0; j < 6; j++)
                    {
                        loto.verilenDeger[j] = NULL;

                        i = 49;
                    }
                }
            }
            int geridon;
            printf("\n\nAna menuye donmek icin: '0' tusuna basiniz: ");
            scanf("%d",&geridon);

            if(geridon == 0)
            {
                hosgeldinEkrani();
            }
            else
            {
                printf("Hatali tus girdiniz.!\n");
                printf("Ana menuye yonlendiriliyorsunuz.! \n");
            }
        }
        else
        {
            printf("\nLutfen 1 veya 2 degerini giriniz!");
        }

    }
    else if(secimYap == 3)
    {
        hosgeldinEkrani();
    }
    else
    {
        printf("Lutfen 0-4 arasinda bir tercih yapiniz!");
        hosgeldinEkrani();
    }

}


int cikisYap_Ekrani()
{
    printf("Cikis yapma ekranını seçtiniz. \n");
}

int hosgeldinEkrani() //Hosgeldin menusu buradadır.
{

    int secimYap;
    printf("\n***********************************\n");
    printf("*                                 *\n");
    printf("*           Hosgeldiniz           *\n");
    printf("*                                 *\n");
    printf("***********************************\n");

    printf("1-) Sayı Bulma\n");
    printf("2-) XOX (Tic Tac Toe) Simulasyonu\n");
    printf("3-) Sayisal Loto Simulasyonu\n");
    printf("4-) Cikis yap\n");

    printf("\n->Lutfen secim yapiniz: ");
    scanf("%d",&secimYap);

    if(secimYap == 1)
    {
        sayiBulma_Ekrani();
    }
    else if(secimYap == 2)
    {
        xox_Ekrani();
    }
    else if(secimYap == 3)
    {
        sayisalLoto_Ekrani();
    }
    else if(secimYap == 4)
    {
        cikisYap_Ekrani();
        exit(0); //Cikis yapmak icin gerekli kod satırıdır.
    }
    else
    {
        printf("Lutfen 0-5 arasinda bir tercih yapiniz!");
        hosgeldinEkrani();
    }

}

int main()
{
    hosgeldinEkrani();
}










