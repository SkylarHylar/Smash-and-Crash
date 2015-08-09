void maps(){
  while(true){
    if(gb.update()){
      gb.display.drawRect(0,0,84,48);
      gb.display.drawBitmap(24,38,point,NOROT,NOFLIP);
      gb.display.drawBitmap(52,38,point,NOROT,FLIPH);
      if(gb.buttons.repeat(BTN_LEFT,15)){
        mapscroll = mapscroll - 1;
        if(mapscroll < 0){
          mapscroll = 3;
        };
      };
      if(gb.buttons.repeat(BTN_RIGHT,15)){
        mapscroll = mapscroll + 1;
        if(mapscroll > 3){
          mapscroll = 0;
        };
      };
      if(gb.buttons.pressed(BTN_A)){
        break;
      }
      if(mapscroll == 0){
        gb.display.cursorX = 24;
        gb.display.cursorY = 16;
        gb.display.print("Lonely");
      };
      if(mapscroll == 1){
        gb.display.cursorX = 28;
        gb.display.cursorY = 16;
        gb.display.print("Ridge");
      };
      if(mapscroll == 2){
        gb.display.cursorX = 28;
        gb.display.cursorY = 16;
        gb.display.print("Tower");
      };
      if(mapscroll == 3){
        gb.display.cursorX = 32;
        gb.display.cursorY = 16;
        gb.display.print("Hill");
      };
    }
  }
}

