class Solution {
public:
    vector<string> fizzBuzz(int n) {

        vector<string> fizzBuzzVector;
        for(int i=1; i<=n ; i++)
        {
            if(((i % 3)==0) && ((i % 5)==0))
                fizzBuzzVector.push_back("FizzBuzz");
            else if ((i % 3)==0)
                fizzBuzzVector.push_back("Fizz");

            else if ((i % 5)==0)
                fizzBuzzVector.push_back("Buzz");
            else 
                fizzBuzzVector.push_back(to_string(i));
        }
        return fizzBuzzVector;
    }
};
