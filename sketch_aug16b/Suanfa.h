/* 
* Suanfa.h
*
* Created: 2018/8/11 16:38:11
* Author: Administrator
*/


#ifndef __Suanfa_H__
#define __Suanfa_H__


class Suanfa
{
public:	
   Suanfa();
   void tozero(double P1,double p0);
   void realXY(double x1,double y1,double p);
   double p;
   double x,y;

   double _x1;
   double _y1;
   double _p1;

  double dx;
  double dy;
  double dp;

  double dx1;
  double dy1;
}; //Suanfa

#endif //__Suanfa_H__
