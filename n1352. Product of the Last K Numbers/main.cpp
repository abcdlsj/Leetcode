// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class ProductOfNumbers {
public:
    vector<int> Num;
    ProductOfNumbers() {
    }
    
    void add(int num) {
      Num.push_back(num);  
    }
    
    int getProduct(int k) {
      int pro = 1;
      for(int i = Num.size()-k;i<Num.size();i++){
        if(Num[i]==0) {
          pro = 0;break;
        }
        pro *= Num[i];
      }
      return pro;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
