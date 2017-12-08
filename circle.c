//Determine the rotation direction for shortest arc length between
//two arbitary points on a circle
//Author: Zhaoyuan "Maxwell" Cui

#include<stdio.h>
#include"circle.h"

int main()
{

  //Declare variables
  //[0] for x, [1] for y
  double A[2];
  double B[2];
  double center[2];
  double radius;
  double tor;

  //Parameter specification process
  init(A, B, center, &radius, &tor);

  //Check if A and B are on the circle
  if(!onArcCheck(A[0],A[1],radius,tor) || !onArcCheck(B[0],B[1],radius,tor))
    {
      printf("At least one of the points is not on the circle!\n");
      printf("Please check the coordinate or change the torlerance.\n");
      return 1;
    }

  //Find the direction
  compare(A,B);

  return 0;
}

