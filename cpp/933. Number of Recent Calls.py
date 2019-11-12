//Second solution
//Complicated (see lecture https://www.youtube.com/watch?v=iK2EnenuLG0&list=PLES6U-jjEXscLKgGQkLglfLn7myfyGtjj&index=80)



//First solution
class RecentCounter {
    
    queue<int> q;
    
    
public:
    
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return (int)q.size();
    }
};
