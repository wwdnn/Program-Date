#include <stdbool.h>
typedef struct date{
	int tanggal;
	int bulan;
	int tahun; 
}date;

void createDate(date *D);
int getTanggal (date D);
int getBulan (date D);
int getTahun (date D);
void setTanggal (int newTanggal, date *D);
void setBulan (int newBulan, date *D);
void setTahun (int newTahun, date *D);
void bacaDate (date *D); 
bool isValidDate (date D); 
bool isKabisat(date D);
int tanggalAkhir(date D); 
void PrintObj (date D);
void dateBefore(date D);
void nextDate(date D);
void selisihDate(date D1, date D2);
