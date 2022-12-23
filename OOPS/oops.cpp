Object-Oriented Programming is a methodology or paradigm to design a
program using classes and objects. It simplifies the software development
and maintenance by providing some concepts defined below :


● Class is a user-defined data type which defines its properties and its
functions. Class is the only logical representation of the data. For
example, Human being is a class. The body parts of a human being are its
properties, and the actions performed by the body parts are known as
functions. The class does not occupy any memory space till the time an
object is instantiated.
  
C++ Syntax (for class):
class student{
public:
int id; // data member
int mobile;
string name;
int add(int x, int y){ // member functions
return x + y;
}
};


Object is a run-time entity. It is an instance of the class. An object can
represent a person, place or any other item. An object can operate on
both data members and member functions.
  
  
  C++ Syntax (for object):
student s = new student();
Note : When an object is created using a new keyword, then space is
allocated for the variable in a heap, and the starting address is stored in
the stack memory. When an object is created without a new keyword,
then space is not allocated in the heap memory, and the object contains
the null value in the stack.
