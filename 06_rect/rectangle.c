#include <stdio.h>
#include <stdlib.h>
//I've provided "min" and "max" functions in
//case they are useful to you
int min (int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
int max (int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

//Declare your rectangle structure here!
typedef struct rect_tag {
  int x;
  int y;
  int width;
  int height;
} rectangle;

rectangle canonicalize(rectangle r) {
  //WRITE THIS FUNCTION
  rectangle myRect;
  myRect.x = r.x;
  myRect.y = r.y;
  myRect.width = r.width;
  myRect.height = r.height;
  if (myRect.width <0){
    myRect.width = (myRect.width * (-1));
    myRect.x = (myRect.x - myRect.width);
  }
  if(myRect.height < 0){
    myRect.height = (myRect.height * (-1));
    myRect.y = (myRect.y - myRect.height);
  } 
  return myRect;
}

rectangle intersection(rectangle r1, rectangle r2) {
  //WRITE THIS FUNCTION
  rectangle ans, ans1, ans2;
  ans1.x = max(r1.x, r2.x);
  ans1.y = max(r1.y, r2.y);

  ans2.x = min(r1.x+r1.width, r2.x+r2.width);
  ans2.y = min(r1.y+r1.height, r2.y+r2.height);
  
  if (ans2.x >= ans1.x && ans2.y >= ans1.y){
    ans.x = ans1.x;
    ans.y = ans1.y;
    ans.width = ans2.x - ans1.x;
    ans.height = ans2.y-ans1.y;
  }else{
    ans.width = 0;
    ans.height = 0;
  }
  
    return ans;
  }
      
//You should not need to modify any code below this line
void printRectangle(rectangle r) {
  r = canonicalize(r);
  if (r.width == 0 && r.height == 0) {
    printf("<empty>\n");
  }
  else {
    printf("(%d,%d) to (%d,%d)\n", r.x, r.y, 
	                           r.x + r.width, r.y + r.height);
  }
}

int main (void) {
  rectangle r1;
  rectangle r2;
  rectangle r3;
  rectangle r4;

  r1.x = 2;
  r1.y = 3;
  r1.width = 5;
  r1.height = 6;
  printf("r1 is ");
  printRectangle(r1);

  r2.x = -1;
  r2.y = -2;
  r2.width = 5;
  r2.height = 7;
  printf("r2 is ");
  printRectangle(r2);
  
  r3.x = -2;
  r3.y = -3;
  r3.width = 7;
  r3.height = 10;
  printf("r3 is ");
  printRectangle(r3);

  r4.x = -4;
  r4.y = 7;
  r4.width = 4;
  r4.height = 2;
  printf("r4 is ");
  printRectangle(r4);

  //test everything with r1
  rectangle i = intersection(r1,r1);
  printf("intersection(r1,r1): ");
  printRectangle(i);

  i = intersection(r1,r2);
  printf("intersection(r1,r2): ");
  printRectangle(i);
  
  i = intersection(r1,r3);
  printf("intersection(r1,r3): ");
  printRectangle(i);

  i = intersection(r1,r4);
  printf("intersection(r1,r4): ");
  printRectangle(i);

  //test everything with r2
  i = intersection(r2,r1);
  printf("intersection(r2,r1): ");
  printRectangle(i);

  i = intersection(r2,r2);
  printf("intersection(r2,r2): ");
  printRectangle(i);
  
  i = intersection(r2,r3);
  printf("intersection(r2,r3): ");
  printRectangle(i);

  i = intersection(r2,r4);
  printf("intersection(r2,r4): ");
  printRectangle(i);

  //test everything with r3
  i = intersection(r3,r1);
  printf("intersection(r3,r1): ");
  printRectangle(i);

  i = intersection(r3,r2);
  printf("intersection(r3,r2): ");
  printRectangle(i);
  
  i = intersection(r3,r3);
  printf("intersection(r3,r3): ");
  printRectangle(i);

  i = intersection(r3,r4);
  printf("intersection(r3,r4): ");
  printRectangle(i);

  //test everything with r4
  i = intersection(r4,r1);
  printf("intersection(r4,r1): ");
  printRectangle(i);

  i = intersection(r4,r2);
  printf("intersection(r4,r2): ");
  printRectangle(i);
  
  i = intersection(r4,r3);
  printf("intersection(r4,r3): ");
  printRectangle(i);

  i = intersection(r4,r4);
  printf("intersection(r4,r4): ");
  printRectangle(i);


  return EXIT_SUCCESS;

}
