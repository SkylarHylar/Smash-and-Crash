void play(){
  while(true){
    ad.clear();
    if(alive == true){
      //Counter
      frames = frames + 1;
      ad.setCursor(0,0);
      ad.print(frames);
      //Player
      playery = playery + playergrav;
      ad.drawBitmap(playerx,playery,player,8,8,1);
      if ((ad.pressed(LEFT_BUTTON)) && (playerx > 0)){
        playerx = playerx - 2;
      };
      if ((ad.pressed(RIGHT_BUTTON)) && (playerx < 120)){
        playerx = playerx + 2;
      };
      if ((ad.pressed(LEFT_BUTTON)) && (playerx > 0) && (ad.pressed(B_BUTTON))){
        playerx = playerx - 3;
      };
      if ((ad.pressed(RIGHT_BUTTON)) && (playerx < 76) && (ad.pressed(B_BUTTON))){
        playerx = playerx + 3;
      };
      if ((ad.pressed(A_BUTTON)) && (playerjump == true)){
          playery = playery - 1;
          playergrav = -7;
      };

      //Disaster Code
      if (change == frames){
        disaster = random(1,12);
        change = change + 200;
      };
      //Meteor
      if ((disaster >= 1) &&(disaster <= 3)){
        ad.drawBitmap(meteorx,meteory,meteor,8,8,1);
        meteory = meteory + 1;
        arrowx = 0;
        ballx = 0;
      };
      //Arrow
      if ((disaster >= 4) &&(disaster <= 6)){
        ad.drawBitmap(arrowx,arrowy,arrow,8,8,1);
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
        ad.fillCircle(ballx,bally,6,1);
        arrowx = 0;
        meteory = 0;
      };
      if(bally <= 0){
        ballyv = 1.5;
      }
      if(bally >= 42){
        ballyv = -1.5;
      }
      if((ballx <= 0) || (ballx >= 127)){
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
        ad.drawRoundRect(120, 10, 8, 46, 8, 1);
        playerx = playerx + 2;
        arrowx = 0;
        meteory = 0;
        ballx = 0;
      };
      //Death Code
      if(playery >= 66){
        alive = false;
      };
      
      if((playerx >= meteorx) && (playerx <= meteorx + 8) && (disaster >= 1) &&(disaster <= 3)){ //Meteor
        alive = false;
      };
      if((playerx >= arrowx) && (playerx <= arrowx + 8) && (disaster >= 4) &&(disaster <= 6)){ //Arrow
        alive = false;
      };
      if((playerx >= ballx) && (playerx <= ballx + 6) && (disaster >= 7) &&(disaster <= 9)){ //Ball
        alive = false;
      };
      if((playerx >= 8) && (playerx <= 120) && (disaster >= 10) &&(disaster <= 12)){ //Black Hole
        alive = false;
      };

      //Lonely Map
      if(mapscroll == 0){
        //Drawing
        ad.fillRect(0,60,128,4,1);    
        //Player Collision
        if(playery >= 56){
          playery = 56;
          playergrav = 0;
          playerjump = true;
        }
        else {
          playergrav = playergrav + 1;
          playerjump = false;
        };
        //Meteor Collision
        if(meteorx >= 56){
          ad.fillRect(meteorx,meteory,8,8,1);
          meteory = -6;
          meteorx = random(0,76);
        };
      };
    };
    if(alive == false){
      ad.setCursor(0,0);
      ad.print(frames);
      ad.setCursor(0,40);
      ad.print("Press B.");
      if (ad.pressed(B_BUTTON)){
        frames = -1;
        break;
        break;
      };
    };
    ad.display();
  };
};
