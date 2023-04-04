#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#define ROWS 3
#define COLS 3

void create_grid(int box_numberx,int box_numbery,int gridsize_x,int gridsize_y);

int GAME_OVER=0;

int main(){
	int clicked_boxes[3][3] = {
	 {0, 0, 0},
	 {0, 0, 0},
	 {0, 0, 0},
	  };
	int box_matrix[ROWS][COLS] ={
	{9,8,6},
	{5,4,0},
	{-1,-2,-3}
	};

	initwindow(1000,1000);
	
	create_grid(3,3,600,600);
	settextstyle(2,HORIZ_DIR,20);
	setlinestyle(3,500,3);
	setcolor(1);
	int x,y,turn;
	turn=1;
	while(!GAME_OVER){
		delay(10);
		if(turn%2==0){
			
			outtextxy(747,127,"X in sýrasý ");
		}
		else if(turn%2==1){
			outtextxy(747,127,"O nun sýrasý");
		}
		
		getmouseclick(WM_LBUTTONDBLCLK,x,y);
		if (x!=-1){
			printf("%d,%d",x,y);
		}
		if ((x<300&&y<300)&&(x>100&&y>100)&&(!clicked_boxes[0][0])){
			
			if(turn%2==0){
				line(100,100,300,300);
				line(300,100,100,300);
				box_matrix[0][0]= 2;
			}
			else{
				circle(200,200,50);
				box_matrix[0][0]= 3;
			}
			clicked_boxes[0][0] = 1;
			
			turn++;
		}
		else if ((x<500&&y<300)&&(x>300&&y>100)&&(!clicked_boxes[0][1])){
			
			if(turn%2==0){
				line(300,100,500,300);
				line(300,300,500,100);
				box_matrix[0][1]= 2;
			}
			else{
				circle(400,200,50);
				box_matrix[0][1]= 3;
			}
			clicked_boxes[0][1] = 1;
			turn++;
			
		}
		else if ((x<700&&y<300)&&(x>500&&y>100)&&(!clicked_boxes[0][2])){
			
			if(turn%2==0){
				line(500,100,700,300);
				line(500,300,700,100);
				box_matrix[0][2]= 2;
			}
			else{
				circle(600,200,50);
				box_matrix[0][2]= 3;
			}
			clicked_boxes[0][2] = 1;
			turn++;
			
		}
		else if ((x<300&&y<500)&&(x>100&&y>300)&&(!clicked_boxes[1][0])){
			// düzenle
			if(turn%2==0){
				line(100,300,300,500);
				line(300,300,100,500);
				box_matrix[1][0]= 2;
			}
			else{
				circle(200,400,50);
				box_matrix[1][0]= 3;
			}
			clicked_boxes[1][0] = 1;
			turn++;
			
		}
		else if ((x<500&&y<500)&&(x>300&&y>300)&&(!clicked_boxes[1][1])){
			
			if(turn%2==0){
				line(300,300,500,500);
				line(500,300,300,500);
				box_matrix[1][1]= 2;
			}
			else{
				circle(400,400,50);
				box_matrix[1][1]= 3;
			}
			clicked_boxes[1][1] = 1;
			turn++;
			
		}
		else if ((x<700&&y<500)&&(x>500&&y>300)&&(!clicked_boxes[1][2])){
			
			if(turn%2==0){
				line(700,500,500,300);
				line(700,300,500,500);
				box_matrix[1][2]= 2;
			}
			else{
				
				circle(600,400,50);
				box_matrix[1][2]= 3;
			}
			clicked_boxes[1][2] = 1;
			turn++;
			
		}
		else if ((x<300&&y<700)&&(x>100&&y>500)&&(!clicked_boxes[2][0])){
			// düzenle
			if(turn%2==0){
				line(100,500,300,700);
				line(300,500,100,700);
				box_matrix[2][0]= 2;
			}
			else{
				circle(200,600,50);
				box_matrix[2][0]= 3;
			}
			clicked_boxes[2][0] = 1;
			turn++;
		}		
		else if ((x<500&&y<700)&&(x>300&&y>500)&&(!clicked_boxes[2][1])){
			
			if(turn%2==0){
				line(300,500,500,700);
				line(500,500,300,700);
				box_matrix[2][1]= 2;
			}
			else{
				circle(400,600,50);
				box_matrix[2][1]= 3;
			}
			clicked_boxes[2][1] = 1;
			turn++;
			
		}
		else if ((x<700&&y<700)&&(x>500&&y>500)&&(!clicked_boxes[2][2])){
			
			
			if(turn%2==0){
				line(500,500,700,700);
				line(700,500,500,700);
				box_matrix[2][2]= 2;
				
			}
			else{
				circle(600,600,50);
				box_matrix[2][2]= 3;
			}
			clicked_boxes[2][2] = 1;
			turn++;
			
		}		
		
	int diagonalElement = box_matrix[0][0]; 
	for(int i=1; i<ROWS; i++) {
	    if(box_matrix[i][i] != diagonalElement) {
	        break;
	    } else if(i == ROWS-1) {
	        outtextxy(752,217,"oyun bitti");
	        GAME_OVER=1;
	    }
	}
	
	for(int i=0; i<ROWS; i++) {
	    for(int j=0; j<COLS; j++) {
	        if(j == COLS-1) {
	            continue;
	        }
	        if(box_matrix[i][j] != box_matrix[i][j+1]) {
	            break;
	        } else if(j == COLS-2) {
	            outtextxy(752,217,"oyun bitti");
	            GAME_OVER=1;
	        }
	    }
	}
	
	for(int i=0; i<COLS; i++) {
	    for(int j=0; j<ROWS; j++) {
	        if(j == ROWS-1) {
	            continue;
	        }
	        if(box_matrix[j][i] != box_matrix[j+1][i]) {
	            break;
	        } else if(j == ROWS-2) {
	            outtextxy(752,217,"oyun bitti");
	            GAME_OVER=1;
	        }
	    }
}
	}
	
	getch();
	closegraph();
	
	return 0;
}



void create_grid(int box_numberx,int box_numbery,int gridsize_x,int gridsize_y){
	
	
	int space_xlines=gridsize_x/box_numberx;	
	
	int space_ylines=gridsize_y/box_numbery;
	
	rectangle(100,100,100+gridsize_x,100+gridsize_y);
	
	int i;
	for(i=1;i<box_numberx;i++){
		
		line(100+i*space_xlines,100,100+i*space_xlines,100+gridsize_y);	
		
	}
	
	int j;
	for(j=1;j<box_numbery;j++){
		
		line(100,100+j*space_ylines,100+gridsize_x,100+j*space_ylines);	
		
	}
	
	
	
	
	
	
	
	
	
}







