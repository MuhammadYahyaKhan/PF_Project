#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<cmath>
using namespace std;

// Variable declaration for Global variables
int	x_max = 720;
    int y_max = 540;
    int scale = 30;
    int x_origin = x_max/2;
	int y_origin = y_max/2;
	char strx[10];
	char stry[10];

// Function to draw x - axis on the screen
void draw_x_axis(){
	// Line of x-axis
	line(0, y_origin, x_max, y_origin);
    
    int numbers_on_axis = -12;    
        
    // Labeling on x-axis
    for(int i = 0; i <= getmaxx(); i = i + scale){
    	line(i, y_origin - 4, i, y_origin + 4);
		
		
		
        // Convert the integer value to string for output
        sprintf(strx, "%d", numbers_on_axis);
        
        // Display the label at the x-axis
        outtextxy(i - 8, y_origin + 5, strx);
        
        // Increment the label counter for the next tick
        numbers_on_axis++;
    	    	
	}                            
}

// function to draw y-axis on the screen

void draw_y_axis(){
	int numbers_on_axis = 9;
	// line of y-axis
	line(x_origin,0,x_origin,y_max);
	
	//lableing on y-axis
	for(int i = 0; i <getmaxy(); i = i + scale){
		line(x_origin-4,i,x_origin+4,i);
		// Convert the integer value to string for output
        sprintf(stry, "%d", numbers_on_axis);
        
        // Display the label at the x-axis
        outtextxy(x_origin - 5, i + 5, stry);
        
		// decreement
		numbers_on_axis--;
	}
}

// function to determine which trigonometric function is given by the user
double trigonometric_functions_by_users(string function, double x){
	if (function == "sin(x)"|| function=="sinx") {
            return sin(x);
        } else if (function == "cos(x)"|| function=="cosx") {
            return cos(x);
        } else if (function == "tan(x)"|| function=="tanx") {
            return tan(x);
        }
        else if (function == "cosec(x)"|| function=="cosecx") {
            return 1/sin(x);
        }
        else if (function == "sec(x)"|| function=="secx") {
            return 1/cos(x);
        }
        else if (function == "cot(x)"|| function=="cotx") {
            return 1/tan(x);
        }

        else {
            cout<<"Invalid Input !";
            return 0;
        }
}

// Function to draw trigonometric functions
void draw_trigonometric_functions(string function) {
    double x, y;
    setcolor(RED);    
    
    for (int i = -x_origin; i < x_max - x_origin; i++) {
        x = i / (double)scale; 
        y = trigonometric_functions_by_users(function,x) * scale; 
    	
        circle(x_origin + i, y_origin - y, 1);
        
    }
}



// Draw Linear Function
void draw_linear_function(double m, double c){
	double x,y;
	setcolor(GREEN);
	for(int i = -x_origin; i < x_max - x_origin; i++){
		x = i / double(scale);
		y = (m*x + c) * scale;
		
		circle(x_origin+i, y_origin-y, 1);
        
		
	}
}


void draw_log_function(double a, double c){
	double x,y;
	setcolor(GREEN);
	for(int i = -x_origin; i < x_max - x_origin; i++){
		x = i/ double(scale);
		y = ((a*log(x)) + c) * scale;
		circle(x_origin + i, y_origin-y,1);
	}
}

void draw_exponential_function(double a, double n, double c){
	double x,y;
	setcolor(GREEN);
	for(int i = -x_origin; i < x_max - x_origin; i++){
		x = i / double(scale);
		y = ((a*pow(x,n)) + c) * scale;
		circle(x_origin + i, y_origin - y, 1);
	}
	
}

void draw_mod_function(double m, double c){
	double x,y;
	setcolor(GREEN);
	for(int i = -x_origin; i < x_max - x_origin; i++){
		x = i / double(scale);
		if( (m*x + c) <= 0 ){
			y = - (m*x + c) * scale;
		}
		else{
			y = (m*x + c) * scale;
		}
		circle(x_origin + i, y_origin - y,1);
	}
}


void draw_hyperbolic_function(double m, double c){
	double x,y;
	setcolor(GREEN);
	for(int i = 0; i < x_max - x_origin; i++){
		x = i / double(scale);
		y = ((m/x) + c) * scale;
		circle(x_origin + i, y_origin-i,1);
	}
}

int main(){
	initwindow(720, 540);
	draw_x_axis();
	draw_y_axis();
	
	//draw_trigonometric_functions("sinx");
	
	// Draw Linear Functions
	/*
	cout << "f(x) = mx + c" << endl;
	double m,c;
	cout << "m: "; cin >> m;
	cout << "c: "; cin >> c;
	draw_linear_function(m,c);
	*/
	
	// Logarthimic Function
	/*
	cout << "f(x) = alog(x) + c\na: ";
	double a,c;
	cin >> a;
	cout << "c: " << endl;
	cin >> c;
	
	draw_log_function(a,c);
	*/
	
	// Draw Exponential Function
	/*
	cout << "f(x) = ax^n + c" << endl;
	double a,n,c;
	cout << "a: ";
	cin >> a;
	cout << "n: ";
	cin >> n;
	cout << "c: ";
	cin >> c;
	draw_exponential_function(a,n,c);
	*/
	
	
	
	// Mod function
	
	double m, c;
	cout << "f(x) = |mx + c|\nm: ";
	cin >> m;
	cout << "c: ";
	cin >> c;
	draw_mod_function(m,c);
	
	
	// Hyperbolic Function
	/*
	double m, c;
	cout << "f(x) = m/x + c\nm: ";
	cin >> m;
	cout << "c: ";
	cin >> c;
	draw_hyperbolic_function(m,c);
	*/
	/*
	char terminate = 'c'
	while(terminate == 'c'){
		char function_keyword;
		Cout << "Enter keyword for the function \nt -- trigonometric\nm -- mod Function\nL -- Linear Function\nE -- Exponential function" << endl;
		cin >> function_keyword;
		
		if(function_keyword == 't'){
			
		}
		else if(function_keyword == 'm'){
			
		}
		else if(function_keyword == 'L'){
			
		}
		else if(function_keyword == 'E'){
			
		}
		else{
			cout << "Invalid Input!" << endl;
		}
		
	}
	*/
	getch();

	return 0;

	
}
	    
    
