void play(){
  while(true){
    if(gb.update()){
      if((alive == true) && (pause == false)){

        //Counter
        frames = frames + 1;
        gb.display.println(frames);

        //Player
        playery = playery + playergrav;
        gb.display.drawBitmap(playerx,playery,player,NOROT,playerflip);
        if ((gb.buttons.repeat(BTN_LEFT,2)) && (playerx > 0)){
          playerx = playerx - 2;
          playerflip = FLIPH;
        };
        if ((gb.buttons.repeat(BTN_RIGHT,2)) && (playerx < 76)){
          playerx = playerx + 2;
          playerflip = NOFLIP;
        };
        if ((gb.buttons.repeat(BTN_LEFT,2)) && (playerx > 0) && (gb.buttons.repeat(BTN_B,1))){
          gb.sound.playNote(6, 1, 1);
          gb.sound.command(1, 1, 0, 1);
          playerx = playerx - 3;
          playerflip = FLIPH;
        };
        if ((gb.buttons.repeat(BTN_RIGHT,2)) && (playerx < 76) && (gb.buttons.repeat(BTN_B,1))){
          gb.sound.playNote(6, 1, 1);
          gb.sound.command(1, 1, 0, 1);
          playerx = playerx + 3;
          playerflip = NOFLIP;
        };
        if ((gb.buttons.repeat(BTN_A,20)) && (playerjump == true)){
            gb.sound.playNote(30, 5, 0);
            gb.sound.command(3, 3, 1, 0);
            playery = playery - 1;
            playergrav = -7;
        };
        if (gb.buttons.repeat(BTN_C,20)){
            pause = true;
        };

        //Disaster Code
        if (change == frames){
          gb.pickRandomSeed();
          disaster = random(1,12);
          change = change + 200;
        };
        //Meteor
        if ((disaster >= 1) &&(disaster <= 3)){
          gb.display.drawBitmap(meteorx,meteory,meteor);
          meteory = meteory + 1;
          arrowx = 0;
          ballx = 0;
        };
        //Arrow
        if ((disaster >= 4) &&(disaster <= 6)){
          gb.display.drawBitmap(arrowx,arrowy,arrow);
          arrowx = arrowx + 1.5;
          meteory = 0;
          ballx = 0;
        };
        if(arrowx >= 80){
          arrowx = 0;
          arrowy = random(6,34);
        };
        //Ball
        if ((disaster >= 7) &&(disaster <= 9)){
          gb.display.drawBitmap(ballx,bally,ball);
          arrowx = 0;
          meteory = 0;
        };
        if(bally <= 0){
          ballyv = 1.5;
        }
        if(bally >= 42){
          ballyv = -1.5;
        }
        if((ballx <= 0) || (ballx >= 83)){
          bally = random(0,42);
          way = random(0,1);
          if(way == 0){
            ballx = 82;
          }
          if(way == 1){
            ballx = 1;
          }
        }
        if(way == 0){
          ballx = ballx - 1.5;
          bally = bally + ballyv;
        }
        if(way == 1){
          ballx = ballx + 1.5;
          bally = bally + ballyv;
        }
        //Black Hole
        if ((disaster >= 10) &&(disaster <= 12)){
          gb.display.drawBitmap(77,10,bhole);
          playerx = playerx + 2;
          arrowx = 0;
          meteory = 0;
          ballx = 0;
        };

        //Death Code

        if(playery >= 50){
          gb.sound.playNote(1, 28, 1);
          gb.sound.command(1, 1, 0, 1);
          gb.sound.command(2, 7, -2, 1);
          alive = false;
        };
        
        if((gb.collideBitmapBitmap(playerx, playery, player, meteorx, meteory, meteor) == true) && (disaster >= 1) &&(disaster <= 3)){ //Meteor
          gb.sound.playNote(1, 28, 1);
          gb.sound.command(1, 1, 0, 1);
          gb.sound.command(2, 7, -2, 1);
          alive = false;
        };
        if((gb.collideBitmapBitmap(playerx, playery, player, arrowx, arrowy, arrow) == true) && (disaster >= 4) &&(disaster <= 6)){ //Arrow
          gb.sound.playNote(1, 28, 1);
          gb.sound.command(1, 1, 0, 1);
          gb.sound.command(2, 7, -2, 1);
          alive = false;
        };
        if((gb.collideBitmapBitmap(playerx, playery, player, ballx, bally, ball) == true) && (disaster >= 7) &&(disaster <= 9)){ //Ball
          gb.sound.playNote(1, 28, 1);
          gb.sound.command(1, 1, 0, 1);
          gb.sound.command(2, 7, -2, 1);
          alive = false;
        };
        if((gb.collideBitmapBitmap(playerx, playery, player, 77, 10, bhole) == true) && (disaster >= 10) &&(disaster <= 12)){ //Black Hole
          gb.sound.playNote(1, 28, 1);
          gb.sound.command(1, 1, 0, 1);
          gb.sound.command(2, 7, -2, 1);
          alive = false;
        };


        //Lonely Map
        if(mapscroll == 0){
          //Drawing
          gb.display.drawBitmap(0,44,platform);
          gb.display.drawBitmap(30,28,platform2);
          
          //Player Collision
          if(gb.collideBitmapBitmap(playerx, playery, player, 0, 44, platform) == true){
            playery = 38;
            playergrav = 0;
            playerjump = true;
          }
          else if(gb.collideBitmapBitmap(playerx, playery, player, 30, 28, platform2) == true){
            playery = 22;
            playergrav = 0;
            playerjump = true;
          }
          else {
            playergrav = playergrav + 1;
            playerjump = false;
          };
          //Meteor Collision
          if((gb.collideBitmapBitmap(meteorx, meteory, meteor, 0, 44, platform)) || (gb.collideBitmapBitmap(meteorx, meteory, meteor, 30, 28, platform2)) == true){
            gb.display.drawBitmap(meteorx, meteory + 4, blow);
            meteory = -6;
            meteorx = random(0,76);
          };
          //Arrow Collision
          if(gb.collideBitmapBitmap(arrowx, arrowy, arrow, 30, 28, platform2) == true){
            arrowx = 0;
            arrowy = random(0,34);
          };
        };

        //Ridge Map
        if(mapscroll == 1){
          //Drawing
          gb.display.drawBitmap(0,28,platform2);
          gb.display.drawBitmap(60,28,platform2);
          gb.display.drawBitmap(18,44,platform2);
          gb.display.drawBitmap(42,44,platform2);
          
          //Player Collision
          if(gb.collideBitmapBitmap(playerx,playery,player,0,28,platform2) == true){
            playery = 22;
            playergrav = 0;
            playerjump = true;
          }
          else if(gb.collideBitmapBitmap(playerx,playery,player,60,28,platform2) == true){
            playery = 22;
            playergrav = 0;
            playerjump = true;
          }
          else if(gb.collideBitmapBitmap(playerx,playery,player,18,44,platform2) == true){
            playery = 38;
            playergrav = 0;
            playerjump = true;
          }
          else if(gb.collideBitmapBitmap(playerx,playery,player,42,44,platform2) == true){
            playery = 38;
            playergrav = 0;
            playerjump = true;
          }
          else {
            playergrav = playergrav + 1;
            playerjump = false;
          };
          //Meteor Collision
          if((gb.collideBitmapBitmap(meteorx,meteory,meteor,0,28,platform2)) || (gb.collideBitmapBitmap(meteorx,meteory,meteor,60,28,platform2)) || (gb.collideBitmapBitmap(meteorx,meteory,meteor,18,44,platform2)) || (gb.collideBitmapBitmap(meteorx,meteory,meteor,42,44,platform2)) == true){
            gb.display.drawBitmap(meteorx, meteory + 4, blow);
            meteory = -6;
            meteorx = random(0,76);
          };
          //Arrow Collision
          if((gb.collideBitmapBitmap(arrowx,arrowy,arrow,0,28,platform2)) || (gb.collideBitmapBitmap(arrowx,arrowy,arrow,60,28,platform2)) || (gb.collideBitmapBitmap(meteorx,meteory,meteor,18,44,platform2)) || (gb.collideBitmapBitmap(meteorx,meteory,meteor,42,44,platform2)) == true){
            arrowx = 0;
            arrowy = random(0,34);
          };
        };

        //Tower Map
        if(mapscroll == 2){
          //Drawing
          gb.display.drawBitmap(0,44,platform);
          gb.display.drawBitmap(30,28,platform2);
          gb.display.drawBitmap(30,16,platform2);
          gb.display.drawBitmap(18,0,platform2);
          gb.display.drawBitmap(42,0,platform2);
          
          //Player Collision
          if(gb.collideBitmapBitmap(playerx, playery, player, 0, 44, platform) == true){
            playery = 38;
            playergrav = 0;
            playerjump = true;
          }
          else if(gb.collideBitmapBitmap(playerx, playery, player, 30, 28, platform2) == true){
            playery = 22;
            playergrav = 0;
            playerjump = true;
          }
          else if(gb.collideBitmapBitmap(playerx, playery, player, 30, 16, platform2) == true){
            playery = 10;
            playergrav = 0;
            playerjump = true;
          }
          else if(gb.collideBitmapBitmap(playerx, playery, player, 0, 0, platform) == true){
            playergrav = 1;
          }
          else {
            playergrav = playergrav + 1;
            playerjump = false;
          };
          //Meteor Collision
          if((gb.collideBitmapBitmap(meteorx, meteory, meteor, 18, 0, platform2)) || (gb.collideBitmapBitmap(meteorx, meteory, meteor, 42, 0, platform2)) || (gb.collideBitmapBitmap(meteorx, meteory, meteor, 0, 44, platform)) == true){
            gb.display.drawBitmap(meteorx, meteory + 4, blow);
            meteory = -6;
            meteorx = random(0,76);
          };
          //Arrow Collision
          if((gb.collideBitmapBitmap(arrowx, arrowy, arrow, 30, 28, platform2)) || (gb.collideBitmapBitmap(arrowx, arrowy, arrow, 30, 16, platform2)) == true){
            arrowx = 0;
            arrowy = random(6,34);
          };
        };

        //Hill Map
        if(mapscroll == 3){
          //Drawing
          gb.display.drawBitmap(0,44,platform);
          gb.display.drawBitmap(18,32,platform2);
          gb.display.drawBitmap(42,32,platform2);
          gb.display.drawBitmap(30,20,platform2);
          
          //Player Collision
          if(gb.collideBitmapBitmap(playerx, playery, player, 0, 44, platform) == true){
            playery = 38;
            playergrav = 0;
            playerjump = true;
          }
          else if(gb.collideBitmapBitmap(playerx, playery, player, 18, 32, platform2) == true){
            playery = 26;
            playergrav = 0;
            playerjump = true;
          }
          else if(gb.collideBitmapBitmap(playerx, playery, player, 42, 32, platform2) == true){
            playery = 26;
            playergrav = 0;
            playerjump = true;
          }
          else if(gb.collideBitmapBitmap(playerx, playery, player, 30, 20, platform2) == true){
            playery = 14;
            playergrav = 0;
            playerjump = true;
          }
          else {
            playergrav = playergrav + 1;
            playerjump = false;
          };
          //Meteor Collision
          if((gb.collideBitmapBitmap(meteorx, meteory, meteor, 0, 44, platform)) || (gb.collideBitmapBitmap(meteorx, meteory, meteor, 18, 32, platform2)) || (gb.collideBitmapBitmap(meteorx, meteory, meteor, 42, 32, platform2)) || (gb.collideBitmapBitmap(meteorx, meteory, meteor, 30, 20, platform2)) == true){
            gb.display.drawBitmap(meteorx, meteory + 4, blow);
            meteory = 0;
            meteorx = random(0,76);
          };
          //Arrow Collision
          if((gb.collideBitmapBitmap(arrowx, arrowy, arrow, 18, 32, platform2)) || (gb.collideBitmapBitmap(arrowx, arrowy, arrow, 42, 32, platform2)) || (gb.collideBitmapBitmap(arrowx, arrowy, arrow, 30, 20, platform2)) == true){
            arrowx = 0;
            arrowy = random(0,34);
          };
        };

        
      };
      
      if((alive == true) && (pause == true)){
        gb.display.setFont(font5x7);
        gb.display.cursorX = 24;
        gb.display.cursorY = 4;
        gb.display.drawRect(0,0,84,48);
        gb.display.println("PAUSED");
        gb.display.cursorX = 8;
        gb.display.println(" ");
        gb.display.cursorX = 12;
        gb.display.print(frames);
        gb.display.println(" frames");
        gb.display.cursorX = 8;
        gb.display.println(" ");
        gb.display.cursorX = 8;
        gb.display.println("\26 to resume");
        if(gb.buttons.pressed(BTN_B)) {
          gb.display.setFont(font3x5);
          pause = false;
        };
      };
      
      if(alive == false){
        gb.display.setFont(font5x7);
        gb.display.drawRect(0,0,84,48);
        gb.display.cursorY = 2;
        gb.display.cursorX = 16;
        gb.display.println("You died!");
        gb.display.cursorX = 8;
        gb.display.println("");
        gb.display.cursorX = 28;
        gb.display.println("Time:");
        gb.display.cursorX = 8;
        gb.display.print(frames);
        gb.display.println(" frames.");
        gb.display.cursorX = 20;
        gb.display.cursorY = 38;
        gb.display.println("Press \26");
        if (gb.buttons.pressed(BTN_B)){
          gb.sound.playCancel();
          frames = -1;
          break;
          break;
          break;
        };
      };
    };
  };
};
