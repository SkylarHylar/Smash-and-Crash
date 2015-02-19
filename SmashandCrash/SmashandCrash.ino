#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;
#define MENULENGTH 4
const char strSurvival[] PROGMEM = "Survival";
const char strOptions[] PROGMEM = "Options";
const char strMulti[] PROGMEM = "Multiplayer";
const char strTitle[] PROGMEM = "Change Game";
const char* const menu[MENULENGTH] PROGMEM = {
  strSurvival,
  strOptions,
  strMulti,
  strTitle,
};
extern const byte logo[];
extern const byte player[];
extern const byte platform[];
extern const byte platform2[];
extern const byte meteor[];
extern const byte arrow[];
extern const byte font3x5[];
extern const byte font5x7[];
void setup(){
  gb.begin();
  gb.display.setFont(font5x7);
  gb.titleScreen(logo);
  gb.battery.show = false;
  gb.display.persistence = false;
}

int playerx = 20;
int playery = 36;
int playerflip = NOFLIP;
int playerxv = 2;
int playeryv = 1;
int playergrav = 1;
int frames = 0;

int meteorx = random(0,76);
int meteory = 0;

int arrowx = 0;
int arrowy = random(20,40);

boolean alive = true;

void loop(){
  gb.battery.show = false;
  switch(gb.menu(menu, MENULENGTH)){
    case -1: //nothing selected
      gb.titleScreen(logo);
      break;
    case 0: //Load Survival
      gb.display.print(F("    Loading...."));
        gb.pickRandomSeed();
        playerx = 20;
        playery = 20;
        playerflip = NOFLIP;
        playerxv = 2;
        playeryv = 1;
        playergrav = 1;
        meteory = 0;
        meteorx = random(0,76);
        arrowx = 0;
        arrowy = random(20,40);
        alive = true;
        play();
      break;
    case 1: //Load Options
      while (1) {
        if (gb.update()) {
          if (gb.buttons.pressed(BTN_B)) {
            gb.sound.playCancel();
            gb.battery.show = false;
            break;
          }
          gb.display.cursorX = 0;
          gb.display.cursorY = 0;
  
          gb.display.print(F("Battery:"));
          gb.display.print(gb.battery.level);
          gb.display.println(F("/4"));
          gb.display.println(F(""));

          gb.display.print(F("Light:"));
          gb.display.println(gb.backlight.ambientLight);
          gb.display.println(F(""));

          gb.display.print(F("Backlight:"));
          gb.display.println(gb.backlight.backlightValue);
          gb.display.println(F(""));
          
          gb.battery.show = true;
      }
    }
      break;
    case 2: //Load Multiplayer
      gb.display.print(F(" Connecting..."));
        delay(100);
      break;
    case 3: //Back to the Title Screen
      gb.changeGame();
      break;
    default:
      break;
  }
}
