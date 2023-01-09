//21118080070 Said Berk Lab 4
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int notGecerliMi(double sinav_not), ogrenciNumarasiDokuzHaneliMi(char ogrenci_no[]), harfBulunduruyorMu(char str[]);
struct Ogrenci;
double enDusukNotHesapla(double ortalamalar[], int ogrenci_sayisi), enYuksekNotHesapla(double ortalamalar[], int ogrenci_sayisi);
double sinifOrtalamasiHesapla(double ortalamalar[], int ogrenci_sayisi), ortalamaHesapla(double vize, double final, double odev_ortalamasi, int odev_sayisi);
double Odev(int odev_sayisi), Hesapla(char ogrenci_no[], int odev_sayisi);


struct Ogrenci{
	double vize;
	double final;
	double odev_ortalamasi;
	double not_ortalamasi;
};

//Gecerlilik Denetleyici Fonksiyonlar Baslangic.
int ogrenciNumarasiDokuzHaneliMi(char ogrenci_no[]){
    int string_uzunluk; 
    for (string_uzunluk = 0; ogrenci_no[string_uzunluk] != '\0'; ++string_uzunluk);

	if(string_uzunluk == 9){
		return 1;
	}
	else{
		return 0;
		printf("\n Ogrenci Numarasi 9 Haneli Degil!");
	}
}


int harfBulunduruyorMu(char str[]){//string olarak alinmis odev notu

	int string_uzunluk; 
	
    for (string_uzunluk = 0; str[string_uzunluk] != '\0'; ++string_uzunluk);
    
	for(int i = 0;i < string_uzunluk; i++){
		
		if(isdigit(str[i]) == 0 && str[i] != (char)46){ //  butun karakterleri gezip sayi olup olmadiklarini denetliyor. ( nokta haric (char)46 noktaya esit. )
			printf("Girdiginiz Sayida Harf Bulunmamali!");
			return 0; //eger sayi disi unsur bulursa return 0;
		}
	}
	return 1;//bulamazsa return 1;
}

int notGecerliMi(double sinav_not){	// verlien degerin 100 ile 0 arasinda olup olmadigini denetliyor
	if(sinav_not > 100 || sinav_not < 0){
		return 0;
	}
	else{
		return 1;
	}
}
//Gecerlilik Denetlemeleri Son.

double enDusukNotHesapla(double ortalamalar[], int ogrenci_sayisi){
		int loop; // dongu degiskeni
		double min_not = ortalamalar[0]; // baslangic degiskeni ilk eleman olur.
		for(loop = 0; loop < ogrenci_sayisi; loop++){ // ogrenci sayisi kadar doner.
			if (min_not > ortalamalar[loop]){ // ilk eleman ile ardindakileri sira sira karsilastirir.
			min_not = ortalamalar[loop];	// karsilastirma esnasinda kucuk olan min_not degiskenine aktarilir.
			}
		}
	return min_not; // dongu sonunda en kucuk bulunmus olur.
}

double enYuksekNotHesapla(double ortalamalar[], int ogrenci_sayisi){
		int loop; // dongu degiskeni
		double max_not = ortalamalar[0];// baslangic degiskeni ilk eleman olur.
		for(loop = 0; loop < ogrenci_sayisi; loop++){// ogrenci sayisi kadar doner.
			
			if (max_not < ortalamalar[loop]){ // ilk eleman ile ardindakileri sira sira karsilastirir.
			max_not = ortalamalar[loop];// karsilastirma esnasinda buyuk olan max_not degiskenine aktarilir.	
			}
		}
	return max_not; // dongu sonunda en buyuk bulunmus olur.
}

double sinifOrtalamasiHesapla(double ortalamalar[], int ogrenci_sayisi){
		int loop;
		double toplam = 0;
		double ortalama;
		
		for(loop = 0; loop < ogrenci_sayisi; loop++){
			toplam = toplam + ortalamalar[loop];//dongudeki butun elemanlari toplam degiskeniyle toplar.(toplam ilk degeri 0)
		}
		ortalama = toplam / ogrenci_sayisi;
		return ortalama;	
}


double Odev(int odev_sayisi){
	char *cp;
	double odev_not_son;
	double odev_notlari[odev_sayisi];
	int i;
	for(i = 0; i < odev_sayisi; i++){
		char mevcut_odev[10]; // odevin icindeki karakterleri tek tek denetleyebilmek amaciyla odevi basta string olarak aliyoruz.
		while(1){
			
		printf("\nOgrencinin %d . Odev Notunu Giriniz:\t", i + 1);
		scanf("%s", &mevcut_odev);
		
		if(harfBulunduruyorMu(mevcut_odev)){ // odev gecerli ise
			odev_not_son = strtod(mevcut_odev, &cp); // basta kontrol edebilme amaciyla string aldigimiz inputu hesaplama yapabilmek amaciyla tekrar double turune donusturuyoruz.
			
			if(odev_not_son > 100 || odev_not_son < 0){
				printf("\nLutfen 0 - 100 Arasinda Bir Deger Giriniz!");
				continue;
				
			}
			else{
				odev_notlari[i] = odev_not_son;
				break;
			}
		}
		else{
			printf("\nOdeviniz Sadece Rakamlardan Olusmalidir !\n");
			continue;
		}
	
		}
	}
	
   double toplam = 0;
   for(i = 0; i < odev_sayisi; i++){ // odev sayisi kadar doner.
   		toplam = toplam + odev_notlari[i]; // odev sayisinin iicindeki butun elemanlari toplar.
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
	if(notGecerliMi(vize)){
		while(1){
		printf("%s Numarali Ogrenci Icin Final Notunu Giriniz: ", ogrenci_no);
		scanf("%lf", &final);
	
		if(notGecerliMi(final)){
				double odev_ortalamasi = Odev(odev_sayisi);
				double not_ortalamasi = ortalamaHesapla(vize, final, odev_ortalamasi, odev_sayisi);
				struct Ogrenci ogrenci = {vize, final, odev_ortalamasi, not_ortalamasi};
				if(odev_sayisi != 0){
				printf("%s Numarali Ogrencinin Odev Ortalamasi = %.2lf", ogrenci_no, ogrenci.odev_ortalamasi);
				}
				
				
				return ogrenci.not_ortalamasi;  
		}
		
		else{
			printf("Final Notu Gecersiz, Lutfen 0 - 100 Arasinda Bir Deger Girin!!!\n");
			continue;
		}
		}
	}
	
	else{
		printf("Vize Notu Gecersiz, Lutfen 0 - 100 Arasinda Bir Deger Girin!!!\n");
		continue;
	}
	break;	
	}
}

int main(){
	printf("NOT ORTALAMASI HESAPLAMA\n************************\n");
	char kontrolcu[20];
	char ogrenci_no[9];
	char odev_sayisi_str[3];
	int bilgisi_girilen_ogrenci_sirasi = 0;
	static double ortalama_listesi[30];
	
	while(1){
	printf("\nLutfen Dersin Odev Sayisini Giriniz: ");
	scanf("%s",&odev_sayisi_str);
	
	int odev_sayisi = atoi(odev_sayisi_str);
	
	if(!harfBulunduruyorMu(odev_sayisi_str) || odev_sayisi < 0 || odev_sayisi > 10){
		printf("Odev Sayisi Hatali! , 0 - 10 arasi bir deger veriniz.");
		continue; 
	}
		

	while(1){
		printf("\nLutfen Ogrenciye Ait Ogrenci Numarasini Giriniz: ");
		scanf("%s",&ogrenci_no);
		
		if(!ogrenciNumarasiDokuzHaneliMi(ogrenci_no) || !harfBulunduruyorMu(ogrenci_no)){
			printf("\nOgrenci Numarasi Gecersiz");
			continue;
		}

		double not_ogrenci = Hesapla(ogrenci_no, odev_sayisi);// ilk asamada dongu olmaksizin bir kere calisiyor.
		printf("\n%s Numarali Ogrencinin Not Ortalamasi = %.2lf", ogrenci_no, not_ogrenci);
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
	
}
