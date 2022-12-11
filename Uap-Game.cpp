#include <iostream>
#include <curses.h>
#include <stdlib.h>
#include <windows.h>

#define SCREEN_WIDTH 100
#define SCREEN_Height 30
#define Win_width 80
#define GAP_SIZE 7
#define Enemy_dif 45
 
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Cursorposition;
int pilih;
int enemyx[2];
int enemyt[2];
int enemyflag[2];
bool play =false;
int x=1,y=1;


/*fungsi untuk mngeluarkan loading*/
void Loading(){
	initscr();
	mvprintw(15,50,"Memuat");
	refresh();
	for(int a =0;a<119;a++){
		mvprintw(16,a,"|");
		refresh();
		Sleep(50);
	}
	endwin();
		

	
}
void gotoxy(int x){
	Cursorposition.X = x;
	SetConsoleCursorPosition(console, Cursorposition);
}
void gen_musuh(int ind){
	enemyt[ind]=3+rand()%(Win_width-10);
}
void musuh(int ind){
	
}
void game(){
	while(1){
		
	}
	
}
void hoto(){
	
}
void hal1(){//halaman utama game
	initscr();
	clear();
	mvprintw(10,5,"1. Start Game");
	mvprintw(11,5,"2. How To Play");
	mvprintw(12,5,"3. Exit");
	refresh();
	getch();
	endwin();
}
void hal2(){
	hal1();
	char movement = getch();
		if(movement=='1') {
			system("cls");
			Loading();
		}
		else if(movement=='2') {
				Loading();	
			}
		else if( movement=='3'){
				exit(0);
		}
	}


int main(){
	Loading();
	hal2();
	
}
