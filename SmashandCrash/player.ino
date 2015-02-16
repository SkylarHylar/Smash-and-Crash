int playerx = 20;
int playery = 20;
int playerflip = NOFLIP;
int playerxv = 2;
int playeryv = 1;
int playergrav = 1;

int meteorx = random(0,76);
int meteory = 0;
void play(){
    while(true){
      if(gb.update()){
        gb.display.drawBitmap(meteorx,meteory,meteor);
        meteory = meteory + 1;
        playery = playery + playergrav;
        gb.display.drawBitmap(playerx,playery,player,NOROT,playerflip);
        gb.display.drawBitmap(0,44,platform);
        if (gb.buttons.repeat(BTN_UP,2)){
          playery = playery - playeryv;
        };
        if (gb.buttons.repeat(BTN_DOWN,2)){
          playery = playery + playeryv;
        };
        if (gb.buttons.repeat(BTN_LEFT,2)){
          playerx = playerx - playerxv;
          playerflip = FLIPH;
        };
        if (gb.buttons.repeat(BTN_RIGHT,2)){
          playerx = playerx + playerxv;
          playerflip = NOFLIP;
        };
        if (gb.buttons.repeat(BTN_A,20)){
          if (playergrav == 0) {
          gb.sound.playOK();
          playery = playery - 20;
          };
        };
        if (gb.buttons.pressed(BTN_C)){
          gb.sound.playCancel();
          break;
          break;
          break;
        };
        if(gb.collideBitmapBitmap(playerx, playery, player, 0, 44, platform) == true){
          playergrav = 0;
        };
        if(gb.collideBitmapBitmap(playerx, playery, player, 0, 44, platform) == false){
          playergrav = 1;
        };
        if(gb.collideBitmapBitmap(playerx, playery, player, meteorx, meteory, meteor) == true){
          gb.display.print(F("Failure"));
        };
        if(gb.collideBitmapBitmap(meteorx, meteory, meteor, 0, 44, platform) == true){
          meteory = 0;
          meteorx = random(0,76);
        };
      };
    };
  };
