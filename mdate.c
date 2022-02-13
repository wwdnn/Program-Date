#include "date.h"
#include <stdio.h>
#include <windows.h>

int main(){
	
	date D1, D2;
	char pilihan;

	do{
		system("cls");
		
		printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
		printf("                   PROGRAM DATE\n");
   		printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
   		printf("**********************************************************************************************************************\n");
    
		bacaDate(&D1);
		bacaDate(&D2);
		
		if(isValidDate(D1) && isValidDate(D2)){
			createDate(&D1);
			createDate(&D2);
			
			PrintObj(D1);
			dateBefore(D1);
			nextDate(D1);
			
			PrintObj(D2);
			dateBefore(D2);
			nextDate(D2);
			
			selisihDate(D1,D2);
			
		} else if (isValidDate(D1)==false && isValidDate(D2)==false){
			printf("\nKEDUA INPUT TIDAK VALID\n");
			
		} else if (isValidDate(D1)==false){
			printf("\nINPUT KE-1 TIDAK VALID\n");
			
		} else {
			printf("\nINPUT KE-2 TIDAK VALID\n");
		}
		
		printf("\nLANJUT (Y/N) : ");
		getche(pilihan);
		
	} while( pilihan =='Y' || pilihan == 'y'); 
	
	
	
	return 0;
}
