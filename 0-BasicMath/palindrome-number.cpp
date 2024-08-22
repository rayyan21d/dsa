bool isPalindrome(int x) {

    int num=x, result = 0, max_last_digit = INT_MAX%10, min_last_digit = INT_MIN%10, digit;
    while (num>0) {
        digit = num % 10;
        num /= 10;
        if((result > INT_MAX/10 || result < INT_MIN/10)) {
            return 0;
        }
        result = result*10 + digit;
    }

    if(result==x){
        return true;
    }else{
        return false;
    }

    

}
