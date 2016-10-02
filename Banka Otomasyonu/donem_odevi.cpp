#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

/*
Bazý gerekli olabilecek bilgiler þunlardýr.  

******PARA GONDERÝMÝ SIRASINDA LAZIM OLACAKTIR.!*****

--Ana kullanici ismi-soyisimi: Ahmet Ekti

--Ana kullanici numarasi: 1780477846

--Ana kullanici sifresi: gattussa

--Ana kullanici dogumTarihi: 13.07.1996

**Yan kullanici ismi-soyismi: Tugrul Vanlý

**Yan kullanici numarasi: 3973621609

**Yan kullanici dogumTarihi: 12.08.1996

*/


char musteri_numara[255]; 
char kullanici_sifre[20];
int gonderilen_para;
int hata_durumu =0;
int main();
int sablon_menu();
int ekrani_temizle();
int secim_ekran();
int kullanici_menu();
int kullanici_sayfasi();

struct ogrenci
{
   	char numara[255];
	char sifre[20];
	char isim[255];
	char soyisim[255];
	char adres[255];
	char cinsiyet[255];
	char dogumTarihi[255];
	char hesapturu[255];
	int bakiyeTL;
	int dolarim;
	int eurom;
	int altinim;
		 
	char numara2[255];
	char sifre2[20];
	char isim2[255];
	char soyisim2[255];
	char adres2[255];
	char cinsiyet2[255];
	char dogumTarihi2[255];
	char hesapturu2[255];
	int bakiyeTL2;
	int dolarim2;
	int eurom2;
	int altinim2;
	
} 
kayit;

/*
Doviz bölümü
Program kendisi finansal degerlerini atar. Dolar,Euro,Altýn olarak.
/satinal bölümü mevcuttur. Burada belirlenen finansal degerlerden birini satin alabiliriz ve bakiyemize ekleriz.
/satisyap bölümü mevcuttur. Elinden bulunan diger para birimlerinden satis yapabilirsiniz ve TurkLiranizi arttirabilirsiniz.
*/

doviz() 
{
	srand(time(0));
	float deneme = (float)1+rand()/50.5;
	float euro = (float)1+rand()/5000.5;
	float altin = (float)rand()/405.4;
	float dolar = (float)rand()/3004.5;
	sablon_menu();	
	printf("\n\n\t**********************************\n");
	printf("\t***********Doviz Bakiyesi*********");
	printf("\n\t********************************** 	==> Istediginiz zaman bu alandan satin alip satis yapabilirsiniz.\n");
	printf("\t*      Dolar: %d		 *\n",kayit.dolarim);	
	printf("\t*       Euro: %d		 *  	==> Herzaman icin en uygun firsatlar sizi bekliyor olacak.\n",kayit.eurom);
	printf("\t*      Altin: %d                *\n",kayit.altinim);
	printf("\t*     Bakiye: %dTL		 *  	==> Geri donmek icin /kullanici_ekrani yazmaniz yeterlidir.\n",kayit.bakiyeTL);
	printf("\t* Hesap Turu: %s		 *	==> Yardim menusune ulasmak icin: /yardim yazabilirsiniz.\n",kayit.hesapturu);
	printf("\t**********************************\n");
	
	printf("\n\tSatin alma islemi yapmak istiyorsaniz: /satinal yazmaniz yeterlidir.\n");
	printf("\tSatis islemi yapmak istiyorsaniz: /satisyap yazmaniz yeterlidir.\n");
	printf("\tMenuden cikis yapmak istiyorsaniz: /cikis yazmaniz yeterlidir.\n");
	char satislemleri[255];
	printf("\n\tSecim islemini gerceklestiriniz: ");
	scanf("%s",satislemleri);
	
	//Elinizdeki mevcut türk lirasi ile diger para birimlerinden satin alabilirsiniz.
	if(strcmp(satislemleri,"/satinal")==0)
	{
		ekrani_temizle();
		sablon_menu();
		
		printf("\n\n\t\t\t1: Dolar satin almak istiyorsaniz seciniz.\n");
		printf("\t\t\t2: Euro satin almak istiyorsaniz seciniz.\n");
		printf("\t\t\t3: Altin satin almak istiyorsaniz seciniz.\n");
		printf("\t\t\t4: Geri donmek istiyorsaniz. Secim isleminden ciktiysaniz /doviz yazmalisiniz.\n");
		int satisislemleri_secim;
		
		printf("\n\tSecim islemini gerceklestiriniz: ");
		scanf("%d",&satisislemleri_secim);
	
		switch(satisislemleri_secim)
		{
			case 1:
				{
					int miktar;
					printf("\n\n\t1 Dolar: %fTL",dolar);
					printf("\n\tNe kadar dolar satin almak istiyorsunuz ?: ");
					scanf("%d",&miktar);
					int yedekbakiye;
				
					yedekbakiye = kayit.bakiyeTL;
					kayit.dolarim= miktar+kayit.dolarim;
					kayit.bakiyeTL = kayit.bakiyeTL- dolar*miktar;
					
						if(kayit.bakiyeTL>=0)
						{
	
							
								FILE *fp;  
 			 			if((fp=fopen("bilgiler.dat", "wb"))==NULL)   
    				{     
  	 					 printf("Dosya acilamadi...\n");
					}
	  			else 
	   				{      
						fwrite(&kayit, sizeof(kayit), 1, fp);
						fclose(fp);  
						printf("\n\tBasariyla %d dolar satin alindi.\n",miktar);
						printf("\tToplam dolar: %d",kayit.dolarim);
						printf("\n\tGeri gitmek icin: /doviz yazmaniz yeterli.\n");
	   				} 
						}	
						else
						{
							printf("\n\tMaalesef bakiyeniz yetersiz.\n");	
							kayit.bakiyeTL=yedekbakiye;
						}
	   				break;
				}
				
					case 2:
				{
					int miktar;
					printf("\n\n\t1 Euro: %fTL",euro);
					printf("\n\tNe kadar euro satin almak istiyorsunuz ?: ");
					scanf("%d",&miktar);
					int yedekbakiye2;
					yedekbakiye2 = kayit.bakiyeTL;
					kayit.eurom= miktar + kayit.eurom;
					kayit.bakiyeTL = kayit.bakiyeTL- euro*miktar;	
					
						if(kayit.bakiyeTL>=0)
						{
								FILE *fp;  
 			 			if((fp=fopen("bilgiler.dat", "wb"))==NULL)   
    				{     
  	 					 printf("Dosya acilamadi...\n");
					}
	  			else 
	   				{      
						fwrite(&kayit, sizeof(kayit), 1, fp);
						fclose(fp);  
						printf("\n\tBasariyla %d euro satin alindi.\n",miktar);
						printf("\tToplam euro: %d\n",kayit.eurom);
			        	printf("\n\tGeri gitmek icin: /doviz yazmaniz yeterli.\n");
	   				} 
						}	
						else
						{
							printf("\n\tMaalesef bakiyeniz yetersiz.\n");	
							kayit.bakiyeTL=yedekbakiye2;
						}
	   				break;
				}
				
					case 3:
				{
					int miktar;
					printf("\n\n\t1gr Altin: %fTL",euro);
					printf("\n\tNe kadar altin satin almak istiyorsunuz ?: ");
					scanf("%d",&miktar);
					int yedekbakiye3;
					yedekbakiye3 = kayit.bakiyeTL;
					kayit.altinim  = miktar + kayit.altinim;
					kayit.bakiyeTL = kayit.bakiyeTL- altin*miktar;	
						
						if(kayit.bakiyeTL>=0)
						{
								FILE *fp;  
 			 			if((fp=fopen("bilgiler.dat", "wb"))==NULL)   
    				{     
  	 					 printf("Dosya acilamadi...\n");
					}
	  			else 
	   				{      
						fwrite(&kayit, sizeof(kayit), 1, fp);
						fclose(fp);  
						printf("\n\tBasariyla %dgr altin satin alindi.\n",miktar);
						printf("\tToplam altin: %dgr\n",kayit.altinim);
			        	printf("\n\tGeri gitmek icin: /doviz yazmaniz yeterli.\n");
	   				} 
						}	
						else
						{
							printf("\n\tMaalesef bakiyeniz yetersiz.\n");	
							kayit.bakiyeTL=yedekbakiye3;
						}
	   				break;
				}
				
				case 4:
			{
				ekrani_temizle();
				doviz();
				break;
			}
		
				default:
				{
					printf("\n\tLutfen seceneklerden birini seciniz.");
					printf("\n\tGeri donmek icin: /borsa yazmalisiniz.\n");
					break;
				}
		}
				
	}
	//Elinizde bulunan diger para birimlerinin satisini yapabilirsiniz, dönüþtürebilirsiniz.
	else if(strcmp(satislemleri,"/satisyap")==0)
	{
		ekrani_temizle();
		sablon_menu();
		
		printf("\n\n\t\t\t1: Dolar satmak istiyorsaniz seciniz.\n");
		printf("\t\t\t2: Euro satmak istiyorsaniz seciniz.\n");
		printf("\t\t\t3: Altin satmak istiyorsaniz seciniz.\n");
		printf("\t\t\t4: Geri donmek istiyorsaniz. Secim isleminden ciktiysaniz /doviz yazmalisiniz.\n");
		int satisislemleri_secim;
		
		printf("\n\tSecim islemini gerceklestiriniz: ");
		scanf("%d",&satisislemleri_secim);
	
		switch(satisislemleri_secim)
		{
			case 1:
				{
					int miktar;
					printf("\tMevcut dolariniz: %d\n",kayit.dolarim);
					printf("\tMevcut Turk Liraniz: %d",kayit.bakiyeTL);
					printf("\n\n\t1 Dolar: %fTL",dolar);
					printf("\n\tNe kadar dolar satmak istiyorsunuz ?: ");
					scanf("%d",&miktar);
					
					if(kayit.dolarim-miktar>=0)
					{
					int yedekbakiye;
				
					yedekbakiye = kayit.bakiyeTL;
					kayit.dolarim= kayit.dolarim-miktar;
					kayit.bakiyeTL = kayit.bakiyeTL+ dolar*miktar;
					
						if(kayit.bakiyeTL>=0)
						{	
					
						FILE *fp;  
 			 			if((fp=fopen("bilgiler.dat", "wb"))==NULL)   
    				{     
  	 					 printf("Dosya acilamadi...\n");
					}
	  			else 
	   				{      
						fwrite(&kayit, sizeof(kayit), 1, fp);
						fclose(fp);  
						printf("\n\tBasariyla %d dolar satin alindi.\n",miktar);
						printf("\tToplam TurkLiraniz: %d",kayit.bakiyeTL);
						printf("\n\tGeri gitmek icin: /doviz yazmaniz yeterli.\n");
	   				} 
						}	
						else
						{
							printf("\n\tMaalesef bakiyeniz yetersiz.\n\a\a\a\a\a\a");	
							kayit.bakiyeTL=yedekbakiye;
						}
	   				
				}
				else
				{
					printf("O miktarda dolariniz bulunmamaktadir.\a\a\a\a\a");
				}
				break;	
			}
			
			case 2:
				{
					int miktar;
					printf("\tMevcut Euro: %d\n",kayit.eurom);
					printf("\tMevcut Turk Liraniz: %d",kayit.bakiyeTL);
					printf("\n\n\t1 Euro: %fTL",euro);
					printf("\n\tNe kadar euro satmak istiyorsunuz ?: ");
					scanf("%d",&miktar);
					
					if(kayit.eurom-miktar>=0)
					{
					int yedekbakiye2;
				
					yedekbakiye2 = kayit.bakiyeTL;
					kayit.eurom= kayit.eurom-miktar;
					kayit.bakiyeTL = kayit.bakiyeTL+ euro*miktar;
					
						if(kayit.bakiyeTL>=0)
						{	
					
						FILE *fp;  
 			 			if((fp=fopen("bilgiler.dat", "wb"))==NULL)   
    				{     
  	 					 printf("Dosya acilamadi...\n");
					}
	  			else 
	   				{      
						fwrite(&kayit, sizeof(kayit), 1, fp);
						fclose(fp);  
						printf("\n\tBasariyla %d euro satin alindi.\n",miktar);
						printf("\tToplam TurkLiraniz: %d",kayit.bakiyeTL);
						printf("\n\tGeri gitmek icin: /doviz yazmaniz yeterli.\n");
	   				} 
						}	
						else
						{
							printf("\n\tMaalesef bakiyeniz yetersiz.\n\a\a\a\a");	
							kayit.bakiyeTL=yedekbakiye2;
						}
	   				
				}
				else
				{
					printf("O miktarda dolariniz bulunmamaktadir.\a\a\a\a");
				}
				break;	
			}
			
			case 3:
				{
					int miktar;
					printf("\tMevcut Altin: %d\n",kayit.altinim);
					printf("\tMevcut Turk Liraniz: %d",kayit.bakiyeTL);
					printf("\n\n\t1gr Altin: %fTL",altin);
					printf("\n\tKac gr altin satmak istiyorsunuz ?: ");
					scanf("%d",&miktar);
					
					if(kayit.altinim-miktar>=0)
					{
					int yedekbakiye3;
				
					yedekbakiye3 = kayit.bakiyeTL;
					kayit.altinim= kayit.altinim-miktar;
					kayit.bakiyeTL = kayit.bakiyeTL+ altin*miktar;
					
						if(kayit.bakiyeTL>=0)
						{	
					
						FILE *fp;  
 			 			if((fp=fopen("bilgiler.dat", "wb"))==NULL)   
    				{     
  	 					 printf("Dosya acilamadi...\n\a\a");
					}
	  			else 
	   				{      
						fwrite(&kayit, sizeof(kayit), 1, fp);
						fclose(fp);  
						printf("\n\tBasariyla %dgr altin satin alindi.\n",miktar);
						printf("\tToplam TurkLiraniz: %d",kayit.bakiyeTL);
						printf("\n\tGeri gitmek icin: /doviz yazmaniz yeterli.\n");
	   				} 
						}	
						else
						{
							printf("\n\tMaalesef bakiyeniz yetersiz.\n\a\a\a");	
							kayit.bakiyeTL=yedekbakiye3;
						}
	   				
				}
				else
				{
					printf("O miktarda dolariniz bulunmamaktadir.\a\a\a");
				}
				break;	
			}
			
			default:
				{
					printf("\n\tLutfen seceneklerden birini seciniz.\a\a\a\a");
					printf("\n\tGeri donmek icin: /borsa yazmalisiniz.\n");
					break;
				}	
	}
}	
	//Programdan cikis yapabilirsiniz.
	else if(strcmp(satislemleri,"/cikis")==0)
	{
		ekrani_temizle();
		kullanici_sayfasi();
	}
	else
	{
		ekrani_temizle();
		printf("\a\a\a\a");
		doviz();
		
	}
}

/*
	Bu bölümde kullanici bilgilerinizi deðiþtirebilirsiniz.
	Deðiþtirelebilir kullanici bilgileri þunlardir.
	-Kullanici numarasi
	-Kullanici sifresi
	-Dogum tarihi
	Burada deðiþtirildiginde veri tabanýndada deðiþtirilecektir.
*/
ayarlar()
{
	sablon_menu();	
	printf("\n\n\t**********************************\n");
	printf("\t*********Kisisel Bilgilerim*******");
	printf("\n\t********************************** 	==> Kisisel bilgilerinize bu bolum uzerinden bakabilirsiniz.\n");
	printf("\t*         Ad: %s		 *\n",kayit.isim);
	printf("\t*      Soyad: %s		 *	==> /bilgilerimi_duzenle diyerek bilgilerinizi duzenleyebilirsiniz.\n",kayit.soyisim);
	printf("\t*      Adres: %s		 *\n",kayit.adres);
	printf("\t*   Cinsiyet: %s		 *	==> /Geri donmek icin /kullanici_ekrani yazmaniz yeterlidir.\n",kayit.cinsiyet);
	printf("\t*   D.Tarihi: %s	 *\n",kayit.dogumTarihi);
	printf("\t* Hesap Turu: %s		 *	==> Yardim menusune ulasmak icin: /yardim yazabilirsiniz.\n",kayit.hesapturu);
	printf("\t**********************************\n");
		
}
/*
	Bu bölümde diger oluþturulan Tugrul Vanli adindaki kullaniciya para aktarimi yapilabilir.
	En basta belirtildigi gibi bazi güvenlik bilgileri soracaktir bu bilgileri yukaridan alarak doldurabilirsiniz.
	Bakiyeniz eðer yoksa mevcut miktari gönderemezsiniz.
*/
para_aktarma()
{
	sablon_menu();

	printf("\n\n   Hosgeldin %s %s; \n       Bu bu menuden arkadaslariniza, akrabalariniza veya baska kullanicilarimiza para aktarimi yapabilirsiniz.\n",kayit.isim,kayit.soyisim);
	printf("       Guvenlik nedeniyle para aktarimi yaparken bazi bilgilerinizi bizimle paylasmaniz gerekecektir.\n");
	printf("       Para aktarimini gerceklestirdikten sonra bakiyenize bakmayi unutmayiniz. /bakiye yazarak ulasabilirsiniz.\n\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t1: 50TL gondermek istiyorsaniz seciniz.\n");
	printf("\t\t\t2: 200TL gondermek istiyorsaniz seciniz.\n");
	printf("\t\t\t3: 1000TL gondermek istiyorsaniz seciniz.\n");
	printf("\t\t\t4: Geri donmek istiyorsaniz. Secim isleminden ciktiysaniz /kullanici_ekrani yazmalisiniz.\n");
	
	int para_secim;
	printf("\n\tSecim islemini gerceklestiriniz: ");
	scanf("%d",&para_secim);
			
		switch(para_secim)
		{		
				
			case 1: 
			{
				if(kayit.bakiyeTL>=50)
			{	
				ekrani_temizle();
				sablon_menu();
				char gonderilenkullanici_numarasi[255];
				printf("\n\n\tGondermek istediginiz kullanici numarasi: ");
				scanf("%s",gonderilenkullanici_numarasi);
				
				if(strcmp(gonderilenkullanici_numarasi,kayit.numara2)==0)
				{
					char onay[255];
					printf("\n\tParayi gondermek istediginiz kullanici: %s %s\n",kayit.isim2,kayit.soyisim2);
					printf("\tOnayliyormusunuz(E/H) ?: ");
					scanf("%s",onay);
					if(strcmp(onay,"e") == 0 || strcmp(onay,"E") == 0)
					{
					char redogumTarihi[255];
					printf("\n\t\t\t\t   Dogum Tarihinizi giriniz: ");
					scanf("%s",redogumTarihi);
				
				if(strcmp(redogumTarihi,kayit.dogumTarihi) == 0 )
					{	
						kayit.bakiyeTL = kayit.bakiyeTL-50;
  						FILE *fp;  
 			 			if((fp=fopen("bilgiler.dat", "wb"))==NULL)   
    				{     
  	 					 printf("Dosya acilamadi...\n");
					}
	  			else 
	   				{      
						fwrite(&kayit, sizeof(kayit), 1, fp);
						fclose(fp);  
						printf("\n\tPara aktarimi basariyla gerceklestirildi.\n");
						printf("\n\tGeri donmek icin: /para_aktarma yazmalisiniz.\n");	
	   				} 
					}
				else
					{
						printf("\n\tGirdiginiz kullanici kimlikleri birbiriyle eslesmiyor.!");
						printf("\n\tGeri donmek icin: /para_aktarma yazmalisiniz.\n");	
					}
					}
					else if(strcmp(onay,"h") == 0 || strcmp(onay,"H") == 0)
					{
						ekrani_temizle();
						para_aktarma();
					}
					
					else
					{
						printf("\n\tLutfen E/H seceneklerinden birini seciniz.");
						printf("\n\tGeri donmek icin: /para_aktarma yazmaniz yeterlidir.\n");
					}
			
				}
				else
					{
						printf("\n\tGondermek istediginiz kullanici bulunamamaktadir.");
						printf("\n\tGeri donmek icin: /para_aktarma yazmalisiniz.\n");					
					}
					break;
		}
			else
	{
		printf("\n\tYeterli bakiyeniz bulunmamaktadir.");
		printf("\n\tGeri donmek icin: /para_aktarma yazmalisiniz.\n");	
	}
	}			
			case 2: 
			{
				if(kayit.bakiyeTL>=200)
				{
				ekrani_temizle();
				sablon_menu();
				char gonderilenkullanici_numarasi[255];
				printf("\n\n\tGondermek istediginiz kullanici numarasi: ");
				scanf("%s",gonderilenkullanici_numarasi);
				
				if(strcmp(gonderilenkullanici_numarasi,kayit.numara2)==0)
				{
					char onay[255];
					printf("\n\tParayi gondermek istediginiz kullanici: %s %s\n",kayit.isim2,kayit.soyisim2);
					printf("\tOnayliyormusunuz(E/H) ?: ");
					scanf("%s",onay);
					if(strcmp(onay,"e") == 0 || strcmp(onay,"E") == 0)
					{
					char redogumTarihi[255];
					printf("\n\t\t\t\t   Dogum Tarihinizi giriniz: ");
					scanf("%s",redogumTarihi);
				
				if(strcmp(redogumTarihi,kayit.dogumTarihi) == 0 )
					{	
						kayit.bakiyeTL = kayit.bakiyeTL-200;
  						FILE *fp;  
 			 			if((fp=fopen("bilgiler.dat", "wb"))==NULL)   
    				{     
  	 					 printf("Dosya acilamadi...\n");
					}
	  			else 
	   				{      
						fwrite(&kayit, sizeof(kayit), 1, fp);
						fclose(fp);  
						printf("\n\tPara aktarimi basariyla gerceklestirildi.\n");
						printf("\n\tGeri donmek icin: /para_aktarma yazmalisiniz.\n");	
	   				} 
					}
				else
					{
						printf("\n\tGirdiginiz kullanici kimlikleri birbiriyle eslesmiyor.!");
						printf("\n\tGeri donmek icin: /para_aktarma yazmalisiniz.\n");	
					}
					}
					else if(strcmp(onay,"h") == 0 || strcmp(onay,"H") == 0)
					{
						ekrani_temizle();
						para_aktarma();
					}
					
					else
					{
						printf("\n\tLutfen E/H seceneklerinden birini seciniz.");
						printf("\n\tGeri donmek icin: /para_aktarma yazmaniz yeterlidir.\n");
					}
			
				}
				else
					{
						printf("\n\tGondermek istediginiz kullanici bulunamamaktadir.");
						printf("\n\tGeri donmek icin: /para_aktarma yazmalisiniz.\n");					
					}
					
		}
			else
	{
		printf("\n\tYeterli bakiyeniz bulunmamaktadir.");
		printf("\n\tGeri donmek icin: /para_aktarma yazmalisiniz.\n");	
	}
	break;
	}					
			case 3: 
			{
					if(kayit.bakiyeTL>=1000)
			{
				ekrani_temizle();
				sablon_menu();
				char gonderilenkullanici_numarasi[255];
				printf("\n\n\tGondermek istediginiz kullanici numarasi: ");
				scanf("%s",gonderilenkullanici_numarasi);
				
				if(strcmp(gonderilenkullanici_numarasi,kayit.numara2)==0)
				{
					char onay[255];
					printf("\n\tParayi gondermek istediginiz kullanici: %s %s\n",kayit.isim2,kayit.soyisim2);
					printf("\tOnayliyormusunuz(E/H) ?: ");
					scanf("%s",onay);
					if(strcmp(onay,"e") == 0 || strcmp(onay,"E") == 0)
					{
					char redogumTarihi[255];
					printf("\n\t\t\t\t   Dogum Tarihinizi giriniz: ");
					scanf("%s",redogumTarihi);
				
				if(strcmp(redogumTarihi,kayit.dogumTarihi) == 0 )
					{	
						kayit.bakiyeTL = kayit.bakiyeTL-1000;
  						FILE *fp;  
 			 			if((fp=fopen("bilgiler.dat", "wb"))==NULL)   
    				{     
  	 					 printf("Dosya acilamadi...\n");
					}
	  			else 
	   				{      
						fwrite(&kayit, sizeof(kayit), 1, fp);
						fclose(fp);  
						printf("\n\tPara aktarimi basariyla gerceklestirildi.\n");
						printf("\n\tGeri donmek icin: /para_aktarma yazmalisiniz.\n");
	   				} 
					}
				else
					{
						printf("\n\tGirdiginiz kullanici kimlikleri birbiriyle eslesmiyor.!");
						printf("\n\tGeri donmek icin: /para_aktarma yazmalisiniz.\n");
					}
					}
					else if(strcmp(onay,"h") == 0 || strcmp(onay,"H") == 0)
					{
						ekrani_temizle();
						para_aktarma();
					}
					
					else
					{
						printf("\n\tLutfen E/H seceneklerinden birini seciniz.");
						printf("\n\tGeri donmek icin: /para_aktarma yazmaniz yeterlidir.\n");
					}
			
				}
				else
					{
						printf("\n\tGondermek istediginiz kullanici bulunamamaktadir.\n");	
						printf("\n\tGeri donmek icin: /para_aktarma yazmalisiniz.\n");			
					}
				
		}
			else
	{
		printf("\n\tYeterli bakiyeniz bulunmamaktadir.");
		printf("\n\tGeri donmek icin: /para_aktarma yazmalisiniz.\n");
	}
		break;
	}
	
		case 4:
			{
				ekrani_temizle();
				kullanici_sayfasi();
				break;
			}
			
		default:
		{
			printf("\tYanlis secim yaptiniz.\n\t*Tekrar secim yapmak icin: /para_aktarma yaziniz.\n");
			break;
		}

	}
}
//Ayarlar bölümünde belirtildiði gibi bilgilerinizi düzenleyeceksinizdir.
bilgilerimi_duzenle()
{
	
	sablon_menu();	
	printf("\n\n   Hosgeldin %s %s; \n       Bu bu menuden kullanici bilgilerinizi degistirebilirsiniz.\n",kayit.isim,kayit.soyisim);
	printf("       Guvenlik nedeniyle bazi bilgilerinizin degisimine izin vermiyoruz.\n");
	printf("       Diger bilgilerinizin degisimi icin subelerimizden herhangi birini ziyaret etmeniz gerekiyor.\n\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t1: Kullanici kimliginizi duzenlemek istiyorsaniz seciniz.\n");
	printf("\t\t\t2: Kullanici sifrenizi duzenlemek istiyorsaniz seciniz.\n");
	printf("\t\t\t3: Kullanici dogum tarihini duzenlemek istiyorsaniz seciniz.\n");
	printf("\t\t\t4: Geri donmek istiyorsaniz. Secim isleminden ciktiysaniz /kullanici_ekrani yazmalisiniz.\n");
	int bilgi_secim;
	printf("\n\tSecim islemini gerceklestiriniz: ");
	scanf("%d",&bilgi_secim);
	
	switch(bilgi_secim)
	{	
		case 1: 
		{
			char renumara[255];
			printf("\n\t\t\t\tYeni kullanici kimligi: ");
			scanf("%s",renumara);
			printf("\t\t\t Tekrar yeni kullanici kimligi: ");
			scanf("%s",kayit.numara);
			ekrani_temizle();
			sablon_menu();
			
			if(strcmp(renumara,kayit.numara) == 0 )
			{
			
  			FILE *fp;  
 			 if((fp=fopen("bilgiler.dat", "wb"))==NULL)   
    		{     
  	 			 printf("Dosya acilamadi...\n");
			}
	  		else 
	   		{      
				fwrite(&kayit, sizeof(kayit), 1, fp);
				fclose(fp);  
				printf("\n\t\t\t\tKullanici kimligi basariyla degistirildi.");
				printf("\n\t\t\t\tGeri donmek icin: /kullanici_ekrani yazmalisiniz.");
	   		} 
			break;
			}
			else
			{
				printf("\n\t\t\t\tGirdiginiz kullanici kimlikleri birbiriyle eslesmiyor.!");
				printf("\n\t\t\t\tGeri donmek icin: /kullanici_ekrani yazmalisiniz.");
				break;
			}
		}
		
		case 2: 
		{
			char resifre[255];
			printf("\n\t\t\t\tYeni sifre: ");
			scanf("%s",resifre);
			printf("\t\t\t Tekrar yeni sifre: ");
			scanf("%s",kayit.sifre);
			ekrani_temizle();
			sablon_menu();
			
			if(strcmp(resifre,kayit.sifre) == 0 )
			{
			
  			FILE *fp;  
 			 if((fp=fopen("bilgiler.dat", "wb"))==NULL)   
    		{     
  	 			 printf("Dosya acilamadi...\n");
			}
	  		else 
	   		{      
				fwrite(&kayit, sizeof(kayit), 1, fp);
				fclose(fp);  
				printf("\n\t\t\t\tKullanici sifresi basariyla degistirildi.");
				printf("\n\t\t\t\tGeri donmek icin: /kullanici_ekrani yazmalisiniz.");
	   		} 
			break;
			}
			else
			{
				printf("\n\t\t\t\tGirdiginiz kullanici sifreler birbiriyle eslesmiyor.!");
				printf("\n\t\t\t\tGeri donmek icin: /kullanici_ekrani yazmalisiniz.");
				break;
			}
		}
		
		case 3: 
		{
		char redogumTarihi[255];
			printf("\n\t\t\t\tYeni Dogum Tarihi: ");
			scanf("%s",redogumTarihi);
			printf("\t\t\t Tekrar yeni Dogum Tarihi: ");
			scanf("%s",kayit.dogumTarihi);
			ekrani_temizle();
			sablon_menu();
			
			if(strcmp(redogumTarihi,kayit.dogumTarihi) == 0 )
			{
			
  			FILE *fp;  
 			 if((fp=fopen("bilgiler.dat", "wb"))==NULL)   
    		{     
  	 			 printf("Dosya acilamadi...\n");
			}
	  		else 
	   		{      
				fwrite(&kayit, sizeof(kayit), 1, fp);
				fclose(fp);  
				printf("\n\t\t\t\tDogrum tarihi basariyla degistirildi.");
				printf("\n\t\t\t\tGeri donmek icin: /kullanici_ekrani yazmalisiniz.");
	   		} 
			break;
			}
			else
			{
				printf("\n\t\t\t\tGirdiginiz dogum tarihleri birbiriyle eslesmiyor.!");
				printf("\n\t\t\t\tGeri donmek icin: /kullanici_ekrani yazmalisiniz.");
				break;
			}
		}
		case 4:
			{
				ekrani_temizle();
				ayarlar();
				break;
			}
		
		default:
		{
			printf("\n\t\t\t\tYanlis secim yaptiniz.");
			printf("\n\t\t\t\tGeri donmek icin: /kullanici_ekrani yazmalisiniz.");
			break;
		}
	}
	
}
//Veritabanindaki bilgileri buradan cekmemizi saglayacaktir.
giris_sorgulama()
{     
 	FILE *fp;  
  	if((fp=fopen("bilgiler.dat", "rb"))==NULL) 
    {     
		printf("Dosya acilamadi...\n");
	} 
		else
		{     
		fread(&kayit, sizeof(kayit), 1, fp);
		fclose(fp);  			  	
		} 	
}

//Kullanici girisi yapildiktan sonra /kullanici_ekrani yazarak ulasilabilecek bir sayfadir.
int kullanici_sayfasi()
{	
	ekrani_temizle();
	sablon_menu();
	kullanici_menu();
	
	if(strcmp(musteri_numara,kayit.numara) ==0 && strcmp(kullanici_sifre,kayit.sifre)==0)
	{
		printf(" Kullanici sayfasina otomatik olarak yonlendirildiniz.");		
		secim_ekran();		
	}
	else
	{	
	
	}
}
/*
	Mevcut bakiyinizi buradan görebilirsiniz.
	Ayrýca kiþisel bilgilerinizede göz atabilirsiniz.
	Deðiþtirmek istediðiniz yerler olursa diðer menülerden yararlanabilirsiniz.
*/
int bakiye() 
{
	sablon_menu();
	printf("\n\n\t**********************************\n");
	printf("\t**********Bakiye Bilgileri********");
	printf("\n\t********************************** 	==> Bakiye bilgilerinize bu bolum uzerinden bakabilirsiniz.\n");
	printf("\t*         Ad: %s		 *\n",kayit.isim);
	printf("\t*      Soyad: %s		 *	==> Para aktarimi yapildiktan sonra buradan kontrol edebilirsiniz.\n",kayit.soyisim);
	printf("\t*     Bakiye: %dTL	         *\n",kayit.bakiyeTL);
	printf("\t*   H.Durumu: CEZASI YOK	 *	==> /Geri donmek icin /kullanici_ekrani yazmaniz yeterlidir.\n",kayit.cinsiyet);
	printf("\t*   K.Durumu: KREDI ALABILIR	 *\n",kayit.dogumTarihi);
	printf("\t* Hesap Turu: %s		 *	==> Yardim menusune ulasmak icin: /yardim yazabilirsiniz.\n",kayit.hesapturu);
	printf("\t**********************************\n");
	
}
//Bireysel krediler bölümüne gönderecektir. Açýklamalardan ibarettir.
int bireysel()
{	
	sablon_menu();
	printf("\n\t\t---EGITIM KREDISI---\t\t\t\t\t\t---TASIT KREDILERI---");
	printf("\n GamaBank'tan Egitim kredisi ile egitim masraflarinizi\t\t0 km ya da 2. el, uygun vade ve faiz oranli tasit\n uygun faiz oranlari ile karsilayin. Geleceginize\t\tkredilerimiz ile hayalinize ulasin.\n ara vermeyin.\n ");
	printf("\n\t\t---KURTARAN HESAP---\t\t\t\t\t\t---MORTGAGE KREDILERI---");
	printf("\n Kira, faturalar, odemeler derken paraya ihtiyacin varsa,\tUygun vade ve faiz oranli Mortgage Kredilerimiz ile \n Kurtaran Hesap yaninda. Kurtaran Hesap, acil nakit \t\thayalinize ulasin...\nihtiyaclarinizi 7/24 karsilayabileceginiz, ustelik\t\tSabit faiz secenegi ile mortgage kredisi kullanabilir,\n taksitli kullanildiginda geri odemesini 12 aya varan\t\tkredinizi esit taksitler halinde odeyebilirsiniz.\n vade secenekleriyle yapabilme kolayligi da saglayan\t\t25 yila kadar vade seseneklerinden yararlanabilirsiniz.\n bir Kredili Mevduat Hesabidir.\t\t\t\t\tSatin alacaginiz konutun ekspertiz degerinin en fazla ");
	printf("\n\t\t\t\t\t\t\t\tyuzde 75'ine kadar kredi kullanabilirsiniz.\n");
	
	printf("\n\tGeri donmek icin: /anasayfa yazmaniz yeterlidir.");
	printf("\n\tYardim menusune ulasabilmek icin: /yardim yazabilirsiniz.\n");
}
//Kobi kredileri bölümüne gönderecektir. Açýklamalardan ibarettir.
kobi()
{
	sablon_menu();
	printf("\n\t\t---KARTLAR---\t\t\t\t\t\t---KOBI KREDILERI---");
	printf("\n GamaSector KOBI Kredisi icinde hazir kart; \t\t\t GamaSector, tum sektorlerde kullanabileceginiz\n GamaSector KOBI'nizi hemen alin, Taksitli Ticari\t\t yeni KOBI kredileri ile de yaninizda.\n Kredi'nizi aninda kullanin, taksit taksit odeyin.\n ");
	printf("\n\t\t---SIGORTA---\t\t\t\t\t\t---TARIM BANKACILIGI---");
	printf("\n Genis kapsamli sigorta sistemlerimizle, isyerinizde\t\tUzman ekibimizle tarim sektorunun ihtiyaclarini, \n meydana gelebilecek tehlikeleri ve her turlu\t\t\tsezonluk nakit akislarini goz onunde bulundurarak\n riski guvence altina alin.\t\t\t\t        size ozel urun ve sigorta hizmetleri sunuyoruz.\n \t\t");
	
	printf("\n\tGeri donmek icin: /anasayfa yazmaniz yeterlidir.");
	printf("\n\tYardim menusune ulasabilmek icin: /yardim yazabilirsiniz.\n");
}
/*
	Ýlk açýlan sayfadir. Görsellik bakimindan yüksektir ve þirketimizin tanitimi yapilmiþtir.
	
*/
int anasayfa() 
{
		srand(time(0)); //herseferinde rastgale deger atamasi icin time degerini sifirliyoruz.
		float deneme = (float)1+rand()/50.5;
		float euro = (float)1+rand()/5000.5;
		float altin = (float)rand()/405.4;
		float dolar = (float)rand()/3004.5;
		
		printf("\n\n										     +");
		printf("++++++++++++++++++++++++++++++++");
		printf("		Yatirim Hakkinda Bilmeniz Gerekenler Tek Noktada!		     	     +				   	     +\n										     +					     +");
		printf("\n Musterilerimizin, oncelikli tercih ettikleri ve finansal piyasalarda uzmanlasmis    + 	        PIYASA DURUMU	     +");
		printf("\n banka olmak hedefi dogrultusunda GamaSector yatirim hizmetlerini gururla sunuyoruz. + 	 -------------------------   +\n");
		printf("   										     +	 |		   	     	 |   +\n");	
		printf(" Eger;  									     +	 |   USD [$] = %.7f |   +\n",dolar);	
		printf("  -Yatirim araclarini cok iyi tanimiyorum, hangi araclara yatirim yapacagima 	     +   |   Euro [E] = %f |   + \n",euro);
		printf(" karar veremiyorum.  								     +	 |   Altin [G] = %.3f  |   +\n",altin);
		printf("  -Yatirim karari verirken hangi riskleri aliyorum? 				     +	 |			   	 |   +\n");
		printf("  -Bana uygun firsatlar neler, bu firsatlari kaciriyor muyum? 			     +   -------------------------   +\n");
		printf("  -Piyasalar cok hizli degisiyor, almis oldugum pozisyonu takip etmekte              + 					     +\n zorlaniyorum.									     +			   		     +");
		printf("  	-Ihtiyac duydugunuz finansal cozumlere ulasirken, sektorlerinin lider	     +				    	     +\n");
		printf(" kuruluslari ile guvenle calismanin getirdigi essiz musteri deneyimini GamaSector    +					     +");
		printf("\n Yatirim Hizmetlerinde bulacaksiniz.						     +					     +\n");
			if(hata_durumu == 1)
		{
			printf(" **Hatali giris yaptiniz detayli bilgi icin: /yardim yaziniz:			     +++++++++++++++++++++++++++++++++");
			hata_durumu = 0;
		}
		else
		{
			printf(" **Program hakkinda detayli bilgi icin: /yardim yaziniz:			     +++++++++++++++++++++++++++++++++");
		}	
}		
//Ekrani temizle fonksiyonudur.
int ekrani_temizle()
{
	system("cls");
}
/*
	En büyük kod satýrýna sahip olan fonksiyondur.
	Bu fonksiyon seçim iþlemlerinin neredeyse çoðunu kapsamaktadir.
	Programin çekirdeði diyebiliriz.
	Bu fonksiyon sayesinde program içerisinde gezinti yapabiliyoruz ve güvenligini saðlayabiliyoruz.
	Örnek vermek gerekirse giriþ yapmadan bakiye sorgulayamazsiniz.
*/
int secim_ekran()
{
	basla:
	char secim[10];
	char destek[10];
	printf("\n $Kullanici: ");
	scanf("%s",secim);
	//Yardim menüsüne buradan ulasabilirsiniz.
	if(strcmp(secim, "/yardim") == 0) 
	{
		ekrani_temizle();
		
		sablon_menu();
		
		printf("\n\n	*** Merhabalar bu bolumde online bankacilik ile ilgili ipuclarini bulacaksiniz.\n\n");
		printf("	1-) Anasayfayi ziyaret etmek icin:			/anasayfa yazarak o menuye gidebilirsiniz.\n");
		printf("	2-) Bireysel krediler hakkinda bilgi almak icin:	/bireysel yazabilirsiniz.\n");
		printf("	3-) Kobiler hakkinda bilgi almak icin:			/kobi yazabilirsiniz.\n");
		printf("	4-) Hesap bilgileriniz ile giris yapmak icin:		/giris_yap yazarak o menuye gidebilirsiniz.\n");
		printf("	5-) Hesap bilgileriniz ile giris yaptiysaniz:		/kullanici_ekrani yazarak o menuye gidebilirsiniz.\n");
		
		printf("	3-) Bakiyenizi gorebilmeniz icin: 		\t/bakiye yazarak o menuye gidebilirsiniz. \n");
		printf("	4-) Baska kullanicilara para gondermek icin: 		/para_aktarma yazarak o menuye gidebilirsiniz. \n");
		printf("	5-) Doviz uzerinden islem yapabilmek icin:		/doviz yazarak o menuye gidebilirsiniz. \n");
		printf("	6-) Kullanici bilgilerinizi degistirebilmek icin:  	/ayarlar yazmalisiniz.\n");
		
		goto basla;
	}
	//Kobi bölümüne gitmenizi saðlayacaktir tüm kullanacilar ulasabilir.
	if(strcmp(secim,"/kobi")==0)
	{
		ekrani_temizle();
		kobi();
		
		goto basla;
	}
	//Giriþ yapmak istiyorsaniz bu kisim çalýþacaktýr ve 3 hatali giriþten sonra oturumu kitleyecektir.
	else if(strcmp(secim, "/giris_yap") == 0) 
	{	gits:
		int hatali_giris =0;
		giris_yap:
		hatali_giris++;
		
		if(strcmp(musteri_numara,kayit.numara) == 0 && strcmp(kullanici_sifre,kayit.sifre) == 0)
		{
			printf(" UYARI: Daha onceden giris yaptiniz.");
			kullanici_sayfasi();
			
			goto basla;
		}
		else
		{
			
		int sayac=0;
		ekrani_temizle();
		sablon_menu();
	
				if(hatali_giris <= 4)
		{
				if(hatali_giris >=2)
				{
					if(4-hatali_giris ==0)
					{
						printf("				         UYARI: Hatali giris yaptiniz!! SON hakkiniz kaldi.\n");
					}
					else
					{		
						char karar[255];
						printf("\n				UYARI: Hatali giris yaptiniz!! %d adet hakkiniz kaldi.\n", 4-hatali_giris);
						
						int secim_sayi =0;
						secim:
						secim_sayi++;
						
						if(secim_sayi <=4 )
						{	
						printf("					  Devam etmek istiyormusun ? [E/H]: ");
						karar;
						scanf("%s",karar);
						
						if(strcmp(karar,"e") == 0 || strcmp(karar,"E") == 0)
						{
							printf("");
						}
						else if(strcmp(karar,"h") == 0 || strcmp(karar,"H") == 0)
						{
							ekrani_temizle();
						 	main();
						}
						else
						{
							printf("				       Hatali secim yaptiniz. Tekrar deneyiniz.\n");
							goto secim;
						}
						}
						else
						{
							ekrani_temizle();
							printf("3'ten daha fazla hatali secim yaptiniz. *BLOKLANDINIZ.");
							return 0;
						}
					}
				}
							
					printf("\n 	    Hosgeldiniz: Musteri numaranizi ve hesap sifrenizi girerek kullanici paneline ulasabilirsiniz.\n\n");	
					printf("					 MUSTERI NUMARASI: ");
					scanf("%s",&musteri_numara);
				
			
			for(int i=0;musteri_numara[i]!='\0';i++)  //  String dizisinin sonuna gelene kadar yap
		{
  		 	if (musteri_numara[i]=='1' || musteri_numara[i]=='2'|| musteri_numara[i]=='3'|| musteri_numara[i]=='4'|| musteri_numara[i]=='5'|| musteri_numara[i]=='6'|| musteri_numara[i]=='7'|| musteri_numara[i]=='8'|| musteri_numara[i]=='9'|| musteri_numara[i]=='0')  // eðer i elemaný A yada kücük a ise sayac deðerini bir attýr
      		sayac++;	
		}
		
			if(sayac == 10) 
		{
			printf("					 Kullanici sifresi: ");
			scanf("%s", kullanici_sifre);
			
			if(strcmp(musteri_numara,kayit.numara) == 0)
			{
				 if(strcmp(kullanici_sifre,kayit.sifre) ==0)
				 {
				 	printf(" Giris basarili.");
				 	ekrani_temizle();
				 	kullanici_sayfasi();
				 }				 
				 else
				 {
				 	goto giris_yap;
				 }
			}
			else
			{
				goto giris_yap;
			}			
		}
		else
		{
			printf("\n	Musteri numaraniz 10 haneli olmali. Tekrar deneyiniz.");
			goto giris_yap;
		}
			goto basla;
	}

	
	else
	{
		ekrani_temizle();
		printf("\n\aOturum Kitlendi.!");
		return 0;
	}		
	}
}
	// Ekrani temizle fonksiyonuna buradan ulasabilirsiniz.
	else if(strcmp(secim,"/ekrani_temizle") == 0 || (strcmp(secim,"/anasayfa") == 0))
	{
		ekrani_temizle();
		main();
	}
	//bireysel fonksiyonu buradan çaðrýlýr herkes ulasabilir.
	else if(strcmp(secim,"/bireysel")==0)
	{
		ekrani_temizle();
		bireysel();
		goto basla;
	}
	//Bakiye fonksiyonuna sadece kayitli olan Ahmet Ekti kullanicisi ulasabilir.
	else if(strcmp(secim,"/bakiye")==0)
	{
		if(strcmp(musteri_numara,kayit.numara) == 0)
		{
			 if(strcmp(kullanici_sifre,kayit.sifre) ==0)
			 {
				ekrani_temizle();
				bakiye();
				goto basla;
			}		
		}
		else
		{
			printf("Lutfen giris yapiniz.");
			goto gits;
		}
	}
	//Kullanici ekrani fonksiyonuna sadece kayitli olan Ahmet Ekti kullanicisi ulasabilir.
		else if(strcmp(secim,"/kullanici_ekrani")==0)
	{
		if(strcmp(musteri_numara,kayit.numara) == 0)
		{
			 if(strcmp(kullanici_sifre,kayit.sifre) ==0)
			 {
				ekrani_temizle();
				kullanici_sayfasi();
				goto basla;
			}		
		}
		else
		{
			printf("Lutfen giris yapiniz.");
			goto gits;
		}
	}
	//Bilgilerimi düzenle fonksiyonuna sadece kayitli olan Ahmet Ekti kullanicisi ulasabilir.
			else if(strcmp(secim,"/bilgilerimi_duzenle")==0)
	{
		if(strcmp(musteri_numara,kayit.numara) == 0)
		{
			 if(strcmp(kullanici_sifre,kayit.sifre) ==0)
			 {
				ekrani_temizle();
				bilgilerimi_duzenle();
				goto basla;
			}		
		}
		else
		{
			printf("Lutfen giris yapiniz.");
			goto gits;
		}
	}
	//Para aktarma fonksiyonuna sadece kayitli olan Ahmet Ekti kullanicisi ulasabilir.
	else if(strcmp(secim,"/para_aktarma")==0)
	{
		if(strcmp(musteri_numara,kayit.numara) == 0)
		{
			 if(strcmp(kullanici_sifre,kayit.sifre) ==0)
			 {
				ekrani_temizle();
				para_aktarma();
				goto basla;
			}		
		}
		else
		{
			printf("Lutfen giris yapiniz.");
			goto gits;
		}
	}
	//Döviz fonksiyonuna sadece kayitli olan Ahmet Ekti kullanicisi ulasabilir.
	else if(strcmp(secim,"/doviz")==0)
	{
		if(strcmp(musteri_numara,kayit.numara) == 0)
		{
			 if(strcmp(kullanici_sifre,kayit.sifre) ==0)
			 {
				ekrani_temizle();
				doviz();
				goto basla;
			}		
		}
		else
		{
			printf("Lutfen giris yapiniz.");
			goto gits;
		}
	}
	//Ayarlar fonksiyonuna sadece kayitli olan Ahmet Ekti kullanicisi ulasabilir.
		else if(strcmp(secim,"/ayarlar")==0)
	{
		if(strcmp(musteri_numara,kayit.numara) == 0)
		{
			 if(strcmp(kullanici_sifre,kayit.sifre) ==0)
			 {
				ekrani_temizle();
				ayarlar();
				goto basla;
			}		
		}
		else
		{
			printf("Lutfen giris yapiniz.");
			goto gits;
		}
	}
	
	else
	{
		ekrani_temizle();
		hata_durumu = 1;
		main();
	}
	
}
//Hemen hemen her sayfada olan sablon menudur. Bunu çaðýrýrýz.
int sablon_menu()
{
	printf("					|*************************************|\n****************************************|     ONLINE BANKACILIK ISLEMLERI     |****************************************\n*					|*************************************|						      *\n*					    									              *\n");
		
	printf("*	   |------------|"); 	 	printf("		|------------|");		printf("		|------------|");		printf("		|--------------------|	      *\n"); 
	printf("*	   |  Anasayfa  |");		printf("		|  Bireysel  |");		printf("		|    Kobi    |");		printf("		|  Kullanici Ekrani  |        *\n");
	printf("*	   |------------|");		printf("		|------------|");		printf("		|------------|");		printf("		|--------------------|        *\n*															      *\n*															      *\n***********************************************************************************************************************");	
}
//Kullanici islemleri sayfasinda olan sablon menudur. Bunu çaðýrýrýz.
int kullanici_menu()
{
	//printf("					|*************************************|\n****************************************|     KULLANICI ISLEMLERI SAYFASI     |****************************************\n*					|*************************************|						      *\n*															      *\n***********************************************************************************************************************\n\n||======================||\n");
	printf("\n\n||**********************||\n||*      -BAKIYE-      *|| =>  Hesap bilgilerinize, hesap durumunuza bakabilirsiniz. /bakiye yazarak ulasabilirsiniz.\n||**********************||\n||======================||\n");
	printf("||**********************||\n||*   -Para Aktarma-   *|| =>  Akrabalariniza, dostlariniza para gonderin. /para_aktarma yazarak ulasabilirsiniz.\n||**********************||\n||======================||\n");	
	printf("||**********************||\n||*      -DOVIZ-       *|| =>  Elinizdeki parayi daha degerli yapabilirsiniz. /doviz yazarak ulasabilirsiniz.\n||**********************||\n||======================||\n");
	printf("||**********************||\n||*     -AYARLAR-      *|| =>  Guvenlik bilgilerini buradan degistirebilirsiniz. /ayarlar yazarak ulasabilirsiniz.\n||**********************||\n||======================||\n");
}
//Ana bölümdür. Bu fonksiyonlar çaðrýlarak programa baþlanýr.
int main()
{
	giris_sorgulama();
	sablon_menu();
	anasayfa();	
	secim_ekran();
}
