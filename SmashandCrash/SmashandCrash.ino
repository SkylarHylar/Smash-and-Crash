#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;
#define MENULENGTH 4
const char strSurvival[] PROGMEM = "Survival";
const char strOptions[] PROGMEM = "Options";
const char strMulti[] PROGMEM = "Multiplayer";
const char strTitle[] PROGMEM = "Back to Title";
const char* const menu[MENULENGTH] PROGMEM = {
  strSurvival,
  strOptions,
  strMulti,
  strTitle,
};
extern const byte player[];
extern const byte platform[];
extern const byte meteor[];
extern const byte font3x5[];
extern const byte font5x7[];
void setup(){
  gb.begin();
  gb.display.setFont(font5x7);
  gb.titleScreen(F("Smash & Crash"));
  gb.battery.show = false;
  gb.display.persistence = true;
}

int playerx = 20;
int playery = 20;
int playerflip = NOFLIP;
int playerxv = 2;
int playeryv = 1;
int playergrav = 1;
int frames = 0;

int meteorx = random(0,76);
int meteory = 0;

boolean alive = true;

void loop(){
  switch(gb.menu(menu, MENULENGTH)){
    case -1: //nothing selected
      gb.titleScreen(F("Smash & Crash"));
      break;
    case 0: //Load story
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
        alive = true;
        play();
      break;
    case 1: //Load Survival
      gb.display.print(F("    Loading...."));
        delay(100);
      break;
    case 2: //Load Multiplayer
      gb.display.print(F(" Connecting..."));
        delay(100);
      break;
    case 3: //Back to the Title Screen
      gb.titleScreen(F("Smash & Crash"));
      break;
    default:
      break;
  }
}
