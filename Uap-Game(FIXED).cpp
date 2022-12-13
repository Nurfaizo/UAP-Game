#include <iostream>
#include <curses.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
using namespace std;
int musuh,player,total1,total2;
char balik;
int movement;
bool gameover=false;
string pedol[2]={"dor","click"};

void judul();
void multi();
void solo(); 
void submenu();
void tips2();
void pilih1(); 
void pilih2();
void menu();
void gen_pel();
void gen_pedol();
void tembak();
void loading();
void quit(){
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t Terima Kasih Telah Mencoba game ini"<<endl;
	cout<<"\t\t\t\t\t\t  /\\__/\\ \n";
	cout<<"\t\t\t\t\t\t (  • w •) \n";
	cout<<"\t\t\t\t\t\t /  ) Thanks\n";
	system("pause");
}
int main(){
	system("cls");
	menu();
}
void judul(){
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t -----------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t|                                                           |"<<endl;
	cout<<"\t\t\t\t|      _______       __       _       __                    |"<<endl;
	cout<<"\t\t\t\t|     |  ____ \\     |  |     | |     |  |           /\\      |"<<endl;
	cout<<"\t\t\t\t|     |  |  |  \\    |  |     | |     |  |          |  |     |"<<endl;
	cout<<"\t\t\t\t|     |  |__/  /    |  |     | |     |  |          /  \\     |"<<endl;
	cout<<"\t\t\t\t|     |       /     |  \\     / |     |  |         |    |    |"<<endl;
	cout<<"\t\t\t\t|     |  | \\  \\      \\  \\___/ /      |  |______  |      |   |"<<endl;
	cout<<"\t\t\t\t|     |  |  \\  \\      \\ ____ /       |_________| |      |   |"<<endl;
	cout<<"\t\t\t\t|                                                           |"<<endl;
	cout<<"\t\t\t\t|                    BY : ODINUR                            |"<<endl;
	cout<<"\t\t\t\t|                                                           |"<<endl;
	cout<<"\t\t\t\t -----------------------------------------------------------"<<endl;
	
}
void menu(){
	do{
	judul();
	cout<<"\n\t\t\t\t\t\t\t  1.Play ";
	cout<<"\n\t\t\t\t\t\t\t  2.Tips ";
	cout<<"\n\t\t\t\t\t\t\t  3.Quit \n";
	pilih1();
	}while(movement>=1&&movement<4);
}
void pilih1(){
	cout<<"\t\t\t\t\t\t\t  ";
	cin>>movement;
	switch(movement){
		case 1:
			submenu();
		case 2:
			tips2();
		case 3:
			quit();
			exit(0);
		default:
			system("cls");
			cout<<"pilihan tidak ada";
	}
}
void submenu(){
	system("cls");
	judul();
	cout<<"\n\t\t\t\t\t\t\t  Game Mode ";
	cout<<"\n\t\t\t\t\t\t\t1.Single Player ";
	cout<<"\n\t\t\t\t\t\t\t2.Multi  Player ";
	char movement1;
	cin>>movement1;
	if(movement1=='1'){
		solo();
	}
	else if(movement1=='2'){
		multi();
	}
}
void tips1(){
	mvprintw(10,55,"PS");
	mvprintw(11,35,"Game ini berdasarkan dari game COD operasi hitam");
	mvprintw(12,43,"Pada saat scene mason di gulag");
}
void tips2(){
	system("cls");
	initscr();
	mvprintw(10,58,"Tips");
	mvprintw(11,35,"Game ini hanya memerlukan beberapa tombol untuk berjalan");
	mvprintw(12,37,"Dan anda yang bermain tidak perlu memikirkan hal lain");
	refresh();
	getch();
	endwin();
	menu();
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
void tembak2(){
	gen_pel();
	gen_pedol();
}
void multi(){
	char fire;
	loading();
	do{
		system("cls");
		for(int player=1;player<3;player++){
			
			cout<<"Player "<<player<<"\n silahkan gunakan giliran anda (t/T)\n";
			cin>>fire;
			if(fire=='t'||fire=='T'){
			tembak2();
				if(total1==total2){
					cout<<"DOR";
					cout<<"\nPlayer "<<player<<"Has been eliminated\n";
					if(player==1){
						cout<<"Player 2 WINS\n";
						system("pause");
						gameover=true;
					}
					else if(player==2){
						cout<<"player 1 Wins\n";
						system("pause");
						gameover=true;
					}	
			}else{
				cout<<"Click\n";
				system("pause");
			}
			}
			else{
				cout<<"giliran anda terlewat";
			}
		
		}
	}while(gameover==false);
	main();
}
void tembak(){
	gen_pedol();
	gen_pel();
	if(total1==total2){
		cout<<pedol[0];
		cout<<"\nKamu Sudah Mati Welcome To Isekai Waga Yuusha\n";
		cout<<"anda akan kembali ke menu\n";
		system("pause");
		gameover=true;
		
	}
	else{
		cout<<pedol[1]<<endl;
		cout<<"Selongsong sedang kosong\n";
		cout<<"Mau Coba Lagi?";
		cin>>balik;
		if(balik=='g'||balik=='G'){
			gameover=true;
		}
		else{
			cout<<"oke";
		}
		
	}
}
void solo(){
	loading();
	do{
	system("cls");
	cout<<"Tarik Pelatuk (Tekan T/t)\n";
	char choice;
	cin>>choice;
	if(choice=='t'||choice=='T'){
	tembak();
    }
    else{
    	cout<<"Tekan T untuk Menembak";
    	getch();
	}
}while(gameover==false);
main();
}
