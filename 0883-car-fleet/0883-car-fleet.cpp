class Solution {
   
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //vector of objects of type car
        vector<pair<int,double>> cars;
        for(int i = 0; i<position.size();i++)
        {
            double time = (double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }

        //sort in decreasing order
        sort(cars.rbegin(),cars.rend());
        stack<double> st;

        //iterate over car vector
        for(auto car:cars)
        {
            double time = car.second;
            //agr curr time top se zayada hoga tabhi fleet possible hoga
            // tabhi push karenge
            if(st.empty() || time > st.top())
            {
                st.push(time);
            }
        }

        //at last stack me sirf fleet waali gadiye hogi
        return st.size();

    }
};