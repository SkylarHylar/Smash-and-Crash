#include <ab_logo.h>
#include <Arduboy.h>
// #include <Maps.ino> Not Yet!
Arduboy ad;
extern const byte Title[];
extern const byte player[];
extern const byte platform[];
extern const byte platform2[];
extern const byte meteor[];
extern const byte arrow[];
extern const byte ball[];
extern const byte blow[];
extern const byte bhole[];
extern const byte point[];
extern const byte font3x5[];
extern const byte font5x7[];
void setup(){
  ad.begin();
  ad.setFrameRate(30);
};

int playerx = 38;
int playery = 36;
int playeryv = 1;
int playergrav = 0;
boolean playerjump = true;

int frames = -1;

int mapscroll = 0;

int meteorx = random(0,120);
int meteory = 0;

int change = 0;
int disaster = 0;

int arrowx = 0;
int arrowy = random(0,50);

int ballx = 0;
int bally = random(6,58);
int way = random(0,1);
int ballyv = -1.5;

boolean alive = true;

void loop(){
  ad.clear();
  ad.print("Press A!")
  if(ad.pressed(A_BUTTON)) {
        playerx = 38;
        playery = 36;
        playeryv = 1;
        playergrav = 1;
        
        meteory = 0;
        meteorx = random(0,120);
        
        change = 0;
        disaster = 0;
        
        arrowx = 0;
        arrowy = random(0,50);
        
        ballx = 0;
        bally = random(6,58);
        way = random(0,1);
        ballyv = -1.5;
        
        alive = true;
        play();
  };
  ad.display();
};
