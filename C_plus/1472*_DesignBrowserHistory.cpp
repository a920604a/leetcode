class BrowserHistory
{
private:
    string stack[5005];
    int p, t; // current pointer, stack's top

public:
    BrowserHistory(string homepage)
    {
        int p = 0, t = 0;
        stack[0] = homepage;
    }

    void visit(string url)
    {
        // stack[t = ++p] = url;
        p++;
        t = p;
        stack[t] = url;
    }

    string back(int steps)
    {
        // return stack[p = max(0, p-steps)];
        p = max(0, p - steps);
        return stack[p];
    }

    string forward(int steps)
    {
        // return stack[p = min(t, p+steps)];
        p = min(t, p + steps);
        return stack[p];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */