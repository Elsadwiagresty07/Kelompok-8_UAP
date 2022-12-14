#include <iostream>
#include <ncurses.h> //animasi text
#include <windows.h>

//untuk menentukan nilai tombol perintah yang digunakan agar tidak tertukar
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;


// unutk menentukan mana tempat yang bisa dilewati dan mana yang tidak
				//  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17
int maze[18][18]={{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,},//0
				  { 0 , 1 , 1 , 1 , 1 , 1 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 0 ,},//1
				  { 0 , 1 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 ,},//2
				  { 0 , 1 , 0 , 0 , 1 , 0 , 1 , 1 , 1 , 1 , 0 , 0 , 0 , 1 , 1 , 0 , 1 , 0 ,},//3
				  { 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 0 ,},//4
				  { 0 , 1 , 0 , 1 , 0 , 0 , 1 , 0 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 0 , 1 , 0 ,},//5
				  { 0 , 0 , 0 , 1 , 1 , 1 , 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 1 , 0 ,},//6
				  { 0 , 0 , 1 , 1 , 1 , 0 , 1 , 1 , 1 , 0 , 1 , 0 , 0 , 1 , 0 , 0 , 0 , 0 ,},//7
				  { 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 ,},//8
				  { 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 1 , 0 , 0 , 1 , 0 , 1 , 1 , 1 , 1 , 0 ,},//9
				  { 0 , 1 , 0 , 0 , 1 , 0 , 0 , 1 , 0 , 1 , 1 , 1 , 0 , 0 , 1 , 0 , 1 , 0 ,},//10
				  { 0 , 1 , 0 , 1 , 1 , 0 , 1 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 1 , 1 , 0 ,},//11
				  { 0 , 1 , 1 , 0 , 1 , 1 , 0 , 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 0 ,},//12
				  { 0 , 1 , 1 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 0 , 0 , 0 , 0 , 0 ,},//13
				  { 0 , 1 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 0 , 1 , 1 , 0 , 0 , 0 , 0 ,},//14
				  { 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 ,},//15
				  { 0 , 0 , 0 , 1 , 1 , 1 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 1 , 0 , 0 , 0 , 0 ,},//16
				  { 0 , 0 , 2 , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,},//17
				  };
				
// tampilan awal							
void loading_game(){
		
		mvprintw(3,0, "--------------------------------------------------------------------------------");
 		mvprintw(4,0, ",------.");                                                                       
		mvprintw(5,0, "|  .---' ,---.  ,---. ,--,--. ,---.  ,---.     ,--.--. ,---.  ,---. ,--,--,--. ");
		mvprintw(6,0, "|  `--, (  .-' | .--'' ,-.  || .-. || .-. :    |  .--'| .-. || .-. ||        | ");
		mvprintw(7,0, "|  `---..-'  `)\ `--.\ '-'  || '-' '\   --.    |  |   ' '-' '' '-' '|  |  |  | ");
		mvprintw(8,0, "`------'`----'  `---' `--`--'|  |-'  `----'    `--'    `---'  `---' `--`--`--' ");
		mvprintw(9,0, "                             `--'                                              ");
		mvprintw(10,0, "--------------------------------------------------------------------------------");
		mvprintw(11,0, "Press any key to continue..............");
		
		
}

//untuk membuat latar belakang
void area(){
	    				//  0 1 2 3 4 5 6 7 8 9 1011121314151617
			 mvprintw(0,0, "[][][][][][][][][][][][][][][][][][]");
    		 mvprintw(1,0, "[]          [][][]                []");
    		 mvprintw(2,0, "[]  []    [][][][][][][][]  [][][][]");
    		 mvprintw(3,0, "[]  [][]  []        [][][]    []  []");
    		 mvprintw(4,0, "[]              []                []");
    		 mvprintw(5,0, "[]  []  [][]  [][]  []  []  [][]  []");
    		 mvprintw(6,0, "[][][]        []              []  []");
			 mvprintw(7,0, "[][]      []      []  [][]  [][][][]");
			 mvprintw(8,0, "[][][][]  [][][][]      [][][][][][]");
			 mvprintw(9,0, "[]            []  [][]  []        []");
			mvprintw(10,0, "[]  [][]  [][]  []      [][]  []  []");
			mvprintw(11,0, "[]  []    []  []    [][][][][]    []");
			mvprintw(12,0, "[]    []    []  []              [][]");
			mvprintw(13,0, "[]    [][]  [][][][]      [][][][][]");
			mvprintw(14,0, "[]  []  [][][][]      []    [][][][]");
			mvprintw(15,0, "[]                [][]            []");
			mvprintw(16,0, "[][][]      [][][]          [][][][]");
			mvprintw(17,0, "[][]    [][][][][][][][][][][][][][]");  
}


int main(){
	int ch;
	int b=0;
	int a=0;
	int x=1;
	int y=16;
	
	initscr();
	loading_game();
	Sleep(getch());
	clear();
    mvprintw(x,y, "0");
    while (b==0) {
    	
		area();
		mvprintw(x,y*2, "00");
		
        ch = getch();
        if(maze[x][y]==2){
			b=5;
            break;
		}
        	
		if(x<=1){
			x=1;
		}
		if(y<=1){
			y=1;
		}
		
		
// untuk menerima input yang masuk dan membiarkan input yang tidak diinginkan
        switch(ch) {
            case 'w': case KEY_UP:
            	clear();
            	x--;
            	if(maze[x][y]==0){
				x++;

				}	
                break;
                
            case 's': case KEY_DOWN:
            	clear();
            	x++;
				if(maze[x][y]==0){
				x--;

				}
                break;
                
            case 'a': case KEY_LEFT:
				clear();
            	y--;
            	if(maze[x][y]==0){
				y++;
				}
                break;
                
            case 'd': case KEY_RIGHT:
				clear();
	            y++;
            	if(maze[x][y]==0){
				y--;
				}
				break;
				
            case 'q': case 27:
            	clear();
            	b=1;
                break;
            default:
            	clear();
        }
        
}
 //output di akhir game nya dia akan keluar seperti ini 'game telah berakhir'
 	cout<<"--------------------------------------------------------------------------------\n"<<endl;
	cout<<"GAME TELAH BERAKHIR\n"<<endl;
	cout<<"--------------------------------------------------------------------------------\n"<<endl;
	 
 }
