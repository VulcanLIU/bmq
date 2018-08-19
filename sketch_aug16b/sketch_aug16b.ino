#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Suanfa.h"
#define   OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);                   //初始化显示屏
Suanfa sf;

const int INT0A = 18;
const int INT0B = 19;
const int INT1A = 2;
const int INT1B = 5;
const int INT2A = 3;
const int INT2B = 4;

const double d = 160; //两轮间距160mm
const double wheel_d = 38;//轮直径38mm

int x = 0;
int y = 0;
int p = 0;

double x1 = 0;
double y1 = 0;
double p1 = 0;

double x2 = 0;
double y2 = 0;
double p2 = 0;

int time = 0;
void setup() {
  Serial.begin(115200);
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
  x1 = double(x)/20*PI*wheel_d;//行走的距离 单位mm；
  y1 = double(y)/20*PI*wheel_d;//行走的距离 单位mm；
  p1 = double(p)/20*PI*wheel_d;//行走的距离 单位mm；

  p2 = (y1 - p1)/d;
  p2 = p2/PI*180;

  x2 = x1 + (y1 - p1)/2*1.166;
  y2 = (y1+p1)/2;

  sf.realXY(x2,y2,p2);
  
  Serial.print("A:");  //串口显口
  Serial.print(x1);                 //串口显示
  Serial.print("B:");  //串口显口
  Serial.print((y1 - p1)/2);                 //串口显示
  Serial.print("X:");  //串口显口
  Serial.print(x2);                 //串口显示
  Serial.print("Y:");                   //串口显示
  Serial.print(y2);                 //串口显示
  Serial.print("P:");                   //串口显示
  Serial.println(p2);  //串口显口
  
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
