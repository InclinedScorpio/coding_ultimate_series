// https://leetcode.com/problems/design-parking-system/

class ParkingSystem {
public:
    int big;
    int medium;
    int small;
    ParkingSystem(int big, int medium, int small) {
        this->big=big;
        this->medium=medium;
        this->small=small;
    }
    
    bool addCar(int carType) {
        if(carType==1&&this->big>0) {
            this->big=this->big-1;
            return true;
        }else if(carType==2 && this->medium>0) {
            this->medium = this->medium-1;
            return true;
        }else if(carType==3 && this->small>0) {
            this->small=this->small-1;
            return true;
        }else {
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

 // Efficient & Clean Solution

 class ParkingSystem {
public:
    int parking[4];
    ParkingSystem(int big, int medium, int small) {
        parking[1]=big;
        parking[2]=medium;
        parking[3]=small;
    }
    
    bool addCar(int carType) {
        return --parking[carType] >= 0;
    }
};
