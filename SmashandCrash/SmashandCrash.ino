#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;
#define MENULENGTH 4
const char strSurvival[] PROGMEM = "Survival";
const char strStatus[] PROGMEM = "Status";
const char strCtrl[] PROGMEM = "Controls";
const char strTitle[] PROGMEM = "Change Game";
const char* const menu[MENULENGTH] PROGMEM = {
  strSurvival,
  strStatus,
  strCtrl,
  strTitle,
};
extern const byte logo[];
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
  gb.begin();
  gb.display.setFont(font5x7);
  titlescreen();
  gb.battery.show = false;
  gb.display.persistence = false;
  gb.setFrameRate(30);
};

int playerx = 38;
int playery = 36;
int playerflip = NOFLIP;
int playeryv = 1;
int playergrav = 0;
boolean playerjump = true;

int frames = -1;
int CPU = gb.getCpuLoad();
int RAM = gb.getFreeRam();

boolean pause = false;

int mapscroll = 0;

int meteorx = random(0,76);
int meteory = 0;

int change = 0;
int disaster = 0;

int arrowx = 0;
int arrowy = random(0,34);

int ballx = 0;
int bally = random(6,42);
int way = random(0,1);
int ballyv = -1.5;

boolean alive = true;

void loop(){
  gb.battery.show = false;
  switch(gb.menu(menu, MENULENGTH)){
    case -1: //nothing selected
      titlescreen();
      break;
    case 0: //Load Survival
      gb.display.print(F("    Loading...."));
        gb.pickRandomSeed();
        playerx = 38;
        playery = 36;
        playerflip = NOFLIP;
        playeryv = 1;
        playergrav = 1;
        
        meteory = 0;
        meteorx = random(0,76);
        
        change = 0;
        disaster = 0;
        
        arrowx = 0;
        arrowy = random(0,34);
        
        ballx = 0;
        bally = random(6,42);
        way = random(0,1);
        ballyv = -1.5;
        
        alive = true;
        pause = false;
        maps();
        gb.display.setFont(font3x5);
        play();
      break;
    case 1: //Load Status
      while (1) {
        if (gb.update()) {
          if (gb.buttons.pressed(BTN_B)) {
            gb.sound.playCancel();
            gb.battery.show = false;
            break;
          }
          gb.display.cursorX = 0;
          gb.display.cursorY = 0;
          CPU = gb.getCpuLoad();
          RAM = gb.getFreeRam();
          gb.display.print("CPU:");
          gb.display.print(CPU);
          gb.display.println("%");
          gb.display.println("");
          gb.display.print("Free RAM: ");
          gb.display.println(RAM);
          gb.display.println("");
          gb.display.println("Press \26");
          gb.battery.show = true;
      };
    };
      break;
    case 2: //Controls
      while (1) {
        if (gb.update()) {
          if (gb.buttons.pressed(BTN_B)) {
            gb.sound.playCancel();
            break;
          }
          gb.display.cursorX = 0;
          gb.display.cursorY = 0;
  
          gb.display.println("\25 Jump");
          gb.display.println("");
          gb.display.println("\26 Run");
          gb.display.println("");
          gb.display.println("\27 Pause");
          gb.display.println("Press \26");
      };
    };
    break;
    case 3: //Back to the Loader
      gb.changeGame();
      break;
    default:
      break;
  };
};

void titlescreen(){
  while(1){
    if (gb.update()){
      gb.display.drawBitmap(0, 0, logo);
      if (gb.buttons.pressed(BTN_A)){
        gb.sound.playOK();
        gb.battery.show = false;
        break;
        break;
      }
      if (gb.buttons.pressed(BTN_UP)){
        gb.sound.setVolume(1);
        gb.sound.playOK();
      }
      if(gb.buttons.pressed(BTN_DOWN)){
        gb.sound.playCancel();
        gb.sound.setVolume(0);
      }
      if (gb.buttons.pressed(BTN_C)){
        gb.changeGame();
      };
    };
  };
};
