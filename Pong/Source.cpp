#include "sl.h"

struct Player {
	double height=100;
	double width=10;
	double posX;
	double posY;
};
struct Ball {
	double posX;
	double posY;
	double speedX=2;
	double speedY=2;
	double radius=18;
	int resolution=10000;
};
struct Screen
{
	int height=600;
	int width=800;
};
struct menuRect
{
	double width=100;
	double height=30;
};

Player player1;
Player player2;
Ball ball;
Ball cursor;
Screen screen;
menuRect play;
menuRect exit;

int main(int args, char *argv[])
{
	slWindow(screen.width, screen.height, "Simple SIGIL Example", false);
	slSetFont(slLoadFont("ttf/white_rabbit.ttf"),24);
	slSetTextAlign(SL_ALIGN_CENTER);
	player1.posX=screen.width/20;
	player1.posY=screen.height/2;
	player2.posX=screen.width-(screen.width/20);
	player2.posY=screen.height-(screen.height/2);
	ball.posX = screen.width / 2;
	ball.posY = screen.height / 2;
	bool gameMenuOn = true;
	int scoreP1 = 0;
	int scoreP2 = 0;
	do{
		while (gameMenuOn&&!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
		{
			if (slGetKey(SL_KEY_ENTER))
			{
				gameMenuOn = false;
			}
			slText(screen.width/2, screen.height/2+100, "Pong");
			slText(screen.width/2, screen.height/2-200, "Press [Enter] to play");
			slText(screen.width/2, screen.height/2-240, "Press [Esc] to Exit");
			slRender();
		}

		ball.posX += ball.speedX;
		ball.posY += ball.speedY;
		if (ball.posY+ball.radius >= screen.height || ball.posY+ball.radius<=0){
			ball.speedY = -ball.speedY;
		}
		if (ball.posX+ball.radius >= screen.width)
		{
			scoreP1++;
		}
		slText(screen.width / 2, screen.height / 2 + 100, "P1:"); 
		slCircleFill(ball.posX, ball.posY, ball.radius, ball.resolution);
		slRectangleFill(player1.posX, player1.posY, player1.width, player1.height);
		slRectangleFill(player2.posX, player2.posY, player2.width, player2.height);
		slRender();// draw everything
	} while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE));
	slClose();// close the window and shut down SIGIL
	return 0;
}