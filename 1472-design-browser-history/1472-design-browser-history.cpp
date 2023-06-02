struct dll{
    dll* next;
    dll* prev;
    string val;
    dll(): next(NULL),prev(NULL),val(""){}
    dll(string x): next(NULL),prev(NULL),val(x){}
};

class BrowserHistory {
public:
    dll* browser;
    BrowserHistory(string homepage) {
        browser=new dll(homepage);
    }

    void visit(string url) {
        browser->next=NULL;
        dll* temp=new dll(url);
        browser->next=temp;
        temp->prev=browser;
        browser=temp;
    }

    string back(int steps) {
        while(steps-- && browser->prev){
            browser=browser->prev;
        }
        return browser->val;
    }

    string forward(int steps) {
        while(steps-- && browser->next){
            browser=browser->next;
        }
        return browser->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */