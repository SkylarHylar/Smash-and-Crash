void play(){
  while(true){
    if(gb.update()){
      if(alive == true){
        frames = frames + 1;
        
        gb.display.drawBitmap(meteorx,meteory,meteor);
        meteory = meteory + 1;
        
        gb.display.drawBitmap(arrowx,arrowy,arrow);
        arrowx = arrowx + 1;
        
        playery = playery + playergrav;
        gb.display.drawBitmap(playerx,playery,player,NOROT,playerflip);
        gb.display.drawBitmap(0,44,platform);
        gb.display.drawBitmap(20,28,platform2);
        
        if ((gb.buttons.held(BTN_DOWN,2)) && (playergrav == 0)){
          playery = playery + 4;
        };
        if ((gb.buttons.released(BTN_DOWN)) && (playergrav == 0)){
          playery = playery - 4;
        };
        if ((gb.buttons.repeat(BTN_LEFT,2)) && (playerx > 0)){
          playerx = playerx - playerxv;
          playerflip = FLIPH;
        };
        if ((gb.buttons.repeat(BTN_RIGHT,2)) && (playerx < 76)){
          playerx = playerx + playerxv;
          playerflip = NOFLIP;
        };
        if (gb.buttons.repeat(BTN_A,20)){
          if (playergrav == 0) {
          gb.sound.playOK();
          playery = playery - 20;
          };
        };
        
        //Platform code
        
        if((gb.collideBitmapBitmap(playerx, playery, player, 0, 44, platform) == true) || (gb.collideBitmapBitmap(playerx, playery, player, 20, 28, platform2) == true)){
          playergrav = 0;
        };
        if((gb.collideBitmapBitmap(playerx, playery, player, 0, 44, platform) == false) && (gb.collideBitmapBitmap(playerx, playery, player, 20, 28, platform2) == false)){
          playergrav = 1;
        };
        
        //Meteor Code
        
        if(gb.collideBitmapBitmap(playerx, playery, player, meteorx, meteory, meteor) == true){
          alive = false;
        };
        if((gb.collideBitmapBitmap(meteorx, meteory, meteor, 0, 44, platform) == true) || (gb.collideBitmapBitmap(meteorx, meteory, meteor, 20, 28, platform2) == true)){
          meteory = 0;
          meteorx = random(0,76);
        };
        
        //Arrow Code
        
        if(gb.collideBitmapBitmap(playerx, playery, player, arrowx, arrowy, arrow) == true){
          alive = false;
        };
        if((gb.collideBitmapBitmap(arrowx, arrowy, arrow, 0, 44, platform) == true) || (gb.collideBitmapBitmap(arrowx, arrowy, arrow, 20, 28, platform2) == true)){
          arrowx = 0;
          arrowy = random(20,40);
        };
        if(arrowx >= 80){
          arrowx = 0;
          arrowy = random(20,40);
        };
      };
      if(alive == false){
        gb.display.setFont(font3x5);
        gb.display.cursorX = 0;
        gb.display.cursorY = 0;
        gb.display.println("You died!");
        gb.display.println("");
        gb.display.println("Time:");
        gb.display.print(frames);
        gb.display.println(" frames.");
        gb.display.println("");
        gb.display.println("Press \26");
        if (gb.buttons.pressed(BTN_B)){
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
