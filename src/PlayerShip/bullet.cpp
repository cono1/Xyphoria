#include "bullet.h"

namespace game
{
bool checkBulletScreenLimit(Bullet bullet);

void initBullet(Bullet& bullet, PlayerShip ship)
{
	bullet.texture = LoadTexture("res/tempBullet.png");
	bullet.pos.x = ship.pos.x + ship.width / 2;
	bullet.pos.y = ship.pos.y;
	bullet.alive = false;
	bullet.speed = 500.f;
	bullet.color = WHITE;
}

void updateBullet(Bullet& bullet, PlayerShip ship)
{
	if (bullet.alive)
	{
		bullet.pos.y -= bullet.speed * GetFrameTime();
	
		if (checkBulletScreenLimit(bullet))
		{
			bullet.alive = false;
		}
	}
	else
	{
		bullet.pos.x = ship.pos.x + ship.width / 2;
		bullet.pos.y = ship.pos.y;
	}
}
	
void drawBullet(Bullet bullet)
{
	if (bullet.alive)
		DrawTextureV(bullet.texture, bullet.pos, bullet.color);
}

void deInitBullet(Bullet& bullet)
{
	UnloadTexture(bullet.texture);
}

bool checkBulletScreenLimit(Bullet bullet)
{
	return(bullet.pos.y + bullet.texture.height <= 0);
}
}