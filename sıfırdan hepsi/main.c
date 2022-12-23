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
	printf("**********U�AK B�LET S�STEM�**********");
	printf("\n\n");
	karsilamaEkrani();
	printf("************** U�USLAR **************\n");
    printf("*      1. ucus bodrum-istanbul      *\n");
    printf("*      2. ucus istanbul-bodrum      *\n");
    printf("*      3. ucus istanbul-antalya     *\n");
    printf("*      4. ucus antalya-istanbul     *\n"); 
	printf("*************************************\n");
	printf("\nUcusunuzu seciniz : ");
	scanf("%d", &ucus);
	if (ucus==1){
		ucusfiyat=650;
		printf("bodrum-istanbul u�u�unu se�tiniz\n");
	}
	else if(ucus==2){
		ucusfiyat=750;
		printf("istanbul-bodrum  u�u�unu se�tiniz\n");
	}
	else if(ucus==3){
		ucusfiyat=700;
		printf("istanbul-antalya  u�u�unu se�tiniz\n");		
	}
	else if(ucus==4){
		ucusfiyat=800;
		printf("antalya-istanbul u�u�unu se�tiniz\n");
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
    printf("\n\n Biletiniz sisteme kaydedilmi�tir.");
	
	FILE *fp;
	fp = fopen("bilet.txt", "a");
 	fprintf(fp,"-------------------------------------------\n");
	fprintf(fp,"|                  B�LET�N�Z              |\n");
	fprintf(fp,"|                                         |\n");
	fprintf(fp,"|                  isim: %s             |\n",isim);
	fprintf(fp,"|               soyisim: %s            |\n",soyisim);
	fprintf(fp,"|      koltuk numaran�z: %d %d              |\n",sira, koltuk_n);
	fprintf(fp,"|       Bilet �cretiniz: %d TL'dir       |\n",toplam);
	fprintf(fp,"-------------------------------------------\n");
	fclose(fp);
 	
	return 0;
	}
	
	
void karsilamaEkrani()	{
	char cevap;	
	while (1) {
	printf("L�tfen isminizi girin: ");	
	scanf("%s",&isim);
	printf("L�tfen soyisminizi girin: ");
	scanf("%s",&soyisim);
	printf("isiminiz %s\nsoyisminiz %s dir\n",isim,soyisim);
	printf("do�ru mu do�ruysa d yanl��sa y harfine bas�n: ");
   scanf(" %c", &cevap);
    if (cevap == 'd'||cevap=='D') {
    printf("�sim ve soyisim bilgileriniz do�ruland�.\n\n");
    break;
  } else if (cevap=='Y' ||cevap=='y') {
    printf("L�tfen tekrar isim ve soyisim bilgilerinizi girin.\n");
    continue;
  } else {
    printf("Ge�ersiz cevap. L�tfen d veya y harflerinden birini girin.\n");
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
        printf("Lutfen bir s�ra ve koltuk numaras� giriniz (�rnek: 1 3): ");
        scanf("%d %d", &sira, &koltuk_n);
        if (sira < 1 || sira > 5 || koltuk_n < 1 || koltuk_n > 5) {
            printf("Lutfen 1 ile 5 arasinda bir s�ra ve koltuk numaras� giriniz\n");
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
	printf("evcil hayvan�n�z var m� ?\n");
	printf("1.kus\n2.kedi\n3.kopek\n4.yok \n");
	printf("bir secenek secin : ");
	scanf("%d",&hayvan);
		switch(hayvan){
   		case 1:
   			printf("ku�unuz i�in yer ay�r�ld�");
			hayvanfiyati=hayvanfiyati+5;
		break;
		case 2:	
			printf("kediniz i�in yer ay�r�ld�");
			hayvanfiyati=hayvanfiyati+10;
		break;
		case 3:
			printf("k�pe�iniz i�in yer a�r�ld�");
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
	printf("|                  B�LET�N�Z              |\n");
	printf("|                                         |\n");
	printf("|                  isim: %s             |\n",isim);
	printf("|               soyisim: %s            |\n",soyisim);
	printf("|      koltuk numaran�z: %d %d              |\n",sira, koltuk_n);
	printf("|       Bilet �cretiniz: %d TL'dir       |\n",toplam);
	printf("-------------------------------------------\n");
}

