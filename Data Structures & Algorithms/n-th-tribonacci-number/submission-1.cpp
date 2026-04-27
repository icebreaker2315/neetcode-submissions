class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        static vector<int> done(38, -1);

        if (done[0] == -1) {
            done[0] = 0;
            done[1] = 1;
            done[2] = 1;
        }

        if(done[n] != -1){
            return done[n];
        }else{
            done[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        }
        return done[n];
    }
};