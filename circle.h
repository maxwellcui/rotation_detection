//Head file of circle direction program
//Author: Zhaoyuan "Maxwell" Cui

#include<stdio.h>
#include<math.h>
#include<stdbool.h>


void init(double *A, double *B, double *center, double *radius, double *tor)
{
  printf("The default center is at (0,0),\nradius is 1,\ntolerance is 0.1.\nDo you want to change any of these values? (Y/N): ");
  
  char sel;
  scanf("%c",&sel);
  
  while(sel!='n' && sel!='N' && sel!='y' && sel!='Y')
    {
      scanf("%c",&sel);
      printf("Invalid input, please enter again. (Y/N)");
    }
    
  if(sel=='n' || sel=='N')
    {
      center[0]=0;
      center[1]=0;
      *radius=1;
      *tor=0.1;
      
    }
  else if(sel=='y' || sel=='Y')
    {
      printf("Please enter the value for x of center: ");
      scanf("%lf",&center[0]);

      printf("Please enter the value for y of center: ");
      scanf("%lf",&center[1]);

      printf("Please enter the value for radius: ");
      scanf("%lf",radius);

      printf("Please enter the value for tolerance: ");
      scanf("%lf",tor);
      
    }

  printf("Please enter the value for x of A: ");
  scanf("%lf",&A[0]);
  printf("Please enter the value for y of A: ");
  scanf("%lf",&A[1]);

  printf("Please enter the value for x of B: ");
  scanf("%lf",&B[0]);
  printf("Please enter the value for y of B: ");
  scanf("%lf",&B[1]);

  printf("Summary\n\tCenter is at (%lf,%lf)\n\tA is at (%lf,%lf)\n\tB is at (%lf,%lf)\n\tRadius is %lf,\n\tTolarance is %lf\n",center[0],center[1],A[0],A[1],B[0],B[1],*radius,*tor);

  //Recenter
  A[0]=A[0]-center[0];
  A[1]=A[1]-center[1];
  B[0]=B[0]-center[0];
  B[1]=B[1]-center[1];
  center[0]=0;
  center[1]=0;

}




bool onArcCheck(double x, double y, double R, double tor)
{
  double D;
  D=x*x+y*y;
  if(fabs(sqrt(D)-R)<=tor)
    return true;
  else
    return false;
}

void compare(double *A, double *B)
{
  if(A[0]==B[0] && A[1]==B[1])
    {
      printf("A and B are at the same location.\n");
    }

  else if(A[0]==-B[0] && A[1]==-B[1])
    {
      printf("A and B are symmetry respect to the center.\n");
    }

  else if(A[0]==0)
    {
      if(A[1]>0 && B[0]>0)
	printf("The rotation is clockwise from A to B.\n");
      
      else if(A[1]>0 && B[0]<0)
	printf("The rotation is counter clockwise from A to B.\n");
      
      else if(A[1]<0 && B[0]>0)
	printf("The rotation is counter clockwise from A to B.\n");
      
      else if(A[1]<0 && B[0]<0)
	printf("The rotation is  clockwise from A to B.\n");
    }

  else
    {
      double slope;
      slope=A[1]/A[0];
      if(A[0]>0)
	{
	  if(slope>=0 && B[1]>slope*B[0])
	    {
	      printf("The rotation is counter clockwise from A to B.\n");
	    }
	  else if(slope>=0 && B[1]<slope*B[0])
	    {
	      printf("The rotation is clockwise from A to B.\n");
	    }
	  else if(slope<0 && B[1]>slope*B[0])
	    {
	      printf("The rotation is counter clockwise from A to B.\n");
	    }
	  else if(slope<0 && B[1]<slope*B[0])
	    {
	      printf("The rotation is clockwise from A to B.\n");
	    }
	}
      else if(A[0]<0)
	{
	  if(slope>=0 && B[1]>slope*B[0])
	    {
	      printf("The rotation is clockwise from A to B.\n");
	    }
	  else if(slope>=0 && B[1]<slope*B[0])
	    {
	      printf("The rotation is counter clockwise from A to B.\n");
	    }
	  else if(slope<0 && B[1]>slope*B[0])
	    {
	      printf("The rotation is clockwise from A to B.\n");
	    }
	  else if(slope<0 && B[1]<slope*B[0])
	    {
	      printf("The rotation is counter clockwise from A to B.\n");
	    }
	}
    }
}
