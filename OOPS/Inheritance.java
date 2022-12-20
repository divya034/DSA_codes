class Employee {
    void bonus(int n) {
        System.out.println(n);
    }
}

class Programmer extends Employee { 
// Programmer class inherits from Employee class
    void bonus(int n) {
        System.out.println(2*n);
    }
}


public class Main
{
	public static void main(String[] args) {
	    Employee e = new Programmer();
	    Programmer p = new Programmer();
	    
	    e.bonus(1);
	    p.bonus(1);
	    
	    
		
	}
}

output: 2 2
