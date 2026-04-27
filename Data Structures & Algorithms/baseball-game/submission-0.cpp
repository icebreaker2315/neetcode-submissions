class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(auto op: operations){
            if(op == "C"){
                st.pop();
            }else if(op == "D"){
                int temp = st.top();
                temp = temp * 2;
                st.push(temp);
            }else if(op == "+"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                int temp = first + second;

                st.push(first);
                st.push(second);
                st.push(temp);
            }else{
                st.push(stoi(op));
            }
        }

        int total = 0;
        while(st.size()>0){
            int temp = st.top();
            st.pop();
            total += temp;
        }
        
        return total;
    }
};