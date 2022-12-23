#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main();
void koltuk();
void karsilamaEkrani();
void EvcilHayvan();
void yemek();
void yasf();
void bavul();
void biletyaz();
char isim[50];
char soyisim[50];
int bavulfiyat=0;
int ucus;
int ucusfiyat=0;
int yasfiyat=0;
int hayvanfiyati=0;
int yemekfiyati=0;
int sira;
int koltuk_n;
int toplam=0;
int yas;

int main() {
	setlocale(LC_ALL,"Turkish");
	printf("**********UÇAK BÝLET SÝSTEMÝ**********");
	printf("\n\n");
	karsilamaEkrani();
	printf("************** UÇUSLAR **************\n");
    printf("*      1. ucus bodrum-istanbul      *\n");
    printf("*      2. ucus istanbul-bodrum      *\n");
    printf("*      3. ucus istanbul-antalya     *\n");
    printf("*      4. ucus antalya-istanbul     *\n"); 
	printf("*************************************\n");
	printf("\nUcusunuzu seciniz : ");
	scanf("%d", &ucus);
	if (ucus==1){
		ucusfiyat=650;
		printf("bodrum-istanbul uçuþunu seçtiniz\n");
	}
	else if(ucus==2){
		ucusfiyat=750;
		printf("istanbul-bodrum  uçuþunu seçtiniz\n");
	}
	else if(ucus==3){
		ucusfiyat=700;
		printf("istanbul-antalya  uçuþunu seçtiniz\n");		
	}
	else if(ucus==4){
		ucusfiyat=800;
		printf("antalya-istanbul uçuþunu seçtiniz\n");
	}
	
	yasf();
	printf("\n");
	koltuk();
	printf("\n");
	bavul();
	printf("\n");
	EvcilHayvan();
	printf("\n");	
	yemek();
	printf("\n\n");
    toplam=yasfiyat+bavulfiyat+hayvanfiyati+yemekfiyati;
    biletyaz();
    printf("\n\n Biletiniz sisteme kaydedilmiþtir.");
	
	FILE *fp;
	fp = fopen("bilet.txt", "a");
 	fprintf(fp,"-------------------------------------------\n");
	fprintf(fp,"|                  BÝLETÝNÝZ              |\n");
	fprintf(fp,"|                                         |\n");
	fprintf(fp,"|                  isim: %s             |\n",isim);
	fprintf(fp,"|               soyisim: %s            |\n",soyisim);
	fprintf(fp,"|      koltuk numaranýz: %d %d              |\n",sira, koltuk_n);
	fprintf(fp,"|       Bilet ücretiniz: %d TL'dir       |\n",toplam);
	fprintf(fp,"-------------------------------------------\n");
	fclose(fp);
 	
	return 0;
	}
	
	
void karsilamaEkrani()	{
	char cevap;	
	while (1) {
	printf("Lütfen isminizi girin: ");	
	scanf("%s",&isim);
	printf("Lütfen soyisminizi girin: ");
	scanf("%s",&soyisim);
	printf("isiminiz %s\nsoyisminiz %s dir\n",isim,soyisim);
	printf("doðru mu doðruysa d yanlýþsa y harfine basýn: ");
   scanf(" %c", &cevap);
    if (cevap == 'd'||cevap=='D') {
    printf("Ýsim ve soyisim bilgileriniz doðrulandý.\n\n");
    break;
  } else if (cevap=='Y' ||cevap=='y') {
    printf("Lütfen tekrar isim ve soyisim bilgilerinizi girin.\n");
    continue;
  } else {
    printf("Geçersiz cevap. Lütfen d veya y harflerinden birini girin.\n");
    continue;
  }
  }
}

void koltuk() {
	 int koltuklar[5][5] = 	{
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    while (1) {
        printf("Lutfen bir sýra ve koltuk numarasý giriniz (örnek: 1 3): ");
        scanf("%d %d", &sira, &koltuk_n);
        if (sira < 1 || sira > 5 || koltuk_n < 1 || koltuk_n > 5) {
            printf("Lutfen 1 ile 5 arasinda bir sýra ve koltuk numarasý giriniz\n");
        continue;
        break;
        }

        if (koltuklar[sira][koltuk_n] == 0) {
          
            printf("Koltugunuz ayarlandi. Tesekkurler!\n");
            koltuklar[sira][koltuk_n]=1;      
		break; 
		} 
        if ( koltuklar[sira][koltuk_n] == 1){
		
            printf("Maalesef koltuk dolu");
        }
        break;
        }
	}
    
void bavul(){
	printf("bavulunuz var mi yoksa sifir kg secin \n");
    printf("bavulunuz kilosunu girin : "); 
	scanf("%d",&bavulfiyat);
	bavulfiyat=bavulfiyat*10;
}

void EvcilHayvan(){
int hayvan;
	printf("evcil hayvanýnýz var mý ?\n");
	printf("1.kus\n2.kedi\n3.kopek\n4.yok \n");
	printf("bir secenek secin : ");
	scanf("%d",&hayvan);
		switch(hayvan){
   		case 1:
   			printf("kuþunuz için yer ayýrýldý");
			hayvanfiyati=hayvanfiyati+5;
		break;
		case 2:	
			printf("kediniz için yer ayýrýldý");
			hayvanfiyati=hayvanfiyati+10;
		break;
		case 3:
			printf("köpeðiniz için yer aýrýldý");
			hayvanfiyati=hayvanfiyati+15;
		break;	
		case 4:
			printf("evcil hayvaniniz yok sonraki adima gecin");	
    	break; 		 
		default:
			printf("1 ile 4 arasinda sayi girmelisiniz.");}
}

void yemek(){
 int yemek;
	printf("\nyiyecek,icicek veya tatli ister misiniz?\n");
	printf("1.yiyecek\n2.icicek\n3.tatli\n4.hayir \n");
	printf("bir secenek secin : ");
	scanf("%d",&yemek);
	switch(yemek){
   case 1:
    	printf("yiyecek sectiniz \n afiyet olsun \n");
		yemekfiyati=yemekfiyati+30;
	break;
	case 2:	
		printf("icicek sectiniz\n afiyet olsun \n");
		yemekfiyati=yemekfiyati+10;
	break;
	case 3:
		printf("tatli sectiniz\n afiyet olsun \n");
		yemekfiyati=yemekfiyati+20;
	break;	
	case 4:
		printf("yemek secmediniz\n");	
	break; 		 
	default:
		printf("1 ile 4 arasinda sayi girmelisiniz.\n");}
}

void yasf(){

	printf("\n yasinizi giriniz : ");
	scanf("%d",&yas);
	if(yas>0 && yas<=6){
		printf("bebek kotegarisindesiniz \n");
		yasfiyat=ucusfiyat-(ucusfiyat*0.80);
	}
	else if (yas>6 && yas<=18){
		printf("cocuk kotegarisindesiniz \n");
		yasfiyat=ucusfiyat-(ucusfiyat*0.40);
	}
	else if (yas>18 && yas<=25){
		printf("ogrenci kotegarisindesiniz \n");
		yasfiyat=ucusfiyat-(ucusfiyat*0.20);
	}
	else if (yas>25 && yas<=65){
		printf("yetiskin kotegarisindesiniz \n");
		yasfiyat=ucusfiyat;}
	else if (yas>65 && yas<=130){
		printf("yasli kotegarisindesiniz \n");
		yasfiyat=ucusfiyat-(ucusfiyat*0.20);
	}	
	else{
		printf("yanlis yas girdiniz\n");} 	 
}
void biletyaz(){
	printf("-------------------------------------------\n");
	printf("|                  BÝLETÝNÝZ              |\n");
	printf("|                                         |\n");
	printf("|                  isim: %s             |\n",isim);
	printf("|               soyisim: %s            |\n",soyisim);
	printf("|      koltuk numaranýz: %d %d              |\n",sira, koltuk_n);
	printf("|       Bilet ücretiniz: %d TL'dir       |\n",toplam);
	printf("-------------------------------------------\n");
}

