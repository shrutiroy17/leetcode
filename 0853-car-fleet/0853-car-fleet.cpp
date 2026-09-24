class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>cars;
        int n = position.size();
        for(int i=0;i<n;i++){
            double time = (double)(target-position[i])/(double)speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.rbegin(),cars.rend());
        stack<double>st;
        for(auto car:cars){
            double speed = car.second;
            if(st.empty() || speed>st.top() ){
                st.push(speed);
            }
        }
        return st.size();
    }
};
