#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define   OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);                   //初始化显示屏

const int INT0A = 18;
const int INT0B = 19;
const int INT1A = 2;
const int INT1B = 5;
const int INT2A = 3;
const int INT2B = 4;

int x = 0;
int y = 0;
int p = 0;
int time = 0;
void setup() {
  // put your setup code here, to run once:
  display.begin(SSD1306_SWITCHCAPVCC);                    //显示屏初始化
  display.display();
  display.clearDisplay();
  view(x, y, p);

  pinMode(INT0B, INPUT);
  pinMode(INT1B, INPUT);
  pinMode(INT2B, INPUT);
  attachInterrupt(digitalPinToInterrupt(INT0A), blink0, FALLING);
  attachInterrupt(digitalPinToInterrupt(INT1A), blink1, FALLING);
  attachInterrupt(digitalPinToInterrupt(INT2A), blink2, FALLING);
}

void loop() {
  view(x, y, p);
}
//中断0调用函数
void blink0()
{
  int xstate = digitalRead(INT0B);
  if (xstate == HIGH)
    x--;
  else
    x++;
}
//中断1调用函数
void blink1()
{
  int ystate = digitalRead(INT1B);
  if (ystate == HIGH)
    y++;
  else
    y--;
}
//中断2调用函数
void blink2()
{
  int pstate = digitalRead(INT2B);
  if (pstate == HIGH)
    p--;
  else
    p++;
}
void view(double x, double y, double p)
{
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.clearDisplay();
  display.print("x = ");
  display.println(x);
  display.print("y = ");
  display.println(y);
  display.print("P = ");
  display.println(p);
  display.display();
  delay(1);
}
