const int ballBitmap[16] = 
{ 0x07E0,
  0x1FF8,
  0x3FFC,
  0x7FFE,
  0x7FFE,
  0xFFFF,
  0xFFFF,
  0xFFFF,
  0xFFFF,
  0xFFFF,
  0xFFFF,
  0x7FFE,
  0x7FFE,
  0x3FFC,
  0x1FF8,
  0x07E0};
/*  
  top will be (x + 5) to (x + 10)
  bottom will be (x + 5) and (y + 15) to (x + 10) and ( y + 15)
  left side will be (y + 5) to (y + 5)
  right side will be (y + 5) and (x + 15) to (y + 10) and (x + 15)
  
  how to calculate diagonals....
*/