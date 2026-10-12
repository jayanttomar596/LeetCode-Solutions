class BusBooking {
    vector<vector<bool>> bus;
    int n ; 
    int toltime = 0 ;
    vector<vector<int>> cost ;
    int booked = 0 ;
public:
    BusBooking(int n) {
        this -> n = n ;
        bus.assign(n+1 , vector<bool>(4 , false)) ;
        cost.assign(n+1 , vector<int>(4 , 0)) ;
    }
    
    void toggle(string seat) {
        int ch = seat[0] - 'A'; 
        string s = seat.substr(1) ;

        int row = stoi(s) ;

        if (bus[row][ch])
        {
            booked-- ;
            bus[row][ch] = false ;
            toltime -= cost[row][ch] ;
            cost[row][ch] = 0 ;
        }
        else
        {
            booked++ ;
            int c = 1 ;
            if (ch == 0 && bus[row][1]) c = 3 ;
            if (ch == 3 && bus[row][2]) c = 3 ;
            bus[row][ch] = true ;
            cost[row][ch] = c ;
            toltime += c ;
        }
    }
    
    int getTotalTime() {
        return toltime ; 
    }
    
    int getMinTime() {
        return booked ;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */