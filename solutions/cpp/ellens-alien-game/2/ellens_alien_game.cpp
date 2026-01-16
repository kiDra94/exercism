namespace targets {
class Alien {
public:
    Alien(int new_x_coordinate, int new_y_coordinate){
         x_coordinate = new_x_coordinate;
         y_coordinate = new_x_coordinate;
    }
    int x_coordinate{};
    int y_coordinate{};
    int get_health(){
        return health;
    }
    bool hit(){
        if(get_health() > 0){ health--;}
        return true;
    };
    bool is_alive(){
        if(get_health() > 0){ return true;}
        else{ return false;}
    };
    bool teleport(int x_new, int y_new){
        x_coordinate = x_new;
        y_coordinate = y_new;
        return true;
    };
    bool collision_detection(Alien a){
        bool collision = (x_coordinate == a.x_coordinate && y_coordinate == a.y_coordinate) ? true : false;
        return collision;
    };
private:
    int health{3};
};

}  // namespace targets
