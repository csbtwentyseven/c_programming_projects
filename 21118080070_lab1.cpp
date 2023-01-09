// Said Berk - 21118080070
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

bool gecerliMi(int sinavNot){ // Girilen notun gecerli mi (100 ile 0 arasinda olup olmadigini) denetleyen fonksiyon.
	if(sinavNot > 100 || sinavNot < 0){
	return false;
	}
	return true;
}

int main() {
	int ogrenci = 1;
	int ogrenci_sayisi;
	char ogrenci_numarasi[12]; //Gazi Universitesinin Kullandigi Ogrenci Numaralari 11 Haneli Oldugu Icin Integer Degisken Olarak Tutulmuyor, Ben De Arrayda Tuttum.
	float vize_notu ;
	float final_notu ;
	float ortalama;
	float final_notu_parite;
	float vize_notu_parite;

	printf("Kac Tane Ogrenci Icin Not Girisi Yapilacak?\t");
	scanf("%d", &ogrenci_sayisi);
	
	while (ogrenci <= ogrenci_sayisi) { //While Dongusunu Kullanmamin Sebebi Kullanici Hatali Bir Girdide Bulunursa Tur Donmesin ve Ayn� Asama Tekrarlansin.
		
		printf("\n%d. Ogrencinin Numarasini Giriniz:\t", ogrenci);
		scanf("%s", &ogrenci_numarasi);

		printf("%s Numarali Ogrenci Icin Vize Notunu Giriniz:\t", ogrenci_numarasi);
		scanf("%f", &vize_notu);

		printf("%s Numarali Ogrenci Icin Final Notunu Giriniz:\t", ogrenci_numarasi);
		scanf("%f", &final_notu);

		if(gecerliMi(final_notu) && gecerliMi(vize_notu)){ //Gecerlilik Kontrolu.
			
			final_notu_parite = final_notu * 4 / 10; // Okunabilirligi Artirmak Icin Parite Isimli Ikincil Degiskenleri Kullandim.
			vize_notu_parite = vize_notu * 6 / 10; // Okunabilirligi Artirmak Icin Parite Isimli Ikincil Degiskenleri Kullandim.
			ortalama = final_notu_parite + vize_notu_parite; // Ortalama Hesaplandi.
		
			printf("%s Numarali Ogrencinin Ortalamasi: %.2f\n\n",ogrenci_numarasi, ortalama); //%.2f noktadan sonra sadece iki basamagin gosterilmesi icin yazdim.
			ogrenci = ogrenci + 1;	
		}
		
		else{
			printf("\nLutfen 0 ile 100 Arasinda Gecerli Bir Not Giriniz!\n"); // Gecerli Degilse Uyari Verdi, Ayni Asama Tekrarlandi.
		}

	}
	return 0;

}
