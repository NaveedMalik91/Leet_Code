class BrowserHistory {
public:
    stack<string>browser; //store curr location
    stack<string> fwdStack; //stores forward location or history
    BrowserHistory(string homepage) {
        browser.push(homepage);
    }
    
    void visit(string url) {
        //kisi doosre url pe jaane se pehle 
        // clear all the forward history
        while(!fwdStack.empty())
        {
            fwdStack.pop();
        }
        //aur next url pe chale jaao
        browser.push(url);
    }
    
    string back(int steps) {
        while(steps--)
        {
            //homepage tk he back kr sakte ho
            if(browser.size() > 1){
                //agr waapis kisi url pe aana hai
                //toh fwd stack me browser stack ki entry daalo
                fwdStack.push(browser.top());
                browser.pop();
            }
            //homepage se piche nahi jaa sakte
            else
            {
                break;
            }
        }
        //return current page
        return browser.top();
        
        
    } 
    
    string forward(int steps) {
        while(steps--)
        {
            //agr forward me koi history hai tabhi jaa sakte ho
            if(!fwdStack.empty()){
                //agr AAGE kisi url pe aana hai
                //toh browser me fwd stack ki entry daalo
                browser.push(fwdStack.top());
                fwdStack.pop();
            }
            //homepage se piche nahi jaa sakte
            else
            {
                break;
            }
        }
        //return current page
        return browser.top();
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */