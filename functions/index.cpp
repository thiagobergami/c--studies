/* 

Function prototypes

To declare the function signature: A function prototype declares the function's name, 
return type, and parameters, but it does not contain the function's body. This information
is used by the compiler to check the function's usage in the code.

To avoid compilation errors: If a function is used before it is defined, 
the compiler generates an error. By providing a function prototype before
its first use, the compiler knows what to expect and can check the syntax of the function call.


void area_circle(); //prototype

int main(){
    area_circle(); //call
}

void area_circle(){ //definition
    statement;
}

Overloading Functions

we can have functions that have different parameter lists that have the same name

It's kind a type of polymorphism, since we can have the same name work with different data types to execute similar behavior

example

int add_numbers(int, int);
double add_numbers(double, double);

int add_numbers(int a, int b){
    return a + b;
}

int add_numbers(double a, double b){
    return a + b;
}

int main(){
    cout << add_numbers(10,20) << endl;
    cout << add_numbers(10.0, 20.0) << endl;

    return 0;
}
*/
