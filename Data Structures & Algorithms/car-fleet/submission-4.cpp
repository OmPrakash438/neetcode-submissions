class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<double> fleet;

        vector<pair<int, int>> cars(n);
        for(int i=0; i<n; i++){
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.rbegin(), cars.rend());


        for(int i=0; i<n; i++){
            double dist = target - cars[i].first;
            double time = dist / cars[i].second;

            if(fleet.empty()) fleet.push(time);
            else if(time > fleet.top()){
                fleet.push(time);
            }
        }

        return fleet.size();
    }
};
