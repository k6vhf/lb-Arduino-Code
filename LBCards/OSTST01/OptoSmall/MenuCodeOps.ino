//////////////////////////////////////////////////////////////////////////////
// MenuCodeOps() - Run the  Menu Functions
//////////////////////////////////////////////////////////////////////////////

void testUUTFcn(void)
{
  int loopCnt;
  unsigned char digRdVal;
  int pass1Fail0;
  menuCard.setLED(0, HIGH);
  do
  {
    testCount++;
    pass1Fail0 = 1;
    for (loopCnt = 0; loopCnt < 4; loopCnt++)
    {
      digitalWrite(loopCnt+7,LOW);
      delay(2);
      digRdVal = digitalRead(loopCnt + 3);
      if (digRdVal != HIGH)
        pass1Fail0 = 0;
      digitalWrite(loopCnt+7,HIGH);
      delay(2);
      digRdVal = digitalRead(loopCnt + 3);
      if (digRdVal != LOW)
        pass1Fail0 = 0;
      digitalWrite(loopCnt+7,LOW);
    }
    if (pass1Fail0 == 1)
      passCount++;
    else
      failCount++;
    u8g.firstPage();
    do
    {
      setDisplayCursor(0, 0);
      u8g.print("OptoSmall Test");
      setDisplayCursor(1, 0);
      u8g.print("Pass=");
      u8g.print(passCount);
      setDisplayCursor(2, 0);
      u8g.setColorIndex(1);  // default color
      u8g.print("Fail=");
      u8g.print(failCount);
      u8g.setColorIndex(1);  // default color
      setDisplayCursor(3, 0);
      u8g.print("Up to restart");
    }
    while ( u8g.nextPage() );
  }
  while (menuCard.pollKeypad() == NONE);
  testCount = 0;
  passCount = 0;
  failCount = 0;
  menuCard.setLED(0, LOW);
}

void monitorFcn(void)
{
  double myTemp;
  uint8_t keyState;
  menuCard.setLED(0, HIGH);
  do
  {
    u8g.firstPage();
    do
    {
      setDisplayCursor(0, 0);
      u8g.print(F("Monitoring"));
    }
    while ( u8g.nextPage() );
    delay(10);
    keyState = menuCard.pollKeypad();
  }
  while (keyState != SELECT);
  menuCard.setLED(0, LOW);
}

void Option1Fcn(void)
{
  u8g.firstPage();
  do
  {
    setDisplayCursor(1, 0);
    u8g.print(F("Selected"));
    setDisplayCursor(2, 0);
    u8g.print(F("Option1"));
  }
  while ( u8g.nextPage() );
  delay(2000);
}

void Option2Fcn(void)
{
  u8g.firstPage();
  do
  {
    setDisplayCursor(1, 0);
    u8g.print(F("Selected"));
    setDisplayCursor(2, 0);
    u8g.print(F("Option2"));
  }
  while ( u8g.nextPage() );
  delay(2000);
}

void testButtons(void)
{
  uint8_t keyState;
  u8g.firstPage();
  do
  {
    setDisplayCursor(0, 0);
    u8g.print(F("Button tests"));
    setDisplayCursor(1, 0);
    u8g.print(F("Press button"));
    setDisplayCursor(2, 0);
    u8g.print(F("Select=exit"));
  }
  while ( u8g.nextPage() );
  do
  {
    delay(100);
    keyState = menuCard.pollKeypad();
    switch (keyState)
    {
      case RIGHT:
        printString("Right button");
        break;
      case LEFT:
        printString("Left Button");
        break;
      case UP:
        printString("Up button");
        break;
      case DOWN:
        printString("Down button");
        break;
    }
  }
  while (keyState != SELECT);
}

void printString(char * myString)
{
  u8g.firstPage();
  do
  {
    setDisplayCursor(0, 0);
    u8g.print(myString);
  }
  while ( u8g.nextPage() );
}

void testLEDsFcn(void)
{
  u8g.firstPage();
  do
  {
    setDisplayCursor(0, 0);
    u8g.print(F("Running"));
    setDisplayCursor(1, 0);
    u8g.print(F("LED Tests"));
  }
  while ( u8g.nextPage() );
  menuCard.setLED(0, HIGH);
  delay(500);
  menuCard.setLED(0, LOW);
  menuCard.setLED(1, HIGH);
  delay(500);
  menuCard.setLED(1, LOW);
  menuCard.setLED(2, HIGH);
  delay(500);
  menuCard.setLED(2, LOW);
}


