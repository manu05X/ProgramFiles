public class Bicycle {
        
    // the Bicycle class has
    // three fields
    public int cadence;
    public int gear;
    public int speed;
        
    // the Bicycle class has
    // one constructor
    public Bicycle(int startCadence, int startSpeed, int startGear) {
        gear = startGear;
        cadence = startCadence;
        speed = startSpeed;
    }
        
    // the Bicycle class has
    // four methods
    public void setCadence(int newValue) {
        cadence = newValue;
    }
        
    public void setGear(int newValue) {
        gear = newValue;
    }
        
    public void applyBrake(int decrement) {
        speed -= decrement;
    }
        
    public void speedUp(int increment) {
        speed += increment;
    }
    public String printInfo(){
        return("No of gears are"+gear+"\n"+"speed of bicycle is"+speed);
    }
        
}

public class MountainBike extends Bicycle {
        
    // the MountainBike subclass has
    // one field
    public int seatHeight;

    // the MountainBike subclass has
    // one constructor
    public MountainBike(int startHeight, int startCadence,int startSpeed, int startGear) 
    {
        /*
            keyword super refer to the superclass,
            which could be the immediate parent or its ancestor.
            
            It is ussed to access superclass method and variables
            within the subclass defination.
        */
        super(startCadence, startSpeed, startGear);
        seatHeight = startHeight;
    }   
        
    // the MountainBike subclass has
    // one method
    public void setHeight(int newValue) {
        seatHeight = newValue;
    } 
    //annotation for compiler
    @Override
    public String printInfo(){
        return(super.printInfo()+"\n seat height is" +seatHeight);
    }

}


public class HelloWorld{

     public static void main(String[] args){
        MountainBike mb = new MountainBike(3,100,25);
        System.out.println(mb.printInfo()+"\n");
        
        mb.speed(20);
        System.out.println(mb.printInfo()+"\n");
        
        mb.seatHeight(25);
        System.out.println(mb.printInfo()+"\n");
    }
}