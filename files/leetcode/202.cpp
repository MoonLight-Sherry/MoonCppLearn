//快慢指针
//数字的平方和形成循环或归于0

class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n)
        {
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = getSum(slow);
            fast = getSum(fast);
            fast = getSum(fast);
        }
        while(slow != fast);
        return slow == 1;
    }
};