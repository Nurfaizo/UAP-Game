#include <iostream>
#include <curses.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
using namespace std;
int musuh,player,total1,total2;
char balik;
bool play=false;
string pedol[2]={"dor","click"};

void judul(); 
void pilih(); 
void menu();
void gen_pel();
void gen_pedol();
void tembak();
void loading();
void judul(){
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t ___________________________________________________________";
	cout<<"\t\t\t\t|                                                           |";
	cout<<"\t\t\t\t|      _______       __       _       __                    |";
	cout<<"\t\t\t\t|     |  ____ \     |  |     | |     |  |           /\      |";
	cout<<"\t\t\t\t|     |  |  |  \    |  |     | |     |  |          |  |     |";
	cout<<"\t\t\t\t|     |  |__/  /    |  |     | |     |  |          /  \     |";
	cout<<"\t\t\t\t|     |       /     |  \     / |     |  |         |    |    |";
	cout<<"\t\t\t\t|     |  | \  \      \  \___/ /      |  |______  |      |   |";
	cout<<"\t\t\t\t|     |  |  \  \      \ ____ /       |_________| |      |   |";
	cout<<"\t\t\t\t|                                                           |";
	cout<<"\t\t\t\t|                    BY : ODINUR                            |";
	cout<<"\t\t\t\t|___________________________________________________________|";
	
}
void menu(){
	judul();
	cout<<"\n\t\t\t\t\t\t  1.Play ";
	cout<<"\n\t\t\t\t\t\t  2.Tips ";
	cout<<"\n\t\t\t\t\t\t  3.Quit ";
	pilih();
}
void pilih(){
	
}
void tips1(){
	mvprintw(10,55,"PS");
	mvprintw(11,35,"Game ini berdasarkan dari game COD operasi hitam");
	mvprintw(12,43,"Pada saat scene mason di gulag");
}
void loading(){
	initscr();
	clear();
	tips1();
	for(int y=0;y<3;y++){
	mvprintw(26,100,"Loading...");
	mvprintw(27,100, "-------------------");
	mvprintw(28,100, "|                 |");
	mvprintw(29,100, "-------------------");
	for(int f=1;f<17;f++){
		mvprintw(28,100+f,">>");
	refresh();
	Sleep(200);
	}
}
	endwin();
}

void gen_pel(){//untuk memutar selongsong revolver sehingga peluru berada pada selongsong acak
	int peluru;
	srand(time(0));
	peluru=(rand()%6);
	total1=peluru;
}
void gen_pedol(){
	int roulete;
	srand(time(0));
	roulete=(rand()%5)+1;
	total2=roulete;
}
void tembak(){
	gen_pedol();
	gen_pel();
	if(total1==total2){
		cout<<pedol[0];
		cout<<"Kamu Sudah Mati Welcome To Isekai Waga Yuusha ";
		
	}
	else{
		cout<<pedol[1]<<endl;
		cout<<"Yeay Peluru tidak dimuntahkan oleh pistol";
		cout<<"Mau Coba Lagi?";
		
	}
}
void solo(){
	cout<<"Silahkan melakukan penembakan";
	system("pause");
	tembak();
	
}
int main(){
	loading();
}
