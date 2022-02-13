#include "date.h"
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>

void createDate(date *D){
	setTanggal(01, &(*D));
	setBulan(01, &(*D));
	setTahun(1900, &(*D)); 
}

int getTanggal (date D){
	return D.tanggal;
}

int getBulan (date D){
	return D.bulan;
}

int getTahun (date D){
	return D.tahun; 
}

void setTanggal (int newTanggal, date *D){
	newTanggal = (*D).tanggal;
}

void setBulan(int newBulan, date *D){
	newBulan = (*D).bulan;
}

void setTahun (int newTahun, date *D){
	newTahun = (*D).tahun;  
}

void bacaDate (date *D){
	
	printf("\n\nINPUT TANGGAL : ");
	scanf("%d", &(*D).tanggal);
	
	printf("INPUT BULAN   : ");
	scanf("%d", &(*D).bulan);
	
	printf("INPUT TAHUN   : ");
	scanf("%d", &(*D).tahun);
	
}

bool isValidDate (date D){
	if ((getTahun(D) < 1900) || (getTahun(D) > 30000) || (getBulan(D) < 1) || (getBulan(D) > 12) || (getTanggal(D) < 1) || (getTanggal(D) > tanggalAkhir(D))){
		return false;
	} else {
		return true; 
	}
}

bool isKabisat (date D){
	if((getTahun(D)%400 == 0) || (getTahun(D)%100 == 0) || (getTahun(D)%4 == 0) && (getBulan(D) == 2)){
		return true;
	} else {
		return false; 
	}
}

int tanggalAkhir (date D){
	if (isKabisat(D)){
		return 29; 
	} else if ((getBulan(D)==1)||(getBulan(D)==3)||(getBulan(D)==5)||(getBulan(D)==7)||(getBulan(D)==8)||(getBulan(D)==10)||(getBulan(D)==12)){
		return 31; 
	} else if ((isKabisat(D) == false) && (getBulan(D) == 2)){
		return 28;
	} else if ((getBulan(D)==4)||(getBulan(D)==6)||(getBulan(D)==9)||(getBulan(D)==11)) {
		return 30; 
	}
}

void PrintObj (date D){
		printf("\nDATE INPUT  : %d/%d/%d", getTanggal(D), getBulan(D), getTahun(D));
}

void dateBefore(date D){
	int beforeTanggal;
	int beforeBulan;
	int beforeTahun;
	
	if(getTanggal(D) == 1 && tanggalAkhir(D)==31){
		if(getBulan(D) == 3 && ((getTahun(D)%400 == 0) || (getTahun(D)%100 == 0) || (getTahun(D)%4 == 0))){
			beforeTanggal = 29;
			beforeBulan = getBulan(D) - 1;
			beforeTahun = getTahun(D);
			
		} else if (getBulan(D) == 3){
			beforeTanggal = 28;
			beforeBulan = getBulan(D) - 1;
			beforeTahun = getTahun(D);
			
		} else if (getBulan(D) == 1){
			beforeTanggal = 31;
			beforeBulan = 12;
			beforeTahun = getTahun(D) - 1; 
			
		} else {
			beforeTanggal = 30;
			beforeBulan = getBulan(D) - 1;
			beforeTahun = getTahun(D);
		}
		
	} else if(getTanggal(D) == 1 && tanggalAkhir(D)==30){
		beforeTanggal = 31;
		beforeBulan = getBulan(D) - 1;
		beforeTahun = getTahun(D);
		
	} else{
		beforeTanggal = getTanggal(D) - 1;
		beforeBulan = getBulan(D);
		beforeTahun = getTahun(D);
	}
	
	printf("\nDATE BEFORE : %d/%d/%d\n", beforeTanggal, beforeBulan, beforeTahun);
}

void nextDate(date D){
	int nextTanggal;
	int nextBulan; 
	int nextTahun; 
	
	if(getTanggal(D) == 31 && tanggalAkhir(D) == 31){
		if(getBulan(D) == 12){
			nextTanggal = 1;
			nextBulan = 1;
			nextTahun = getTahun(D) + 1;
			
		} else {
			nextTanggal = 1;
			nextBulan = getBulan(D) + 1;
			nextTahun = getTahun(D);
		}
		
	} else if(getTanggal(D) == 30 && tanggalAkhir(D) == 30){
		nextTanggal = 1;
		nextBulan = getBulan(D) + 1;
		nextTahun = getTahun(D);
		
	} else if(getTanggal(D) == 29 && tanggalAkhir(D) == 29){
		nextTanggal = 1; 
		nextBulan = getBulan(D) + 1;
		nextTahun = getTahun(D);
		
	} else if(getTanggal(D) == 28 && tanggalAkhir(D) == 28){
		nextTanggal = 1;
		nextBulan = getBulan(D) + 1;
		nextTahun = getTahun(D);
		
	} else {
		nextTanggal = getTanggal(D) + 1;
		nextBulan = getBulan(D);
		nextTahun = getTahun(D);
	}
	
	printf("NEXT DATE   : %d/%d/%d\n", nextTanggal, nextBulan, nextTahun);
}

void selisihDate(date D1, date D2){
	int hariMulai;
	int hariSelesai; 
	int hariSelisih;
	int hari, bulan, tahun;
	
	hariMulai = getTanggal(D1) + (getBulan(D1)*30) + (getTahun(D1)*365);
	hariSelesai = getTanggal(D2) + (getBulan(D2)*30) + (getTahun(D2)*365);
	hariSelisih = abs(hariSelesai-hariMulai);
	
	tahun = hariSelisih/365;
	bulan = (hariSelisih%365)/30;
	hari = hariSelisih - (tahun * 365 + bulan * 30);
	
	printf("\n\nJARAK ANTARA KEDUA TANGGAL TERSEBUT YAITU : %d HARI ATAU %d TAHUN, %d BULAN, %d HARI  \n", hariSelisih, tahun, bulan, hari);
}



















