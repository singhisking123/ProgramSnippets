bool isPossible(vector<int> & piles, int h, int mid) {
    int curr_h = 1;
    int sum = 0;
    for(int i = 0; i<piles.size(); i++) {
        sum += piles[i];
        if(sum > mid) {
            sum = piles[i]; // sum ko phirse piles[i] se suru kar do 
            curr_h++; //day is incremented as new subarray begin up
        }
    }
    return curr_h <= h;
}