class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long int count=0;
        long long int sum=0;
        while(sum<neededApples){
            count++;
            sum=sum+12*count*count;
        }
        return 8*count;
    }
};