const byte player[] PROGMEM = {8,8,
B00111100,
B01101010,
B01101010,
B01101010,
B00111100,
B00100100,
B00100100,
B00000000,
};

const byte platform[] PROGMEM = {88,4,
B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,
B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,
B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,
B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,
};

const byte platform2[] PROGMEM = {24,4,
B11111111,B11111111,B11111111,
B11111111,B11111111,B11111111,
B11111111,B11111111,B11111111,
B11111111,B11111111,B11111111,
};

const byte meteor[] PROGMEM = {8,8,
B00011000,
B00111100,
B00100100,
B01100110,
B01000010,
B11000011,
B10000001,
B01111110,
};
const byte arrow[] PROGMEM = {8,8,
B11111100,
B11001110,
B11000111,
B11111111,
B11111111,
B11000111,
B10000110,
B11111100,
};

const byte point[] PROGMEM = {8,8,
B00000011,
B00001111,
B00111111,
B11111111,
B11111111,
B00111111,
B00001111,
B00000011,
};

const byte logo[] PROGMEM = {88,48,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B01110010,B00100010,B00011100,B10001000,B00001000,B10001011,B10000000,B11100111,B10000100,B00111001,B00010000,
B10001011,B01100101,B00100010,B10001000,B00010100,B11001010,B01000001,B00010100,B01001010,B01000101,B00010000,
B10000010,B10101000,B10100000,B10001000,B00100010,B10101010,B00100001,B00000100,B01010001,B01000001,B00010000,
B01110010,B10101000,B10011100,B11111000,B00100010,B10011010,B00100001,B00000111,B10010001,B00111001,B11110000,
B00001010,B00101111,B10000010,B10001000,B00111110,B10001010,B00100001,B00000101,B00011111,B00000101,B00010000,
B10001010,B00101000,B10100010,B10001000,B00100010,B10001010,B01000001,B00010100,B10010001,B01000101,B00010000,
B01110010,B00101000,B10011100,B10001000,B00100010,B10001011,B10000000,B11100100,B01010001,B00111001,B00010000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000011,B11001111,B00111110,B01110001,B11000000,B00000101,B00010001,B01000000,B00000000,B00000000,
B00000000,B00000010,B00101000,B10100000,B10001010,B00100000,B00000101,B00101001,B01000000,B00000000,B00000000,
B00000000,B00000010,B00101000,B10100000,B10000010,B00000000,B00000000,B01000100,B00000000,B00000000,B00000000,
B00000000,B00000011,B11001111,B00111100,B01110001,B11000000,B00000000,B01000100,B00000000,B00000000,B00000000,
B00000000,B00000010,B00001010,B00100000,B00001000,B00100000,B00000000,B01111100,B00000000,B00000000,B00000000,
B00000000,B00000010,B00001001,B00100000,B10001010,B00100000,B00000000,B01000100,B00000000,B00000000,B00000000,
B00000000,B00000010,B00001000,B10111110,B01110001,B11000000,B00000000,B01000100,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B01111111,B11110000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000001,B00110101,B01010000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000010,B01000110,B01010000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000100,B00100100,B00100000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00001000,B00010110,B00100000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00010000,B01100101,B00100000,
};

const byte blow[] PROGMEM = {8,4,
B11111111,
B11111111,
B11111111,
B11111111,
};

const byte ball[] PROGMEM = {8,6,
B00111100,
B01111110,
B01111110,
B01111110,
B01111110,
B00111100,
};

const byte bhole[] PROGMEM = {8,32,
B00011000,
B00111100,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B01111110,
B00111100,
B00011000,
};
