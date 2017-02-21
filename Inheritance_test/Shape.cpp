#include <iostream>
#include <fstream>
 
using namespace std;

// Base class
class Shape  {
   public:
      void setWidth(int w) {
         width = w;
      }
		
      void setHeight(int h) {
         height = h;
      }
		
   protected:
      int width;
      int height;
};

// Derived class
class Rectangle: public Shape {
   public:
      int getArea() { 
         return (width * height); 
      }
};

int main(void) {
   Rectangle Rect;
 
   Rect.setWidth(5);
   Rect.setHeight(7);
   ofstream myfile;
   myfile.open ("example.txt", ios_base::app);
   myfile << "Change.\n";
   myfile.close();
    
   // Print the area of the object.
   cout << "Total area plus change: " << Rect.getArea() << endl;

   return 0;
}
