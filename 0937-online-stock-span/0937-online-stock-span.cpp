class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>> st;
    int next(int price) {
       
         int span = 1;
        while(!st.empty() && st.top().first <= price)
        {
           
            //jab tk baraabar ya kam ka stock price mile toh span me add krte chalo
            //aur bahar nikaalte chalo
            span += st.top().second;
            st.pop();
        }

        //yaa stack empty  hai 
        //yaa stock price bada hai(shota nahi mila abhi) curr se toh use b push krdo with its span
        st.push({price,span});
        return span;
        
    }
};
