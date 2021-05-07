

// Write your Student class here
class Student{
    private:
    int scores[5];
    public:
   
    void input(){
        
        for(int i = 0 ; i < 5 ; i++){
            int scores;
            cin >> scores;
            this-> scores[i] = scores;
        }
    }

    int calculateTotalScore(){
        int sum = 0;
        for(int i = 0 ; i < 5 ; i++){
            sum += scores[i];
        }
        return sum;
    }
};

