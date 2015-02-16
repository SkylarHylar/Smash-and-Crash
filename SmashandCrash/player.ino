void play(){
  while(true){
    if(gb.update()){
      if(alive == true){
        frames = frames + 1;
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
        if(gb.collideBitmapBitmap(playerx, playery, player, 0, 44, platform) == true){
          playergrav = 0;
        };
        if(gb.collideBitmapBitmap(playerx, playery, player, 0, 44, platform) == false){
          playergrav = 1;
        };
        if(gb.collideBitmapBitmap(playerx, playery, player, meteorx, meteory, meteor) == true){
          alive = false;
        };
        if(gb.collideBitmapBitmap(meteorx, meteory, meteor, 0, 44, platform) == true){
          meteory = 0;
          meteorx = random(0,76);
        };
      };
      if(alive == false){
        gb.display.setFont(font3x5);
        gb.display.cursorX = 0;
        gb.display.cursorY = 0;
        gb.display.println("You died!");
        gb.display.println("");
        gb.display.println("You lived for:");
        gb.display.print(frames);
        gb.display.println(" frames.");
        if (gb.buttons.pressed(BTN_C)){
          gb.sound.playCancel();
          frames = 0;
          gb.display.setFont(font5x7);
          break;
          break;
          break;
          };
        };
      };
    };
  };
