//Alan Achtenberg
//CSCE 113-501
//Assignment 5


#include "Simple_window.h"


class Smiley:public Circle{
public:
	Circle eye_l;
	Circle eye_r;
	Point p;
	int r;
	Smiley(Point pp, int rr):Circle(pp,rr),eye_l(Point(pp.x-rr*.3,pp.y-rr*.3),rr*.25),eye_r(Point(pp.x+rr*.3,pp.y-rr*.3),rr*.25),r(rr),p(pp){}

	void draw_lines() const
	{
		Circle::draw_lines();//use previously defined circle::draw_lines for the head
		fl_arc(p.x-.75*r,p.y-r,1.5*r,1.5*r,210,325);//draw smile fl_arc draws a circle inside a box specified by a point and size of the box and from begining angle to ending angle
		eye_l.draw_lines();//use previously defined circle::draw_lines for the eyes
		eye_r.draw_lines();
	}

};

class Frowny:public Circle{
public:
	Circle eye_l;
	Circle eye_r;
	Point p;
	int r;
	Frowny(Point pp, int rr):Circle(pp,rr),eye_l(Point(pp.x-rr*.3,pp.y-rr*.3),rr*.25),eye_r(Point(pp.x+rr*.3,pp.y-rr*.3),
		rr*.25),r(rr),p(pp){}

	void draw_lines() const
	{
		Circle::draw_lines();//use previously defined circle::draw_lines for the head
		fl_arc(p.x-.75*r,p.y+.1*r,1.5*r,1.5*r,45,135);//draw smile fl_arc draws a circle inside a box specified by a point and size of the box and from begining angle to ending angle
		eye_l.draw_lines();//use previously defined circle::draw_lines for the eyes
		eye_r.draw_lines();
	}

};

class Smiley_hat:public Smiley{
public:

	Smiley_hat(Point pp,int rr):Smiley(pp,rr){}

	void draw_lines() const
	{
		Smiley::draw_lines();// use previously defined draw lines
		Point top(center().x,center().y-.9*r);// new reference point to simplifly fl_polygon function call
		fl_polygon(top.x-.75*r,top.y,top.x,top.y-.5*r,top.x+.75*r,top.y);//use polygon to draw a triangle hat
	}
};

class Frowny_hat:public Frowny{
public:

	Frowny_hat(Point pp,int rr):Frowny(pp,rr){}

	void draw_lines() const
	{
	Frowny::draw_lines(); // use previously definied draw lines
		Point top(center().x,center().y-.9*r);// new reference point to simplify
		fl_polygon(top.x-.6*r,top.y,top.x-.6*r,top.y-.7*r,top.x+.6*r,top.y-.7*r,top.x+.6*r,top.y);//hat brim
		fl_polygon(top.x-.75*r,top.y,top.x-.75*r,top.y-.2*r,top.x+.75*r,top.y-.2*r,top.x+.75*r,top.y);//use polygon to draw a rectangle hat
	}
};


int main(){

	Simple_window win1(Point(20,20),500,400,"my_window");
	Smiley_hat one(Point(300,200),70);
	Frowny_hat two(Point(100,200),70);
	win1.attach(one);
	win1.attach(two);

	win1.redraw();
   return Fl::run();
}
