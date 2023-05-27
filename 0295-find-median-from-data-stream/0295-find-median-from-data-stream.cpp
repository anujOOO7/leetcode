#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class MedianFinder {
public:
    typedef tree<pair<int,int>, null_type, 
        less<pair<int,int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set_pair;
    
    ordered_set_pair s;
    int i=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.insert({num,i++});
    }
    
    double findMedian() {
        int n=s.size();
        auto it1=s.find_by_order(n/2); 
        double num=(*it1).first;
        if(n%2==0){
            auto it2=s.find_by_order((n-1)/2);
            double num1=(*it2).first;
            num=(num+num1)/2;
        }
        return num;
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */