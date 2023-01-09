//21118080070 Said Berk Lab 3
#include <stdio.h>
#include <string.h>

int gecerliMi(double a){	
	if(a > 100 || a < 0){
		return 0;
	}
	else{
		return 1;
	}
}

double enDusukNotHesapla(double ortalamalar[], int ogrenci_sayisi){
		int loop;
		double min_not = ortalamalar[0];
		printf("min: %lf ogrenci sayisi: %d",ortalamalar[0], ogrenci_sayisi);
		for(loop = 0; loop < ogrenci_sayisi; loop++){
			
			if (min_not > ortalamalar[loop]){
			min_not = ortalamalar[loop];	
			}
		}
	return min_not;
}

double enYuksekNotHesapla(double ortalamalar[], int ogrenci_sayisi){
		int loop;
		double max_not = ortalamalar[0];
		for(loop = 0; loop < ogrenci_sayisi; loop++){
			
			if (max_not < ortalamalar[loop]){
			max_not = ortalamalar[loop];	
			}
		}
	return max_not;
}

double sinifOrtalamasiHesapla(double ortalamalar[], int ogrenci_sayisi){
		int loop;
		double toplam = 0;
		double ortalama;
		
		for(loop = 0; loop < ogrenci_sayisi; loop++){
			toplam = toplam + ortalamalar[loop];
		}
		ortalama = toplam / ogrenci_sayisi;
		return ortalama;	
}


double Odev(int odev_sayisi){
	double odev_notlari[odev_sayisi];
	int i;
	for(i = 0; i < odev_sayisi; i++){
		double mevcut_odev;
		while(1){
			
		printf("Ogrencinin %d . Odev Notunu Giriniz:\t", i + 1);
		scanf("%lf", &mevcut_odev);
		if(gecerliMi(mevcut_odev)){
			odev_notlari[i] = mevcut_odev;
			break;	
		}
		else{
			printf("Odev Notu Gecersiz, Lutfen 0 - 100 Arasinda Bir Deger Girin!!!\n");
			continue;
		}
		}
	}
	
   double toplam = 0;
   for(i = 0; i < odev_sayisi; i++){
   		toplam = toplam + odev_notlari[i];
   }
   
   double odev_ortalama = toplam / odev_sayisi;
   return odev_ortalama;
}

double ortalamaHesapla(double vize, double final, double odev_ortalamasi, int odev_sayisi){
	double ortalama;
	if(odev_sayisi != 0){
		ortalama = (vize * 3/10) + (final * 4/10) + (odev_ortalamasi * 3/10);	
	}
	
	else{
		ortalama = (vize * 6/10) + (final * 4/10);	
	}

	return ortalama;
}


double Hesapla(char ogrenci_no[], int odev_sayisi){
	double vize;
	double final;
	while(1){
	printf("%s Numarali Ogrenci Icin Vize Notunu Giriniz: ", ogrenci_no);
	scanf("%lf", &vize);
	if(gecerliMi(vize)){
		while(1){
		printf("%s Numarali Ogrenci Icin Final Notunu Giriniz: ", ogrenci_no);
		scanf("%lf", &final);
	
		if(gecerliMi(final)){
				double odev_ortalamasi = Odev(odev_sayisi);
				double notOrtalamasi = ortalamaHesapla(vize, final, odev_ortalamasi, odev_sayisi);
				if(odev_sayisi != 0){
				printf("%s Numarali Ogrencinin Odev Ortalamasi = %.2lf", ogrenci_no, odev_ortalamasi);
				}
				
				printf("\n%s Numarali Ogrencinin Not Ortalamasi = %.2lf", ogrenci_no, notOrtalamasi);
				return notOrtalamasi;  
		}
		
		else{
			printf("Final Notu Gecersiz, Lutfen 0 - 100 Arasinda Bir Deger Girin!!!");
			continue;
		}
		}
	}
	
	else{
		printf("Vize Notu Gecersiz, Lutfen 0 - 100 Arasinda Bir Deger Girin!!!");
		continue;
	}
	break;	
	}
}

int main(){
	printf("NOT ORTALAMASI HESAPLAMA\n************************\n");
	char kontrolcu[20];
	char ogrenci_no[9];
	int odev_sayisi;
	int bilgisi_girilen_ogrenci_sirasi = 0;
	static double ortalama_listesi[30];
	
	printf("\nLutfen Dersin Odev Sayisini Giriniz: ");
	scanf("%d",&odev_sayisi);
	
	while(1){
		printf("\nLutfen Ogrenciye Ait Ogrenci Numarasini Giriniz: ");
		scanf("%s",&ogrenci_no);
		double not_ogrenci = Hesapla(ogrenci_no, odev_sayisi);// ilk asamada dongu olmaksizin bir kere calisiyor.
		ortalama_listesi[bilgisi_girilen_ogrenci_sirasi] = not_ogrenci;
		bilgisi_girilen_ogrenci_sirasi = bilgisi_girilen_ogrenci_sirasi + 1;
      	
		while(1){
			printf("\n\nYeni bir ogrenci notu hesaplamak icin '1' cikmak icin '0' tuslayiniz:");
			scanf("%s", &kontrolcu);
			
			if(!strcmp(kontrolcu, "1")){
				break; 
			}
			
			else if(!strcmp(kontrolcu, "0")){				
				double enDusukNot = enDusukNotHesapla(ortalama_listesi, bilgisi_girilen_ogrenci_sirasi);
				double enYuksekNot = enYuksekNotHesapla(ortalama_listesi, bilgisi_girilen_ogrenci_sirasi);
				double sinifOrtalamasi = sinifOrtalamasiHesapla(ortalama_listesi, bilgisi_girilen_ogrenci_sirasi);
				
				printf("\nDersi alan %d ogrenci icin en dusuk not: %.2lf", bilgisi_girilen_ogrenci_sirasi, enDusukNot);
				printf("\nDersi alan %d ogrenci icin en yuksek not: %.2lf", bilgisi_girilen_ogrenci_sirasi, enYuksekNot);
				printf("\nDersi alan %d ogrenci icin sinif ortalamasi: %.2lf", bilgisi_girilen_ogrenci_sirasi, sinifOrtalamasi);

				return 0; 
			}
			
			else{
				printf("\nHatali secim yaptiniz.");
				continue;
			}
		}
		continue;
	}
}
